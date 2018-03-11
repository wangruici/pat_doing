//必须在每一步求和时都进行约分，最后再约分会导致溢出
//5/0或6%0这样的情况会导致浮点错误
//计算最大公约数时一定要使用绝对值，否则会造成错误
//对负数求余数是非法的
#include <cstdio>
#include <algorithm>
using std::abs;
typedef long long ll;
struct Fraction{
	ll up,down;	
};
/*
//辗转相除法
//如果a%b==0,最大公因数为b
//否则求b与a%b的最大公因数
*/
//辗转相除法求最大公因数
ll gcd(ll a,ll b){
	if(b==0){
		return a;
	}
	ll c=a%b;
	while(c!=0){
		a=b;
		b=c;
		c=a%b;
	}
	return b;
}
//辗转相除法可以写成递归的形式
ll _gcd(ll a,ll b){
	return b==0?a:_gcd(b,a%b);
}

//该函数无法处理分母为0的违法分数
Fraction reduction(Fraction result){
	//保证负数写到分子上
	if(result.down<0){
		result.down=-result.down;
		result.up=-result.up;
	}
	//不规则的分数
	else if(result.down<0&&result.up<0){
		result.down=-result.down;
		result.up=-result.up;
	}
	else if(result.up==0){
		result.down=1;
	}
	else{
		ll d=gcd(abs(result.up),abs(result.down));
		result.up/=d;
		result.down/=d;
	}
	return result;
}

Fraction add(Fraction f1,Fraction f2){
	Fraction f3;
	f3.up=f1.up*f2.down+f2.up*f1.down;
	f3.down=f1.down*f2.down;
	return reduction(f3);
}

void showResult(Fraction r){
	reduction(r);
	if(r.down==1) printf("%lld",r.up);
	else if(abs(r.up)>r.down){
		printf("%lld %lld/%lld",r.up/r.down,abs(r.up)%r.down,r.down);
	}
	else{
		printf("%lld/%lld",r.up,r.down);
	}
}

int main(){
	int n;
	scanf("%d",&n);
	Fraction sum,temp;
	sum.up=0;
	sum.down=1;
	for(int i=0;i<n;++i){
		scanf("%lld/%lld",&temp.up,&temp.down);
		sum=add(sum,temp);
	}
	showResult(sum);
	printf("\n");
	return 0;
}

