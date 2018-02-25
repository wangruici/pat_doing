#include <cstring>
#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>

using std::stack;
using std::vector;
using std::sort;

struct Node{
	int weight;
	vector<int> children;
	int weights_sum;
	int index;
};

const int maxn=110;

Node nodes[maxn];


bool cmp(int a,int b){
	return nodes[a].weight<nodes[b].weight;
}

vector<vector<int>> dfs(int object){
	vector<vector<int> > ans;
	bool flag[maxn]={false};
	nodes[0].weights_sum=nodes[0].weight;
	stack<Node> node_stack;
	node_stack.push(nodes[0]);
	vector<int> sub_ans;
	while(!node_stack.empty()){
		if(flag[node_stack.top().index]==false){
			Node node=node_stack.top();
			sub_ans.push_back(node.weight);
			if(node.weights_sum==object&&node.children.size()==0){
				ans.push_back(sub_ans);
			}
			for(int i=0;i<(int)node.children.size();++i){
				nodes[node.children[i]].weights_sum=node.weights_sum+nodes[node.children[i]].weight;
				node_stack.push(nodes[node.children[i]]);
			}
			flag[node.index]=true;
		}
		else{
			sub_ans.pop_back();
			node_stack.pop();
		}
	}
	return ans;
}
int main(){
	int node_count=0,non_leaf_count=0,object=0;
	scanf("%d %d %d",&node_count,&non_leaf_count,&object);

	for(int i=0;i<node_count;++i){
		scanf("%d",&nodes[i].weight);
		nodes[i].index=i;
		nodes[i].children.clear();
	}
	for(int i=0;i<non_leaf_count;++i){
		int j;
		int child_count;
		scanf("%d %d",&j,&child_count);
		for(int k=0;k<child_count;++k){
			int value;
			scanf("%d",&value);
			nodes[j].children.push_back(value);
		}
		sort(nodes[j].children.begin(),nodes[j].children.end(),cmp);
	}

	vector<vector<int> > ans=dfs(object);
	for(int i=0;i<(int)ans.size();++i){
		for(int j=0;j<(int)ans[i].size();++j){
			printf("%d",ans[i][j]);
			if(j<(int)ans[i].size()-1){
				printf(" ");
			}
		}
		if(i<(int)ans.size()-1){
			printf("\n");
		}
	}

}
