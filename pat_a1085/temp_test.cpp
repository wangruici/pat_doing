#include <cstdio>
#include <cstring>
const int INF=999999999;//this is a flag,and will be insert to any array.

int upper_bound(int* array,int begin,int end,int value){
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

	int test[]={1,2,3,4,7,9,10,45,67,88,INF};
	print_array(test,11);
	int value;
	printf("input value you want to search:");
	scanf("%d",&value);
	int kk=upper_bound(test,0,10,value);
	printf("ans:%d\n",kk);
	return 0;
}


