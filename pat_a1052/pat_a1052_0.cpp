#include <cstdio>
#include <cstring>
#include <algorithm>

using std::sort;

const int maxn=100010;

struct Node {
	int address;
	int data;
	int next;
	bool flag;
}node[maxn];

bool cmp(Node a,Node b){
	if(a.flag==false||b.flag==false)
		return a.flag>b.flag;
	else{
		return a.data<b.data;
	}
}

int main(){
	int begin_address,count;
	for(int i=0;i<maxn;++i){
		node[i].flag=false;
	}
	scanf("%d %d",&count,&begin_address);
	int address;
	for(int i=0;i<count;++i){
		scanf("%d",&address);
		scanf("%d %d",&node[address].data,&node[address].next);
		node[address].address=address;
	}
	int effective_count=0;
	int p=begin_address;
	while(p!=-1){
		node[p].flag=true;
		p=node[p].next;
		++effective_count;
	}


	if(effective_count==0){
		printf("0 -1");
		return 0;
	}
	sort(node,node+maxn,cmp);
	printf("%d %05d\n",effective_count,node[0].address);
	for(int i=0;i<effective_count-1;++i){
		printf("%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address);
	}
	printf("%05d %d -1\n",node[effective_count-1].address,node[effective_count-1].data);
	return 0;
}
