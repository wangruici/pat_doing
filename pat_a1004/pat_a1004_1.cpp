#include <iostream>
#include <string>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::queue;
using std::vector;
using std::ios;

struct Node{
	vector<int> children;
	int deep;
	Node():deep(0){}
};

vector<Node> tree(110);

vector<int> get_leaf(vector<Node> &tree,int root){
	queue<Node*> que;
	tree[root].deep=1;
	int nowDeep=1;
	int counter=0;
	vector<int> ans;
	que.push(&tree[root]);
	Node* front;
	while(!que.empty()){
		front=que.front();
		que.pop();
		if(front->deep!=nowDeep){
			ans.push_back(counter);
			counter=0;
			nowDeep=front->deep;
		}
		if(front->children.size()<=0){
			++counter;
		}
		for(int i=0;i<(int)front->children.size();++i){
			tree[front->children[i]].deep=front->deep+1;
			que.push(&tree[front->children[i]]);
		}
	}
	ans.push_back(counter);
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	int node_num,nonleaf_num;
	cin>>node_num>>nonleaf_num;
	int temp;
	int id;
	int child;
	for(int i=0;i<nonleaf_num;++i){
		cin>>id>>temp;
		for(int j=0;j<temp;++j){
			cin>>child;
			tree[id].children.push_back(child);
		}
	}
	vector<int> ans=get_leaf(tree,1);
	for(int i=0;i<(int)ans.size();++i){
		cout<<ans[i];
		if(i!=(int)ans.size()-1){
			cout<<" ";
		}
		else{
			cout<<endl;
		}
	}
	return 0;
}
