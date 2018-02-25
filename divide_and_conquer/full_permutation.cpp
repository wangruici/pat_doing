#include <cstdio>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
void full_permutation(const int* const initArray,bool *hashTable,const int initArraylen\
		,int *const resultArray,const int index);
template<typename T>
int printArray(T* array,int n){
	for(int i=0;i<n-1;++i){
		cout<<array[i]<<", ";
	}
	cout<<array[n-1]<<endl;
	return n;
}

int
main(){
	const int base_len=3;
	int initArray[base_len]={3,2,1},resultArray[base_len];
	bool hashTable[base_len]={false};
	cout<<"initArray is:"<<endl;
	printArray<int>(initArray,base_len);
	full_permutation(initArray,hashTable,base_len,resultArray,0);
	return 0;
}

void
full_permutation(const int * const initArray,bool* hashTable,const int initArraylen,\
		int *const resultArray,const int index ){
	if(index==initArraylen){
		for(int i=0;i<initArraylen;++i){
			if(i!=initArraylen-1){
				printf("%d,",resultArray[i]);
			}
			else{
				printf("%d",resultArray[i]);
			}
		}
		printf("\n");
		return;
	}
	else{
		for(int i=0;i<initArraylen;++i){
			if(hashTable[i]!=true){
				hashTable[i]=true;
				resultArray[index]=initArray[i];
				full_permutation(initArray,hashTable,initArraylen,resultArray,index+1);
				hashTable[i]=false;//一定要置位
			}
		}
	}
}


