#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;


//islower在std命名空间，不存在string命名空间
int main(){
	std::string s("hello world");
	if(std::islower(s[2])){
		cout<<"yes"<<endl;
	}else{
		cout<<"no"<<endl;
	}
	return 0;
}