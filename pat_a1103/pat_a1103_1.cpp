#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>

using std::vector;
using std::sort;

const int maxn=1000;

vector<int> fac;


int init_array_with_pow(vector<int>& array,int object,int mi){
	int i=0;
	do{
		array.push_back(pow(i,mi));
		++i;
	}while(array[i-1]<=object);
	return i-1;
}

void print_array(int* array,int len){
	for(int i=0;i<len;++i){
		printf("%d ",array[i]);
	}
	printf("\n");
	return;
}
vector<int> temp,ans;

int object,mi,total_num;
int max_fac_sum=-1;
void dfs_kp(int index,int now_choose_count,int sum,int fac_sum);
int main(){
	scanf("%d%d%d",&object,&total_num,&mi);	
	int limit_bound_fact=init_array_with_pow(fac,object,mi);
	dfs_kp(limit_bound_fact-1,0,0,0);
	if(max_fac_sum==-1) printf("Impossible\n");
	else{
		printf("%d = %d^%d",object,ans[0],mi);
		for(int i=1;i<(int)ans.size();++i){
			printf(" + %d^%d",ans[i],mi); 
		}
	}

	return 0;
}

void dfs_kp(int index,int now_choose_count,int sum,int fac_sum){
	//查找到满足条件的一组数据
	if(sum==object&&now_choose_count==total_num){
		if(fac_sum>max_fac_sum){
			max_fac_sum=fac_sum;
			ans=temp;
		}
		return;
	}
	//查找失败，当前分支并不能满足条件
	if(index<=0||now_choose_count>total_num||sum>object) return;
	
	//需要继续进行递归
	//将当前节点推入
	temp.push_back(index);
	//当前节点加入组合的分支
	dfs_kp(index,now_choose_count+1,sum+fac[index],fac_sum+index);
	//对于加入组合分支，结束一条路线需要弹出这个节点，因为该节点的所以可能都已经尝试了
	//对于不加入组合分支，由于前面压入了这个节点，所以还是要弹出
	temp.pop_back();
	//当前节点不加入组合
	dfs_kp(index-1,now_choose_count,sum,fac_sum);
	return;
}





