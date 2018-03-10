#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
using std::sort;
using std::string;

const int maxn=40020;

int course[maxn];

struct Stu{
	char name[20];
	int course_id;
}stu[maxn*20];

bool cmp(const Stu &s1,const Stu &s2){
	if(s1.course_id!=s2.course_id){
		return s1.course_id<s2.course_id;
	}
	else{
		return strcmp(s1.name,s2.name)<=0;
	}
}
int main(){
	int student_num,course_num;
	int count=0;
	int temp_count;
	int temp_index;
	char name[20];
	scanf("%d %d",&student_num,&course_num);
	for(int i=0;i<student_num;++i){
		scanf("%s",name);
		scanf("%d",&temp_count);
		for(int j=0;j<temp_count;++j){
			scanf("%d",&temp_index);
			strcpy(stu[count].name,name);
			stu[count++].course_id=temp_index;
			course[temp_index]++;
		}
	}
	sort(stu,stu+count,cmp);
	count=0;
	for(int i=1;i<=course_num;++i){
		printf("%d %d\n",i,course[i]);
		for(int j=0;j<course[i];++j){
			printf("%s\n",stu[count++].name);
		}
	}
	return 0;
}

