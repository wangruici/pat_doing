#include <cstring>
#include <cstdio>
#include <algorithm>

using std::sort;

#define increase sort
bool cmp_decrease(int a1,int a2){
	return a1>a2;
}

#define decrease(a,b) sort(a,b,cmp_decrease)

void to_array(int n,int num[]){
	for(int i=0;i<4;++i){
		num[i]=n%10;
		n=n/10;
	}
}

int to_number(int num[]){
	int sum=0;
	for(int i=0;i<4;++i){
		sum=sum*10+num[i];
	}
	return sum;
}

int main(){
	int n,MIN,MAX;
	scanf("%d",&n);
	int num[5];
	while(true){
		to_array(n,num);
		increase(num,num+4);
		MIN=to_number(num);
		decrease(num,num+4);
		MAX=to_number(num);
		n=MAX-MIN;
		printf("%04d - %04d = %04d\n",MAX,MIN,n);
		if(n==0||n==6174) break;
	}
	return 0;
}
