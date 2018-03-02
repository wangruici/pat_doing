#include <cstdio>
#include <utility>
#include <cstring>
#include <vector>
#include <algorithm>
#include <tuple>
#include <stack>
using std::fill;
using std::vector;
using std::tuple;
using std::stack;
using std::pair;
using std::get;
const int maxn=510;
const int INF=0x3fffffff;

int city_num=0,road_num=0,start_point=0,end_point=0;
int graph[maxn][maxn];
bool visited[maxn];
int distance[maxn];
vector<int> pre[maxn];
int num[maxn];
int cost[maxn][maxn];
int c[maxn];
void dijkstra(int start_point){
	memset(visited,false,sizeof(visited));
	fill(distance,distance+maxn,INF);
	distance[start_point]=0;
	fill(num,num+maxn,0);
	num[start_point]=1;
	for(int i=0;i<city_num;++i){
		int u=-1;
		int MIN=INF;
		for(int j=0;j<city_num;++j){
			if(visited[j]==false&&distance[j]<MIN){
				u=j;
				MIN=distance[j];
			}
		}
		if(MIN==INF) return;
		visited[u]=true;
		for(int v=0;v<city_num;++v){
			if(visited[v]==false&&graph[u][v]!=INF){
				if(graph[u][v]+distance[u]<distance[v]){
					distance[v]=graph[u][v]+distance[u];
					pre[v].clear();
					pre[v].push_back(u);
					num[v]=num[u];
				}
				else if(graph[u][v]+distance[u]==distance[v]){
					pre[v].push_back(u);
					num[v]=num[u]+num[v];
				}
				else{
					;
				}
			}
		}
	}
}

vector<vector<int>> get_path(int start_point,int end_point){
	vector<vector<int>> path;
	stack<pair<int,bool> > sta;
	vector<int> temp;
	sta.push(pair<int,bool>(end_point,false));
	while(!sta.empty()){
		pair<int,bool> &top=sta.top();
		if(top.second==false){
			if(top.first!=start_point){
				for(int i=0;i<(int)pre[top.first].size();++i){	
					sta.push(pair<int,bool>(pre[top.first][i],false));
				}
			}
			else{
				temp.push_back(top.first);
				path.push_back(temp);
				temp.pop_back();
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
int minCost=INF;
vector<int> path;
vector<int> tempPath;
void DFS(int v){
	if(v==start_point){
		tempPath.push_back(v);
		int tempCost=0;
		for(int i=tempPath.size()-1;i>0;--i){
			int id=tempPath[i],idNext=tempPath[i-1];
			tempCost+=cost[id][idNext];
		}
		if(tempCost<minCost){
			minCost=tempCost;
			path=tempPath;

		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for(int i=0;i<(int)pre[v].size();++i){
		DFS(pre[v][i]);
	}
	tempPath.pop_back();
}


int main(){
	int city_num,road_num,start_point,end_point;
	scanf("%d%d%d%d",&city_num,&road_num,&start_point,&end_point);
	int u,v;
	fill(graph[0],graph[0]+maxn*maxn,INF);
	fill(cost[0],cost[0]+maxn*maxn,INF);
	for(int i=0;i<road_num;++i){
		scanf("%d%d",&u,&v);
		scanf("%d%d",&graph[u][v],&cost[u][v]);
		graph[v][u]=graph[u][v];
		cost[v][u]=cost[u][v];
	}
	dijkstra(start_point);
	DFS(end_point);
	for(int i=path.size()-1;i>=0;--i){
		printf("%d ",path[i]);
	}
	printf("%d %d\n",distance[end_point],minCost);
	return 0;
}
