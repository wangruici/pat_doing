#include <queue>
#include <iostream>

using std::queue;
using std::cin;
using std::cout;
using std::endl;

struct mice{
	int weight;
	int rank;
};

typedef struct mice mice;
mice mices[1010];

int main(){
	int mice_count=0,max_capa_turn=0;
	scanf("%d%d",&mice_count,&max_capa_turn);
	for(int i=0;i<mice_count;++i){
		scanf("%d",&mices[i].weight);
	}

	queue<int> co;
	int order;
	for(int i=0;i<mice_count;++i){
		scanf("%d",&order);
		co.push(order);
	}

	int left=mice_count;
	int group;
	while(co.size()>1){
		if(left%max_capa_turn==0){
			group=left/max_capa_turn;
		}
		else{
			group=left/max_capa_turn+1;
		}
		for(int i=0;i<group;++i){
			int max_wight_local=co.front();
			for(int j=0;j<max_capa_turn;++j){
				if(i*max_capa_turn+j>=left) break;
				int front=co.front();
				if(mices[front].weight>mices[max_wight_local].weight){
					max_wight_local=front;	
				}
				mices[front].rank=group+1;
				co.pop();
			}
			co.push(max_wight_local);
		}
		left=group;
	}
	mices[co.front()].rank=1;
	for(int i=0;i<mice_count;++i){
		printf("%d",mices[i].rank);
		if(i<mice_count-1) printf(" ");
	}
	return 0;
}
