#include <cstdio>
#include <cstring>

long long get_howmany(long long num,long long base,int num_array[],long long len){
	long long howmany=0;
	long long temp=num;
	while(temp){
		if(howmany<len){
			num_array[howmany]=temp%base;	
		}
		else{
			return len;
		}
		++howmany;
		temp=temp/base;	
	}
	return howmany;
}
int main(){
	const long long maxn=1000000;
	long long num; 
	long long howmany=0;
	long long base; 
	int ans[maxn]; 
	scanf("%lld %lld",&num,&base); 
	if(num==0){
		printf("Yes\n0\n");
		return 0;
	}
	howmany=get_howmany(num,base,ans,maxn);
	
	bool flag=true;
	for(long long i=0,j=howmany-1;i<howmany&&j>=0;++i,--j){
		if(ans[i]!=ans[j]){
			flag=false;
			break;
		}
	}
	if(flag){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	} for(long long i=howmany-1;i>=0;--i){ 
		printf("%d",ans[i]);
		if(i==0){
			printf("\n");
		}
		else{
			printf(" ");
		}
	}
	return 0;
}
