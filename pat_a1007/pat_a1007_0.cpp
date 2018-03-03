#include <cstdio>
#include <algorithm>
#include <vector>
using std::vector;
using std::fill;

int main(){
	const int maxn=10010;
	int num=0;
	int sum[maxn];
	fill(sum,sum+maxn,0);
	scanf("%d",&num);
	int temp;
	for(int i=1;i<=num;++i){
		scanf("%d",&temp);
		sum[i]=temp+sum[i-1];
	}
	
	int max_sum=0;
	int index_left=-1;
	int index_right=-1;
	int sum_i_j=1+num;
	int temp_sum=0;
	for(int i=num;i>0;--i){
		for(int j=0;j<i;++j){
			temp_sum=sum[i]-sum[j];
			if(temp_sum>max_sum){
				max_sum=temp_sum;
				index_left=j;
				index_right=i;
				sum_i_j=i+j;
			}
			else if(temp_sum==max_sum){
				if(i+j<sum_i_j){
					index_left=j;
					index_right=i;
				}
			}
		}
	}
	if(index_left==-1){
		printf("%d %d %d",max_sum,sum[1],sum[num]-sum[num-1]);
	}
	else{
		printf("%d %d %d",max_sum,sum[index_left+1]-sum[index_left],sum[index_right]-sum[index_right-1]);
	}
	return 0;
}
