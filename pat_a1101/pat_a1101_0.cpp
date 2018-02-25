#include <cstdio>
#include <cstring>
#include <algorithm>

using std::sort;
using std::min;
using std::max;
int array[100010];
const int INF=0x3fffffff;
int leftMax[100010]={0};
int rightMin[100010]={INF};
int ans[100010];
void print_array(int array[],int len){
	for(int i=0;i<len;++i){
		printf("%d ",array[i]);
	}
}
int main(){
	int count;
	scanf("%d",&count);

	for(int i=0;i<count;++i){
		scanf("%d",&array[i]);	
	}

	for(int i=1;i<count;++i){
		leftMax[i]=max(leftMax[i-1],array[i-1]);
	}

	rightMin[count-1]=INF;
	for(int i=count-2;i>=0;--i){
		rightMin[i]=min(rightMin[i+1],array[i+1]);
	}
	int ansCount=0;
	
	for(int i=0;i<count;++i){
		if(leftMax[i]<=array[i]&&rightMin[i]>=array[i]){
			ans[ansCount++]=array[i];
		}
	}
	sort(ans,ans+ansCount);
	printf("%d\n",ansCount);
	for(int i=0;i<ansCount;++i){
		printf("%d",ans[i]);
		if(i!=ansCount-1){
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}
