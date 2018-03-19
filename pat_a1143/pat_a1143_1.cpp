//run out of memory
#include <unordered_map>
#include <iostream>
#include <queue>
#include <cstdio>
using std::queue;
using std::cin;
using std::cout;
using std::endl;
using std::unordered_map;

const int maxn=10010;
//dp
int graph[maxn][maxn];

struct Node{
	Node *parent;
	Node *lchild;
	Node *rchild;
	int value;
	Node(int _value):parent(NULL),lchild(NULL),rchild(NULL),value(_value){
		;
	}
};

Node* insert(Node *parent,Node* &root,int value){
	if(root==NULL){
		root=new Node(value);
		root->parent=parent;
		return root;
	}
	else if(value<root->value){
		return insert(root,root->lchild,value);
	}
	else if(value>root->value){
		return insert(root,root->rchild,value);
	}
	else{
		return root;
	}
}

struct levelItem{
	int parentIndex;
	int value;
	levelItem():parentIndex(-1){}
}tree[maxn];


int levelSearch(Node *root,levelItem* tree){
	queue<Node*> que;
	que.push(root);
	int nowIndex=0;
	int parentIndex=-1;
	tree[nowIndex].parentIndex=parentIndex;
	tree[nowIndex].value=root->value;
	parentIndex=nowIndex;
	while(!que.empty()){
		Node* front=que.front();
		que.pop();
		if(front->lchild!=NULL){	
			++nowIndex;
			tree[nowIndex].parentIndex=parentIndex;
			tree[nowIndex].value=front->lchild->value;
			que.push(front->lchild);
		}
		if(front->rchild!=NULL){
			++nowIndex;
			tree[nowIndex].parentIndex=parentIndex;
			tree[nowIndex].value=front->rchild->value;
			que.push(front->rchild);
		}
		++parentIndex;
	}

	return nowIndex+1;
}

unordered_map<int,int> valueToIndex;

void get_dp(int len,int dp[maxn][maxn]){
	for(int i=0;i<len;++i){
		for(int j=i;j<len;++j){
			if(tree[j].parentIndex==i){
				dp[i][j]=i;
				dp[j][i]=i;
			}
			else if(tree[j].parentIndex==-1){
				/*
				 *这表明j为根节点
				 *
				 *
				 *
				 */
				dp[i][j]=j;
				dp[j][i]=j;

			}
			else{//取决于j的父亲节点与i的low common ancestor
				dp[i][j]=dp[tree[j].parentIndex][i];
				dp[j][i]=dp[tree[j].parentIndex][i];
			}
				
		}
	}
}

int main(){
	int query_num,node_num;
	cin>>query_num>>node_num;
	int temp;
	Node* root=NULL;
	for(int i=0;i<node_num;++i){
		cin>>temp;
		insert(NULL,root,temp);
	}

	int len=levelSearch(root,tree);
	get_dp(len,graph);
	for(int i=0;i<len;++i){
		valueToIndex[tree[i].value]=i;
	}
	int temp1,temp2;
	bool flag1=true,flag2=true;
	int ans_index;
	for(int i=0;i<query_num;++i){
		cin>>temp1>>temp2;	
		if(valueToIndex.find(temp1)==valueToIndex.end()){
			flag1=false;
		}
		else{
			flag1=true;
		}
		if(valueToIndex.find(temp2)==valueToIndex.end()){
			flag2=false;
		}
		else{
			flag2=true;
		}
		if(flag1&&flag2){
			ans_index=graph[valueToIndex[temp1]][valueToIndex[temp2]];
		}
		//输出
		if(flag1==false&&flag2==false){
			printf("ERROR: %d and %d are not found.\n",temp1,temp2);
		}
		else if(flag1==false){
			printf("ERROR: %d is not found.\n",temp1);
		}
		else if(flag2==false){
			printf("ERROR: %d is not found.\n",temp2);
		}
		else if(flag1&&flag2&&temp1==tree[ans_index].value){
			printf("%d is an ancestor of %d.\n",temp1,temp2);
		}
		else if(flag1&&flag2&&temp2==tree[ans_index].value){
			printf("%d is an ancestor of %d.\n",temp2,temp1);
		}
		else if(flag1&&flag2){
			printf("LCA of %d and %d is %d.\n",temp1,temp2,tree[ans_index].value);
		}
		else{
			;
		}
	}

	return 0;
}
