#include <set>
#include <map>
#include <iostream>
#include <string>
using std::string;
using std::set;
using std::map;
using std::cin;
using std::cout;
using std::endl;

int main(){
	int couple_count;
	cin>>couple_count;
	string id1,id2;
	map<string,string> couple_pair;
	set<string> ans;
	set<string> party;
	for(int i=0;i<couple_count;++i){
		cin>>id1>>id2;
		couple_pair[id1]=id2;
		couple_pair[id2]=id1;
	}
	int total_num;
	cin>>total_num;
	for(int i=0;i<total_num;++i){
		cin>>id1;
		party.insert(id1);
	}

	for(auto it=party.begin();it!=party.end();++it){
		if(couple_pair.find(*it)==couple_pair.end()||party.find(couple_pair[*it])==party.end()){
			ans.insert(*it);
		}
	}
	cout<<ans.size()<<endl;
	int len=ans.size();
	int counter=0;
	for(auto it=ans.begin();it!=ans.end();++it){
		cout<<*it;
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
