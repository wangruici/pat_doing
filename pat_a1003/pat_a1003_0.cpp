#include <cstdio>
#include <vector>
#include <algorithm>

using std::fill;
using std::vector;

const int maxn=510;
const int INF=0x3fffffff;

int num[maxn]={0};
int weight[maxn];
int graph[maxn][maxn]={{INF}};
int distance[maxn];
int w[maxn]={0};
void dijkstra(int begin_point,const int (&graph)[maxn][maxn],const int node_num,int (&weight)[maxn]){
	num[begin_point]=1;
	w[begin_point]=weight[begin_point];
	bool visited[maxn]={false};
	fill(distance,distance+maxn,INF);
	distance[begin_point]=0;
	for(int i=0;i<node_num;++i){
		int u=-1;
		int MIN=INF;
		for(int j=0;j<node_num;++j){
			if(visited[j]==false&&MIN>distance[j]){
				MIN=distance[j];
				u=j;
			}
		}
		if(u==-1) return;
		visited[u]=true;
		for(int v=0;v<node_num;++v){
			if(visited[v]==false&&graph[u][v]!=INF){
				if(graph[u][v]+distance[u]<distance[v]){
					distance[v]=graph[u][v]+distance[u];
					num[v]=num[u];
					w[v]=w[u]+weight[v];
				}
				else if(graph[u][v]+distance[u]==distance[v]){
					if(w[u]+weight[v]>w[v]){
						w[v]=w[u]+weight[v];
					}
					num[v]+=num[u];
				}
			}
		}
	}
}

void dijkstra(int begin_point,const int (&graph)[maxn][maxn],const int node_num,int (&weight)[maxn]);
int main(){
	fill(graph[0],graph[0]+maxn*maxn,INF);
	int city_num=0,road_num=0,current_in=0,object=0;
	scanf("%d %d %d %d",&city_num,&road_num,&current_in,&object);
	int value;
	for(int i=0;i<city_num;++i){
		scanf("%d",&value);
		weight[i]=value;
	}
	int id1,id2;
	int len;
	for(int i=0;i<road_num;++i){
		scanf("%d %d",&id1,&id2);
		scanf("%d",&len);
		graph[id1][id2]=len;
		graph[id2][id1]=len;
	}
	dijkstra(current_in,graph,city_num,weight);
	printf("%d %d\n",num[object],w[object]);
	return 0;
}
