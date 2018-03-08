#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
int count_n(int num);
string get_result(string s,int num);
int main(){
	string s;
	getline(cin,s);
	int n=count_n((int)s.size());
	string result=get_result(s,n);
	cout<<result<<endl;
	return 0;
}

int count_n(int num){
	int max_k=-1;
	for(int i=3;i<=num;++i){
		for(int k=0;k<=i;++k){
			if(((2*k+i-2)==num)&&(max_k<k)){
				max_k=k;
			}
		}
	}
	return max_k;
}

string get_result(string s,int num){
	int space_num=(int)s.size()-2*num;
	int len=(int)s.size();
	string result="";
	string space=" ";
	for(int i=0;i<num-1;++i){
		result+=s[i];
		for(int j=0;j<space_num;++j){
			result+=space;
		}
		result+=s[len-1-i];
		result+='\n';
	}
	for(int i=num-1;i<space_num+num+1;++i){
		result+=s[i];
	}
	return result;
}
