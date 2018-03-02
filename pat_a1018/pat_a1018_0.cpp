#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
#include <stack>
#include <cmath>
using std::stack;
using std::pair;
using std::fill;
using std::vector;

const int maxn=510;
const int INF=0x3fffffff;
vector<vector<int> > dijkstra(int (&graph)[maxn][maxn],int node_num,int start_point,int end_point,int &min_distance){
	bool visited[maxn];
	vector<int> pre[maxn];
	int distance[maxn];
	memset(visited,false,sizeof(visited));
	fill(distance,distance+maxn,INF);
	distance[start_point]=0;
	for(int i=0;i<node_num;++i){
		int u=-1;
		int MIN=INF;
		for(int j=0;j<node_num;++j){
			if(visited[j]==false&&MIN>distance[j]){
				MIN=distance[j];
				u=j;
			}
		}
		if(MIN==INF) break;
		visited[u]=true;
		for(int v=0;v<node_num;++v){
			if(visited[v]==false&&graph[u][v]!=INF){
				if(distance[u]+graph[u][v]<distance[v]){
					distance[v]=distance[u]+graph[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if(distance[u]+graph[u][v]==distance[v]){
					pre[v].push_back(u);
				}
			}
		}
	}
	min_distance=distance[end_point];
	vector<vector<int> > ans;
	stack<pair<int,bool> >sta;
	vector<int> temp;
	sta.push(pair<int,bool>(end_point,false));
	while(!sta.empty()){
		pair<int,bool> &top=sta.top();
		if(top.second==false){
			if(top.first==start_point){
				temp.push_back(top.first);
				ans.push_back(temp);
				temp.pop_back();
			}
			else{
				for(int i=0;i<(int)pre[top.first].size();++i){
					sta.push(pair<int,bool>(pre[top.first][i],false));
				}
			}
			temp.push_back(top.first);
			top.second=true;
		}
		else{
			sta.pop();
			temp.pop_back();
		}
	}
	return ans;
}

int graph[maxn][maxn];
int statu_currently[maxn];

int main(){
	fill(graph[0],graph[0]+maxn*maxn,INF);
	fill(statu_currently,statu_currently+maxn,0);
	int max_capacity,station_num,index_wrong,road_num;

	scanf("%d%d%d%d",&max_capacity,&station_num,&index_wrong,&road_num);

	for(int i=1;i<=station_num;++i){
		scanf("%d",&statu_currently[i]);
		statu_currently[i]=statu_currently[i]-max_capacity/2;
	}
	int id1,id2;
	for(int i=0;i<road_num;++i){
		scanf("%d%d",&id1,&id2);
		scanf("%d",&graph[id1][id2]);
		graph[id2][id1]=graph[id1][id2];
	}
	int min_distance;
	vector<vector<int> > ans=dijkstra(graph,station_num+1,0,index_wrong,min_distance);
	int min_take=INF;
	int min_remin=INF;
	int index=0;
	for(int i=0;i<(int)ans.size();++i){
		int take=0;
		int remin=0;
		for(int j=(int)ans[i].size()-2;j>=0;--j){
			if(statu_currently[ans[i][j]]>=0){
				remin+=statu_currently[ans[i][j]];
			}
			else if(remin-abs(statu_currently[ans[i][j]])>=0){
				remin-=abs(statu_currently[ans[i][j]]);
			}
			else{
				take+=abs(statu_currently[ans[i][j]])-remin;
				remin=0;
			}
		}
		if(min_take>take){
			index=i;
			min_take=take;
			min_remin=remin;
		}
		else if(min_take==take&&min_remin>remin){
			index=i;
			min_remin=remin;
		}
	}
	printf("%d ",min_take);
	for(int i=(int)ans[index].size()-1;i>=0;--i){
		printf("%d",ans[index][i]);
		if(i!=0){
			printf("->");
		}
		else{
			printf(" ");
		}
	}
	printf("%d",min_remin);
	return 0;
}
