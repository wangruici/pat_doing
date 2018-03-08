#include <string>
#include <vector>
#include <iostream>
#include <utility>

using std::pair;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

bool convert(string &s){
	bool flag=false;
	for(int i=0;i<(int)s.size();++i){
		switch(s[i]){
			case '1':
				s[i]='@';
				flag=true;
				break;
			case '0':
				s[i]='%';
				flag=true;
				break;
			case 'l':
				s[i]='L';
				flag=true;
				break;
			case 'O':
				s[i]='o';
				flag=true;
				break;
		}
	}
	return flag;
}

int main(){
	int get_num;
	cin>>get_num;
	int give_num=0;
	string team;
	string code;
	vector<pair<string,string> > result;
	for(int i=0;i<get_num;++i){
		cin>>team>>code;
		bool flag=convert(code);
		if(flag){
			result.push_back(pair<string,string>(team,code));
			++give_num;
		}

	}
	if(!give_num){
		if(get_num<=1){
		cout<<"There is "<<get_num<<" account and no account is modified"<<\
			endl;
		}
		else{
		cout<<"There are "<<get_num<<" accounts and no account is modified"<<\
			endl;
		}
		return 0;
	}
	cout<<give_num<<endl;
	for(int i=0;i<give_num;++i){
		cout<<result[i].first<<" "<<result[i].second<<endl;
	}

	return 0;
}
