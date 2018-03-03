#include <cmath>
#include <cstdio>
#include <algorithm>

using std::fill;
int main(){
	const int maxn=2010;
	double ex1[maxn];
	fill(ex1,ex1+maxn,0);
	int num;
	scanf("%d",&num);
	int ex;
	double co;
	for(int i=0;i<num;++i){
		scanf("%d %lf",&ex,&co);
		ex1[ex]=co;
	}

	double ex2[maxn];
	fill(ex2,ex2+maxn,0);
	
	scanf("%d",&num);
	for(int i=0;i<num;++i){
		scanf("%d %lf",&ex,&co);
		ex2[ex]=co;
	}
	double ex3[maxn];
	fill(ex3,ex3+maxn,0);
	for(int i=0;i<maxn;++i){
		for(int j=0;j<maxn;++j){
			if(i+j<maxn){
				ex3[i+j]+=ex1[i]*ex2[j];
			}
		}
	}
	int count=0;
	for(int i=0;i<maxn;++i){
		if(ex3[i]!=0){
			++count;
		}
	}
	printf("%d ",count);
	int temp=0;
	for(int i=maxn-1;i>=0;--i){
		if(ex3[i]!=0){
			++temp;
			if(temp<count){
				printf("%d %.1lf ",i,ex3[i]);
			}
			else{
				printf("%d %.1lf\n",i,ex3[i]);
				break;
			}
		}
	}
}
