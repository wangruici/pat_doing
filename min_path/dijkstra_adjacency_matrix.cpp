#include <algorithm>
using std::fill;
const int MAXV=1000;
const int INF=0x3fffffff;

int point_num,graph[MAXV][MAXV];

int distance[MAXV];
int pre[MAXV];//表示从起点到顶点v的最短路径上v的前一个点
bool visited[MAXV]={false};

void Dijkstra(int begin_index){
	fill(distance,distance+MAXV,INF);//fill函数将整个数组distance赋值为INF;
	distance[begin_index]=0;
	for(int i=0;i<point_num;++i){
		int u=-1,MIN=INF;//distance[u]是中distance[i]最小的，MIN存放distance[u]
		for(int j=0;j<point_num;++j){
			if(visited[j]==false&&distance[j]<MIN){
				u=j;
				MIN=distance[j];
			}
		}
				
		if(u==-1) return;//找不到未访问而且距离比INF更小的点了，说明其他点和起点都不联通
		visited[u]=true;//标记为已经访问
		for(int i=0;i<point_num;++i){
			//如果i还没有被访问&&u能到达i&&以u为中介可以使distance[i]更优
			if(visited[i]==false&&graph[u][i]!=INF&&distance[u]+graph[u][i]<distance[i]){
				distance[i]=distance[u]+graph[u][i];
				pre[i]=u;//记录i的前驱
			}
		}
	}
}

void get_path_dfs(int begin_point,int end_point){
	if(begin_point==end_point){
		printf("%d\n",begin_point);
		return;
	}
	get_path_dfs(begin_point,pre[end_point]);
	printf("%d\n",end_point);
}


/********************************************************************************************/
//如果题目给出了不止一种权值，还有另外一种权值（边权），可以改进该算法
//设另外一个权值为cost ,cost[][];
void Dijkstra2(int begin_index){
	fill(distance,distance+MAXV,INF);//fill函数将整个数组distance赋值为INF;
	distance[begin_index]=0;
	for(int i=0;i<point_num;++i){
		int u=-1,MIN=INF;//distance[u]是中distance[i]最小的，MIN存放distance[u]
		for(int j=0;j<point_num;++j){
			if(visited[j]==false&&distance[j]<MIN){
				u=j;
				MIN=distance[j];
			}
		}
				
		if(u==-1) return;//找不到未访问而且距离比INF更小的点了，说明其他点和起点都不联通
		visited[u]=true;//标记为已经访问
		for(int i=0;i<point_num;++i){
			//如果i还没有被访问&&u能到达i&&以u为中介可以使distance[i]更优
			if(visited[i]==false&&graph[u][i]!=INF){
				if(distance[u]+graph[u][i]<distance[i]){
					distance[i]=distance[u]+graph[u][i];
					c[i]=c[u]+cost[u][i];
				}
				else if(distance[u]+graph[u][i]==distance[i]&&c[u]+cost[u][i]<c[i]){
					c[i]=c[u]+cost[u][i];
				}
			}
		}
	}
}



