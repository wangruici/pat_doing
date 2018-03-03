#include <cstdio>
#include <cstring>


int main(){
	char ans[3];
	double sub[3];
	double profile=0;
	double v1,v2,v3;
	for(int i=0;i<3;++i){
		scanf("%lf %lf %lf",&v1,&v2,&v3);
		double max=v1;
		int index=0;
		if(max<v2){
			max=v2;
			index=1;
		}
		if(max<v3){
			max=v3;
			index=2;
		}
		sub[i]=max;
		switch(index){
			case 0:
				ans[i]='W';
				break;
			case 1:
				ans[i]='T';
				break;
			case 2:
				ans[i]='L';
				break;
		}
	}
	profile=(sub[0]*sub[1]*sub[2]*0.65-1)*2;
	printf("%c %c %c %.2lf\n",ans[0],ans[1],ans[2],profile);
	return 0;
}
