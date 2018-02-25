#include <cstdio>
#include <algorithm>
#include <vector>
using std::sort;
using std::vector;

struct Student{
	int GE,GI,sum;
	int id,rank;
	int cho[6];
}stu[40010];

struct School{
	int quota;//招生人数总额度
	vector<int> ids;//实际招生的编号
	int shengyu;
	int lastRank;
}sch[110];



bool cmpStu(Student a,Student b){
	if(a.sum!=b.sum){
		return a.sum>b.sum;
	}
	else
		return a.GE>b.GE;
}
bool cmpId(int a,int b){
	return a<b;
}

int main(){
	int num_appli,num_sch,num_cho;
	scanf("%d %d %d",&num_appli,&num_sch,&num_cho);
	for(int i=0;i<num_sch;++i){
		scanf("%d",&sch[i].shengyu);
		sch[i].quota=sch[i].shengyu;
		sch[i].lastRank=-1;
	}
	for(int i=0;i<num_appli;++i){
		scanf("%d %d",&stu[i].GE,&stu[i].GI);
		stu[i].sum=stu[i].GE+stu[i].GI;
		for(int j=0;j<num_cho;++j){
			scanf("%d",&stu[i].cho[j]);
		}
		stu[i].id=i;
	}
	sort(stu,stu+num_appli,cmpStu);
	//计算考生名次
	stu[0].rank=0;
	for(int i=1;i<num_appli;++i){
		if((stu[i-1].sum!=stu[i].sum)||stu[i-1].GE!=stu[i].GE){
			stu[i].rank=i;
		}
		else{
			stu[i].rank=stu[i-1].rank;
		}
	}
	int schoolId;
	//根据考生名次写入学校;
	for(int i=0;i<num_appli;++i){
		for(int j=0;j<num_cho;++j){
			schoolId=stu[i].cho[j];
			if((sch[schoolId].shengyu>0)||(stu[i].rank==sch[schoolId].lastRank)){
				sch[schoolId].ids.push_back(stu[i].id);
				--(sch[schoolId].shengyu);
				sch[schoolId].lastRank=stu[i].rank;
				break;
			}
		}
	}

	//输出成绩
	int idsSize;
	for(int i=0;i<num_sch;++i){
		idsSize=sch[i].ids.size();
		if(idsSize<=0){
			printf("\n");
		}
		else{
			sort(sch[i].ids.begin(),sch[i].ids.end(),cmpId);
			for(int j=0;j<idsSize-1;++j){
				printf("%d ",sch[i].ids[j]);
			}
			printf("%d",sch[i].ids[idsSize-1]);
			if(i!=num_sch-1){	
				printf("\n");
			}
		}
	}

	return 0;
}


