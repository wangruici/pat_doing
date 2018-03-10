#include <cstdio>
#include <algorithm>
using std::max;
using std::min;
using std::abs;
const int max_len=100010;
int array[max_len];
int zheng[max_len];
int fan[max_len];
int main(){
	int len;
	scanf("%d",&len);
	zheng[0]=0;
	array[0]=0;
	for(int i=1;i<=len;++i){
		scanf("%d",&array[i]);
		zheng[i]=zheng[i-1]+array[i-1];
	}
	fan[len]=0;
	fan[1]=array[len];
	for(int i=2;i<len;++i){
		fan[i]=fan[i-1]+array[i-1];
	}
	int count;
	scanf("%d",&count);
	int index1,index2;
	for(int i=1;i<=count;++i){
		scanf("%d %d",&index1,&index2);
		int distance1=abs(zheng[index1]-zheng[index2]);
		int distance2=abs(fan[index1]-fan[index2]);
		printf("%d\n",min(distance1,distance2));
	}


}
