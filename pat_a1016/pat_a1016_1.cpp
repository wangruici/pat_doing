#include <cstdio>
#include <cstring>
#include <algorithm>

//原来希望通过修改get_ans函数，来实现提升速度60倍，但上交代码后发现没有速度提升
//同时，没有办法通过最后一个测试点，很伤心

using std::sort;

const int maxn=1010;
int toll[25];

struct Record{
	char name[25];
	int month,dd,hh,mm;
	bool status;//status==true记为on-line,否则记为off-line;
}rec[maxn],temp;//接受记录

bool cmp(Record a,Record b){
	int s=strcmp(a.name,b.name);
	//如果用户名不同则按用户名排序
	if(s!=0) return s<0;
	//否则按月来排序
	else if(a.month!=b.month) return a.month<b.month;
	//否则按照天排序
	else if(a.dd!=b.dd) return a.dd<b.dd;
	else if(a.hh!=b.hh) return a.hh<b.hh;
	else return a.mm<b.mm;
}


//计算话费的函数，使用的是一分钟一分钟计时的方法，每增加一分钟计算一次
void get_ans(int on,int off,int& time,int& money){
	temp=rec[on];
	while(temp.dd<rec[off].dd||temp.hh<rec[off].hh||temp.mm<rec[off].mm){
		time++;
		money+=toll[temp.hh];//话费增加toll[temp.hh]
		temp.mm++;//当前时间增加1min
		if(temp.mm>=60){
			temp.mm=0;
			temp.hh++;
		}
		if(temp.hh>=24){
			temp.hh=0;
			temp.dd++;
		}
	}
}

void get_ans2(int on,int off,int& time,int& money){
	temp=rec[on];
	int dd_minus=rec[off].dd-temp.dd;//一定大于等于零
	int hh_minus=rec[off].hh-temp.hh;//有可能小于零
	int mm_minus=rec[off].mm-temp.mm;//有可能小于零
	time=dd_minus*24*60+hh_minus*60+mm_minus;//化为分钟数的时间
	int temp_time=time;
	money=(60-temp.mm)*toll[temp.hh];
	temp_time=temp_time-(60-temp.mm);
	int i=1;
	while(temp_time-60>=0){
		money=money+toll[(temp.hh+i)%24]*60;
		++i;
		temp_time=temp_time-60;
	}
	money=money+rec[off].mm*toll[rec[off].hh];

}


int main(){
	for(int i=0;i<24;++i){
		scanf("%d",&toll[i]);
	}
	int n;
	scanf("%d",&n);
	char line[10];//临时存放on-line或off-line的输入
	for(int i=0;i<n;++i){
		scanf("%s",rec[i].name);
		scanf("%d:%d:%d:%d",&rec[i].month,&rec[i].dd,&rec[i].hh,&rec[i].mm);
		scanf("%s",line);
		if(strcmp(line,"on-line")==0){
			rec[i].status=true;
		}else{
			rec[i].status=false;
		}
	}
	sort(rec,rec+n,cmp);//排序
	int on=0,off,next;//on 和off为配对的两条记录,next为下一个用户
	while(on<n){
		int needPrint=0;
		next=on;
		while(next<n&&strcmp(rec[next].name,rec[on].name)==0){
			if(needPrint==0&&rec[next].status==true){
				needPrint=1;
			}else if(needPrint==1&&rec[next].status==false){
				needPrint=2;//如果在on之后找到了off,置needPrint为2
			}
			next++;//next自增，直到找到不同的名字
		}
		if(needPrint<2){//始终没有找到配对
			on=next;
			continue;
		}
		int AllMoney=0;//总共花费的钱
		printf("%s %02d\n",rec[on].name,rec[on].month);
		while(on<next){
			while(on<next-1&&!(rec[on].status==true&&rec[on+1].status==false)){
				on++;//直到找到连续的on-line和off-line
			}
			off=on+1;
			if(off==next){
				on=next;
				break;
			}
			printf("%02d:%02d:%02d ",rec[on].dd,rec[on].hh,rec[on].mm);
			printf("%02d:%02d:%02d ",rec[off].dd,rec[off].hh,rec[off].mm);
			int time=0,money=0;
			get_ans2(on,off,time,money);
			AllMoney+=money;
			printf("%d $%.2f\n",time,money/100.0);
			on=off+1;
		}
		printf("Total amount: $%.2f\n",AllMoney/100.0);
	}
	return 0;
}