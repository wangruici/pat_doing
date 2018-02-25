#include <cstring>
#include <cstdio>


#define INDEX int
#define DATATYPE int


INDEX upper_bound(DATATYPE* array,INDEX left,INDEX right,DATATYPE value){
	INDEX mid;
	while(left<right){
		mid=(left+right)/2;
		if(array[mid]<=value){
			left=mid+1;
		}
		else{
			right=mid;
		}
	}
	return left;
}

void print_array(DATATYPE* array,INDEX len){
	for(int i=0;i<len;++i){
		printf("%d ",array[i]);
	}
	printf("\n");
}

int main(){
	DATATYPE array[]={0,1,2,3,5,6,7,8,9,10};
	print_array(array,10);
	printf("input value you want to search:");
	DATATYPE value;
	scanf("%d",&value);
	INDEX ans=upper_bound(array,0,9,value);
	printf("ans:%d\n",ans);
	return 0;

}
