#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
using std::vector;
using std::sort;

struct Ins{
	string name;
	int count;
	int total_score;
	int tScore;
	int aScore;
	int bScore;
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
	unordered_map<string,Ins> records;



	int total_count;
	cin>>total_count;
	string temp_name;
	string temp_ins;
	int temp_score;
	for(int i=0;i<total_count;++i){
		cin>>temp_name>>temp_score>>temp_ins;
		convertToLow(temp_ins);
		auto it=&records[temp_ins];
		it->name=temp_ins;
		it->count++;
		if(temp_name[0]=='B'){
			it->bScore+=temp_score;
		}
		else if(temp_name[0]=='A'){
			it->aScore+=temp_score;
		}
		else{
			it->tScore+=temp_score;
		}
	}
	vector<Ins*> ans;
	for(auto it=records.begin();it!=records.end();++it){
		it->second.total_score=(int)(it->second.aScore*1.0+it->second.bScore/1.5+it->second.tScore*1.5);
		ans.push_back(&(it->second));	
	}
	sort(ans.begin(),ans.end(),cmp);
	int nowRank=1;
	if(ans.size()==0){
		cout<<0<<endl;
		return 0;
	}
	int nowScore=ans[0]->total_score;
	int len=ans.size();
	cout<<len<<endl;
	for(int i=0;i<len;++i){
		int score=ans[i]->total_score;
		if(score<nowScore){
			nowRank=i+1;
			nowScore=score;
		}
		cout<<nowRank<<" "<<ans[i]->name<<" "<<nowScore<<" "<<ans[i]->count<<endl;

	}
	return 0;
}
