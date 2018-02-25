#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <unordered_map>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::flush;

using std::string;
using std::map;
using std::unordered_map;

int
main(){
	unordered_map<int,int> orders;
	int sch_or=0,stu_or=0,score=0;
	int count=0;
	int max=0;
	int maxScore=0;
	scanf("%d",&count);
	for(int i=0;i<count;++i){
		scanf("%d-%d %d",&sch_or,&stu_or,&score);
		orders[sch_or]+=score;
		if(maxScore<orders[sch_or]){
			max=sch_or;
			maxScore=orders[sch_or];
		}
	}
	printf("%d %d\n",max,maxScore);
	

	return 0;
}

