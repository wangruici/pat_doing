#include <cstdio>
#include <cstring>
#include <algorithm>

using std::sort;
using std::max;
const int maxn=100010;
int main(){
	int n,p,array[maxn];
	scanf("%d%d",&n,&p);
	for(int i=0;i<n;++i){
		scanf("%d",&array[i]);
	}
	sort(array,array+n);
	int i=0,j=0,count=1;
	while(i<n&&j<n){
		while(j<n&&array[j]<=(long long)array[i]*p){
			count=max(count,j-i+1);
			++j;
		}
		++i;
	}
	printf("%d\n",count);
	return 0;

}
