//run out of time
#include <unordered_map>
#include <iostream>
#include <queue>
#include <cstdio>
#include <utility>
using std::pair;
using std::queue;
using std::cin;
using std::cout;
using std::endl;
using std::unordered_map;

const int maxn=10010;
//dp

unordered_map<int,unordered_map<int,int> > dp;
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


void get_dp(int len,unordered_map<int,unordered_map<int,int>> &dp){
	int vi,vj;
	for(int i=0;i<len;++i){
		for(int j=i;j<len;++j){
			vi=tree[i].value;
			vj=tree[j].value;
			if(tree[j].parentIndex==i){
				dp[vi][vj]=vi;
				dp[vj][vi]=vi;
			}
			else if(tree[j].parentIndex==-1){
				/*
				 *这表明j为根节点
				 *
				 *
				 *
				 */
				dp[vi][vj]=vj;
				dp[vj][vi]=vj;

			}
			else{//取决于j的父亲节点与i的low common ancestor
				int vk=tree[tree[j].parentIndex].value;
				dp[vi][vj]=dp[vk][vi];
				dp[vj][vi]=dp[vk][vi];
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
	get_dp(len,dp);
	int temp1,temp2;
	bool flag1=true,flag2=true;
	int ans;
	for(int i=0;i<query_num;++i){
		cin>>temp1>>temp2;	
		if(dp.find(temp1)==dp.end()){
			flag1=false;
		}
		else{
			flag1=true;
		}
		if(dp.find(temp2)==dp.end()){
			flag2=false;
		}
		else{
			flag2=true;
		}
		if(flag1&&flag2){
			ans=dp[temp1][temp2];
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
		else if(flag1&&flag2&&temp1==ans){
			printf("%d is an ancestor of %d.\n",temp1,temp2);
		}
		else if(flag1&&flag2&&temp2==ans){
			printf("%d is an ancestor of %d.\n",temp2,temp1);
		}
		else if(flag1&&flag2){
			printf("LCA of %d and %d is %d.\n",temp1,temp2,ans);
		}
		else{
			;
		}
	}

	return 0;
}
