#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::max;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


typedef long long LL;
const LL INF=(1LL<<63)-1; 
LL MAP[256];

void init_MAP(){
	for(char c='0';c<='9';++c){
		MAP[c]=c-'0';
	}
	for(char c='a';c<='z';++c){
		MAP[c]=c-'a'+10;
	}
	return;
}

LL convertNum10(string snum,LL radix){
	LL ans=0;
	int len=snum.size();
	for(int i=0;i<len;++i){
		ans=ans*radix+MAP[snum[i]];
	}
	return ans;
}

//题目没有明确给出，但是给定进制的数不过超过long long 的范围
//一旦经过转换溢出即说明该数较大
LL cmp(LL t,string snum,LL radix){
	LL num=convertNum10(snum,radix);
	if(num<0) return -1;
	else if(t>num) return 1;
	else if(t<num) return -1;
	else if(t==num) return 0;
	else{
		return 10086;
	}
}

LL binarySearch(LL t,string snum,LL left,LL right){
	LL mid;
	while(left<=right){
		mid=(left+right)/2;
		int flag=cmp(t,snum,mid);
		if(flag==0){
			return mid;
		}
		else if(flag<0){
			right=mid-1;
		}
		else if(flag>0){
			left=mid+1;
		}
	}
	return -1;
}

LL findLargest(string snum){
	LL max=0;
	int len=snum.size();
	for(int i=0;i<len;++i){
		if(MAP[snum[i]]>max){
			max=MAP[snum[i]];
		}
		else{
			;
		}
	}
	return max+1;
}


int main(){
	init_MAP();
	string sn1,sn2;
	LL flag;
	LL radix;
	cin>>sn1>>sn2>>flag>>radix;
	LL n;
	string sn;
	if(flag==1){
		n=convertNum10(sn1,radix);
		sn=sn2;
	}
	else if(flag==2){
		n=convertNum10(sn2,radix);
		sn=sn1;
	}
	else{
		;
	}


	LL low=findLargest(sn);
	LL high=max(low,n)+1;
	LL ans=binarySearch(n,sn,low,high);

	if(ans==-1){
		cout<<"Impossible"<<endl;
	}
	else{
		cout<<ans<<endl;
	}
	return 0;
}
