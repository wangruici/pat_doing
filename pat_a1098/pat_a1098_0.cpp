#include <vector>
#include <cstdio>
#include <algorithm>
using std::sort;
using std::vector;
using std::swap;
vector<int> origin_array;
vector<int> object;
vector<int> insert_array;

void element_down(int index,int high,vector<int> &array){
	int i=2*index+1;
	int right_child=2*index+2;
	while(i<=high){
		if(right_child<=high&&array[i]<array[right_child]){
			i=right_child;
		}
		if(array[index]<array[i]){
			swap(array[index],array[i]);
			index=i;
			i=2*index+1;
			right_child=i+1;
		}
		else{
			break;
		}
	}
}

void create_heap(vector<int> &array){
	for(int i=array.size()-1;i>=0;--i){
		element_down(i,array.size()-1,array);		
	}
}


int main(){


	int count;
	scanf("%d",&count);
	int value;
	for(int i=0;i<count;++i){
		scanf("%d",&value);
		origin_array.push_back(value);
	}

	for(int i=0;i<count;++i){
		scanf("%d",&value);
		object.push_back(value);
	}

	bool is_insert=false;
	int iteration_count=1;
	insert_array=origin_array;
	for(iteration_count=1;iteration_count<=count;++iteration_count){
		sort(insert_array.begin(),insert_array.begin()+iteration_count);
		if(iteration_count!=1&&insert_array==object){
			is_insert=true;
			break;
		}
	}
	if(is_insert){
		printf("Insertion Sort\n");
		sort(insert_array.begin(),insert_array.begin()+iteration_count+1);
		for(int i=0;i<(int)insert_array.size();++i){
			printf("%d",insert_array[i]);
			if(i!=(int)insert_array.size()-1){
				printf(" ");
			}
		}
	}
	else{
		printf("Heap Sort\n");
		create_heap(origin_array);
		//
		count--;
		while(origin_array!=object){
			swap(origin_array[0],origin_array[count]);
			element_down(0,--count,origin_array);
		}
		swap(origin_array[0],origin_array[count]);
		element_down(0,--count,origin_array);
		for(int i=0;i<(int)origin_array.size();++i){
			printf("%d",origin_array[i]);
			if(i!=(int)origin_array.size()-1){
				printf(" ");
			}
		}
	}

	return 0;
}


