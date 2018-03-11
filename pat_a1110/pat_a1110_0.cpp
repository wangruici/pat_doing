#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using std::string;
using std::sort;
using std::cin;
using std::cout;
using std::endl;
using std::flush;
using std::queue;
const int maxn=30;
struct Node{
	int id;
	int leftChild;
	int rightChild;
	bool isRoot;
	int deep_id;
	int deep;
	Node(){
		this->id=-1;
		this->leftChild=-1;
		this->rightChild=-1;
		this->isRoot=true;
		this->deep_id=-1;
		this->deep=-1;
	}
}tree[30];
bool cmp(Node &no1,Node &no2){
	return no1.deep_id<no2.deep_id;
}
void dfs(int rootIndex){
	tree[rootIndex].deep_id=1;
	tree[rootIndex].deep=1;
	queue<int> q;
	q.push(rootIndex);
	int deep_id=1;
	while(!q.empty()){
		int front_index=q.front();
		q.pop();
		tree[front_index].deep_id=deep_id;
		++deep_id;
		int left=tree[front_index].leftChild;
		int right=tree[front_index].rightChild;
		if(left!=-1){
			tree[left].deep=tree[front_index].deep+1;
			q.push(left);
		}
		if(right!=-1){
			tree[right].deep=tree[front_index].deep+1;
			q.push(right);
		}
	}
}

int main(){
	int node_num;
	cin>>node_num;
	string temp1,temp2;
	for(int i=0;i<node_num;++i){
		cin>>temp1>>temp2;
		tree[i].id=i;
		if(isdigit(temp1[0])){
			tree[i].leftChild=stoi(temp1,nullptr,10);
			tree[tree[i].leftChild].isRoot=false;
		}
		else{
			tree[i].leftChild=-1;
		}
		if(isdigit(temp2[0])){
			tree[i].rightChild=stoi(temp2,nullptr,10);
			tree[tree[i].rightChild].isRoot=false;
		}
		else{
			tree[i].rightChild=-1;
		}
	
	}
	int rootIndex=-1;
	for(int i=0;i<node_num;++i){
		if(tree[i].isRoot){
			rootIndex=i;
			break;
		}
	}

	dfs(rootIndex);
	bool flag=true;
	int last_index=rootIndex;
	int max_id=1;
	for(int i=0;i<node_num;++i){
		int left=tree[i].leftChild;
		int right=tree[i].rightChild;
		if(tree[i].deep_id>max_id){
			max_id=tree[i].deep_id;
			last_index=i;
		}
		if(left!=-1){
			if(tree[left].deep_id!=tree[i].deep_id*2){
				flag=false;
				break;
			}
		}
		if(right!=-1){
			if(tree[right].deep_id!=tree[i].deep_id*2+1){
				flag=false;
				break;
			}
		}
	}
	if(flag){
		cout<<"YES"<<" "<<last_index<<endl;
	}
	else{
		cout<<"NO"<<" "<<rootIndex<<endl;
	}
	return 0;

}
