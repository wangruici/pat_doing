#include <cstdio>
#include <cstring>


const int maxn=100010;
int memory_space[maxn]={0};

int main(){
	int begin_address1,begin_address2,count;
	scanf("%d%d%d",&begin_address1,&begin_address2,&count);
	
	int address,next;
	char data;
	memory_space[begin_address1]++;
	memory_space[begin_address2]++;
	int ans;
	bool flag=false;
	for(int i=0;i<count;++i){
		scanf("%d %c %d",&address,&data,&next);
		if(next>-1){
			memory_space[next]++;
			if(memory_space[next]>=2){
				flag=true;
				ans=next;
				break;
			}
		}
	}
	if(flag){
		printf("%05d\n",ans);
	}
	else{
		if(memory_space[begin_address1]>=2){
			printf("%05d\n",begin_address1);		
		}
		else{
			printf("-1\n");
		}
	}
	return 0;
}
