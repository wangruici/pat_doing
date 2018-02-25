#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
using std::vector;

const int maxn=100010;

struct Node{
	vector<int> children;
}nodes[maxn];


int max_depth=0;
int max_num=0;
void dfs_search(int depth,int index){
	if(nodes[index].children.size()==0){
		if(depth>max_depth){
			max_num=1;
			max_depth=depth;
		}
		else if(depth==max_depth){
			++max_num;
		}
		else{
			;
		}
		return;
	}
	for(int i=0;i<(int)nodes[index].children.size();++i){
		dfs_search(depth+1,nodes[index].children[i]);
	}
}


int main(){
	int count=0;
	double root_price=0;
	double r_percentage=0;

	scanf("%d %lf %lf",&count,&root_price,&r_percentage);
	r_percentage=r_percentage*0.01;

	int root_index=0;

	int value=0;
	for(int i=0;i<count;++i){		
		scanf("%d",&value);
		if(value==-1){
			root_index=i;
		}
		else{
			nodes[value].children.push_back(i);
		}
	}
	dfs_search(0,root_index);
	double max_price=root_price*pow(1+r_percentage,max_depth);

	printf("%.2lf %d",max_price,max_num);
	return 0;
}
