#include <cstdio>
#include <algorithm>

using std::sort;

const int maxn=100010;

struct Node{
	int address;
	int data;
	int next;
	int order;
}node[maxn];

bool cmp(Node a,Node b){
	return a.order<b.order;
}

int main(){
	for(int i=0;i<maxn;++i){
		node[i].order=maxn;
	}//not effective

	int begin_address,node_count,reverse_num;
	scanf("%d%d%d",&begin_address,&node_count,&reverse_num);
	int address;
	for(int i=0;i<node_count;++i){
		scanf("%d",&address);
		scanf("%d%d",&node[address].data,&node[address].next);
		node[address].address=address;
	}

	int p=begin_address,count=0;
	while(p!=-1){
		node[p].order=count++;
		p=node[p].next;
	}
	sort(node,node+maxn,cmp);
	int effective_node_count=count;
	int complete_block=effective_node_count/reverse_num;
	for(int i=0;i<complete_block;++i){
		for(int j=(i+1)*reverse_num-1;j>i*reverse_num;--j){
			printf("%05d %d %05d\n",node[j].address,node[j].data,node[j-1].address);
		}
		printf("%05d %d ",node[i*reverse_num].address,node[i*reverse_num].data);
		if(i<effective_node_count/reverse_num-1){
			printf("%05d\n",node[(i+2)*reverse_num-1].address);
		}
		else if(effective_node_count%reverse_num==0){
			printf("-1\n");
		}
		else{
			printf("%05d\n",node[(i+1)*reverse_num].address);
			for(int j=effective_node_count/reverse_num*reverse_num;j<effective_node_count;++j){
				printf("%05d %d ",node[j].address,node[j].data);
				if(j<effective_node_count-1){
					printf("%05d\n",node[j+1].address);
				}
				else{
					printf("-1\n");
				}
			}
		}
	}
	return 0;
}
