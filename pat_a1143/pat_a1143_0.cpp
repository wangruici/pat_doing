//run out of time
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
	Node(int _value):value(_value),lchild(NULL),rchild(NULL),parent(NULL){}
};


void insert(Node* parent,Node* &root,int value){
	if(root==NULL){
		root=new Node(value);
		root->parent=parent;	
	}
	else if(value<root->value){
		insert(root,root->lchild,value);
	}
	else if(value>=root->value){
		insert(root,root->rchild,value);
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
		unordered_set<Node*> parent1;
		Node* temp_n=n1;
		while(temp_n!=NULL){
			parent1.insert(temp_n);
			temp_n=temp_n->parent;
		}
		temp_n=n2;
		while(temp_n!=NULL){
			if(parent1.find(temp_n)!=parent1.end()){
				return temp_n;
			}
			temp_n=temp_n->parent;
		}
		return NULL;
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
		insert(NULL,root,temp);

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
