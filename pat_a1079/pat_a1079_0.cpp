#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using std::vector;
const int maxn=100010;

struct node{
	double data;
	vector<int> child;
}Node[maxn];

double ans=0;
double root_price;
double percentage;
void dfs(int depth,int index){
	if(Node[index].child.size()<=0){
		ans=ans+Node[index].data*pow(1+percentage,depth);
		return;
	}
	else{
		for(int i=0;i<(int)Node[index].child.size();++i){
			dfs(depth+1,Node[index].child[i]);
		}
	}
}


int main(){
	int chain_count;
	scanf("%d %lf %lf",&chain_count,&root_price,&percentage);
	percentage=percentage*0.01;
	int value_count;
	for(int i=0;i<chain_count;++i){
		scanf("%d",&value_count);
		if(value_count==0){
			int howmany;
			scanf("%d",&howmany);
			Node[i].data=howmany;
		}
		else{
			int child_id;
			for(int j=0;j<value_count;++j){
				scanf("%d",&child_id);
				Node[i].child.push_back(child_id);
			}
		}
	}
	dfs(0,0);
	printf("%.1f\n",root_price*ans);
	return 0;
}
