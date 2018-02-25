#include <cstdio>
#include <algorithm>

using std::sort;

struct mooncake{
	double store;
	double spell;
	double price;
}cake[1010];

bool cmp(mooncake a,mooncake b){
	return a.price>b.price;
}

int main(){
	double categories;
	double requests;
	scanf("%lf %lf",&categories,&requests);
	for(int i=0;i<categories;++i){
		scanf("%lf",&cake[i].store);
	}
	for(int i=0;i<categories;++i){
		scanf("%lf",&cake[i].spell);
		cake[i].price=cake[i].spell/cake[i].store;
	}
	sort(cake,cake+(int)categories,cmp);

	double temp_requests=requests;
	double profit=0.0;
	for(int i=0;i<categories;++i){
		if(cake[i].store>=temp_requests){
			cake[i].store-=temp_requests;
			profit+=temp_requests*cake[i].price;
			temp_requests=0;
			break;
		}
		else{
			profit+=cake[i].price*cake[i].store;
			temp_requests-=cake[i].store;
			cake[i].store=0;	
		}

	}
	printf("%.02lf\n",profit);
	return 0;
}
