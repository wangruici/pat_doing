#include <cstdio>
#include <algorithm>
#include <string>
using std::string;
using std::sort;
const int maxsize=20;
struct record{
	char id_num[maxsize];
	int sign_in;
	int sign_out;
};
const int maxn=100010;

record records[maxn];

bool cmp1(record r1,record r2){
	return r1.sign_in<r2.sign_in;
}
bool cmp2(record r1,record r2){
	return r1.sign_out>r2.sign_out;
}
int main(){
	int num;
	scanf("%d",&num);
	int HH,MM,SS;
	for(int i=0;i<num;++i){
		scanf("%s",records[i].id_num);
		scanf("%d:%d:%d",&HH,&MM,&SS);
		records[i].sign_in=HH*60*60+MM*60+SS;
		scanf("%d:%d:%d",&HH,&MM,&SS);
		records[i].sign_out=HH*60*60+MM*60+SS;
	}
	sort(records,records+num,cmp1);
	printf("%s ",records[0].id_num);
	sort(records,records+num,cmp2);
	printf("%s\n",records[0].id_num);
	return 0;

}
