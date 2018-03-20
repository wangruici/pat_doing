/*
 *用nowHander记录最短路径上收集到的人手，如果可以在最短的前提下
 *收集到更多的人手，更新
 *优化路径长度时，最短路径的数目num为上一节点最短路径的数目
 *如果出现相同的路径长度，当前节点的路径数目+上一节点的路径数目
 *一定要记住，在dijkstra算法的大循环中，每循环一次，会检查两次visited
 */
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using std::fill;
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

const int maxn=510;
const int INF=0x3fffffff;
int graph[maxn][maxn];
bool visited[maxn];
int distance[maxn];
int hander[maxn];
int num[maxn];
int nowHander[maxn];
void dijkstra(int begin,int ncount){
	memset(visited,false,sizeof(visited));
	fill(distance,distance+maxn,INF);
	fill(nowHander,nowHander+maxn,0);
	fill(num,num+maxn,0);
	distance[begin]=0;
	num[begin]=1;
	nowHander[begin]=hander[begin];
	for(int i=0;i<ncount;++i){
		int u=-1;
		int minDis=INF;
		for(int j=0;j<ncount;++j){
			if(visited[j]==false&&minDis>distance[j]){
				u=j;
				minDis=distance[j];
			}
		}
		if(u==-1){
			return;
		}
		visited[u]=true;
		for(int v=0;v<ncount;++v){
			if(visited[v]==false&&graph[u][v]!=INF){
				if(distance[u]+graph[u][v]<distance[v]){
					distance[v]=distance[u]+graph[u][v];
					num[v]=num[u];
					nowHander[v]=nowHander[u]+hander[v];
				}
				else if(distance[u]+graph[u][v]==distance[v]){
					if(nowHander[u]+hander[v]>nowHander[v]){
						nowHander[v]=nowHander[u]+hander[v];	
					}
					num[v]+=num[u];
				}
			}
		}
	}
}

int main(){
	int point_count,road_count,begin,end;
	scanf("%d%d%d%d",&point_count,&road_count,&begin,&end);
	for(int i=0;i<point_count;++i){
		scanf("%d",&hander[i]);
	}

	fill(graph[0],graph[0]+maxn*maxn,INF);
	int id1,id2;
	int howLong;
	for(int i=0;i<road_count;++i){
		scanf("%d %d %d",&id1,&id2,&howLong);
		graph[id1][id2]=howLong;
		graph[id2][id1]=howLong;
	}
	dijkstra(begin,point_count);
	printf("%d %d\n",num[end],nowHander[end]);
	return 0;

}
