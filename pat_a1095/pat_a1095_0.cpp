#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>

using std::string;
using std::map;
using std::sort;
using std::max;


const int maxQu=80010;
const int maxRe=10010;

struct Car{
	char id[8];
	int time;
	bool status;
	Car(){
		status=false;
		time=0;
		strcpy(id,"\0");
	}
	Car(char* id,int time,bool status){
		strcpy(this->id,id);
		this->time=time;
		this->status=status;
	}
	Car& operator=(const Car& c){
		strcpy(this->id,c.id);
		this->time=c.time;
		this->status=c.status;
		return *this;
	}
};

bool cmpByIdAndTime(Car a,Car b){
	//如果不相等
	if(strcmp(a.id,b.id)) return strcmp(a.id,b.id)<0;
	else return a.time<b.time; 
}

bool cmpByTime(Car a,Car b){
	return a.time<b.time;
}

map<string,int> parkTime;
int main(){
	int numQ,numR;
	scanf("%d %d",&numR,&numQ);
	Car* cars_record=new Car[numR];
	Car* valid_record=new Car[numR];
	int hh,mm,ss;
	char status[4];
	//读入信息；
	for(int i=0;i<numR;++i){
		scanf("%s %d:%d:%d %s",cars_record[i].id,&hh,&mm,&ss,status);
		cars_record[i].time=hh*3600+mm*60+ss;
		if(!strcmp(status,"in")){
			cars_record[i].status=true;
		}
	}
	//计算信息有效性
	sort(cars_record,cars_record+numR,cmpByIdAndTime);
	int numV=0;
	int inTime;
	int maxInTime=0;
	for(int i=0;i<numR-1;++i){
		//是同一辆车的记录，并且先是in后是out
		if((!strcmp(cars_record[i].id,cars_record[i+1].id))&&
			(cars_record[i].status==true)&&
			(cars_record[i+1].status==false)){
			valid_record[numV++]=cars_record[i];
			valid_record[numV++]=cars_record[i+1];
			inTime=cars_record[i+1].time-cars_record[i].time;
			parkTime[cars_record[i].id]+=inTime;
			maxInTime=max(maxInTime,parkTime[cars_record[i].id]);
		}
	}
	//按照时间进行排序，准备输出
	sort(valid_record,valid_record+numV,cmpByTime);
	//查询是按照顺序进行查询的
	int qTime;
	int now=0;
	int inCars=0;
	for(int i=0;i<numQ;++i){
		scanf("%d:%d:%d",&hh,&mm,&ss);
		qTime=hh*3600+mm*60+ss;
		while(now<numV&&valid_record[now].time<=qTime){
			if(valid_record[now].status==true){
				++inCars;
			}
			else{
				--inCars;
			}
			++now;
		}
		printf("%d\n",inCars);

	}
	map<string,int>::iterator it;
	for(it=parkTime.begin();it!=parkTime.end();++it){
		if(it->second==maxInTime){
			printf("%s ",it->first.c_str());
		}
	}
		printf("%02d:%02d:%02d",maxInTime/3600,maxInTime%3600/60,maxInTime%60);
	delete []cars_record;
	delete []valid_record;
	return 0;
}









