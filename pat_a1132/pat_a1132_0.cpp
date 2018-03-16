#include <iostream>
#include <vector>


using std::cin;
using std::cout;
using std::endl;
using std::vector;
typedef long long ll;
bool get_ans(long long l){
	vector<ll> digit;
	if(l==0){
		return false;
	}
	ll num=l;
	while(l){
		digit.push_back(l%10);
		l/=10;
	}
	ll num1=0;
	ll num2=0;
	int cut_digit_count=digit.size()/2;
	for(int i=digit.size()-1;i>=(int)digit.size()-cut_digit_count;--i){
		num1=num1*10+digit[i];	
	}
	for(int i=digit.size()-cut_digit_count-1;i>=0;--i){
		num2=num2*10+digit[i];
	}
	if(num1==0||num2==0){
		return false;
	}
	if(num%(num1*num2)==0){
		return true;
	}
	else{
		return false;
	}
	
}

int main(){
	int count;
	cin>>count;
	ll temp;
	int flag=true;
	for(int i=0;i<count;++i){
		cin>>temp;
		flag=get_ans(temp);
		if(flag){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
