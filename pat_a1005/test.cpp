#include <iostream>
#include <sstream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

int main(){
	int int_temp=1024;
	int int_temp1=0;
	string s;
	stringstream stre;
	stre<<int_temp;
	s=stre.str();
	cout<<s[0]<<endl;
	stringstream stre1;
	stre1<<int_temp1;
	string s1;
	s1=stre1.str();
	cout<<s1[0]<<endl;
	return 0;
}
