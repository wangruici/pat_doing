#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <set>

using std::sort;
using std::max;
using std::priority_queue;
using std::queue;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::flush;
using std::set;

struct Customer{
	int arriving_time;
	int need_time;
	int serve_time;
	int leave_time;
	bool vip_flag;
	int table_index;
	Customer(int arriving_time,int need_time,bool vip_flag){
		this->arriving_time=arriving_time;
		this->need_time=need_time;
		this->vip_flag=vip_flag;
	}
};

bool sort_cmp(Customer &c1,Customer &c2){
	return c1.arriving_time<c2.arriving_time;
}

bool sort_cmp1(Customer &c1,Customer &c2){
	return c1.serve_time<c2.serve_time;
}

struct using_queue_cmp{
	bool operator () (Customer *c1,Customer *c2){
		if(c1->leave_time==c2->leave_time){
			if(c1->vip_flag==c2->vip_flag){
				return c1->table_index>c2->table_index;	
			}
			else{
				return c1->vip_flag<c2->vip_flag;
			}
		}
		else{
			return c1->leave_time>c2->leave_time;
		}
	}
};

priority_queue<Customer*,vector<Customer*>,using_queue_cmp> using_queue;

vector<Customer> customer_queue;

set<int> vip_table_index;
set<int> vip_customer_index;

const int maxn=110;
const int max_customer=10010;
const int max_using_table=2*60*60;
const int start_time=8*60*60;
const int end_time=21*60*60;

bool hasoccupied[maxn]={false};
bool hasin[max_customer]={false};
int notdeal;
void insert_using_queue(int table_index,int customer_index,int last_leave_time){
	int serve_time=max(last_leave_time,customer_queue[customer_index].arriving_time);
	customer_queue[customer_index].serve_time=serve_time;
	customer_queue[customer_index].table_index=table_index;
	customer_queue[customer_index].leave_time=serve_time+\
											  customer_queue[customer_index].need_time;
	hasin[customer_index]=true;
	hasoccupied[table_index]=true;
	using_queue.push(&customer_queue[customer_index]);
	--notdeal;
}
int main(){
	memset(hasoccupied,sizeof(hasoccupied),false);
	memset(hasin,sizeof(hasin),false);
	int customer_num;
	cin>>customer_num;
	int HH,MM,SS,need_time,vip_flag;
	int arriving_time;
	notdeal=customer_num;
	for(int i=0;i<customer_num;++i){
		scanf("%d:%d:%d %d %d",&HH,&MM,&SS,&need_time,&vip_flag);
		arriving_time=HH*60*60+MM*60+SS;
		if(arriving_time>end_time){
			continue;
		}
		need_time=need_time*60;
		if(need_time>max_using_table){
			need_time=max_using_table;
		}
		customer_queue.push_back(Customer(arriving_time,need_time,vip_flag));
	}
	sort(customer_queue.begin(),customer_queue.end(),sort_cmp);
	for(int i=0;i<(int)customer_queue.size();++i){
		if(customer_queue[i].vip_flag){
			vip_customer_index.insert(i);
		}
	}
	int table_num;
	int vip_table_num;
	cin>>table_num;
	cin>>vip_table_num;
	int temp_table_id;
	for(int i=0;i<vip_table_num;++i){
		cin>>temp_table_id;
		vip_table_index.insert(temp_table_id);
	}
	int index=0;
	//首先填满vip table
	for(auto i=vip_table_index.begin();i!=vip_table_index.end();++i){
		if(!vip_customer_index.empty()){
			insert_using_queue(*i,*(vip_customer_index.begin()),start_time);
			vip_customer_index.erase(*(vip_customer_index.begin()));
		}
		else{
			break;
		}
	}
	//再填满普通table
	for(int i=1;i<=table_num;++i){
		if(vip_table_index.find(i)!=vip_table_index.end()&&!vip_customer_index.empty()){
			continue;
		}
		if(hasoccupied[i]==true){
			continue;
		}
		while(index<customer_num&&hasin[index]==true) ++index;
		if(index<customer_num){
			insert_using_queue(i,index,start_time);
		}
		else{
			break;
		}
	}
	while(notdeal>0){
		Customer *front=using_queue.top();
		using_queue.pop();
		if(front->vip_flag){
			if(!vip_customer_index.empty()){
				insert_using_queue(front->table_index,*vip_customer_index.begin(),front->leave_time);
				vip_customer_index.erase(*vip_customer_index.begin());
			}
			else{
				while(index<customer_num&&hasin[index]==true) ++index;
				if(index<customer_num){
					insert_using_queue(front->table_index,index,front->leave_time);		
				}
			}
		}
		else{
			while(index<customer_num&&hasin[index]==true) ++index;
			if(index<customer_num){
				insert_using_queue(front->table_index,index,front->leave_time);		
			}
		}
	}
	sort(customer_queue.begin(),customer_queue.end(),sort_cmp1);
	int HH1,HH2,MM1,MM2,SS1,SS2;
	int di;
	for(int i=0;i<customer_num;++i){
		if(customer_queue[i].serve_time>end_time){
			continue;
		}
		else{
			HH1=customer_queue[i].arriving_time/60/60;
			MM1=customer_queue[i].arriving_time/60%60;
			SS1=customer_queue[i].arriving_time%60;
			printf("%02d:%02d:%02d ",HH1,MM1,SS1);
			HH2=customer_queue[i].serve_time/60/60;
			MM2=customer_queue[i].serve_time/60%60;
			SS2=customer_queue[i].serve_time%60;			
			printf("%02d:%02d:%02d ",HH2,MM2,SS2);
			di=customer_queue[i].serve_time-customer_queue[i].arriving_time;
			if(di%60>=30){
				di=di/60+1;
			}
			else{
				di=di/60;
			}
			printf("%d\n",di);
		}
	}

	return 0;
}
