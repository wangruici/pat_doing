#include <cstdio>


int
main(){
	unsigned int count[10]={0};
	for(int i=0;i<10;++i){
		scanf("%d",&count[i]);
	}
	int i=1;
	if(count[0]!=0){
		i=0;
		while(count[++i]==0);
		printf("%d",i);
		count[i]--;
		for(int j=count[0];j>0;--j){
			printf("%d",0);
		}
	}
	for(int m=i;m<10;++m){
		for(int j=count[m];j>0;--j){
			printf("%d",m);
		}
	}

	return 0;
}

