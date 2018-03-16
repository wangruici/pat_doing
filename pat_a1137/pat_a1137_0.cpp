#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::unordered_map;
using std::vector;
using std::string;
using std::sort;
using std::round;
struct Record{
	string name;
	int g_final;
	int g_mid;
	int g;
	int gp;
	Record(){
		name="";
		g_final=-1;
		g_mid=-1;
		g=-1;
		gp=-1;
	}
};

bool cmp(Record *r1,Record *r2){
	if(r1->g!=r2->g){
		return r1->g>r2->g;
	}
	else{
		return r1->name<r2->name;
	}
}

unordered_map<string,Record> stu;

int main(){
	int gp_num,g_mid_num,g_final_num;
	cin>>gp_num>>g_mid_num>>g_final_num;
	string name;
	for(int i=0;i<gp_num;++i){
		cin>>name;
		stu[name].name=name;
		cin>>stu[name].gp;
	}
	for(int i=0;i<g_mid_num;++i){
		cin>>name;
		cin>>stu[name].g_mid;
		stu[name].name=name;
	}
	for(int i=0;i<g_final_num;++i){
		cin>>name;
		cin>>stu[name].g_final;
		stu[name].name=name;
	}
	vector<Record*> records;
	for(auto it=stu.begin();it!=stu.end();++it){
		if(it->second.g_mid>it->second.g_final){
			it->second.g=round(it->second.g_mid*0.4+it->second.g_final*0.6);
		}
		else{
			it->second.g=it->second.g_final;
		}
		records.push_back(&(it->second));	
	}
	sort(records.begin(),records.end(),cmp);
	for(int i=0;i<(int)records.size();++i){
		if(records[i]->gp>=200&&records[i]->g>=60){
			cout<<records[i]->name<<" "<<records[i]->gp<<" "<<\
				records[i]->g_mid<<" "<<records[i]->g_final<<" "<<\
				records[i]->g<<endl;
		}
	}
	return 0;
}
