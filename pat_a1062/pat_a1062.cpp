#include <cstdio>
#include <cstring>
#include <algorithm>

using std::sort;

struct Student{
	char id[10];
	int de,cai,sum;//德分，才分及总分
	int flag;//考生类别：第1类-第5类
}stu[100010];

bool cmp(Student a,Student b){
	if(a.flag!=b.flag) return a.flag<b.flag;//类别小的在前
	else if(a.sum!=b.sum) return a.sum>b.sum;//类别相同时，总分大的在前
	else if(a.de!=b.de) return a.de>b.de;//总分相同时，德育分大的在前
	else return strcmp(a.id,b.id)<0;//德育分相同时，准考证号小的在前面
}

int main(){
	int n,L,H;
	scanf("%d %d %d",&n,&L,&H);
	int m=n;//m为及格人数
	for(int i=0;i<n;++i){
		scanf("%s %d %d",stu[i].id,&stu[i].de,&stu[i].cai);
		stu[i].sum=stu[i].de+stu[i].cai;
		if(stu[i].de<L||stu[i].cai<L){
			stu[i].flag=5;
			m--;//及格人数减1
		}
		else if(stu[i].de>=H&&stu[i].cai>=H) stu[i].flag=1;
		else if(stu[i].de>=H&&stu[i].cai<H) stu[i].flag=2;
		else if(stu[i].de>=stu[i].cai) stu[i].flag=3;
		else stu[i].flag=4;//第四类的情况是最多的，所以最后写入
	}
	sort(stu,stu+n,cmp);//排序
	printf("%d\n",m);
	for(int i=0;i<m;++i){
		printf("%s %d %d\n",stu[i].id,stu[i].de,stu[i].cai);
	}
	return 0;
}