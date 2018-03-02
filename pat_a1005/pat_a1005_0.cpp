#include <iostream>
#include <string>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fill;

int how_many_bit(int sum){
	int ans=0;
	while(sum){
		sum=sum/10;
		++ans;
	}
	return ans;
}

int ans[11]={0};

int get_every_bit(int sum,int bit_num){
	int temp=sum;
	for(int i=0;i<bit_num;++i){
		int yu=temp%10;
		ans[i]=yu;
		temp=temp/10;
	}
}

int main(){
	string num;
	cin>>num;
	const int maxn=10;
	int bit[maxn];
	fill(bit,bit+maxn,0);
	int sum=0;
	for(int i=0;i<(int)num.size();++i){
		++bit[num[i]-'0'];
	}
	for(int i=0;i<10;++i){
		sum+=bit[i]*i;
	}
	if(sum==0){
		cout<<"zero"<<endl;
		return 0;
	}
	int bit_num=how_many_bit(sum);

	get_every_bit(sum,bit_num);
	for(int i=bit_num-1;i>=0;--i){
		int bit=ans[i];
		string s;
		switch(bit){
			case 0:
				s=string("zero");
				break;
			case 1:
				s=string("one");
				break;
			case 2:
				s=string("two");
				break;
			case 3:
				s=string("three");
				break;	
			case 4:
				s=string("four");
				break;
			case 5:
				s=string("five");
				break;
			case 6:
				s=string("six");
				break;
			case 7:
				s=string("seven");
				break;
			case 8:
				s=string("eight");
				break;
			case 9:
				s=string("nine");
				break;
		}
		cout<<s;
		if(i!=0){
			cout<<" ";
		}
		else{
			cout<<endl;
		}
	}
	return 0;
}
