#include <cstring>
#include <cstdio>
#include <algorithm>

const int maxn=100010;
int main(){
	int count;
	scanf("%d",&count);
	double ans=0;
	double temp=0;
	for(int i=1;i<=count;++i){
		scanf("%lf",&temp);
		ans+=temp*i*(count-i+1);
	}

	printf("%.2lf\n",ans);


	return 0;
}
