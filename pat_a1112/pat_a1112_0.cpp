#include <cstring>
#include <string>
#include <set>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::flush;
using std::string;
using std::set;

const int judge_len=10+26+1+10;
bool judge_array[judge_len];
bool has_printed[judge_len];
int convert(char c){
	int result;
	if(c>='0'&&c<='9'){
		result=c-'0';	
	}
	else if(c>='a'&&c<='z'){
		result=c-'a'+10;
	}
	else{
		result=c-'_'+26+10;
	}
	return result;
}

int main(){
	memset(judge_array,true,sizeof(judge_array));
	memset(has_printed,false,sizeof(has_printed));
	int k;
	cin>>k;
	string s;
	cin>>s;
	int s_len=(int)s.size();
	for(int i=0;i<s_len;++i){
		int count=1;
		int j=i+1;
		while(j<s_len&&s[j]==s[i]){
			++count;
			++j;
		}
		if(count%k!=0){
			judge_array[convert(s[i])]=false;
		}
		i=j-1;
	}
	for(int i=0;i<s_len;++i){
		if(judge_array[convert(s[i])]==true&&has_printed[convert(s[i])]==false){
			i=i+k-1;
			cout<<s[i];
			has_printed[convert(s[i])]=true;
		}
		else{
			continue;
		}
	}
	cout<<endl;
	for(int i=0;i<s_len;++i){
		if(judge_array[convert(s[i])]==false){
			cout<<s[i];
		}
		else{
			i=i+k-1;
			cout<<s[i];
		}
	}
	cout<<endl;
	return 0;
}
