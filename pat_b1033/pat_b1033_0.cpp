#include <cstring>
#include <cstdio>

const int maxn=100010;
bool hashTable[257];
char str[maxn];

int main(){
	memset(hashTable,true,sizeof(hashTable));//全部设置为true
	gets(str);
	int len=strlen(str);
	for(int i=0;i<len;++i){
		if(str[i]>='A'&&str[i]<='Z'){
			str[i]=str[i]-'A'+'a';//如果是大写字母转化为小写字母
		}
		hashTable[str[i]]=false;//设置为失效
	}
	gets(str);
	len=strlen(str);
	int low;
	for(int i=0;i<len;++i){
		if(str[i]>='A'&&str[i]<='Z'){
			low=str[i]-'A'+'a';
			if(hashTable[low]==true&&hashTable['+']==true){
				printf("%c",str[i]);
			} 
		}
		else if(hashTable[str[i]]==true){
			printf("%c",str[i]);
		}
	}
	printf("\n");
	return 0;
}