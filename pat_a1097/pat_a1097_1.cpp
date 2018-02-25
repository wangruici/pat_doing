#include <cstdio>
#include <cstring>
#include <algorithm>

using std::sort;
using std::abs;

const int maxn=100010;

struct NODE{
	int address;
	int next;
	int data;
	int order;
}node[maxn];

bool isExisted[10010]={false};

bool cmp(NODE a,NODE b){
	return a.order<b.order;
}
int print_node(struct NODE* node,int len){
	for(int i=0;i<len;++i){
		printf("%d ",node[i].data);	
	}
	printf("\n");
}
int main(){
	int num,begin_address;
	scanf("%d %d",&begin_address,&num);
	int address;
	for(int i=0;i<num;++i){
		scanf("%d",&address);
		scanf("%d%d",&node[address].data,&node[address].next);
		node[address].address=address;
	}
	int valid_count=0,removed_count=0;

	for(int i=0;i<maxn;++i){
		node[i].order=2*maxn;
	}

	int p=begin_address;
	while(p!=-1){
		if(!isExisted[abs(node[p].data)]){
			isExisted[abs(node[p].data)]=true;
			node[p].order=valid_count++;
		}
		else{
			node[p].order=maxn+removed_count;
			removed_count++;
		}
		p=node[p].next;
	}

	sort(node,node+maxn,cmp);
//print_node(node,valid_count+removed_count);
	int count=valid_count+removed_count;
	for(int i=0;i<count;++i){
		if(i!=valid_count-1&&i!=count-1){
			printf("%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address);
		}
		else{
			printf("%05d %d -1\n",node[i].address,node[i].data);
		}
	}
	return 0;
}
