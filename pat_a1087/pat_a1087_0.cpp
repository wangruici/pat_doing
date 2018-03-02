#include <vector>
#include <cstring>
#include <map>
#include <utility>
#include <algorithm>
#include <stack>
#include <string>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stack;
using std::fill;
using std::vector;
using std::pair;
using std::map;

const int maxn=300;
const int INF=0x3fffffff;

vector<vector<int> > dijkstra(int (&graph)[maxn][maxn],int node_num,int start_point,int end_point,int &min_distance){
	int distance[maxn];
	bool visited[maxn];
	memset(visited,false,sizeof(visited));
	fill(distance,distance+maxn,INF);
	distance[start_point]=0;
	vector<int> pre[maxn];
	for(int i=0;i<node_num;++i){
		int u=-1;
		int MIN=INF;
		for(int j=0;j<node_num;++j){
			if(visited[j]==false&&MIN>distance[j]){
				u=j;
				MIN=distance[j];
			}
		}
		if(MIN==INF) break;
		visited[u]=true;
		for(int v=0;v<node_num;++v){
			if(visited[v]==false&&graph[u][v]!=INF){
				if(distance[v]>distance[u]+graph[u][v]){
					pre[v].clear();
					pre[v].push_back(u);
					distance[v]=distance[u]+graph[u][v];
				}
				else if(distance[v]==distance[u]+graph[u][v]){
					pre[v].push_back(u);
				}
			}
		}
	}
	vector<vector<int> > path;
	vector<int> temp;
	min_distance=distance[end_point];
	stack<pair<int,bool> >sta;
	sta.push(pair<int,bool>(end_point,false));
	while(!sta.empty()){
		pair<int,bool> &top=sta.top();
		if(top.second==false){
			if(top.first==start_point){
				temp.push_back(top.first);
				path.push_back(temp);
				temp.pop_back();
			}
			else{
				for(int i=0;i<(int)pre[top.first].size();++i){
					sta.push(pair<int,bool>(pre[top.first][i],false));
				}
			}
			top.second=true;
			temp.push_back(top.first);
		}
		else{
			sta.pop();
			temp.pop_back();
		}
	}
	return path;
}



int main(){
	map<int,string> get_name;
	map<string,int> get_id;
	int graph[maxn][maxn];
	fill(graph[0],graph[0]+maxn*maxn,INF);
	int node_num,route_num;
	string start_city;
	int city_happiness[maxn];
	fill(city_happiness,city_happiness+maxn,INF);
	cin>>node_num>>route_num>>start_city;
	string city_name;
	int happiness_num;
	for(int i=0;i<node_num-1;++i){
		cin>>city_name>>happiness_num;
		get_id[city_name]=i;
		get_name[i]=city_name;
		city_happiness[i]=happiness_num;
	}
	string name1,name2;
	int d;
	for(int i=0;i<route_num;++i){
		cin>>name1>>name2;
		if(get_id.find(name1)==get_id.end()){
			get_id[name1]=node_num-1;
			get_name[node_num-1]=name1;
		}
		if(get_id.find(name2)==get_id.end()){
			get_id[name2]=node_num-1;
			get_name[node_num-1]=name2;
		}
		cin>>d;
		graph[get_id[name1]][get_id[name2]]=graph[get_id[name2]][get_id[name1]]=d;
	}
	int min_distance;
	vector<vector<int> > path=dijkstra(graph,node_num,get_id[start_city],get_id["ROM"],min_distance);
	int max_happiness=-1;
	int max_avg=-1;
	int index;
	/*
	for(int i=0;i<(int)path.size();++i){
		for(int j=(int)path[i].size()-1;j>=0;--j){
			cout<<path[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	for(int i=0;i<(int)path.size();++i){
		int happiness=0;
		int avg=0;
		for(int j=path[i].size()-2;j>=0;--j){
			happiness=happiness+city_happiness[path[i][j]];	
		}
		avg=happiness/(path[i].size()-1);
		if(happiness>max_happiness){
			index=i;
			max_happiness=happiness;
			max_avg=avg;
		}
		else if(happiness==max_happiness&&max_avg<avg){
			index=i;
			max_avg=avg;
		}
	}
	cout<<path.size()<<" "<<min_distance<<" "<<max_happiness<<" "<<max_avg<<endl;
	for(int i=path[index].size()-1;i>=0;--i){
		cout<<get_name[path[index][i]];
		if(i!=0){
			cout<<"->";
		}
		else{
			cout<<endl;
		}
	}
	return 0;
}

