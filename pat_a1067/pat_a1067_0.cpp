#include <cstring>
#include <cstdio>
#include <algorithm>

using std::swap;


const int maxn=100010;
int pos[maxn];

int main(){
	int count,ans=0;
	scanf("%d",&count);
	int left=count-1;
	int temp;
	int pointer=1;
	for(int i=0;i<count;++i){
		scanf("%d",&temp);
		pos[temp]=i;
		if(temp==i){
			--left;
		}
	}

	while(left>0){
		if(pos[0]==0){
			while(pos[pointer]==pointer&&pointer<count){
				++pointer;
			}
			swap(pos[0],pos[pointer]);
			++ans;

		}
		while(pos[0]!=0){
			swap(pos[0],pos[pos[0]]);
			ans++;
			--left;
		}
	}
	printf("%d\n",ans);
	return 0;
}
