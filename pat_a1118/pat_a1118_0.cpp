#include <iostream>
#include <string>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::flush;

const int maxn=10000+10;

int bird_set[maxn];

void init(){
	for(int i=0;i<maxn;++i){
		bird_set[i]=i;
	}
}

int find_group(int index){
	int y=index;
	while(index!=bird_set[index]){
		index=bird_set[index];
	}

	while(bird_set[y]!=index){
		int z=bird_set[y];
		bird_set[y]=index;
		y=z;
	}
	return index;
}

int union_group(int index1,int index2){
	int root1=find_group(index1);
	int root2=find_group(index2);
	if(root1!=root2){
		bird_set[root1]=root2;
	}
	return root2;
}
bool visited[maxn];
int main(){
	init();
	int num;
	scanf("%d",&num);
	int temp_num;
	int temp;
	int temp_root;
	int count=0;
	for(int i=0;i<num;++i){
		scanf("%d",&temp_num);
		if(temp_num>0){
			scanf("%d",&temp_root);
			if(visited[temp_root]==false){
				visited[temp_root]=true;
				++count;
			}
		}
		for(int j=1;j<temp_num;++j){
			scanf("%d",&temp);
			union_group(temp_root,temp);
			if(visited[temp]==false){
				visited[temp]=true;
				++count;
			}
		}
	}
	int query_num;
	scanf("%d",&query_num);
	map<int,int> ans;
	for(int i=1;i<=count;++i){
		++ans[find_group(bird_set[i])];
	}
	printf("%d %d\n",(int)ans.size(),count);
	int index1,index2;
	for(int i=0;i<query_num;++i){
		scanf("%d %d",&index1,&index2);
		if(find_group(index1)==find_group(index2)){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	return 0;	
}
