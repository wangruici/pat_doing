#include <cstdio>
#include <cstring>

const int maxn=100010;
struct NODE {
	char data;
	int next;
	bool flag;
}node[maxn];

int main(){

	for(int i=0;i<maxn;++i){
		node[i].flag=false;
	}

	int begin_address1,begin_address2,count;
	scanf("%d%d%d",&begin_address1,&begin_address2,&count);

	int address,next;
	char data;
	for(int i=0;i<count;++i){
		scanf("%d %c %d",&address,&data,&next);
		node[address].data=data;
		node[address].next=next;
	}

	int p=begin_address1;
	while(p!=-1){
		node[p].flag=true;
		p=node[p].next;
	}

	p=begin_address2;
	while(p!=-1){
		if(node[p].flag==true)
			break;
		p=node[p].next;
	}

	if(p!=-1){
		printf("%05d\n",p);
	}
	else{
		printf("-1\n");
	}
	return 0;
}
