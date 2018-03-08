#include <vector>
#include <string>
#include <queue>
#include <iostream>
#include <cstdio>
#include <set>
#include <cstring>
#include <algorithm>
using std::sort;
using std::fill;
using std::set;
using std::priority_queue;
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::flush;
using std::queue;
using std::max;
using std::min;
const int open_door=8*60*60;
const int shut_door=21*60*60;
const int max_customer=10010;
struct Customer{
	int arrive_time;
	int vip_flag;
	int need_time;
	int serve_time;
	int leave_time;
	int table_index;
	Customer(int arrive_time,int need_time,int vip_flag){
		this->arrive_time=arrive_time;
		this->need_time=need_time;
		this->vip_flag=vip_flag;
	}
};

bool
sort_cmp_arrive(const Customer &c1,const Customer &c2){
	return c1.arrive_time<c2.arrive_time;
}

bool
sort_cmp_serve(const Customer &c1,const Customer &c2){
	return c1.serve_time<c2.serve_time;
}

struct get_next_leave{
	bool
	operator() (const Customer *c1,const Customer *c2){
		if(c1->leave_time!=c2->leave_time){
			return c1->leave_time>c2->leave_time;
		}
		else if(c1->table_index!=c2->table_index){
			return c1->table_index>c2->table_index;
		}
		else{
			return c1->vip_flag<c2->vip_flag;
		}
	}
};

		

typedef priority_queue<Customer*,vector<Customer*> , get_next_leave > tableCon;

vector<Customer> customer_queue;

tableCon using_table;

set<int> has_come_vip_index;

set<int> vip_table_index;

bool hasusing[max_customer]={false};

void insert_using_table(tableCon &using_table,Customer* c,int customer_index,\
		int table_index,int last_leave_time,bool hasusing[]){
	int serve_time=max(last_leave_time,c->arrive_time);
	c->serve_time=serve_time;
	c->leave_time=c->serve_time+c->need_time;
	c->table_index=table_index;
	using_table.push(c);
	hasusing[customer_index]=true;
}



void insert_using_table(tableCon &using_table,Customer* c,int customer_index,\
		int table_index,int laset_leave_time,bool hasusing[]);

int main(){
	int customer_num;
	cin>>customer_num;
	int HH,MM,SS,need_time,vip_flag;
	for(int i=0;i<customer_num;++i){
		scanf("%d:%d:%d %d %d",&HH,&MM,&SS,&need_time,&vip_flag);
		if(need_time>120){
			need_time=120;
		}
		customer_queue.push_back(Customer(HH*60*60+MM*60+SS,need_time*60,vip_flag));
	}

	int table_num,vip_table_num;
	cin>>table_num>>vip_table_num;
	int temp_vip_table;
	for(int i=1;i<=vip_table_num;++i){
		cin>>temp_vip_table;
		vip_table_index.insert(temp_vip_table);
	}
	sort(customer_queue.begin(),customer_queue.end(),sort_cmp_arrive);

	//p_front执行第一个没有使用桌子的人
	//p_last指向最后一个排队的人
	int p_front=0;
	int p_last=0;
	int not_use=customer_num;
	//根据桌子的数目来选择初始队伍长度
	p_last=customer_num-1;
	queue<int > vip_queue;
	for(int i=p_front;i<=p_last;++i){
		if(customer_queue[i].vip_flag){
			vip_queue.push(i);
		}
	}
	//将桌子全部填满
	for(int i=1;i<=table_num;++i){
		//是vip桌子
/*
 * 
void insert_using_table(tableCon &using_table,Customer* c,int customer_index,\
		int table_index,int laset_leave_time,bool hasusing[]);
 */
		if(vip_table_index.find(i)!=vip_table_index.end()){
			if(!vip_queue.empty()){
				int vip=vip_queue.front();
				vip_queue.pop();
				if(hasusing[vip]==false){
					insert_using_table(using_table,&customer_queue[vip],vip,i,open_door,hasusing);
					not_use--;
					continue;
				}
			}
		}
		while(hasusing[p_front]!=false&&p_front<=p_last) ++p_front;
	
		insert_using_table(using_table,&customer_queue[p_front],p_front,i,open_door,hasusing);
		not_use--;
		++p_front;
	}

	while(not_use>0){
		Customer *front_index=using_table.top();
		using_table.pop();
		while()
	}

	int not_use=customer_num;

	return 0;
}
