#include <algorithm>
#include <cstdio>

using std::sort;

const int N=1005;

int HashTable[N];

int
main(){
	int n,m,a;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;++i){
		scanf("%d",&a);
		++HashTable[a];
	}
	for(int i=1;i<m;++i){
		if(HashTable[i]&&HashTable[m-i]){
			if(i==m-i&&HashTable[i]<=1){
				continue;
			}
			printf("%d %d\n",i,m-i);
			return 0;
		}
	}
	printf("No Solution\n");
	return 0;
}
