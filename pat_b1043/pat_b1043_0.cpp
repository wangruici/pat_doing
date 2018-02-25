#include <cstdlib>
#include <cstdio>
#include <cstring>


const int maxn=10010;
const int dict_len=6;

const char dict[dict_len]={'P'-'A',0,'T'-'A','e'-'a'+26,'s'-'a'+26,'t'-'a'+26};
char str[maxn];
const char ori_dict[dict_len]={'P','A','T','e','s','t'};
int result[60];

int
hashTo(char c){
	if(c>='A'&&c<='Z'){
		c=c-'A';
	}
	else{
		c=c-'a'+26;
	}
	return c;
}

int
main(){
	int effect_char=0;
	scanf("%s",str);
	int str_len=strlen(str);
	for(int i=0;i<str_len;++i){
		++result[hashTo(str[i])];
	}
	for(int i=0;i<dict_len;++i){
		effect_char+=result[dict[i]];
	}
	for(int i=0;i<effect_char;++i){
		for(int j=0;j<dict_len;++j){
			if(result[dict[j]]>0){
				printf("%c",ori_dict[j]);
				--result[dict[j]];
			}
			else{
				continue;
			}
		}
	}
	printf("\n");
	return 0;
}
