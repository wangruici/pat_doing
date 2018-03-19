#include <unordered_set>
#include <iostream>

using std::unordered_set;
using std::cin;
using std::cout;
using std::endl;

const int maxn=210;

unordered_set<int> graph[maxn];

unordered_set<int> intersection(const unordered_set<int> &s1,const unordered_set<int> &s2){
	unordered_set<int> ans;
	for(auto it=s1.begin();it!=s1.end();++it){
		if(s2.find(*it)!=s2.end()){
			ans.insert(*it);	
		}
	}
	return ans;
}

int main(){
	int point_count,road_count;
	cin>>point_count>>road_count;
	int temp1,temp2;
	for(int i=1;i<=point_count;++i){
		graph[i].insert(i);
	}
	for(int i=1;i<=road_count;++i){
		cin>>temp1>>temp2;
		graph[temp1].insert(temp2);
		graph[temp2].insert(temp1);
	}
	int query_num;
	cin>>query_num;
	int temp;
	unordered_set<int> maxc;
	unordered_set<int> sequence;
	unordered_set<int> ans;
	for(int i=0;i<query_num;++i){
		cin>>temp;
		for(int j=0;j<temp;++j){
			cin>>temp1;
			sequence.insert(temp1);
		}
		if(temp==0){
			cout<<"Not a Clique"<<endl;
			return 0;
		}
		maxc=graph[*sequence.begin()];
		for(auto it=sequence.begin();it!=sequence.end();++it){
			maxc=intersection(graph[*it],maxc);
		}
		ans=intersection(maxc,sequence);	
		if(ans.size()<sequence.size()){
			cout<<"Not a Clique"<<endl;
		}
		else if(maxc.size()>sequence.size()){
			cout<<"Not Maximal"<<endl;
		}
		else{
			cout<<"Yes"<<endl;
		}
		ans.clear();
		maxc.clear();	
		sequence.clear();
	}
	
}
