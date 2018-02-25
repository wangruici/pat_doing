#include <cstdio>
#include <cstdlib>
#include <cstring>

char target[1010];
char sold[1010];
int hashTable[70];

int change(char c){
	if(c>='0'&&c<='9'){
		return c-'0';
	}
	else if(c>='a'&&c<='z'){
		return c-'a'+10;
	}
	else if(c>='A'&&c<='Z'){
		return c-'A'+36;
	}
	else return 69;
}

int main(){
	gets(sold);
	gets(target);

	int len1=strlen(sold);
	int len2=strlen(target);

	int temp;
	int miss=0;
	for(int i=0;i<len1;++i){
		temp=change(sold[i]);
		++hashTable[temp];
	}
	for(int i=0;i<len2;++i){
		temp=change(target[i]);
		--hashTable[temp];
		if(hashTable[temp]<0){
			++miss;
		}
	}
	if(miss>0){
		printf("No %d",miss);
	}
	else printf("Yes %d",len1-len2);
	return 0;
}