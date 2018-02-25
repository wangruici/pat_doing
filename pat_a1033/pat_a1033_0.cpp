#include <cstring>
#include <cstdio>
#include <algorithm>

using std::sort;

const int maxn=510;
const int INF=10000000;
struct Station{
	double price;
	double distance;
}station[maxn];

bool cmp(Station a,Station b){
	return a.distance<b.distance;
}


int main(){
	int num=0;
	double capa_max,hang_distance,per_long;
	scanf("%lf %lf %lf %d",&capa_max,&hang_distance,&per_long,&num);

	for(int i=0;i<num;++i){
		scanf("%lf %lf",&station[i].price,&station[i].distance);
	}

	station[num].price=0;
	station[num].distance=hang_distance;

	sort(station,station+num+1,cmp);

	int now=0;
	double howmuch=0;
	double distance=0;
	const double can_run=capa_max*per_long;
	double nowTank=0;
	if(station[0].distance>0){
		printf("The maximum travel distance = %.2f\n",0);
		return 0;
	}
	while(now!=num){
		int min_index=-1;
		double min=INF;
		for(int i=now+1;(i<num+1)&&(station[i].distance-station[now].distance)<=can_run;++i){
			if(station[i].price<=min){
				min_index=i;
				min=station[i].price;
			}
			if(min<=station[now].price){
				break;			
			}
		}
		if(min_index==-1){
			distance=station[now].distance+can_run;
			printf("The maximum travel distance = %.2f\n",distance);
			return 0;
		}
		else{
			if(min<=station[now].price){
				double need=(station[min_index].distance-station[now].distance)/per_long;
				if(need<=nowTank){
					nowTank=nowTank-need;
					now=min_index;
					howmuch+=0;	
				}
				else{
					howmuch=howmuch+(need-nowTank)*station[now].price;
					now=min_index;
					nowTank=0;
				}
			}
			else{
				howmuch=howmuch+(capa_max-nowTank)*station[now].price;
				nowTank=capa_max-(station[min_index].distance-station[now].distance)/per_long;
				now=min_index;
			}
		}
	}
	printf("%.2f\n",howmuch);

	return 0;
}
