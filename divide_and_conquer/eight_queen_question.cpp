#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
using std::cin;
using std::endl;
using std::cout;
using std::flush;
using std::string;
void
printArray2(int* array,int len){
	for(int i=0;i<len-1;++i){
		printf("(%d,%d)  ",i+1,array[i]+1);
	}
	printf("(%d,%d)\n",len-1+1,array[len-1]+1);
}
void
solve_eight_queen_question(int* const result,int* const temp_arr,int index\
	,const int n_queen,bool* const hashTable);

void
solve_eight_queen_question(int* const result,int* const temp_arr,int index\
	,const int n_queen,bool* const hashTable){
	if(index==n_queen){
		(*esult)++;
//		printf("%5d:  ",*result);
//		printArray2(temp_arr,n_queen);
		return;
	}
	else{
		for(int i=0;i<n_queen;++i){
			if(hashTable[i]==false){
				bool flag=true;
				for(int pre=0;pre<index;++pre){
					if(abs(pre-index)==abs(temp_arr[pre]-i)){
						flag=false;
						break;
					}
				}
				if(flag){
						hashTable[i]=true;
						temp_arr[index]=i;
						solve_eight_queen_question(result,temp_arr,index+1,n_queen,hashTable);
						hashTable[i]=false;
				}
			}
		}
	}
}
int
main(){
	int i=10;
	const int n_queen=i;
	int result=0;
	int temp_arr[n_queen]={0};
	int index=0;
	bool hashTable[n_queen]={false};
	solve_eight_queen_question(&result,temp_arr,index,n_queen,hashTable);
	printf("%d\n",result);

	return 0;
}








