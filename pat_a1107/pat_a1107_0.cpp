#include <cstdio>
#include <algorithm>
using std::sort;

const int N=1010;
int father[N];
int element_count[N]={0};
int course[N]={0};

int findRoot(int x){
	while(x!=father[x]){
		x=father[x];
	}
	return x;
}

void Union(int a,int b){
	int rootA=findRoot(a);
	int rootB=findRoot(b);
	if(rootA!=rootB){
		father[rootA]=rootB;
	}
}

void init(int n){
	for(int i=1;i<=n;++i){
		father[i]=i;
		element_count[i]=0;
	}
}

bool cmp(int a,int b){
	return a>b;
}

int main(){
	int n,k,h;
	scanf("%d",&n);
	init(n);
	for(int i=1;i<=n;++i){
		scanf("%d:",&k);
		for(int j=0;j<k;++j){
			scanf("%d",&h);
			if(course[h]==0){
				course[h]=i;
			}
			Union(i,course[h]);
		}
	}

	for(int i=1;i<=n;++i){
		element_count[findRoot(i)]++;
	}

	int ans=0;
	for(int i=1;i<=n;++i){
		if(element_count[i]!=0){
			++ans;
		}
	}

	printf("%d\n",ans);
	sort(element_count+1,element_count+1+n,cmp);
	for(int i=1;i<=ans;++i){
		printf("%d",element_count[i]);
		if(i<ans) printf(" ");
	}
	return 0;
}
