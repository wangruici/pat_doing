#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
const int maxn=1010;

struct Node{
	vector<int> link;
};
Node origin_graph[maxn];
bool hasVisited[maxn];

void init_hasVisited(){
	memset(hasVisited,false,sizeof(hasVisited));
}


void dfs(Node (&new_graph)[maxn],int index,int delete_index){
	if(index==delete_index) return;
	for(int i=0;i<(int)new_graph[index].link.size();++i){
		if(hasVisited[new_graph[index].link[i]]==false){
			hasVisited[new_graph[index].link[i]]=true;
			dfs(new_graph,new_graph[index].link[i],delete_index);
		}
	}
}


int main(){
	int city_num,remaining_highways,check_num;
	int id1,id2;
	scanf("%d%d%d",&city_num,&remaining_highways,&check_num);
	for(int i=0;i<remaining_highways;++i){
		scanf("%d %d",&id1,&id2);
		origin_graph[id1].link.push_back(id2);
		origin_graph[id2].link.push_back(id1);
	}
	for(int i=0;i<check_num;++i){
		int num=0;
		int id;
		scanf("%d",&id);
		init_hasVisited();
		for(int j=1;j<=city_num;++j){
			if(hasVisited[j]==false&&j!=id){
				++num;
				dfs(origin_graph,j,id);
			}
		}
		printf("%d\n",num-1);
	}
	return 0;
}

