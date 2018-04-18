#include <cstdio>
#include <cmath>

bool isPrime(int n){
	if(n<=1) return false;
	else{
		int sq=sqrt(1.0*n);
		for(int i=2;i<=sq;++i){
			if(n%i==0) return false;
		}
		return true;
	}
}

int num_array[112];

int R_convertTo10(int *num_array,int len,int radix){
	int ans=0;
	for(int i=0;i<len;++i){
		ans=ans*radix+num_array[i];
	}
	return ans;
}

int convertToRadix(int num,int radix,int *num_array){
	int i=0;
	do{
		num_array[i++]=num%radix;
		num/=radix;
	}while(num!=0);
	return i;
}

int main(){
	int num;
	int radix;

	while(scanf("%d",&num)!=EOF){
		if(num>=0){
			scanf("%d",&radix);
			if(isPrime(num)){
				int len=convertToRadix(num,radix,num_array);
				num=R_convertTo10(num_array,len,radix);
				if(isPrime(num)){
					printf("Yes\n");
					continue;
				}
			}
			printf("No\n");
		}
		else{
			break;
		}
	}
	return 0;
}
