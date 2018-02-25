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
	unordered_map<string,bool> keys;
	string mmm="";
	string s1;
	string s2;
	cin>>s1>>s2;
	for(string::iterator c1=s1.begin();c1!=s1.end();++c1){
		if(std::islower(*c1)){
			(*c1)=std::toupper(*c1);
		}
		string::iterator c2;
		for(c2=s2.begin();c2!=s2.end();++c2){
			if(std::islower(*c2)){
				(*c2)=std::toupper(*c2);
			}
			if((*c1)==(*c2)){
				break;
			}
		}
		if(c2==s2.end()&&keys.find(mmm+(*c1))==keys.end()){
			cout<<*c1;
			keys[mmm+(*c1)]=true;
		}
	}
	cout<<flush;
	return 0;
}