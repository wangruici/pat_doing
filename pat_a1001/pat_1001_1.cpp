#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::vector;


string
format(int n){
	int k=n;
	int len=0;
	string str;
	if(n<0){
		k=-k;
	}
	while(k){
		str+='0'+k%10;
		k/=10;
		++len;
		if(len%3==0&&k!=0)
			str+=',';
	}
	if(n<0){
		k=-k;
		str+='-';
	}
	else if(n==0){
		str+='0';
	}
	else{;}
	return str;
}

int reverse(string &s){
	auto temp=s[0];
	int i;
	for(i=0;i<s.length()/2;++i){
		temp=s[i];
		s[i]=s[s.length()-i-1];
		s[s.length()-i-1]=temp;
	}
	return i; 
}

int
main(){
	int a,b,c;
	cin>>a>>b;
	c=a+b;
	string s;
	s=format(c);
	reverse(s);
	cout<<s;
	return 0;
}

