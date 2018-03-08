#include <string>
#include <iostream>
#include <algorithm>

using std::reverse;
using std::string;
using std::endl;
using std::cin;
using std::cout;
using std::flush;
string convert(int num,int radix);

int main(){
	string nulls;
	int red;
	int green;
	int	blue;
	cin>>red>>green>>blue;
	string red_13=convert(red,13);
	if(red_13.size()<2) red_13=nulls+'0'+red_13; 
	string green_13=convert(green,13);
	if(green_13.size()<2) green_13=nulls+'0'+green_13; 
	string blue_13=convert(blue,13);
	if(blue_13.size()<2) blue_13=nulls+'0'+blue_13; 

	string result="";
	result=result+'#'+red_13+green_13+blue_13;
	cout<<result<<endl;
	return 0;
}

string convert(int num,int radix){
	string result="";
	int remain;
	if(num==0){
		result='0';
		return result;
	}
	while(num){
		remain=num%radix;
		num/=radix;
		if(remain<10){
			result+=(remain+'0');
		}
		else{
			remain-=10;
			result+=(remain+'A');
		}
	}
	reverse(result.begin(),result.end());
	return result;
}
