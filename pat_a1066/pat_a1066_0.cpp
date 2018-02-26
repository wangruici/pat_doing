#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using std::max;
using std::vector;


struct node{
	int data;
	node *leftchild;
	node *rightchild;
	int height;
}*root;

node* newNode(int data){
	node* Node=new node;
	Node->data=data;
	Node->height=1;
	Node->leftchild=Node->rightchild=NULL;
	return Node;
}

int getHeight(node* root){
	if(root==NULL) return 0;
	return root->height;
}

void updateHeight(node* root){
	root->height=max(getHeight(root->leftchild),getHeight(root->rightchild))+1;
}

int getBalanceFactor(node *root){
	return getHeight(root->leftchild)-getHeight(root->rightchild);
}

void L(node* &root){
	node* temp=root->rightchild;
	root->rightchild=temp->leftchild;
	temp->leftchild=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
}

void R(node* &root){
	node* temp=root->leftchild;
	root->leftchild=temp->rightchild;
	temp->rightchild=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
}

void insert(node* &root,int v){
	if(root==NULL){
		root=newNode(v);
		return;
	}
	else{
		if(v<root->data){
			//左插入，左子树可能不平衡
			insert(root->leftchild,v);
			updateHeight(root);
			if(getBalanceFactor(root)==2){
				if(getBalanceFactor(root->leftchild)==1){
					R(root);
				}
				else if(getBalanceFactor(root->leftchild)==-1){
					L(root->leftchild);
					R(root);
				}
			}
		}
		else{
			insert(root->rightchild,v);
			updateHeight(root);
			if(getBalanceFactor(root)==-2){
				if(getBalanceFactor(root->rightchild)==-1){
					L(root);
				}
				else if(getBalanceFactor(root->rightchild)==1){
					R(root->rightchild);
					L(root);
				}
			}
			
		}
	}
}



int main(){
	int n,v;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&v);
		insert(root,v);
	}
	printf("%d\n",root->data);
	return 0;
}
