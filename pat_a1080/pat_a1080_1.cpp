#include <cstdio>
#include <algorithm>

using std::sort;

struct Student{
	int GE,GI,sum;
	int r,stuID;
	int cho[6];
}stu[40010];

struct School{
	int quota;
	int stuNum;
	int id[40010];
	int lastAdmit;
}sch[110];

bool cmpStu(Student a,Student b){
	if(a.sum!=b.sum) return a.sum>b.sum;
	else return a.GE>b.GE;
}

bool cmpID(int a,int b){
	return stu[a].stuID<stu[b].stuID;
}

int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);//考生人数，学校数，及每人可申请的学校数
	for(int i=0;i<m;++i){
		scanf("%d",&sch[i].quota);
		sch[i].stuNum=0;
		sch[i].lastAdmit=-1;
	}
	for(int i=0;i<n;++i){
		stu[i].stuID=i;
		scanf("%d%d",&stu[i].GE,&stu[i].GI);
		stu[i].sum=stu[i].GE+stu[i].GI;
		for(int j=0;j<k;++j){
			scanf("%d",&stu[i].cho[j]);
		}
	}

	sort(stu,stu+n,cmpStu);//给n位考生按成绩排序
	for(int i=0;i<n;++i){//计算每个考生的排名
		if(i>0&&stu[i].sum==stu[i-1].sum&&stu[i].GE==stu[i-1].GE){
			stu[i].r=stu[i-1].r;
		}
		else{
			stu[i].r=i;
		}
	}
	//判断录取
	for(int i=0;i<n;++i){
		for(int j=0;j<k;++j){
			int choice=stu[i].cho[j];
			int num=sch[choice].stuNum;
			int last=sch[choice].lastAdmit;
			//如果人数未满或该学校最后一个录取的考生与当前考生的排名相同
			if(num<sch[choice].quota||(last!=-1&&stu[i].r==stu[last].r)){
				sch[choice].id[num]=i;
				sch[choice].lastAdmit=i;
				sch[choice].stuNum++;
				break;
			}
		}
	}

	for(int i=0;i<m;++i){
		if(sch[i].stuNum>0){
			sort(sch[i].id,sch[i].id+sch[i].stuNum,cmpID);
			for(int j=0;j<sch[i].stuNum;++j){
				printf("%d",stu[sch[i].id[j]].stuID);
				if(j<sch[i].stuNum-1){
					printf(" ");
				}
			}
		}
		printf("\n");
	}
	return 0;
}



















