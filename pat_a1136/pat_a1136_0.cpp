#include <iostream>
#include <string>
#include <algorithm>


using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::fill;
using std::reverse;


const int maxn=1010;
struct BigInterger{
	int data[maxn];
	int len;
	BigInterger(){
		len=0;
		fill(data,data+maxn,0);
	}
	BigInterger(string s){
		len=s.size();
		fill(data,data+maxn,0);
		for(int i=0;i<len;++i){
			data[i]=s[len-1-i]-'0';
		}
	}
	BigInterger(const BigInterger &b){
		len=b.len;
		for(int i=0;i<len;++i){
			data[i]=b.data[i];
		}
	}
	void operator= (const BigInterger &b){
		fill(data,data+maxn,0);
		this->len=b.len;
		for(int i=0;i<b.len;++i){
			this->data[i]=b.data[i];
		}
	}
};

void reverseBig(BigInterger &b){
	reverse(b.data,b.data+b.len);
	while(b.data[b.len-1]==0&&b.len>=1){
		b.len--;
	}
}
BigInterger add(BigInterger b1,BigInterger b2){
	BigInterger b3;
	int carry=0;
	for(int i=0;i<b1.len||i<b2.len;++i){
		int temp=b1.data[i]+b2.data[i]+carry;
		b3.data[b3.len++]=temp%10;
		carry=temp/10;
	}
	if(carry!=0){
		b3.data[b3.len++]=carry;
	}
	return b3;
}

int printBigInterger(BigInterger b){
	for(int i=b.len-1;i>=0;--i){
		cout<<b.data[i];
	}
	return 0;
}


int isP(const BigInterger &b){
	for(int i=0;i<b.len;++i){
		if(b.data[i]!=b.data[b.len-1-i])
			return false;
	}
	return true;
}

int main(){
	string s;
	cin>>s;
	BigInterger b1=BigInterger(s);
	int counter=0;
	while(!isP(b1)&&counter<10){
		BigInterger b2(b1);
		BigInterger b3;
		reverseBig(b2);
		b3=add(b1,b2);
		printBigInterger(b1);
		cout<<" + ";
		printBigInterger(b2);
		cout<<" = ";
		printBigInterger(b3);
		cout<<endl;
		b1=b3;
		++counter;
	}
	if(isP(b1)){
		printBigInterger(b1);
		cout<<" is "<<"a palindromic number."<<endl;
	}
	else{
		cout<<"Not found in 10 iterations."<<endl;
	}
}



