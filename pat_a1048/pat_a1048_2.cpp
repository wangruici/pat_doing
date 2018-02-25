#include <cstdio>
#include <cstring>
#include <algorithm>

using std::sort;
using std::max;
using std::min;

const int maxn=100010;

int coins[maxn];

int main(){
	int count=0;
	int value=0;
	scanf("%d%d",&count,&value);
	for(int i=0;i<count;++i){
		scanf("%d",&coins[i]);
	}
	int i=0,j=count-1;
	bool flag=false;
	sort(coins,coins+count);
	while(i<j){
		if(coins[i]+coins[j]==value){
			flag=true;
			break;
		}
		else if(coins[i]+coins[j]>value){
			--j;
		}
		else{
			++i;
		}
	}
	if(flag){
		printf("%d %d\n",coins[i],coins[j]);
	}
	else{
		printf("No Solution\n");
	}
	return 0;

}
