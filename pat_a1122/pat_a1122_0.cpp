#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using std::fill;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
const int maxn=220;
int graph[maxn][maxn];
bool flag[maxn];
const int non_link=0;
const int link=1;
bool isRight(vector<int> &path,int (&graph)[maxn][maxn],int count){
	memset(flag,false,sizeof(flag));	
	if(path[0]!=count+1){
		return false;
	}
	int len=path.size();
	if(path[1]!=path[len-1]){
		return false;
	}	
	for(int i=2;i<(int)path.size();++i){
		if(graph[path[i]][path[i-1]]==non_link||flag[path[i]]==true){
			return false;
		}
		else{
			flag[path[i]]=true;
		}
	}
	return true;
	
}

int main(){
	fill(graph[0],graph[0]+maxn*maxn,non_link);
	int point_count,link_count;
	cin>>point_count>>link_count;
	int id1,id2;
	for(int i=0;i<link_count;++i){
		cin>>id1>>id2;
		graph[id1][id2]=link;
		graph[id2][id1]=link;
	}
	int query_num;
	cin>>query_num;
	vector<int> path;
	for(int i=0;i<query_num;++i){
		cin>>id1;
		path.push_back(id1);
		for(int j=0;j<id1;++j){
			cin>>id2;
			path.push_back(id2);
		}
		bool a=isRight(path,graph,point_count);
		if(a){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
		path.clear();
	}
	return 0;
}

