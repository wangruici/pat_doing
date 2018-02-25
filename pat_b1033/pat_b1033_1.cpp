#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>
#include <stdexcept>
using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::islower;
using std::toupper;
using std::tolower;
using std::isupper;

using std::unordered_map;

using std::vector;

using std::set;

using std::runtime_error;
using std::out_of_range;

int main(){
	string nullString="";
	set<string> m_brokenKeys;
	string s_brokenKeys;
	string inputKeys;
	cin>>s_brokenKeys;
	cin>>inputKeys;
	if(inputKeys.empty()){
		inputKeys=s_brokenKeys;
		s_brokenKeys="";
	}
	for(auto c:s_brokenKeys){ 
		m_brokenKeys.insert(nullString+(char)tolower(c));//如果c不大写字母，就不会改变
	}
	for(auto c:inputKeys){
		//set里面没有at函数,at是map里的
		/*
		try{
			if(!islower(c)){
				m_brokenKeys.at(nullString+'+');
			}
			m_brokenKeys.at(nullString+(char)tolower(c))
			cout<<c;
		}
		catch(out_of_range error){
			;
		}
		*/
		if(m_brokenKeys.find(nullString+(char)tolower(c))==m_brokenKeys.cend()){
			if((isupper(c))&&(m_brokenKeys.find(nullString+'+')!=m_brokenKeys.cend())){
				continue;
			}
			else{
				cout<<c;
			}
		}
	}
	cout<<endl;
	return 0;
}