#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
#include <algorithm>
using std::ceil;
using std::unordered_set;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(){
	int total_num;
	int skip_num;
	int index;
	cin>>total_num>>skip_num>>index;
	unordered_set<string> winer;
	string name;
	int p=index;
	for(int i=1;i<=total_num;++i){
		cin>>name;
		if(i==p&&winer.find(name)==winer.end()){
			cout<<name<<endl;
			winer.insert(name);
			p+=skip_num;
		}
		else if(i==p&&winer.find(name)!=winer.end()){
			++p;
		}
		else{
			;
		}
	}
	if(winer.empty()){
		cout<<"Keep going..."<<endl;
	}
	return 0;
}
