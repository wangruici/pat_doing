#include <cstring>
#include <cstdio>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::flush;

bool haveOunt[257]={false};

int main(){
	char s1[100],s2[100];
	gets(s1);
	gets(s2);
	
	int len1=strlen(s1);
	int len2=strlen(s2);

	for(int i=0;i<len1;++i){
		int j;
		char c1=s1[i],c2;
		if(c1>='a'&&c1<='z'){
			c1-=32;
		}
		for(j=0;j<len2;++j){
			c2=s2[j];
			if(c2>='a'&&c1<='z'){
				c2-=32;
			}
			if(c1==c2){
				break;//如果s1的字母在s2中出现了，证明没有缺失
			}
		}
		if(j==len2&&haveOunt[c1]==false){
			printf("%c",c1);
			haveOunt[c1]=true;
		}
	}
	return 0;
}