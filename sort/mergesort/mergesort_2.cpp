//非递归实现
#include <cstring>
#include <cstdio>
#include <algorithm>

using std::sort;
using std::swap;
using std::min;
const int maxn=100;

void merge(int A[],int L1,int R1,int L2,int R2){
	int i=L1,j=L2;
	int temp[maxn],index=0;
	while(i<=R1&&j<=R2){
		if(A[i]<=A[j]){
			temp[index++]=A[i++];
		}
		else{
			temp[index++]=A[j++];
		}
	}
	while(i<=R1) temp[index++]=A[i++];
	while(j<=R2) temp[index++]=A[j++];
	for(i=0;i<index;++i){
		A[L1+i]=temp[i];
	}
	return;
}
void mergeSort(int A[],int n){
	for(int step=2;step/2<=n;step*=2){
		for(int i=0;i<n;i+=step){
			int mid=i+step/2-1;
			if(mid+1<n){
				merge(A,i,mid,mid+1,min(i+step-1,n-1));
			}
		}
	}
}
void print_array(int array[],int len){
	for(int i=0;i<len;++i){
		printf(" %d",array[i]);
	}
	printf("\n");
}

int main(){
	int array[]={1000,6,32,12,45,22,676,12,34,1,5,2};
	print_array(array,12);
	mergeSort(array,12);
	print_array(array,12);
	return 0;
}
