/*
 *这个版本是在edit-0的基础上修改的
 *修改了getLow函数
 *算法是将两个节点提升到同一高度，然后在同时提升
 *经过这样的修改就不会run out of time了
 *
 *
 */
#include <iostream>
#include <string>
#include <unordered_set>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::unordered_set;
const int maxn=10010;
struct Node{
	int value;
	Node* lchild;
	Node* rchild;
	Node* parent;
	int deep;
	Node(int _value):value(_value),lchild(NULL),rchild(NULL),parent(NULL),deep(0){}
};


void insert(Node* parent,Node* &root,int value,int deep){
	if(root==NULL){
		root=new Node(value);
		root->parent=parent;	
		root->deep=deep;
	}
	else if(value<root->value){
		insert(root,root->lchild,value,root->deep+1);
	}
	else if(value>=root->value){
		insert(root,root->rchild,value,root->deep+1);
	}
}

Node* search(Node* root,int value){
	if(root==NULL){
		return NULL;
	}
	else if(value>root->value){
		return search(root->rchild,value);
	}
	else if(value<root->value){
		return search(root->lchild,value);
	}
	else{
		return root;
	}
}

Node* getLow(Node* root,int value1,Node* &n1,int value2,Node* &n2){
	n1=search(root,value1);
	n2=search(root,value2);
	if(n1==NULL||n2==NULL){
		return NULL;
	}
	else{
		//首先提升到同一深度
		Node* pn1;
		Node* pn2;
		pn1=n1;
		pn2=n2;
		while(pn1!=pn2){
			if(pn1->deep>pn2->deep){
				pn1=pn1->parent;
			}
			else if(pn2->deep>pn1->deep){
				pn2=pn2->parent;
			}
			else{
				pn1=pn1->parent;
				pn2=pn2->parent;
			}
		}
		return pn1;
	}
	
}



int main(){
	int total_node;
	int query_count;
	scanf("%d",&query_count);
	scanf("%d",&total_node);
	Node* root=NULL;
	int temp;
	for(int i=0;i<total_node;++i){
		scanf("%d",&temp);
		insert(NULL,root,temp,1);

	}
	int temp1,temp2;
	Node* tempn1;
	Node* tempn2;
	Node* tempn;
	for(int i=0;i<query_count;++i){
		scanf("%d%d",&temp1,&temp2);
		tempn=getLow(root,temp1,tempn1,temp2,tempn2);
		if(tempn1==NULL&&tempn2==NULL){
			printf("ERROR: %d and %d are not found.\n",temp1,temp2);
		}
		else if(tempn1==NULL){
			printf("ERROR: %d is not found.\n",temp1);
			
		}
		else if(tempn2==NULL){
			printf("ERROR: %d is not found.\n",temp2);
		
		}
		else if(tempn==tempn1){
			printf("%d is an ancestor of %d.\n",temp1,temp2);
		}
		else if(tempn==tempn2){
			printf("%d is an ancestor of %d.\n",temp2,temp1);
		}
		else{
			printf("LCA of %d and %d is %d.\n",temp1,temp2,tempn->value);
		}
	}
	return 0;
}
