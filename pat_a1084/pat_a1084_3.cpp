#include <string>
#include <iostream>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::flush;

using std::string;

using std::unordered_map;


int main(){
	cout<<"3"<<endl;
	unordered_map<string,bool> keys;
	string mmm="";
	string s1;
	string s2;
	cin>>s1>>s2;
	for(auto &c1:s1){
		if(std::islower(c1)){
			c1=std::toupper(c1);
		}
		int i=0;//作为计数器，因为对于range for来说,c2必须是局部变量
		for(auto &c2:s2){
			++i;
			if(std::islower(c2)){
				c2=std::toupper(c2);
			}
			if(c1==c2){
				break;
			}
		}
		if(i==s2.size()&&keys.find(mmm+c1)==keys.end()){
			cout<<c1;
			keys[mmm+c1]=true;
		}
	}
	cout<<flush;
	return 0;
}