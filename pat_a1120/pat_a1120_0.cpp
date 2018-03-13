#include <iostream>
#include <string>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;

int get_sum(string s){
	int sum=0;
	for(int i=(int)s.size()-1;i>=0;--i){
		sum+=(s[i]-'0');
	}
	return sum;
}

map<int,int> ans;

int main(){
	int count;
	cin>>count;
	string temp;
	for(int i=0;i<count;++i){
		cin>>temp;
		++ans[get_sum(temp)];
	}
	int len=ans.size();
	cout<<len<<endl;
	int counter=0;
	for(auto it=ans.begin();it!=ans.end();++it){
		cout<<it->first;
		++counter;
		if(counter!=len){
			cout<<" ";	
		}
		else{
			cout<<endl;
		}
	}
	return 0;
}
