#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::abs;
struct Student{
	char name[10];
	int height;
}students[10010];

struct Name{
	char name[10];
}location[13][10010];

bool cmp(Student &s1,Student &s2){
	if(s1.height!=s2.height){
		return s1.height>s2.height;
	}
	else{
		return strcmp(s1.name,s2.name)<0;
	}

}

int main(){
	int num,row_count;
	int row_stu;
	int last_row_stu;
	cin>>num>>row_count;
	//scanf("%d %d",&num,&row_count);
	row_stu=num/row_count;
	last_row_stu=row_stu+num%row_count;

	for(int i=1;i<=num;++i){
		cin>>students[i].name>>students[i].height;
		//scanf("%s %d",students[i].name,&students[i].height);
	}

	sort(students+1,students+num+1,cmp);
	int middle=row_stu/2+1;
	int last_middle=last_row_stu/2+1;
	int p=0;
	bool flag=true;
	for(int i=1;i<=last_row_stu;++i){
		strcpy(location[row_count][last_middle+p].name,students[i].name);
		if(flag){
			p=-(abs(p)+1);
			flag=false;
		}
		else{
			p=-p;
			flag=true;
		}

	}
	int stu_p=last_row_stu+1;
	for(int i=1;i<row_count;++i){
		int p=0;
		flag=true;
		for(int j=1;j<=row_stu;++j){
			if(stu_p>num) break;
			strcpy(location[i][middle+p].name,students[stu_p].name);
			stu_p++;
			if(flag){
				p=-(abs(p)+1);
				flag=false;
			}
			else{
				p=-p;
				flag=true;
			}
		}
	}
	for(int i=1;i<=last_row_stu;++i){
		cout<<location[row_count][i].name;
		//printf("%s",location[row_count][i].name);
		if(i!=last_row_stu){
			cout<<" ";
			//printf(" ");
		}
		else{
			cout<<endl;
		}
	}
	//printf("\n");
	for(int i=1;i<=row_count-1;++i){
		for(int j=1;j<=row_stu;++j){
			cout<<location[i][j].name;
			//printf("%s",location[i][j].name);
			if(j!=row_stu){
				cout<<" ";
				//printf(" ");
			}
		}
		cout<<endl;
		//printf("\n");
	}
	return 0;
}

