#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using std::sort;
struct Student{
	char name[11];
	char id[11];
	int grade;
};
bool cmp(Student a,Student b){
	return a.grade>b.grade;
}

int main(){
	int num=0;
	scanf("%d",&num);
	Student* stu=(Student*)malloc(num*sizeof(Student));
	for(int i=0;i<num;++i){
		scanf("%s %s %d",stu[i].name,stu[i].id,&stu[i].grade);
	}
	sort(stu,stu+num,cmp);
	bool flag=false;
	int max,min;
	int temp=0;
	scanf("%d %d",&min,&max);
	for(int i=0;i<num;++i){
		if(stu[i].grade>max){
			continue;
		}
		else{
			if(stu[i].grade<min){
				break;
			}
			else{
				flag=true;
				temp=i;
				break;
			}
		}
	}
	if(flag){
		printf("%s %s\n",stu[temp].name,stu[temp].id);
		for(int i=temp+1;i<num;++i){
			if(stu[i].grade>=min){
				printf("%s %s\n",stu[i].name,stu[i].id);
			}
			else{
				break;
			}
		}
	}
	else{
		printf("NONE");
	}
	free(stu);
	return 0;
}






