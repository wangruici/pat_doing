//从低位到高位依次处理
//假设处理到第k位
//left表示k以左的位（高位）组成的数字
//right表示k以右（低位）的位组成的数字
#include <cstdio>

int main(){
	int n,a=1,ans=0;
	int left,now,right;
	scanf("%d",&n);
	while(n/a!=0){
		left=n/(a*10);
		now=n/a%10;
		right=n%a;
		if(now==0) ans+=left*a;
		else if(now==1) ans+=left*a+right+1;
		else ans+=(left+1)*a;
		a*=10;
	}
	printf("%d\n",ans);
	return 0;
}
