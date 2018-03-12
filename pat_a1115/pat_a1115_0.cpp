#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
using std::pair;
using std::vector;
using std::queue;

const int maxn=1010;
struct Node{
	int value;
	int lchild;
	int rchild;
	Node(){
		this->value=0;
		this->lchild=-1;
		this->rchild=-1;
	}
}bst[maxn];

void insert(int root,int index){
	if(bst[index].value<=bst[root].value){
			if(bst[root].lchild==-1){
				bst[root].lchild=index;
				return;
			}
			else{
				insert(bst[root].lchild,index);
			}
	}
	else{
			if(bst[root].rchild==-1){
				bst[root].rchild=index;
				return;
			}
			else{
				insert(bst[root].rchild,index);
			}
	}
}


vector<int> bfs(){
	queue<pair<int,int>> que;
	vector<int> ans;
	int now_deep=1;
	int counter=0;
	que.push(pair<int,int>(0,1));
	while(!que.empty()){
		pair<int,int> p=que.front();
		que.pop();
		if(now_deep==p.second){
			++counter;
		}
		else{
			now_deep=p.second;
			ans.push_back(counter);
			counter=1;
		}
		if(bst[p.first].lchild!=-1){
			que.push(pair<int,int>(bst[p.first].lchild,p.second+1));
		}
		if(bst[p.first].rchild!=-1){
			que.push(pair<int,int>(bst[p.first].rchild,p.second+1));
		}

	}
	ans.push_back(counter);
	return ans;
}

int main(){
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;++i){
		scanf("%d",&bst[i].value);
	}
	for(int i=1;i<num;++i){
		insert(0,i);
	}
	vector<int> ans=bfs();
	int len=ans.size();
	printf("%d + %d = %d",ans[len-1],ans[len-2],ans[len-1]+ans[len-2]);
	return 0;
}

