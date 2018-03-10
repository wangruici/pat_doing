#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int maxn=100010;
const int sqrN=316;//sqrt(100001),表示块内元素的个数
stack<int> st;
int block[sqrN];
int table[maxn];

void peekMedian(int K){
	int sum=0;
	int idx=0;
	while(sum+block[idx]<K){
		sum+=block[idx++];
	}
	int num=idx*sqrN;
	while(sum+table[num]<K){
		sum+=table[num++];
	}
	printf("%d\n",num);
}

void Push(int x){
	st.push(x);
	block[x/sqrN]++;
	table[x]++;
}
void Pop(){
	int x=st.top();
	st.pop();
	block[x/sqrN]--;
	table[x]--;
	printf("%d\n",x);
}


int main(){
	int x,query;
	memset(block,0,sizeof(block));
	memset(table,0,sizeof(table));
	char cmd[20];
	scanf("%d",&query);
	for(int i=0;i<query;++i){
		scanf("%s",cmd);
		if(strcmp(cmd,"Push")==0){
			scanf("%d",&x);
			Push(x);
		}
		else if(strcmp(cmd,"Pop")==0){
			if(st.empty()==true){
				printf("Invalid\n");
			}
			else{
				Pop();
			}
		}
		else{
			if(st.empty()==true){
				printf("Invalid\n");
			}
			else{
				int K=st.size();
				if(K%2==1) K=(K+1)/2;
				else K=K/2;
				peekMedian(K);
			}
		}
	}
	return 0;
}
