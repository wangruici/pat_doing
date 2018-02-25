#include <cstring>
#include <cstdio>

int fact(int n){
	int ans=1;
	if(n==0) return 1;
	while(n>=1){
		ans*=n--;
	}
	return ans;
}

int combin(int n,int r){
	return fact(n)/(fact(r)*fact(n-r));
}

int wrc_sum(int n){
	int ans=0;
	int record=n;
	while(n>=0){
		ans+=n*combin(record,n);
		--n;
	}
	return ans;
}

int get_k_num(int all,int value,int k){
	if(k>all){
		return -1;
	}
	else{
		while(k-1>0){
			--k;
			value=value/10;
		}
		int left=all-k;
		while(left>0){
			--left;
			value=value%10;
		}

	}
	return value;
}

int get_all_num(int value){
	if(value==0){
		return 1;
	}
	int ans=0;
	while(value){
		++ans;
		value=value/10;
	}
	return ans;
}

int zhishu10(int n){
	int ans=1;
	while(n>0){
		--n;
		ans*=10;
	}
	return ans;
}


int main(){
	int value;
	scanf("%d",&value);
	int all_num=get_all_num(value);
	int ans=0;
		int k=get_k_num(all_num,value,1);
		if(k<=0){
			ans=0;
		}
		else{
			ans=1;
		}
		int kst=2;
		while(kst<=all_num){
			k=get_k_num(all_num,value,kst);
			if(k==1){
				///////////////////////////////
				ans=wrc_sum(kst-1)+ans+value-k*zhishu10(kst-1)+1;
			}
			else{
				ans=ans+zhishu10(kst-1)+k*wrc_sum(kst-1);
			}
			++kst;
		}
	printf("%d\n",ans);
	return 0;
}
