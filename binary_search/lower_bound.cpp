#include <cstring>
#include <cstdio>


#define INDEX int
#define DATATYPE int


INDEX lower_bound(DATATYPE* array,INDEX left,INDEX right,DATATYPE value){
	INDEX mid;
	while(left<right){
		mid=(left+right)/2;
		if(value<=array[mid]){
			right=mid;
		}
		else{
			left=mid+1;
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
	INDEX ans=lower_bound(array,0,9,value);
	printf("ans:%d\n",ans);
	return 0;

}
