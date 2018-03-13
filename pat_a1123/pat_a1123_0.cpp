#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using std::max;
using std::min;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::queue;
const int maxn=300;
struct Node{
	int value;
	Node *lchild;
	Node *rchild;
	int deep_order;
	int height;
	Node(int value){
		this->value=value;
		this->lchild=nullptr;
		this->rchild=nullptr;
		this->deep_order=0;
		this->height=1;
	}
	Node(){
		this->value=0;
		this->lchild=nullptr;
		this->rchild=nullptr;
		this->deep_order=0;
		this->height=1;
	}
};

struct staticNode{
	int value;
	int lchild;
	int rchild;
}staticTree[maxn];
int data[maxn];
int getHeight(Node* &root){
	if(root==nullptr) return 0;
	return root->height;
}

int getBalanceFactor(Node* &root){
	return getHeight(root->lchild)-getHeight(root->rchild);
}

int updateHeight(Node* &root){
	root->height=max(getHeight(root->lchild),getHeight(root->rchild))+1;
	return root->height;
}

Node* R(Node* &root){
	Node* temp=root->lchild;
	root->lchild=temp->rchild;
	temp->rchild=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
	return root;
}

Node* L(Node* &root){
	Node* temp=root->rchild;
	root->rchild=temp->lchild;
	temp->lchild=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
	return root;
}

void insert(Node* &root,int value){
	if(root==nullptr){
		root=new Node(value);
	}
	else{
		if(value<root->value){
			insert(root->lchild,value);
			updateHeight(root);
			if(getBalanceFactor(root)==2){
				//如果是LL树
				if(getBalanceFactor(root->lchild)==1){
					R(root);
				}
				else if(getBalanceFactor(root->lchild)==-1){
					L(root->lchild);
					R(root);
				}
			}
		}
		else{
			insert(root->rchild,value);
			updateHeight(root);
			if(getBalanceFactor(root)==-2){
				if(getBalanceFactor(root->rchild)==-1){
					L(root);
				}
				else if(getBalanceFactor(root->rchild)==1){
					R(root->rchild);
					L(root);
				}
			}
		}
	}
}

Node* establishTree(int count){
	Node* root=nullptr;	
	for(int i=0;i<count;++i){
		insert(root,data[i]);
	}
	return root;
}

int getDeepOrder(Node* root){
	queue<Node*> que;
	root->deep_order=1;
	que.push(root);
	int deep_order=1;
	while(!que.empty()){
		Node* p_front=que.front();
		que.pop();

		staticTree[p_front->deep_order].value=p_front->value;
		staticTree[p_front->deep_order].lchild=-1;
		staticTree[p_front->deep_order].rchild=-1;
		if(p_front->lchild!=nullptr){
			++deep_order;
			p_front->lchild->deep_order=deep_order;
			staticTree[p_front->deep_order].lchild=deep_order;
			que.push(p_front->lchild);
		}
		if(p_front->rchild!=nullptr){
			++deep_order;
			p_front->rchild->deep_order=deep_order;
			staticTree[p_front->deep_order].rchild=deep_order;
			que.push(p_front->rchild);
		}
	}
	return deep_order;
}

bool isCompleteTree(staticNode tree[],int count){
	bool flag=true;
	int notLeaf=count/2;
	for(int i=1;i<=notLeaf;++i){
		int left=tree[i].lchild;
		int right=tree[i].rchild;
		if(left==right){
			return false;
		}
		if(left!=-1&&left!=2*i){
			return false;
		}
		if(right!=-1&&right!=2*i+1){
			return false;
		}
	}
	for(int i=notLeaf+1;i<=count;++i){
		if(tree[i].lchild!=-1&&tree[i].rchild!=-1){
			return false;
		}
	}
	return flag;
}

int main(){
	int count;
	cin>>count;
	for(int i=0;i<count;++i){
		cin>>data[i];
	}
	Node* root=nullptr;
	root=establishTree(count);
	getDeepOrder(root);
	bool isComplete=isCompleteTree(staticTree,count);
	for(int i=1;i<=count;++i){
		cout<<staticTree[i].value;
		if(i!=count){
			cout<<" ";
		}
		else{
			cout<<endl;
		}
	}
	if(isComplete){
		cout<<"YES";
	}
	else{
		cout<<"NO";
	}
	cout<<endl;
	return 0;

}

