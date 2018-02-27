#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

const int maxn=100010;

struct Node{
	vector<int> link;
}graph[maxn];

bool visited[maxn]={false};
//define UFS,union and find set;
/**********************************************************/
int data_set[maxn];

void init_data_set(int data_set[],int len){
	for(int i=1;i<=len;++i){
		data_set[i]=i;
	}
}

int get_set_name(int data_set[],int index){
	int name=index;
	while(name!=data_set[name]){
		name=data_set[name];
	}
	int next=data_set[index];
	while(next!=data_set[next]){
		data_set[index]=name;
		index=next;
		next=data_set[index];
	}
	return name;
}

void union_set(int data_set[],int index1,int index2){
	int set_name1=get_set_name(data_set,index1);
	int set_name2=get_set_name(data_set,index2);

	data_set[set_name1]=set_name2;
}

/**********************************************************/
int calBlock(int data_set[],int set_len){
	bool isRoot[maxn]={false};
	int Block=0;
	for(int i=1;i<=set_len;++i){
		isRoot[get_set_name(data_set,i)]=true;
	}
	for(int i=1;i<=set_len;++i){
		Block+=isRoot[i];
	}
	return Block;
}
/**********************************************************/
void dfs(int index,int depth,int &max_depth);
int main(){
	int node_num;
	int id1;
	int id2;
	scanf("%d",&node_num);
	init_data_set(data_set,node_num);
	for(int i=0;i<node_num-1;++i){
		scanf("%d %d",&id1,&id2);
		graph[id1].link.push_back(id2);
		graph[id2].link.push_back(id1);
		union_set(data_set,id1,id2);
	}
	int block=calBlock(data_set,node_num);
	if(block!=1){
		printf("Error: %d components\n",block);
	}
	else{
		vector<int> depth_nodes;
		int max_depth=0;
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





