#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using std::fill;
using std::vector;


const int MAXV=510;
const int INF=0x3ffffff;

int node_num,road_num,start_point,end_point,graph[MAXV][MAXV],cost[MAXV][MAXV];

int distance[MAXV],c[MAXV],pre[MAXV];
bool visited[MAXV];

void dijkstra(int start_point){
	memset(visited,false,sizeof(visited));
	fill(distance,distance+MAXV,INF);
	fill(c,c+MAXV,INF);
	fill(pre,pre+MAXV,-1);
	distance[start_point]=0;
	c[start_point]=0;
	for(int i=0;i<node_num;++i){
		int MIN=INF;
		int u=-1;
		for(int j=0;j<node_num;++j){
			if(visited[j]==false&&distance[j]<MIN){
				u=j;
				MIN=distance[j];
			}
		}
		if(MIN==INF) return;
		visited[u]=true;
		for(int v=0;v<node_num;++v){
			if(visited[v]==false&&graph[u][v]!=INF){
				if(graph[u][v]+distance[u]<distance[v]){
					distance[v]=graph[u][v]+distance[u];
					pre[v]=u;
					c[v]=c[u]+cost[v][u];
				}
				else if(graph[u][v]+distance[u]==distance[v]&&cost[u][v]+c[u]<c[v]){
					pre[v]=u;
					c[v]=c[u]+cost[v][u];
				}
			}
		}
	}
}

//打印路径
void dfs(int v){
	if(v==start_point){
		printf("%d ",v);
		return;
	}
	dfs(pre[v]);
	printf("%d ",v);
}

int main(){
	scanf("%d%d%d%d",&node_num,&road_num,&start_point,&end_point);
	int u,v;
	fill(graph[0],graph[0]+MAXV*MAXV,INF);
	for(int i=0;i<road_num;++i){
		scanf("%d%d",&u,&v);
		scanf("%d%d",&graph[u][v],&cost[u][v]);
		graph[v][u]=graph[u][v];
		cost[v][u]=cost[u][v];
	}
	dijkstra(start_point);
	dfs(end_point);
	printf("%d %d\n",distance[end_point],c[end_point]);
	return 0;
}
