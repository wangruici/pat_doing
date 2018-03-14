#include <iostream>
#include <string>
#include <queue>
#include <stack>
using std::stack;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::queue;
const int maxn=40;

struct Node{
	int data;
	int deep;
	Node* lchild;
	Node* rchild;
};
Node* newNode(int v){
	Node* node=new Node;
	node->data=v;
	node->lchild=node->rchild=NULL;
	return node;
}
int inOrder[maxn];
int postOrder[maxn];

Node* get_tree(int inL,int inR,int postL,int postR){
	if(postL>postR) return NULL;
	Node* root=new Node;
	root->data=postOrder[postR];
	int k;
	for(k=inL;k<=inR;++k){
		if(inOrder[k]==root->data){
			break;
		}
	}
	int numLeft=k-inL;
	root->lchild=get_tree(inL,k-1,postL,postL+numLeft-1);
	root->rchild=get_tree(k+1,inR,postL+numLeft,postR-1);
	return root;

	
}

void zZprint(Node *root,int total_num){
	if(root==NULL) return;
	queue<Node*> que;
	root->deep=1;
	que.push(root);
	int counter=0;
	stack<Node*> sta;
	while(!que.empty()){
		Node* front=que.front();
		que.pop();
		if(front->lchild!=NULL){
			front->lchild->deep=front->deep+1;
			que.push(front->lchild);
		}
		if(front->rchild!=NULL){
			front->rchild->deep=front->deep+1;
			que.push(front->rchild);
		}
		if(!sta.empty()&&sta.top()->deep!=front->deep){
			while(!sta.empty()){
				Node* top=sta.top();
				sta.pop();
				cout<<top->data;
				++counter;
				if(counter!=total_num){
					cout<<" ";
				}
				else{
					cout<<endl;
				}
			}
		}
		if(front->deep%2!=0){
			sta.push(front);
		}
		if(front->deep%2==0){
			cout<<front->data;
			++counter;
			if(counter!=total_num){
				cout<<" ";
			}
			else{
				cout<<endl;
			}
		}
	}
	while(!sta.empty()){
		Node* top=sta.top();
		sta.pop();
		cout<<top->data;
		++counter;
		if(counter!=total_num){
			cout<<" ";
		}
		else{
			cout<<endl;
		}
	}

}
int main(){
	int total_num;
	cin>>total_num;
	for(int i=1;i<=total_num;++i){
		cin>>inOrder[i];
	}
	for(int i=1;i<=total_num;++i){
		cin>>postOrder[i];
	}
	Node* tree=get_tree(1,total_num,1,total_num);
	zZprint(tree,total_num);
	return 0;
}
