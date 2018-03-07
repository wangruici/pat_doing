#include <queue>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>

using std::max;
using std::string;
using std::fill;
using std::vector;
using std::priority_queue;
using std::sort;

struct Record{
	int begin_time;
	int end_time;
	int need_time;
	int window_index;
};
const int begin_time=8*60*60;
const int end_time=17*60*60;
bool cmp(Record &r1,Record &r2){
	return r1.begin_time<r2.begin_time;
}

struct priority_queue_cmp{
	bool operator()(Record* pr1,Record* pr2){
		return (pr1->end_time)>(pr2->end_time);
	}
};

int main(){
	vector<Record> records;
	int customer_num,window_num;
	int line_end_time[110];
	scanf("%d %d",&customer_num,&window_num);
	int HH,MM,SS;
	Record temp;
	int need_time;
	for(int i=0;i<customer_num;++i){
		scanf("%d:%d:%d %d",&HH,&MM,&SS,&need_time);
		temp.begin_time=HH*60*60+MM*60+SS;
		temp.need_time=need_time*60;
		if(temp.need_time>60*60){
			temp.need_time=60*60;
		}
		records.push_back(temp);
	}
	
	sort(records.begin(),records.end(),cmp);
	priority_queue<Record*,vector<Record*>,priority_queue_cmp> queueline;
	int p_index=0;
	fill(line_end_time,line_end_time+110,begin_time);
	for(int i=0;i<window_num&&p_index<customer_num;++i){
		records[p_index].window_index=i;
		records[p_index].end_time=max(line_end_time[i],records[i].begin_time)+records[p_index].need_time;
		line_end_time[i]=records[p_index].end_time;
		queueline.push(&records[p_index]);
		++p_index;

	}

	while(p_index<customer_num){
		Record* pr_front=queueline.top();
		queueline.pop();
		records[p_index].window_index=pr_front->window_index;
		records[p_index].end_time=max(line_end_time[pr_front->window_index],records[p_index].begin_time)+\
								  records[p_index].need_time;
		line_end_time[pr_front->window_index]=records[p_index].end_time;
		queueline.push(&records[p_index]);
		++p_index;
	}
	double all_time=0;
	double deal_cnt=0;
	for(int i=0;i<customer_num;++i){
		if(records[i].begin_time>end_time){
			;	
		}
		else{
			all_time+=(records[i].end_time-records[i].begin_time-records[i].need_time);
			deal_cnt++;
		}
	}
	double ans=all_time/60/deal_cnt;
	printf("%.1lf\n",ans);
	return 0;

}
