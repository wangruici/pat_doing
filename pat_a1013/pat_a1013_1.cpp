#include <vector>
#include <iostream>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

const int maxn=1010;
struct Node{
	vector<int> link;
}original_graph[maxn];

bool hasVisited[maxn];
void init_hasVisited(){
	for(int i=0;i<maxn;++i){
		hasVisited[i]=false;
	}
}

void dfs(Node *original_graph,int point){
	hasVisited[point]=true;
	int n=original_graph[point].link.size();
	for(int i=0;i<n;++i){
		int j=original_graph[point].link[i];
		if(hasVisited[j]==false){
			dfs(original_graph,j);
		}
	}
}

int main(){
	int point_count,link_count,query_count;
	cin>>point_count>>link_count>>query_count;
	int point1,point2;
	for(int i=0;i<link_count;++i){
		cin>>point1>>point2;
		original_graph[point1].link.push_back(point2);
		original_graph[point2].link.push_back(point1);
	}
	for(int i=0;i<query_count;++i){
		cin>>point1;
		int num=0;
		init_hasVisited();
		hasVisited[point1]=true;
		for(int j=1;j<=point_count;++j){
			if(hasVisited[j]==false){
				dfs(original_graph,j);
				++num;
			}
		}
		cout<<num-1<<endl;
	}

	return 0;
}
