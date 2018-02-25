#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>

using std::vector;
const int maxn=110;

struct Node{
	vector<int> children;
}nodes[maxn];
int generation_breath[maxn]={0};

void dfs_search(int depth,int index){
	++generation_breath[depth];
	if(nodes[index].children.size()==0){
		return;
	}
	else{
		for(int i=0;i<(int)nodes[index].children.size();++i){
			dfs_search(depth+1,nodes[index].children[i]);
		}
	}
}

int main(){
	int family_num=0,have_child_num=0;
	scanf("%d %d",&family_num,&have_child_num);
	int count=0;
	int child_index=0;
	int index=0;
	for(int i=0;i<have_child_num;++i){
		scanf("%d %d",&index,&count);
		for(int j=0;j<count;++j){
			scanf("%d",&child_index);
			nodes[index].children.push_back(child_index);
		}
	}

	dfs_search(1,1);
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
