#include <queue>
#include <cstdio>
#include <vector>
using std::vector;
using std::queue;





struct Person{
	int waiting_time;
	int done_time;
	int index;
	bool deal;
	Person(int _waiting_time,int _index){
		this->waiting_time=_waiting_time;
		this->done_time=0;
		this->index=_index;
		this->deal=false;
	}
};
const int max_person_num=1010;
const int max_window_num=20;
const int begin_time=8*60;
const int end_time=17*60;
vector<Person> people;

queue<Person*> windows[max_window_num];
int query[max_person_num];


/*-------------------------------------------------------------------------*/
void print_state(int num,int now_time){
	printf("~~~~~~~~~~~~~~~~~~\n");
	printf("now_time:%d\n",now_time);
	for(int i=0;i<num;++i){
		if(!windows[i].empty()){
			printf("%d:%d\n",windows[i].front()->index,windows[i].front()->waiting_time);
		}
	}
	printf("~~~~~~~~~~~~~~~~~~\n");
}
/*-------------------------------------------------------------------------*/
int main(){
	int window_num,capacity,customer_num,querry_num;
	scanf("%d %d %d %d",&window_num,&capacity,&customer_num,&querry_num);
	int temp;
	for(int i=0;i<customer_num;++i){
		scanf("%d",&temp);
		people.push_back(Person(temp,i));
	}
	for(int i=0;i<querry_num;++i){
		scanf("%d",&temp);
		query[i]=temp-1;
	}

	int index=0;
	int now_time=begin_time;
	for(int i=0;i<capacity;++i){
		for(int j=0;j<window_num&&index<customer_num;++j){
			windows[j].push(&people[index]);
			++index;
		}	
	}
	now_time=begin_time;
	int other=customer_num;
	while(other>0&&now_time<end_time){
		int min_time=0x3fffffff;
		int i_index=-10;
		for(int i=0;i<window_num;++i){
			if(!windows[i].empty()){
				if(windows[i].front()->waiting_time<min_time){
					min_time=windows[i].front()->waiting_time;
					i_index=i;
				}
			}
		}
		if(i_index!=-10){
			now_time+=min_time;
		}
		else{
			break;
		}
		for(int i=0;i<window_num;++i){
			if(!windows[i].empty()){
				windows[i].front()->waiting_time=(windows[i].front()->waiting_time-min_time);
				windows[i].front()->deal=true;
				if((windows[i].front()->waiting_time)==0){
					windows[i].front()->done_time=now_time;
					windows[i].pop();
					--other;
					if(index<customer_num){
						windows[i].push(&people[index]);
						++index;
					}
				}
			}
		}
		//print_state(2,now_time);
	}
	for(int i=0;i<querry_num;++i){
		if(people[query[i]].done_time==0&&people[query[i]].deal==false){
			printf("Sorry\n");
		}
		else{
			if(people[query[i]].done_time!=0){
				printf("%02d:%02d\n",people[query[i]].done_time/60,people[query[i]].done_time%60);
			}
			else{
				printf("%02d:%02d\n",(now_time+people[query[i]].waiting_time)/60,(now_time+people[query[i]].waiting_time)%60);	
			}
		}
	}
}
