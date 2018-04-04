#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
const int maxn=2010;
struct ploy{
	int exp;
	double cof;
	ploy():exp(0),cof(0.0){}
};

int main(){
	vector<ploy> p(maxn);
	vector<double> ans(maxn);
	int exp;
	double cof;
	int num;
	cin>>num;
	for(int i=0;i<num;++i){
		scanf("%d %lf",&p[i].exp,&p[i].cof);
	}
	int counter;
	scanf("%d",&counter);
	for(int i=0;i<counter;++i){
		scanf("%d %lf",&exp,&cof);
		for(int j=0;j<num;++j){
			ans[exp+p[j].exp]+=cof*p[j].cof;
		}
	}
	counter=0;
	for(int i=0;i<maxn;++i){
		if(ans[i]!=0.0){
			++counter;
		}
	}
	cout<<counter<<" ";
	for(int i=maxn;i>=0;--i){
		if(ans[i]!=0.0){
			printf("%d %.1lf",i,ans[i]);
			--counter;
			if(counter>0){
				printf(" ");
			}
			else{
				printf("\n");
			}
		}
	}
	return 0;
}
