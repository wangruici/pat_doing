#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::sort;

struct cake{
	double num;
	double total_price;
	double per_price;
};

bool cmp(const cake &c1,const cake &c2){
	return c1.per_price>c2.per_price;
}

int main(){
	int total_cat;
	double total_need;
	cin>>total_cat>>total_need;
	vector<cake> record;
	cake c;
	for(int i=0;i<total_cat;++i){
		cin>>c.num;
		record.push_back(c);
	}
	for(int i=0;i<total_cat;++i){
		cin>>record[i].total_price;
		record[i].per_price=record[i].total_price/record[i].num;
	}

	double profile=0;
	sort(record.begin(),record.end(),cmp);
	int p=0;
	while(p<total_cat&&total_need>0){
		if(record[p].num>=total_need){
			record[p].num-=total_need;
			profile+=total_need*record[p].per_price;
			total_need=0;
		}
		else if(record[p].num<total_need){
			total_need-=record[p].num;
			profile+=record[p].total_price;
			record[p].num=0;
		}
		++p;
	}
	printf("%.2lf\n",profile);	
	return 0;
}
