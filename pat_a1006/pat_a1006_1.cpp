#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
using std::unordered_map;
using std::cin;
using std::cout;
using std::sort;
using std::string;
const int maxn=10010;
struct Record{
	char name[20];
	int inTime;
	int outTime;
}records[maxn];

bool cmp1(const Record &r1,const Record &r2){
	return r1.inTime<r2.inTime;
}
bool cmp2(const Record &r1,const Record &r2){
	return r1.outTime>r2.outTime;
}
int main(){
	int count;
	scanf("%d",&count);
	int HH,MM,SS;
	for(int i=0;i<count;++i){
		scanf("%s",records[i].name);
		scanf("%d:%d:%d",&HH,&MM,&SS);
		records[i].inTime=HH*60*60+MM*60+SS;
		scanf("%d:%d:%d",&HH,&MM,&SS);
		records[i].outTime=HH*60*60+MM*60+SS;
	}
	sort(records,records+count,cmp1);
	printf("%s",records[0].name);

	printf(" ");
	
	sort(records,records+count,cmp2);
	printf("%s",records[0].name);
	return 0;
}
