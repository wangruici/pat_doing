#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
using std::sqrt;
using std::cin;
using std::cout;
using std::endl;
using std::flush;
using std::map;
using std::string;
struct Record{
	bool isVisited;
	string reward;
};
bool isPrime(int num){
	if(num<=1) return false;
	int sqr=sqrt(1.0*num);
	for(int i=2;i<=sqr;++i){
		if(num%i==0){
			return false;
		}
	}
	return true;
}
int main(){
	map<int,Record> records;
	int num,query_num;
	scanf("%d",&num);
	int temp;
	for(int i=1;i<=num;++i){
		scanf("%d",&temp);
		if(i==1){
			records[temp].reward="Mystery Award";
		}
		else if(isPrime(i)){
			records[temp].reward="Minion";
		}
		else{
			records[temp].reward="Chocolate";
		}
	}
	scanf("%d",&query_num);
	for(int i=0;i<query_num;++i){
		scanf("%d",&temp);
		if(records.find(temp)==records.end()){
			printf("%04d: Are you kidding?\n",temp);
		}
		else if(records[temp].isVisited==false){
			records[temp].isVisited=true;
			printf("%04d: %s\n",temp,records[temp].reward.c_str());
		}
		else{
			printf("%04d: Checked\n",temp);
		}
	}
}
