#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <unordered_set>
using std::string;
using std::map;
using std::set;
using std::unordered_set;
const int maxn=2510;
//const int maxm=40010;
unordered_set<string> courses[maxn];
/*
int getId(string name){
	int id=0;
	for(int i=0;i<3;++i){
		id=id*26+(name[i]-'A');
	}
	id=id*10+(name[3]-'0');
	return id;
}

int getName(int id,char name[]){
	name[4]='\0';
	name[3]=id%10+'0';
	id=id/10;
	for(int i=2;i>=0;--i){
		name[i]=id%26;
		id/=10;
	}
}
*/

int main(){
	char name[10];
	int student_num,course_num;
	int course_id;
	int temp_count;
	scanf("%d %d",&student_num,&course_num);
	for(int i=0;i<student_num;++i){
		scanf("%s",name);
		scanf("%d",&temp_count);
		for(int j=0;j<temp_count;++j){
			scanf("%d",&course_id);
			courses[course_id].insert(name);
			
		}
	}
	for(int i=1;i<=course_num;++i){
		printf("%d %d\n",i,(int)courses[i].size());
		for(auto j=courses[i].begin();j!=courses[i].end();++j){
			printf("%s\n",j->c_str());
		}
	}
	return 0;
}
