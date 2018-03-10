#include <cstdio>
#include <algorithm>
using std::max;
using std::min;
using std::abs;
const int max_len=100010;
int array[max_len]={0};
int zheng[max_len]={0};
int main(){
	int len;
	scanf("%d",&len);
	zheng[0]=0;
	array[0]=0;
	for(int i=1;i<=len;++i){
		scanf("%d",&array[i]);
		zheng[i]=zheng[i-1]+array[i-1];
	}
	int cycle=array[len]+zheng[len];
	int count;
	scanf("%d",&count);
	int index1,index2;
	int ma;
	int mi;
	for(int i=1;i<=count;++i){
		scanf("%d %d",&index1,&index2);
		ma=max(index1,index2);
		mi=min(index1,index2);
		printf("%d\n",min(zheng[ma]-zheng[mi],cycle-zheng[ma]+zheng[mi]));
	}
	return 0;
}
