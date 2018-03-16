#include <vector>
#include <set>
#include <iostream>
#include <unordered_set>

using std::unordered_set;
using std::vector;
using std::set;
using std::cin;
using std::cout;
using std::endl;
using std::flush;
const int maxn=10010;
vector<int> graph[maxn];
unordered_set<int> query;
int main(){
	int point_num,road_num;
	cin>>point_num>>road_num;
	int id1,id2;
	for(int i=0;i<road_num;++i){
		cin>>id1>>id2;
		graph[id1].push_back(id2);
		graph[id2].push_back(id1);
	}
	int query_num;
	cin>>query_num;
	int temp;
	int num;
	for(int i=0;i<query_num;++i){
		cin>>temp;
		int flag=true;
		for(int j=0;j<temp;++j){
			cin>>num;
			query.insert(num);
		}

			for(int k=0;k<point_num;++k){
				if(!graph[k].empty()){
					if(query.find(k)==query.end()){
						for(int l=0;l<(int)graph[k].size();++l){
							if(query.find(graph[k][l])==query.end()){
								flag=false;
								break;
							}
						}
					}
				}
				if(!flag){
					break;
				}
			}
		if(flag){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
		query.clear();
	}
	return 0;
}
