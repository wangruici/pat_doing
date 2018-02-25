#include <cstdio>
#include <cstring>

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

void mergeSort(int A[],int left,int right){
	if(left<right){
		int mid=(left+right)/2;
		mergeSort(A,left,mid);
		mergeSort(A,mid+1,right);
		merge(A,left,mid,mid+1,right);
	}
}

void print_array(int array[],int len){
	for(int i=0;i<len;++i){
		printf(" %d",array[i]);
	}
	printf("\n");
}
int main(){
	int array[]={6,32,12,45,22,676,12,34,1,5,2};
	print_array(array,11);
	mergeSort(array,0,10);
	print_array(array,11);
	return 0;
}
