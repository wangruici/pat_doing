#include <cstdio>
#include <cstring>
#include <algorithm>

using std::sort;
using std::swap;

const int maxn=100010;
int sum[maxn];

int count,S,nearS=100000010;

int upper_bound(int* array,int left,int right,int value){
	int mid;
	while(left<right){
		mid=(left+right)/2;
		if(array[mid]>value){
			right=mid;
		}
		else{
			left=mid+1;
		}
	}
	return left;
}

int main(){
	scanf("%d %d",&count,&S);
	for(int i=1;i<=count;++i){
		scanf("%d",&sum[i]);
	}

	sum[0]=0;
	for(int i=1;i<=count;++i){
		sum[i]=sum[i]+sum[i-1];
	}

	for(int i=1;i<=count;++i){
		int j=upper_bound(sum,i,count+1,S+sum[i-1]);
		if(sum[j-1]-sum[i-1]==S){
			nearS=S;
			break;
		}
		//when count>count,that means all diamonds can not afford.
		else if(j<=count&&sum[j]-sum[i-1]<nearS){
			nearS=sum[j]-sum[i-1];
		}
	}

	for(int i=1;i<=count;++i){
		int j=upper_bound(sum,i,count+1,nearS+sum[i-1]);
		if(sum[j-1]-sum[i-1]==nearS){
			printf("%d-%d\n",i,j-1);
		}
	}
	return 0;
}
