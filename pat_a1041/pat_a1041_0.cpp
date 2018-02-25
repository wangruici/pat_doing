#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <unordered_map>
#include <string>
#include <map>
#include <vector>
#include <cassert>

using std::string;
using std::map;
using std::vector;
using std::unordered_map;
int order[10001];
int
main(){
	int count;
	scanf("%d",&count);
	int temp;
	unordered_map<int,int> records;
	for(int i=1;i<=count;++i){
		scanf("%d",&temp);
		order[temp]=i;
		records[temp]++;
	}
	int win_num=0;
	int minIndex=2000200;//must be big enough,or when the data became bigger,the program will be wrong.
	int minValue=0;
	for(unordered_map<int,int>::iterator i=records.begin();i!=records.end();++i){
		if(i->second<=1){
			win_num++;
			if(order[i->first]<minIndex){
				minIndex=order[i->first];
				minValue=i->first;
			}
		}
	}
	if(win_num==0){
		printf("None");
	}
	else{
		printf("%d",minValue);
	}
	return 0;
}
