#include <cstdio>
#include <algorithm>

using std::sort;
/*pat_a1068:动态规划解法，背包问题
 *将物品的重量与价值设为相等，
 *dp[i]记录背包容量为i时所能存放的最大价值，
 *这样，i理论上能存放的最大价值就是i,
 *但是如果给定的硬币串不能达到要求就会比i小
 */

//maxn硬币的最大数目,maxv需要得到的最大价值
const int maxn=10010;
const int maxv=110;

int w[maxn],dp[maxv]={0};
bool choice[maxn][maxv];
bool flag[maxn];
bool cmp(int a,int b){
	return a>b;
}

int main(){
	int coin_num,require_value;
	scanf("%d %d",&coin_num,&require_value);
	for(int i=1;i<=coin_num;++i){
		scanf("%d",&w[i]);
	}
	sort(w+1,w+coin_num+1,cmp);
	for(int i=1;i<=coin_num;++i){
		for(int v=require_value;v>=w[i];--v){
			if(dp[v]<=dp[v-w[i]]+w[i]){
				dp[v]=dp[v-w[i]]+w[i];
				choice[i][v]=true;
			}
			else{
				choice[i][v]=false;
			}
		}
	}
	if(dp[require_value]!=require_value) printf("No Solution");
	else{
		int k=coin_num,num=0,v=require_value;
		while(k>=0){
			if(choice[k][v]==1){
				flag[k]=true;
				v-=w[k];
				++num;
			}
			else flag[k]=false;
			--k;
		}
		for(int i=coin_num;i>=1;--i){
			if(flag[i]==true){
				printf("%d",w[i]);
				--num;
				if(num>0) printf(" ");
			}
		}
	}
	return 0;
}

