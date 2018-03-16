#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using std::fill;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node{
	int data;
	Node* lchild;
	Node* rchild;
};

Node* newNode(int data){
	Node *root=new Node;
	root->data=data;
	root->lchild=NULL;
	root->rchild=NULL;
	return root;
}
const int maxn=50010;
int preOrder[maxn];
int inOrder[maxn];
Node* createTree(int preL,int preR,int inL,int inR){
	if(preL>preR){
		return NULL;
	}
	int k;
	Node* root=newNode(preOrder[preL]);
	for(k=inL;k<=inR;++k){
		if(inOrder[k]==preOrder[preL]){
			break;
		}
	}
	int leftNum=k-inL;
	root->lchild=createTree(preL+1,preL+leftNum,inL,k-1);
	root->rchild=createTree(preL+leftNum+1,preR,k+1,inR);
	return root;
}

void postTraverse(Node* root,vector<int> &ans){
	if(root==NULL){
		return;
	}
	postTraverse(root->lchild,ans);
	postTraverse(root->rchild,ans);
	ans.push_back(root->data);
}

int main(){
	fill(preOrder,preOrder+maxn,0);
	fill(inOrder,inOrder+maxn,0);
	int total_num;
	cin>>total_num;
	for(int i=0;i<total_num;++i){
		cin>>preOrder[i];
	}
	for(int i=0;i<total_num;++i){
		cin>>inOrder[i];
	}
	Node* root=createTree(0,total_num-1,0,total_num-1);
	vector<int> ans;
	postTraverse(root,ans);
	cout<<ans[0]<<endl;
	return 0;
}
