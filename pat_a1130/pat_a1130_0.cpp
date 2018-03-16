#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
const int maxn=100;
struct Node{
	string s;
	int lchild;
	int rchild;
	bool isRoot;
	Node(){
		isRoot=true;
		s="";
		lchild=-1;
		rchild=-1;
	}
}synTree[maxn];


void dfs(int root,int depth,vector<string> &ans,Node* synTree){
	if(root==-1){
		return;
	}
	if((synTree[root].lchild!=-1||synTree[root].rchild!=-1)&&depth!=1){
		ans.push_back("(");
	}
	dfs(synTree[root].lchild,depth+1,ans,synTree);
	ans.push_back(synTree[root].s);
	dfs(synTree[root].rchild,depth+1,ans,synTree);
	if((synTree[root].rchild!=-1||synTree[root].lchild!=-1)&&depth!=1){
		ans.push_back(")");
	}
/*
//原来的代码没有管最外层的括号，而是在最后去除掉，这样的算法最后错了一个测试点。不知道是为什么
	if(synTree[root].lchild!=-1||synTree[root].rchild!=-1){
		ans.push_back("(");
	}
	dfs(synTree[root].lchild,depth+1,ans,synTree);
	ans.push_back(synTree[root].s);
	dfs(synTree[root].rchild,depth+1,ans,synTree);
	if(synTree[root].rchild!=-1||synTree[root].lchild!=-1){
		ans.push_back(")");
	}
*/

}

int main(){
	int total_num;
	cin>>total_num;
	for(int i=1;i<=total_num;++i){
		cin>>synTree[i].s;
		cin>>synTree[i].lchild;
		cin>>synTree[i].rchild;
		if(synTree[i].rchild!=-1){
			synTree[synTree[i].rchild].isRoot=false;
		}
		if(synTree[i].lchild!=-1){
			synTree[synTree[i].lchild].isRoot=false;
		}
	}
	int root;
	for(int j=1;j<=total_num;++j){
		if(synTree[j].isRoot){
			root=j;
		}
	}
	vector<string> ans;
	dfs(root,1,ans,synTree);
	for(int i=0;i<(int)ans.size();++i){
		cout<<ans[i];
	}
	cout<<endl;
	return 0;
}
