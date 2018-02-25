//随机选择算法，从array[left,right]中返回第K大的数
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <algorithm>
using std::sort;
using std::swap;
int rand_partition(int array[],int left,int right){
	int p=(round(1.0*rand()/RAND_MAX*(right-left)+left));
	swap(array[p],array[left]);
	int temp=array[left];
	while(left<right){
		while(left<right&array[right]>temp) --right;
		array[left]=array[right];
		while(right>left&&array[left]<=temp) ++left;
		array[right]=array[left];
	}
	array[left]=temp;
	return left;
}

int randSelect(int array[],int left,int right,int K){
	if(left==right) return array[left];//
	int p=rand_partition(array,left,right);
	int M=p-left+1;
	if(K==M) return array[p];
	if(K<M){
		return randSelect(array,left,p-1,K);
	}
	else{
		return randSelect(array,p+1,right,K-M);
	}
}

int main(){
	int array[]={4,3,1,33,45,34,2,3,67,732,34,11};
	const int len=12;
	int ans=randSelect(array,0,11,5);
	printf("%d",ans);
	return 0;
}
