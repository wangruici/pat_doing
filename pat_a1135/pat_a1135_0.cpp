#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using std::vector;
using std::abs;
using std::queue;
using std::cin;
using std::cout;
using std::endl;

struct Node{
	int data;
	Node *lchild;
	Node *rchild;
	int black_deep;
};

Node* newNode(int data){
	Node* root=new Node;
	root->data=data;
	root->lchild=nullptr;
	root->rchild=nullptr;
	root->black_deep=0;
	return root;
};

void insert(Node* &root,int data){
	if(root==nullptr){
		root=newNode(data);
		return;
	}
	if(abs(data)<abs(root->data)){
		insert(root->lchild,data);
	}
	else if(abs(data)==abs(root->data)){
		return;
	}
	else{
		insert(root->rchild,data);
	}
}
void prePrint(Node* root){
	if(root==nullptr){
		return;
	}
	cout<<root->data<<" ";
	prePrint(root->lchild);
	prePrint(root->rchild);
	return;
}
void print(int i){
	cout<<"-------------"<<i<<endl;
}
bool isRBT(Node* &root){
	if(root==nullptr){
		return true;
	}
	if(root->data<=0){
		return false;
	}
	queue<Node*> que;
	root->black_deep=1;
	que.push(root);

	int max_black_deep=-1;
	while(!que.empty()){
		Node* front=que.front();
		que.pop();
		if(front->data==0){
			return false;
		}
		if(front->lchild!=nullptr){
			if(front->data<0&&front->lchild->data<0){
				return false;
			}
			if(front->lchild->data>0){
				front->lchild->black_deep=front->black_deep+1;
			}
			else{
				front->lchild->black_deep=front->black_deep;
			}
			que.push(front->lchild);
		}
		if(front->lchild==nullptr){
			if(max_black_deep!=-1&&front->black_deep+1!=max_black_deep){
				return false;
			}
			else if(max_black_deep==-1){
				max_black_deep=front->black_deep+1;
			}
			else if(max_black_deep!=-1&&front->black_deep==max_black_deep){
				;
			}
		}
		if(front->rchild!=nullptr){
			if(front->data<0&&front->rchild->data<0){
				return false;
			}
			if(front->rchild->data>0){
				front->rchild->black_deep=front->black_deep+1;
			}
			else{
				front->rchild->black_deep=front->black_deep;
			}
			que.push(front->rchild);
		}
		if(front->rchild==nullptr){
			if(max_black_deep!=-1&&front->black_deep+1!=max_black_deep){
				return false;
			}
			else if(max_black_deep==-1){
				max_black_deep=front->black_deep+1;
			}
			else if(max_black_deep!=-1&&front->black_deep==max_black_deep){
				;
			}
		}
/*
		if(front->lchild==nullptr&&front->rchild==nullptr){
			if(max_black_deep!=-1&&front->black_deep!=max_black_deep){
				return false;
			}
			else if(max_black_deep==-1){
				max_black_deep=front->black_deep;
			}
			else if(max_black_deep!=-1&&front->black_deep==max_black_deep){
				;
			}
		}
*/

	}
	return true;
}

int main(){
	int total_num;
	cin>>total_num;
	int temp_num;
	int temp;
	for(int i=0;i<total_num;++i){
		cin>>temp_num;
		Node* root=nullptr;
		for(int j=0;j<temp_num;++j){
			cin>>temp;
			insert(root,temp);
		}
		if(isRBT(root)){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}

