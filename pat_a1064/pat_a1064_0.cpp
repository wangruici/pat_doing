#include <cstdio>
#include <algorithm>
#include <vector>

using std::vector;
using std::sort;

const int maxn=1010;

int node_count=0;

int value[maxn];
int complete_tree[maxn];
int index=0;

void inOrder(int root){
	if(root>node_count){
		return;
	}
	else{
		inOrder(2*root);
		complete_tree[root]=value[index++];
		inOrder(2*root+1);
	}
}

int main(){
	scanf("%d",&node_count);
	for(int i=0;i<node_count;++i){
		scanf("%d",&value[i]);
	}
	sort(value,value+node_count);
	inOrder(1);
	for(int i=1;i<=node_count;++i){
		printf("%d",complete_tree[i]);
		if(i<node_count) printf(" ");
	}
	return 0;
}
