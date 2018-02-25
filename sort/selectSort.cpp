#include <cstdio>
#include <cstdlib>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

template <typename T>
T* selectSort2(T* unsortedData,int n){
	T temp;
	int k;
	for(int i=0;i<n;++i){
		k=i;
		for(int j=i;j<n;++j){
			if(unsortedData[k]>unsortedData[j]){
				k=j;
			}
		}
		temp=unsortedData[i];
		unsortedData[i]=unsortedData[k];
		unsortedData[k]=temp;
	}
	return unsortedData;
}

typedef int* DataType;
DataType selectSort(DataType unsortedData,int n){
	//decltype(unsortedData[0]) temp;//decltype将其申明为引用类型，而引用一旦绑定就不能更改
	//怎样使用decltype申明一个左值？
	auto temp=unsortedData[0];
	//cout<<"1"<<endl;
	int k;
	//cout<<"2"<<endl;
	for(int i=0;i<n;++i){
		k=i;
		for(int j=i;j<n;++j){
			if(unsortedData[k]>unsortedData[j]){
				k=j;
				//cout<<"pp:"<<" "<<k<<"----"<<unsortedData[j]<<endl;
			}
		}
		temp=unsortedData[i];
		//cout<<"temp:"<<temp<<endl;
		unsortedData[i]=unsortedData[k];
		unsortedData[k]=temp;
	}
	return unsortedData;
}
void printArray(DataType array,int n){
	for(int i=0;i<n;++i){
		printf("%d ",array[i]);
	}
}

int main(){
	int k[14]={3,4,1,2,1,45,32,1,45,66,42,16,534,34};
	printArray(k,14);
	printf("\n");
	selectSort2<int>(k,14);
	printArray(k,14);
	printf("\n");
	return 0;

}
