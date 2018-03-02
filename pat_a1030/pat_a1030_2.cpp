#include <cstdio>

#include <cstring>
#include <utility>
#include <vector>
#include <algorithm>
#include <stack>

using std::fill;
using std::vector;
using std::stack;
using std::pair;

const int maxn=510;
const int INF=0x3fffffff;


vector<vector<int> > dijkstra(int (&graph)[maxn][maxn],int point_num,int start_point,int end_point,int &min_distance){
	bool visited[maxn];
	int distance[maxn];
	vector<int> pre[maxn];
	memset(visited,false,sizeof(visited));
	fill(distance,distance+maxn,INF);
	distance[start_point]=0;
	for(int i=0;i<point_num;++i){
		int u=-1;
		int MIN=INF;
		for(int j=0;j<point_num;++j){
			if(visited[j]==false&&distance[j]<MIN){
				u=j;
				MIN=distance[j];
			}
		}
		if(MIN==INF) break;
		visited[u]=true;
		for(int v=0;v<point_num;++v){
			if(visited[v]==false&&graph[u][v]!=INF){
				if(graph[u][v]+distance[u]<distance[v]){
					distance[v]=graph[u][v]+distance[u];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if(graph[u][v]+distance[u]==distance[v]){
					pre[v].push_back(u);
				}
				else{
					;
				}
			}
		}
	}
	min_distance=distance[end_point];
	vector<vector<int> >path;
	stack<pair<int,bool> >sta;
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


int main(){
	int city_num,road_num,start_point,end_point;
	int graph[maxn][maxn];
	int cost[maxn][maxn];
	scanf("%d%d%d%d",&city_num,&road_num,&start_point,&end_point);
	int u,v;
	fill(graph[0],graph[0]+maxn*maxn,INF);
	for(int i=0;i<road_num;++i){
		scanf("%d%d",&u,&v);
		scanf("%d%d",&graph[u][v],&cost[u][v]);
		graph[v][u]=graph[u][v];
		cost[v][u]=cost[u][v];
	}
	int min_distance;
	vector<vector<int>> ans=dijkstra(graph,city_num,start_point,end_point,min_distance);
	int min_cost=INF;
	int min_path_index;
	for(int i=0;i<(int)ans.size();++i){
		int c=0;
		for(int j=0;j<(int)ans[i].size()-1;++j){
			c+=cost[ans[i][j]][ans[i][j+1]];
		}
		if(min_cost>c){
			min_cost=c;
			min_path_index=i;
		}
	}
	for(int i=(int)ans[min_path_index].size()-1;i>=0;--i){
		printf("%d ",ans[min_path_index][i]);
	}
	printf("%d %d\n",min_distance,min_cost);
	return 0;


}
