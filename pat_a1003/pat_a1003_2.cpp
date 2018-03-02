#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>

using std::vector;
using std::set;
using std::fill;

const int MAXV=510;

const int INF=0x3fffffff;

struct Node{
	int v,dis;
	Node(int _v,int _dis):v(_v),dis(_dis){}
};

vector<Node> Adj[MAXV];

int n,m,st,ed,weight[MAXV];

int d[MAXV],w[MAXV],num[MAXV];

set<int> pre[MAXV];

void Bellman(int s){
	fill(d,d+MAXV,INF);
	memset(num,0,sizeof(num));
	memset(w,0,sizeof(w));
	d[s]=0;
	w[s]=weight[s];
	num[s]=1;
	for(int i=0;i<n-1;++i){
		for(int u=0;u<n;++u){
			for(int j=0;j<Adj[u].size();++j){
				int v=Adj[u][j].v;
				int dis=Adj[u][j].dis;
				if(d[u]+dis<d[v]){
				}
			}
		}
	}
}
