#include <set>
#include <string>
#include <iostream>
#include <cstdio>
#include <unordered_map>
using std::unordered_map;
using std::set;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::flush;

const int maxn=100+26*10+26*26*10+26*26*26*10;
set<int> regist_table[maxn];

int hash(char name[]){
	int index=name[3]-'0';
	index+=10*(name[2]-'A'+1);
	index+=10*26*(name[1]-'A'+1);
	index+=10*26*26*(name[0]-'A'+1);
	return index;
}

int main(){
	char name[10];
	int query_num,course_num;
	scanf("%d %d",&query_num,&course_num);
	int course_index;
	int count;
	int index;
	for(int i=0;i<course_num;++i){
		scanf("%d %d",&course_index,&count);
		for(int j=0;j<count;++j){
			scanf("%s",name);
			index=hash(name);	
			regist_table[index].insert(course_index);
		}
	}
	for(int i=0;i<query_num;++i){
		scanf("%s",name);
		index=hash(name);
		printf("%s",name);
		if(regist_table[index].size()==0){
			printf(" 0\n");	
		}
		else{
			const set<int> &courses=regist_table[index];
			printf(" %d",(int)courses.size());
			for(auto c=courses.begin();c!=courses.end();++c){
				printf(" %d",*c);
			}
			printf("\n");
		}
	}
	return 0;
}
