#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using std::sort;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

struct Station{
	double price;
	double distance;
	Station(double _p,double _d):price(_p),distance(_d){}
};


bool cmp(const Station &s1,const Station &s2){
	return s1.distance<s2.distance;
}
const int INF=0x3fffffff;
int main(){
	double maxCapacity,maxDistance,canRun,stationNum;
	cin>>maxCapacity>>maxDistance>>canRun>>stationNum;
	vector<Station> path;
	double price;
	double distance;
	for(int i=0;i<stationNum;++i){
		cin>>price>>distance;
		path.push_back(Station(price,distance));
	}
	path.push_back(Station(0,maxDistance));
	sort(path.begin(),path.end(),cmp);
	double reachDis=0;
	int now=0;
	double cost=0;
	double nowTank=0;
	double MAX=maxCapacity*canRun;
	if(path[0].distance!=0){
		printf("The maximum travel distance = %.2lf\n",reachDis);
		return 0;
	}
	while(now<stationNum){
		int k=-1;
		double minPrice=INF;
		for(int i=now+1;i<stationNum+1;++i){
			if(path[i].distance-path[now].distance>MAX){
				break;
			}
			//以下，都满足可以到达
			else if(path[i].price<minPrice){
				//找一个可到达范围内的最低油价
				k=i;
				minPrice=path[i].price;
				//找到第一个可以到达范围内的比目前还低的油价
				if(minPrice<path[now].price){
					break;
				}
			}
		}
		//没有任何一个可以到达的加油站
		if(k==-1){
			//加满油
			cost+=(maxCapacity-nowTank)*path[now].price;
			nowTank=maxCapacity;
			//跑到最远的距离
			reachDis+=nowTank*canRun;
			nowTank=0;
			//结束
			break;
		}
		//在可以到达的范围内，找到了一个比当前油价还要低的加油站
		else if(minPrice<path[now].price){
			//两种可能
			//不加油也能直接到达,接着跑到k去
			if(nowTank*canRun>=path[k].distance-path[now].distance){
				nowTank-=(path[k].distance-path[now].distance)/canRun;
				reachDis+=path[k].distance-path[now].distance;
				now=k;
			}
			//需要加油才能到达，那加刚好可以到达的油
			else{
				cost+=((path[k].distance-path[now].distance)/canRun-nowTank)*path[now].price;
				nowTank=(path[k].distance-path[now].distance)/canRun;
				nowTank=0;
				now=k;
			}
		}
		//可以到达的范围内，只有比当前油价要高的加油站，加满油跑过去,找一个价格最低的跑过去
		else if(minPrice>=path[now].price){
			cost+=(maxCapacity-nowTank)*path[now].price;	
			nowTank=maxCapacity-(path[k].distance-path[now].distance)/canRun;
			now=k;
		}
	}
	if(now==stationNum){
		printf("%.2lf\n",cost);
	}
	else{
		printf("The maximum travel distance = %.2f\n",path[now].distance+MAX);
	}
	return 0;
}
