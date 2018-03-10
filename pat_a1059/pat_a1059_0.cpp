#include <cstdio>
#include <cmath>

bool isPrime(int num){
	if(num==1) return false;
	int sqr=sqrt(1.0*num);
	for(int i=2;i<=sqr;++i){
		if(num%i==0){
			return false;
		}
	}
	return true;
}
const int maxn=100010;
int prime[maxn];//素数表
int pNum=0;//记录素数表的大小
//打表函数
void Find_Prime(){
	for(int i=1;i<maxn;++i){
		if(isPrime(i)==true){
			prime[pNum++]=i;
		}
	}
}

struct factor{
	int x,cnt;
}fac[10];

int main(){
	Find_Prime();
	int n,num=0;
	scanf("%d",&n);
	if(n==1){
		printf("1=1");
		return 0;
	}
	printf("%d=",n);
	int sqr=(int)sqrt(1.0*n);
	for(int i=0;i<pNum&&prime[i]<=sqr;++i){
		if(n%prime[i]==0){
			fac[num].x=prime[i];
			fac[num].cnt=0;
			while(n%prime[i]==0){
				fac[num].cnt++;
				n/=prime[i];
			}
			++num;
		}
		if(n==1) break;
	}
	//如果不能除尽，一定存在一个大于sqr的
	//不可能存在多个大于sqr的，因为相乘一定会大于n
	if(n!=1){
		fac[num].x=n;
		fac[num++].cnt=1;
	}
	for(int i=0;i<num;++i){
		if(i>0) printf("*");
		printf("%d",fac[i].x);
		if(fac[i].cnt>1){
			printf("^%d",fac[i].cnt);
		}
	}
	return 0;
}
