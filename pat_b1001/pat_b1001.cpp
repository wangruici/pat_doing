#include <cstdio>

int main(){
	int value=0;
	int step=0;
	scanf("%d",&value);
	while(value!=1){
		if((value%2)==0){
			value=value/2;
		}
		else{
			value=(3*value+1)/2;
		}
		step++;
	}
	printf("%d",step);
	return 0;
}