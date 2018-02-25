#include <cstdio>
#include <cstdlib>


template <typename T>
T* insertSort(T* unsortedData,int n){
	T temp;
	for(int i=1;i<n;++i){
		temp=unsortedData[i];
		for(int j=i;j>=0;--j){
			if(unsortedData[j]<temp){
				break;
			}
			unsortedData[j+1]=unsortedData[j];
		}
		unsortedData[j+1]=temp;
	}
	return unsortedData;
}

template <typename T>
void printArray(T* array,int n){
	for(int i=0;i<n;++i){
		printf("%d ",array[i]);
	}
}
int main(){
	int k[14]={3,4,1,2,1,45,32,1,45,66,42,16,534,34};
	printArray<int>(k,14);
	printf("\n");
	insertSort<int>(k,14);
	printArray<int>(k,14);
	printf("\n");
	return 0;

}
