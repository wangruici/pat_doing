#include <cstdio>
#include <cmath>
const int maxx=810,maxy=610;
const int max=2<<24;

int count[2<<24]={0};

int main(){
	int x,y;
	scanf("%d %d",&x,&y);
	unsigned long long temp;
	int d=ceil(x*y/2.0);
	unsigned long long flag=0;
	for(int i=0;i<x;++i){
		for(int j=0;j<y;++j){
			scanf("%llu",&temp);
			++count[temp];
			if(count[temp]>=d){
				flag=temp;
				break;
			}
		}
		
	}
	printf("%llu\n",flag);
	return 0;
}
