#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using std::max;
using std::vector;


const int maxn=110;

vector<int> nodes[maxn];

int leaves[maxn]={0};

int max_depth=0;

void dfs(int index,int depth){
	max_depth=max(max_depth,depth);
	if(nodes[index].size()==0){
		++leaves[depth];
		return;
	}
	else{
		for(int i=0;i<(int)nodes[index].size();++i){
			dfs(nodes[index][i],depth+1);
		}
	}
}

int main(){
	int nodes_num=0,non_leaf_nodes=0;
	scanf("%d %d",&nodes_num,&non_leaf_nodes);
	int count;
	int index;
	int value;
	for(int i=0;i<non_leaf_nodes;++i){
		scanf("%d %d",&index,&count);
		for(int j=0;j<count;++j){
			scanf("%d",&value);
			nodes[index].push_back(value);
		}
	}
	dfs(1,1);
	for(int i=1;i<=max_depth;++i){
		printf("%d",leaves[i]);
		if(i!=max_depth){
			printf(" ");
		}
	}
	return 0;
}
