#include <string>
#include <iostream>
#include <vector>
#include <ctype.h>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;

//只能判断是否是一个合法的数字
bool isLeagle(string s){
	bool flag=true;
	int pos_point=-1;
	int point_num=0;
	int len=s.size();
	for(int i=0;i<(int)s.size();++i){
		if(!isdigit(s[i])&&s[i]!='.'&&s[i]!='-'){
			flag=false;
			break;
		}
		else if(s[i]=='.'){
			++point_num;
			if(point_num>1){
				flag=false;
				break;
			}
			else{
				pos_point=i;
			}
		}
		else if(s[i]=='-'&&i!=0){
			flag=false;
		}
		else{
			continue;
		}
	}
	if(point_num>0&&len-pos_point-1>2){
		flag=false;
	}
	if(len==1&&s[0]=='-'){
		flag=false;
	}
	if(pos_point<1||pos_point==len-1){
		flag=false;
	}
	return flag;
}
vector<float> nums;

int main(){
	int count;
	int leagle_count=0;
	string temp;
	
	cin>>count;
	cin.get();
	for(int i=0;i<count;++i){
		cin>>temp;
		if(!isLeagle(temp)){
			cout<<"ERROR: "<<temp<<" is not a leagal number"<<endl;
		}
		
	}
}
