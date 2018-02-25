#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
using std::queue;
using std::vector;
using std::sort;

struct node{
	int data;
	int leftchild;
	int rightchild;
};

const int maxn=110;

node nodes[maxn];

int value[maxn]={0};
int index=0;

void inOrder(int root){
	if(root==-1){
		return;
	}
	else{
		inOrder(nodes[root].leftchild);
		nodes[root].data=value[index++];
		inOrder(nodes[root].rightchild);
	}
}
int node_count=0;
void bfs(int root){
	queue<int> que;
	que.push(root);
	int i=0;
	while(!que.empty()){
		int front=que.front();
		que.pop();
		printf("%d",nodes[front].data);
		++i;
		if(i<node_count) printf(" ");
		if(nodes[front].leftchild!=-1) que.push(nodes[front].leftchild);
		if(nodes[front].rightchild!=-1) que.push(nodes[front].rightchild);
	}
}

int main(){
	int leftchild,rightchild;
	scanf("%d",&node_count);
	for(int i=0;i<node_count;++i){
		scanf("%d%d",&leftchild,&rightchild);
		nodes[i].leftchild=leftchild;
		nodes[i].rightchild=rightchild;
	}
	for(int i=0;i<node_count;++i){
		scanf("%d",&value[i]);
	}
	sort(value,value+node_count);
	inOrder(0);

	bfs(0);
	return 0;
}
