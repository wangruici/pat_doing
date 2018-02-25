#include <cstring>
#include <cstdio>

#define INDEX int
#define DATATYPE int

INDEX binarySearch(DATATYPE* array,INDEX begin,INDEX end,DATATYPE value){
	INDEX mid;
	while(begin<=end){
		mid=(begin+end)/2;
		if(value<array[mid]){
			end=mid-1;
		}
		else if(array[mid]<value){
			begin=mid+1;
		}
		else{
			return mid;
		}
	}
	return -1;
}


int main(){
	DATATYPE array[10]={0,1,2,3,4,5,6,7,8,9};

	DATATYPE value;
	printf("input value you want to search:");
	scanf("%d",&value);
	INDEX ans=binarySearch(array,0,9,value);
	printf("ans:%d",ans);
	return 0;
}
