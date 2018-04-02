#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
using std::fill;
using std::cin;
using std::cout;
using std::endl;



const int maxn=10010;
int hashTable[maxn];

bool isPrime(int num){
	if(num<2) return false;
	int sqr=sqrt(1.0*num);
	for(int i=2;i<=sqr;++i){
		if(num%i==0){
			return false;
		}
	}
	return true;
}

int prime[maxn];

int pNum=0;

void Find_Prime(){
	for(int i=1;i<maxn;++i){
		if(isPrime(i)==true){
			prime[pNum++]=i;
		}
	}
}

void init(int *hashTable,int max,int none){
	fill(hashTable,hashTable+max,none);
}
int getAddress(int value,int size){
	return value%size;
}
int insert(int *hashTable,int size,int value,int none){
	int index;
	for(int i=0;i<size;++i){
		index=getAddress(value+i*i,size);
		if(hashTable[index]==none){
			hashTable[index]=value;	
			return index;
		}
	}
	return none;
}
int search(int *hashTable,int size,int value,int none,bool &flag){
	int time=0;
	int index=0;
	for(int i=0;i<size;++i){
		++time;
		index=getAddress(value+i*i,size);
		if(hashTable[index]==value){
			flag=true;	
			return time;
		}
		if(hashTable[index]==none){
			flag=false;
			return time;
		}
	}
	flag=false;
	//不清楚为什么越界了要用time+1次
	return time+1;
}

int main(){
	int none=-1;
	init(hashTable,maxn,none);
	int tsize,n1,n2;	
	cin>>tsize>>n1>>n2;
	while(!isPrime(tsize)) ++tsize;
	int temp;
	int locate;
	for(int i=0;i<n1;++i){
		cin>>temp;	
		locate=insert(hashTable,tsize,temp,none);
		if(locate==none){
			cout<<temp<<" cannot be inserted."<<endl;
		}
	}
	int cnt=0;
	bool flag=false;
	for(int i=0;i<n2;++i){
		cin>>temp;
		cnt+=search(hashTable,tsize,temp,none,flag);
	}
	float ans=cnt*1.0/n2;
	printf("%.1f\n",ans);
	return 0;
	
}
