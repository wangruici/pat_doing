#include <cstdio>
#include <cstring>
#include <algorithm>

using std::max;
using std::min;
using std::sort;


const int INF=0x7fffffff;
const int maxn=1000010;

int main(){
	int len1=0,len2=0;
	int array1[maxn],array2[maxn];
	scanf("%d",&len1);
	for(int i=0;i<len1;++i){
		scanf("%d",&array1[i]);
	}
	scanf("%d",&len2);
	for(int i=0;i<len2;++i){
		scanf("%d",&array2[i]);
	}
	 array1[len1]=array2[len2]=INF;
	int middle=(len1+len2-1)/2;
	int count=0,i=0,j=0;
	while(count<middle){
		if(array1[i]<array2[j]) ++i;
		else ++j;
		++count;
	}
	if(array1[i]<array2[j])
		printf("%d",array1[i]);
	else
		printf("%d",array2[j]);

	return 0;
}
