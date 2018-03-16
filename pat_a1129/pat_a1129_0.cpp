#include <queue>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <map>
using std::map;
using std::vector;
using std::priority_queue;
using std::unordered_map;
using std::cin;
using std::cout;
using std::endl;


struct Item{
	int index;
	int count;
	Item(int index,int count){
		this->index=index;
		this->count=count;
	}
};

struct cmp{
	bool operator() (const Item &i1,const Item &i2){
		if(i1.count!=i2.count){
			return i1.count<i2.count;
		}
		else{
			return i1.index>i2.index;
		}
	}
};

int main(){
	map<int,int> history;
	priority_queue<Item,vector<Item>,cmp> recommand;

	int query_count;
	int temp;
	int maxReCount;
	cin>>query_count;
	cin>>maxReCount;
	for(int i=0;i<query_count;++i){
		cin>>temp;
		if(i!=0){
			for(auto it=history.begin();it!=history.end();++it){
				recommand.push(Item(it->first,it->second));					
			}
			int j=maxReCount;

			cout<<temp<<":";
			while(!recommand.empty()&&j!=0){
				--j;
				cout<<" "<<recommand.top().index;
				recommand.pop();
			}
			cout<<endl;
			while(!recommand.empty()){
				recommand.pop();
			}
		}
		else{
			;
		}
		history[temp]++;
	}
	return 0;
}
