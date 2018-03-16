#include <iostream>
#include <set>
#include <unordered_map>
using std::unordered_map;
using std::cin;
using std::cout;
using std::endl;
using std::set;


struct Record{
	int cnt;
	int index;
	Record(int _index,int _cnt){
		cnt=_cnt;
		index=_index;
	}
	Record()=default;
	bool operator< (const Record &r) const{
		if(this->cnt!=r.cnt){
			return this->cnt>r.cnt;
		}
		else{
			return this->index<r.index;
		}
	}
}r;

int main(){
	unordered_map<int,int> history;
	set<Record> records;
	int query_num,count;
	cin>>query_num>>count;
	int temp;
	for(int i=0;i<query_num;++i){
		cin>>temp;
		if(i){
			cout<<temp<<":";
			auto it=records.begin();
			for(int j=count;j>0&&it!=records.end();--j,++it){
				cout<<" "<<it->index;	
			}
			cout<<endl;
		}
		else{
			;
		}
		r.cnt=history[temp];
		r.index=temp;
		++history[temp];
		auto it=records.find(r);
		++r.cnt;
		if(it!=records.end()){
			records.erase(it);
			records.insert(r);
		}
		else{
			records.insert(r);
		}


	}
	return 0;
}
