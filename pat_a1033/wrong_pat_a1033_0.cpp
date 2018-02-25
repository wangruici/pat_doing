#include <cstring>
#include <cstdio>
#include <algorithm>


using std::sort;

const int maxn=510;
const int INF=1000000000;

typedef struct station{
	double price,distance;
}station;

station sta[maxn];

bool cmp(station a,station b){
	return a.distance<b.distance;
}

int main(){
		double max_capa,hang_distance,per_long;
		int num_station;
		scanf("%lf %lf %lf %d",&max_capa,&hang_distance,&per_long,&num_station);
		for(int i=0;i<num_station;++i){
			scanf("%lf %lf",&sta[i].price,&sta[i].distance);
		}
		sta[num_station+1].price=0;
		sta[num_station+1].distance=0;
		sort(sta,sta+num_station+1,cmp);

		double x=0;
		double how_much=0;

		if(sta[0].distance>0){
			x=0;
			how_much=0;
			printf("The maximum travel distance=%.2lf",x);
			return 0;
		}else{
			int ptr_now=0;
			int ptr_longest_loc=0;
			int ptr_first_low_loc_inrange=0;
			int inrange_distance=0;
			const double can_run=max_capa*per_long;
			while(ptr_now!=num_station){
				inrange_distance=sta[ptr_now].distance+can_run;
				ptr_first_low_loc_inrange=-1;
				ptr_longest_loc=ptr_now;
				for(int i=ptr_now+1;i<num_station+1;++i){
					if(sta[i].distance<=inrange_distance){
						if(ptr_first_low_loc_inrange==-1&&sta[i].price<=sta[ptr_now].price){
							ptr_first_low_loc_inrange=i;
							ptr_longest_loc=i;
							break;
						}
						continue;
					}
					else{
						ptr_longest_loc=i-1;
						break;
					}
				}
				if(ptr_longest_loc<=ptr_now){
					x+=can_run;
					printf("The maximum travel distance=%.2lf",x);
					return 0;
					break;
				}
				else if(ptr_first_low_loc_inrange==-1){
					x=sta[ptr_longest_loc].distance;
					how_much+=(sta[ptr_longest_loc].distance-sta[ptr_now].distance)/per_long*sta[ptr_now].price;
#ifndef __NDEBUG
printf("ptr_longest, %.2lf,now:%d\n",how_much,ptr_now);
#endif
					ptr_now=ptr_longest_loc;
					continue;
				}
				else{
					x=sta[ptr_first_low_loc_inrange].distance;
					how_much+=(sta[ptr_first_low_loc_inrange].distance-sta[ptr_now].distance)/per_long*sta[ptr_now].price;
#ifndef __NDEBUG
printf("%d,%d               ptr_first,%.2lf,now:%d\n",ptr_now,ptr_first_low_loc_inrange,how_much,ptr_now);
#endif
					ptr_now=ptr_first_low_loc_inrange;
					continue;
				}


			}
		}
		printf("%.2lf",how_much);

		return 0;
}


























