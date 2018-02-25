#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

using std::vector;

const int maxn=100010;
struct Node{
	vector<int> children;
}nodes[maxn];

int min_depth_num=0;
int min_depth=100010;

void dfs(int depth,int index){
	if(nodes[index].children.size()==0){
		if(depth<min_depth){
			min_depth=depth;
			min_depth_num=1;
		}
		else if(depth==min_depth){
			min_depth_num++;
		}
		else{
			;
		}
		return;
	}
	else{
		for(int i=0;i<(int)nodes[index].children.size();++i){
			dfs(depth+1,nodes[index].children[i]);
		}
	}
}


int main(){
	int count;
	int value;
	double root_price;
	double r;
	scanf("%d %lf %lf",&count,&root_price,&r);
	r=0.01*r;
	int child_num;
	for(int i=0;i<count;++i){
		scanf("%d",&child_num);
		for(int j=0;j<child_num;++j){
			scanf("%d",&value);
			nodes[i].children.push_back(value);
		}
	}
	dfs(0,0);
	double min_price=root_price*pow(1+r,min_depth);

	printf("%.4lf %d",min_price,min_depth_num);
	return 0;
}
