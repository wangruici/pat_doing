//动态规划解法
#include <cstdio>
#include <algorithm>

using std::fill;
using std::max;
using std::min;

const int maxn=10010;

int sequence[maxn];
int stripe[maxn];
int dp[maxn];//记录以stripe[i]结尾的最大长度

bool isRightSeq(int before,int behind){
	if(sequence[before]==-1||sequence[behind]==-1){
		return false;
	}
	if(sequence[before]<=sequence[behind]){
		return true;
	}
	return false;
}

int main(){
	fill(sequence,sequence+maxn,-1);
	int color_num;
	int love_color_num;
	int stripe_num;
	int temp;
	int num=0;
	scanf("%d",&color_num);
	scanf("%d",&love_color_num);
	for(int i=0;i<love_color_num;++i){
		scanf("%d",&temp);
		sequence[temp]=i;
	}
	scanf("%d",&stripe_num);
	for(int i=0;i<stripe_num;++i){
		scanf("%d",&temp);
		if(sequence[temp]>=0){
			stripe[num++]=sequence[temp];
		}
	}
	int ans=-1;
	//动态规划解
	for(int i=0;i<num;++i){
		dp[i]=1;
		for(int j=0;j<i;++j){
			if(stripe[j]<=stripe[i]&&\
					(dp[j]+1>dp[i])){
				dp[i]=dp[j]+1;
			}
		}
		ans=max(ans,dp[i]);
	}
	printf("%d\n",ans);
	return 0;

}
