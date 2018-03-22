#include <iostream>
#include <string>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::ios;
void print_result(string result){
	for(int i=0;i<(int)result.size();++i){
		switch(result[i]){
			case '0':
				cout<<"zero";
				break;
			case '1':
				cout<<"one";
				break;
			case '2':
				cout<<"two";
				break;
			case '3':
				cout<<"three";
				break;
			case '4':
				cout<<"four";
				break;
			case '5':
				cout<<"five";
				break;
			case '6':
				cout<<"six";
				break;
			case '7':
				cout<<"seven";
				break;
			case '8':
				cout<<"eight";
				break;
			case '9':
				cout<<"nine";
				break;
		}
		if(i!=(int)result.size()-1){
			cout<<" ";
		}
		else{
			cout<<endl;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	string num_s;
	cin>>num_s;
	int sum=0;
	for(int i=0;i<(int)num_s.size();++i){
		sum+=(num_s[i]-'0');
	}
	stringstream convert;
	convert<<sum;
	string result;
	convert>>result;
	print_result(result);
	return 0;
}
