#include <cstdio>

bool isPrimer(int n){
	if(n<2) return false;
	else if(n==3||n==2) return true;
	else{
		for(int i=2;i*i<=n;++i){
			if(n%i==0){
				return false;
			}
		}
		return true;
	}
}

int reverse_num(int n,int radix){
	int sum=0;
	while(n){
		sum=sum*radix+n%radix;
		n/=radix;
	}
	return sum;
}

int main(){
	int value,radix;
	scanf("%d %d",&value,&radix);
	while(value>=0){
		if(isPrimer(value)&&isPrimer(reverse_num(value,radix))){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
		scanf("%d %d",&value,&radix);
	}
	return 0;
}
