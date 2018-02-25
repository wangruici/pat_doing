#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using std::vector;
using std::queue;

const int maxn=110;

struct Node{
	vector<int> children;
	int ge;
}nodes[maxn];

int generation_breath[maxn]={0};
void bfs_search(){
	queue<int> que;
	que.push(1);
	while(!que.empty()){
		int f=que.front();
		que.pop();
		++generation_breath[nodes[f].ge];
		for(int i=0;i<(int)nodes[f].children.size();++i){
			nodes[nodes[f].children[i]].ge=nodes[f].ge+1;
			que.push(nodes[f].children[i]);
		}
	}
}

int main(){
	nodes[1].ge=1;
	int family_num=0,have_child_num=0;
	int index=0;
	int count=0;
	int value=0;
	scanf("%d %d",&family_num,&have_child_num);
	for(int i=0;i<have_child_num;++i){
		scanf("%d %d",&index,&count);
		for(int j=0;j<count;++j){
			scanf("%d",&value);
			nodes[index].children.push_back(value);
		}
	}

	bfs_search();
	int max_index=1;
	int max_index_count=1;
	for(int i=1;i<family_num;++i){
		if(generation_breath[i]>max_index_count){
			max_index_count=generation_breath[i];
			max_index=i;
		}
	}

	printf("%d %d",max_index_count,max_index);


	return 0;
}
