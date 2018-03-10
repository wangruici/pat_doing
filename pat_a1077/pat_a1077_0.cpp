#include <string>
#include <iostream>
#include <algorithm>

using std::reverse;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
	int num;
	cin>>num;
	cin.get();
	string message[101];
	int minLen=9999999;
	for(int i=0;i<num;++i){
		getline(cin,message[i]);
		if(minLen>(int)message[i].size()){
			minLen=message[i].size();
		}
	}
	//转置
	for(int i=0;i<num;++i){
		reverse(message[i].begin(),message[i].end());
	}
	int suffix_len=0;
	for(int j=0;j<minLen;++j){
		bool ox=false;
		char c=message[0][j];
		for(int i=0;i<num;++i){
			if(message[i][j]!=c){
				ox=true;
				break;
			}
		}
		if(ox){
			break;
		}
		++suffix_len;
	}
	string suffix_word=message[0].substr(0,suffix_len);
	if(suffix_word==""){
		suffix_word="nai";
	}
	else{
		reverse(suffix_word.begin(),suffix_word.end());
	}
	cout<<suffix_word<<endl;
	return 0;
}
