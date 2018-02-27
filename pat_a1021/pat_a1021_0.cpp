#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using std::vector;
using std::queue;


const int maxn=10010;

struct Node{
	vector<int> link;
};

bool visited[maxn]={false};

Node graph[maxn];
void dfs(int index,int depth,int &max_depth);
int main(){
	int node_num;
	int id1;
	int id2;
	scanf("%d",&node_num);
	for(int i=0;i<node_num-1;++i){
		scanf("%d %d",&id1,&id2);
		graph[id1].link.push_back(id2);
		graph[id2].link.push_back(id1);
	}
	int block=0;
	int max_depth=0;	
	for(int i=1;i<=node_num;++i){
		if(visited[i]==false){
			block++;
			dfs(i,1,max_depth);
		}
	}
	if(block!=1){
		printf("Error: %d components\n",block);
	}
	else{
		vector<int> depth_nodes;
		max_depth=0;
		for(int i=1;i<=node_num;++i){
			int depth=0;
			memset(visited,false,sizeof(visited));
			dfs(i,1,depth);
			if(depth==max_depth){
				depth_nodes.push_back(i);
			}
			else if(depth>max_depth){
				depth_nodes.clear();
				max_depth=depth;
				depth_nodes.push_back(i);
			}
			else{
				;
			}
		}
		for(int i=0;i<(int)depth_nodes.size();++i){
			printf("%d\n",depth_nodes[i]);
		}
	}
}

void dfs(int index,int depth,int &max_depth){
	if(visited[index]==false){
		visited[index]=true;
		if(depth>max_depth){
			max_depth=depth;
		}
		for(int i=0;i<(int)graph[index].link.size();++i){
			dfs(graph[index].link[i],depth+1,max_depth);
		}
	}
	else return;
}
