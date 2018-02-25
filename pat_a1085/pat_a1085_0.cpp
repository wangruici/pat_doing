#include <cstring>
#include <cstdio>
#include <algorithm>

using std::sort;
const int INF=1100000001;
const int maxn=100010;
int array[maxn];

int upper_bound(int* array,int begin,int end,long long value){
	int mid;
	while(begin<end){
		mid=(begin+end)/2;
		if(array[mid]<=value){
			begin=mid+1;
		}
		else{
			end=mid;
		}
	}
	return begin;
}

void print_array(int* array,int len){
	for(int i=0;i<len;++i){
		printf("%d ",array[i]);
	}
	printf("\n");
	return;
}

int main(){
	int count=0;
	int ans=1;
	int num;
	scanf("%d",&count);
	scanf("%d",&num);
	for(int i=0;i<count;++i){
		scanf("%d",&array[i]);
	}
	int temp;
	sort(array,array+count);
	array[count]=INF;
	for(int i=0;i<count-1;++i){
		temp=upper_bound(array,i+1,count,(long long)array[i]*num);
		if(temp-i>ans){
			ans=temp-i;
		}
	}
	printf("%d\n",ans);
	return 0;
}
