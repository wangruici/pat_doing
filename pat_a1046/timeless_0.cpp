#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using std::max;
using std::min;
using std::cin;
using std::cout;
using std::endl;

const int maxn=100010;
int array[maxn];
int getIndex(int index,int len){
	while(index<0){
		index=index+len;
	}
	if(index<len){
		return index;
	}
	while(index>=len){
		index=index-len;
	}
	return index;
}

int getMinDistance(int from,int to,int len){
	int distance1=0;
	for(int i=from;getIndex(i,len)!=to;++i){
		distance1+=array[getIndex(i,len)];
	}
	int distance2=0;
	for(int i=to;getIndex(i,len)!=from;++i){
		distance2+=array[getIndex(i,len)];
	}
	return min(distance1,distance2);
}

int main(){
	int len;
	int mind;
	scanf("%d",&len);
	for(int i=0;i<len;++i){
		scanf("%d",&array[i]);
	}
	int num;
	scanf("%d",&num);
	int from,to;
	for(int i=0;i<num;++i){
		scanf("%d %d",&from,&to);
		--from;
		--to;
		mind=getMinDistance(from,to,len);
		printf("%d\n",mind);
	}
	return 0;
}
