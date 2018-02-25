#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>
using std::swap;
int partition(int array[],int left,int right){
	int temp=array[left];
	while(left<right){
		while(left<right&&array[right]>temp) --right;
		array[left]=array[right];
		while(right>left&&array[left]<=temp) ++left;
		array[right]=array[left];
	}
	array[left]=temp;
	return left;
}

void quick_sort(int array[],int left,int right){
	if(left<right){
		int pos=partition(array,left,right);
		quick_sort(array,left,pos-1);
		quick_sort(array,pos+1,right);
	}
}

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

void rand_quick_sort(int array[],int left,int right){
	if(left<right){
		int pos=partition(array,left,right);
		rand_quick_sort(array,left,pos-1);
		rand_quick_sort(array,pos+1,right);

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
	rand_quick_sort(array,0,10);
	print_array(array,11);
	return 0;
}
