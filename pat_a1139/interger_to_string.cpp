#include <string>
#include <iostream>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(){
	int a=100;
	//这句是错误的，说明int不能这样转化为string
	//string s=string(a);
	char s[10]="1132";
	string b=string(s);
	cout<<b<<endl;
	return 0;
}

