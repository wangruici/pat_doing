#include <cstring>
#include <cstdio>
#include <algorithm>

using std::sort;
using std::swap;

int record[100010];

int binSearch(int* array,int left,int right,int key){
	int mid;
	while(left<=right){
		mid=(right+left)/2;
		if(array[mid]==key) return mid;
		else if(array[mid]>key) right=mid-1;
		else left=mid+1;
	}
	return -1;
}

int main(){
	int count,m;
	scanf("%d%d",&count,&m);
	for(int i=0;i<count;++i){
		scanf("%d",&record[i]);
	}
	sort(record,record+count);
	int i;
	for( i=0;i<count;++i){
		int pos=binSearch(record,0,count-1,m-record[i]);
		if(pos!=-1&&i!=pos){
			printf("%d %d\n",record[i],record[pos]);
			break;
		}
	}
	if(i==count) printf("No Solution\n");
	return 0;
}
