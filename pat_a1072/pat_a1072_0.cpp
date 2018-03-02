#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
using std::vector;
using std::fill;

const int maxn=1020;
const int INF=0x3fffffff;
int n,m,k,DS,graph[maxn][maxn];
int distance[maxn];
bool visited[maxn];
int node_num;
void dijkstra(int start_point){
	fill(distance,distance+maxn,INF);
	memset(visited,false,sizeof(visited));
	distance[start_point]=0;
	for(int i=1;i<=node_num;++i){
		int u=-1;
		int MIN=INF;
		for(int j=1;j<=node_num;++j){
			if(visited[j]==false&&distance[j]<MIN){
				u=j;
				MIN=distance[j];
			}
		}
		if(MIN==INF) return;
		visited[u]=true;
		for(int v=1;v<=node_num;++v){
			if(visited[v]==false&&graph[u][v]!=INF){
				if(distance[v]>graph[u][v]+distance[u]){
					distance[v]=graph[u][v]+distance[u];
				}
			}
		}
	}
}
int getID(char str[]){
	int i=0;
	int len=strlen(str);
	int ID=0;
	while(i<len){
		if(str[i]!='G'){
			ID=ID*10+(str[i]-'0');
		}
		++i;
	}
	if(str[0]=='G') return n+ID;
	else return ID;
}

int main(){
	scanf("%d%d%d%d",&n,&m,&k,&DS);
	int u,v,w;
	char city1[5],city2[5];
	fill(graph[0],graph[0]+maxn*maxn,INF);
	for(int i=0;i<k;++i){
		scanf("%s %s %d",city1,city2,&w);
		u=getID(city1);
		v=getID(city2);
		graph[v][u]=graph[u][v]=w;
	}
	double ansDis=-1,ansAvg=INF;
	int ansID=-1;
	node_num=m+n;
	for(int i=n+1;i<=n+m;++i){
		double minDis=INF,avg=0;
		dijkstra(i);
		for(int j=1;j<=n;++j){
			if(distance[j]>DS){
				minDis=-1;
				break;
			}
			if(distance[j]<minDis) minDis=distance[j];
			avg+=1.0*distance[j]/n;
		}
		if(minDis==-1) continue;
		if(minDis>ansDis){
			ansID=i;
			ansDis=minDis;
			ansAvg=avg;
		}
		else if(minDis==ansDis&&avg<ansAvg){
			ansID=i;
			ansAvg=avg;
		}
	}
	if(ansID==-1) printf("No Solution\n");
	else{
		printf("G%d\n",ansID-n);
		printf("%.1f %.1f\n",ansDis,ansAvg);
	}
	return 0;
}
