#include <cstring>
#include <cstdlib>
#include "stdio.h"

const int MAX_LEN=10005;
char s1[MAX_LEN],s2[MAX_LEN];

bool HashTable[256];

int
main(){
	memset(HashTable,false,256);
//at first,i want to use function "gets()";
//however,standard 11 has removed the dangerous function "gets()"
//so i replace gets() with fgets(char[],len,stream)
	fgets(s1,MAX_LEN,stdin);
	fgets(s2,MAX_LEN,stdin);
	int len_s1=strlen(s1);
	int len_s2=strlen(s2);
	for(int i=0;i<len_s2;++i){
		HashTable[s2[i]]=true;
	}
	for(int i=0;i<len_s1;++i){
		if(!HashTable[s1[i]]){
			printf("%c",s1[i]);
		}
	}

	return 0;
}
