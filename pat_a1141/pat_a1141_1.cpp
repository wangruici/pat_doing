#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
using std::vector;
using std::sort;
using std::map;

struct Ins{
	string name;
	int count;
	double total_score;
};

void convertToLow(string &s){
	for(int i=0;i<(int)s.size();++i){
		s[i]=tolower(s[i]);
	}
	return;
}
bool cmp(Ins *i1,Ins *i2){
	if(i1->total_score!=i2->total_score){
		return i1->total_score>i2->total_score;
	}
	else if(i1->count!=i2->count){
		return i1->count<i2->count;
	}
	else{
		return i1->name<i2->name;
	}
}

int main(){
	map<string,Ins> records;



	int total_count;
	cin>>total_count;
	string temp_name;
	string temp_ins;
	double temp_score;
	for(int i=0;i<total_count;++i){
		cin>>temp_name>>temp_score>>temp_ins;
		convertToLow(temp_ins);
		auto it=&records[temp_ins];
		it->name=temp_ins;
		it->count++;
		if(temp_name[0]=='B'){
			it->total_score+=temp_score/1.5;
		}
		else if(temp_name[0]=='A'){
			it->total_score+=temp_score*1.0;
		}
		else{
			it->total_score+=temp_score*1.5;
		}
	}
	vector<Ins*> ans;
	for(auto it=records.begin();it!=records.end();++it){
		ans.push_back(&(it->second));	
	}
	sort(ans.begin(),ans.end(),cmp);
	int nowRank=1;
	int nowScore=ans[0]->total_score;
	int len=ans.size();
	cout<<len<<endl;
	for(int i=0;i<len;++i){
		int score=(int)ans[i]->total_score;
		if(score<nowScore){
			nowRank=i+1;
			nowScore=score;
		}
		cout<<nowRank<<" "<<ans[i]->name<<" "<<nowScore<<" "<<ans[i]->count<<endl;

	}
	return 0;
}
