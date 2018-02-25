#include <cstring>
#include <cstdio>
#include <stack>
#include <queue>

using std::stack;
using std::queue;
const int maxn=20;
int count=0;
struct Node{
	int data;
	int lchild;
	int rchild;
};


Node nodes[maxn];
bool notRoot[maxn]={false};

int rootnum=-1;
int strToNum(char c){
	if(c=='-') return -1;
	else{
		return c-'0';
	}
}

void level_order(){
	queue<Node> node_queue;
	node_queue.push(nodes[rootnum]);
	while(!node_queue.empty()){
		Node no=node_queue.front();
		if(no.lchild!=-1){
			node_queue.push(nodes[no.lchild]);
		}
		if(no.rchild!=-1){
			node_queue.push(nodes[no.rchild]);
		}
		node_queue.pop();
		printf("%d",no.data);
		if(!node_queue.empty()){
			printf(" ");
		}
	}
}

void bfs_invert(){
	queue<Node*> node_queue;
	node_queue.push(&nodes[rootnum]);
	while(!node_queue.empty()){
		Node *no=node_queue.front();
		node_queue.pop();
		int temp;
		temp=no->lchild;
		no->lchild=no->rchild;
		no->rchild=temp;
		if(no->lchild!=-1)
			node_queue.push(&nodes[no->lchild]);
		if(no->rchild!=-1)
			node_queue.push(&nodes[no->rchild]);
	}
}

int num=0;
void inorder_traverse(int rootnum){
	if(rootnum<0){
		return;	
	}
	else{
		inorder_traverse(nodes[rootnum].lchild);
		printf("%d",nodes[rootnum].data);
		++num;
		if(num<count){
			printf(" ");
		}
		inorder_traverse(nodes[rootnum].rchild);
	}
}
int main(){
	scanf("%d",&count);
	char lchild,rchild;
	for(int i=0;i<count;++i){
		scanf("%*c%c %c",&lchild,&rchild);
		nodes[i].lchild=strToNum(lchild);
		nodes[i].rchild=strToNum(rchild);
		nodes[i].data=i;
		if(nodes[i].lchild!=-1){
			notRoot[nodes[i].lchild]=true;
		}
		if(nodes[i].rchild!=-1){
			notRoot[nodes[i].rchild]=true;
		}
	}
	for(int i=0;i<count;++i){
		if(!notRoot[i])
			rootnum=i;
	}
	bfs_invert();
	level_order();
	printf("\n");
	inorder_traverse(rootnum);
	return 0;
}
