#include <iostream>
#include <string>
#include <cstdio>

int main(){
	double profit=1.0;
	double temp;
	double max;
	int index=0;
	char name[3]={'W','T','L'};
	for(int i=0;i<3;++i){
		max=0;
		index=0;
		for(int j=0;j<3;++j){
			scanf("%lf",&temp);
			if(temp>max){
				max=temp;
				index=j;
			}
		}
		printf("%c ",name[index]);
		profit=profit*max;
	}
	profit=(profit*0.65-1)*2;
	printf("%.2lf\n",profit);
	return 0;
}
