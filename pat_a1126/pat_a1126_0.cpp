#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using std::fill;
using std::vector;
using std::cin;
using std::cout;
using std::string;
using std::endl;

const int maxn=510;
vector<int> graph[maxn];
bool visited[maxn];
//判断图示否联通
int dfs(vector<int> (&graph)[maxn],int begin,bool (&visited)[maxn]){
	visited[begin]=true;
	for(int i=0;i<(int)graph[begin].size();++i){
		if(visited[graph[begin][i]]==false){
			dfs(graph,graph[begin][i],visited);
		}
	}
	return 0;
}
int main(){
	memset(visited,false,sizeof(visited));
	int point_num,edge_num;
	cin>>point_num>>edge_num;
	int point1,point2;

	for(int i=0;i<edge_num;++i){
		cin>>point1>>point2;		
		graph[point1-1].push_back(point2-1);
		graph[point2-1].push_back(point1-1);
	}
	bool isConnected=true;
	int count=0;
	for(int i=0;i<point_num;++i){
		if(visited[i]==false){
			++count;
			dfs(graph,0,visited);
		}
	}
	if(count>1){
		isConnected=false;
	}
	int odd_degree_point=0;
	if(isConnected){
		for(int i=0;i<point_num;++i){
			if((int)graph[i].size()%2!=0){
				++odd_degree_point;
			}
		}
	}
	for(int i=0;i<point_num;++i){
		cout<<graph[i].size();
		if(i!=point_num-1){
			cout<<" ";
		}
		else{
			cout<<endl;
		}
	}
	if(isConnected&&odd_degree_point==0){
		cout<<"Eulerian"<<endl;
	}
	else if(isConnected&&odd_degree_point==2){
		cout<<"Semi-Eulerian"<<endl;
	}
	else{
		cout<<"Non-Eulerian"<<endl;
	}
	return 0;
}
