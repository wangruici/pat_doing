#include <cstdio>
#include <cstdlib>

int main(){
	int n;
	int* scores;
	int schID,score;
	scanf("%d",&n);
	scores=(int*)malloc(n*sizeof(int));
	for(int i=0;i<n;++i){
		scores[i]=0;
	}
	for(int i=0;i<n;++i){
		scanf("%d %d",&schID,&score);
		scores[schID-1]+=score;
	}
	int maxID=-1,maxScore=-1;
	for(int i=0;i<n;++i){
		if(scores[i]>maxScore){
			maxID=i+1;
			maxScore=scores[i];
		}
	}
	printf("%d %d\n",maxID,maxScore);
	free(scores);
	return 0;
}