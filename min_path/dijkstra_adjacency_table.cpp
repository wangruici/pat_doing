#include <algorithm>
#include <vector>;
using std::vector;
using std::fill;
const int MAXV=1000;
const int INF=0x3fffffff;
struct Node{
	int end;
	int dis;
};

vector<Node> Adj[MAXV];

int point_num;

int distance[MAXV];
bool visited[MAXV]={false};
void Dijkstra(int begin_index){
	fill(distance,distance+MAXV,INF);
	distance[begin_index]=0;
	for(int i=0;i<point_num;++i){
		int u=-1;
		int MIN=INF;
/********************************************************************************/
//这一段代码是为了查找未被访问的而且距离最小的点，可以用堆或者优先队列priority_queue STL来优化
//但是visited数组仍旧需要保留因为后没需要按照序号访问位置
		for(int j=0;j<point_num;++j){
			if(visited[j]==false&&MIN>distance[j]){
				u=j;
				MIN=distance[j];
			}
		}
/********************************************************************************/		
		if(u==-1) return;
		visited[u]=true;
		for(int j=0;j<(int)Adj[u].size();++j){
			int v=Adj[u][j].end;
			if(visited[v]==false&&distance[u]+Adj[u][j].dis<distance[v]){
				distance[v]=distance[u]+Adj[u][j].dis;
			}
		}
	}
}
