#include <set>
#include <cstdio>
using std::set;

set<int> int_set[50];

int main(){
	int int_set_num;
	scanf("%d",&int_set_num);
	int count=0;
	int temp;
	for(int i=0;i<int_set_num;++i){
		scanf("%d",&count);
		for(int j=0;j<count;++j){
			scanf("%d",&temp);
			int_set[i].insert(temp);
		}
	}
	int query_num,i1,i2;
	double pro;
	int distinct;
	int common;
	scanf("%d",&query_num);
	for(int i=0;i<query_num;++i){
		scanf("%d %d",&i1,&i2);
		--i1;--i2;		
		distinct=(int)int_set[i1].size();
		common=0;
		for(auto it=int_set[i2].begin();it!=int_set[i2].end();++it){
			if(int_set[i1].find(*it)!=int_set[i1].end()){
				++common;	
			}
			else{
				++distinct;
			}
		}
		pro=common*1.0/distinct*1.0;
		printf("%.01lf%\n",pro*100);
	}
	return 0;
}
