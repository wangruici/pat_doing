#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int
main(){
	string s("wrc is my hh");
	cout<<s.length()<<endl;
	auto c=s.rbegin();
	cout<<*c<<endl;
	return 0;
}