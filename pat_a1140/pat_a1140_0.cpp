#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using std::cin;
using std::cout;
using std::endl;
using std::string;
char m[1000];
string getNext(string s){
	int len=s.size();
	int i=0;
	int counter=0;
	string result="";
	char nowChar;
	while(i<len){
		nowChar=s[i];
		while(i<len&&s[i]==nowChar){
			++i;
			++counter;	
		}
		sprintf(m,"%d",counter);
		counter=0;
		result+=nowChar;
		result+=m;
	}
	return result;
}

int main(){
	int begin;
	int time;
	string result="";

	cin>>begin>>time;
	sprintf(m,"%d",begin);
	result+=m;
	for(int i=1;i<time;++i){
		result=getNext(result);
	}
	cout<<result<<endl;
	return 0;
}
