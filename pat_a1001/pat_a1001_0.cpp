/*
 *因该从后低位向高位数，如果位数模3为0,就输出","
 *但是要注意，首位不能输出","
 *
 */
#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>
using std::abs;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::stringstream;

int main(){
	long long num1,num2;
	cin>>num1>>num2;
	long long num;
	num=num1+num2;
	if(num<0){
		cout<<"-";
		num=abs(num);
	}
	stringstream ss;
	ss<<num;
	string s;
	ss>>s;
	int len=s.size();
	for(int i=0;i<len;++i){
		if((len-i)%3==0&&i>0){
			cout<<","<<s[i];
		}
		else{
			cout<<s[i];
		}
	}
	cout<<endl;
	return 0;
}
