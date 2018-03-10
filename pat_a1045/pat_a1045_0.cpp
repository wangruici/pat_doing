#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using std::fill;
using std::cin;
using std::cout;
using std::endl;
using std::flush;
using std::string;
using std::vector;
using std::max;

const int max_color_num=210;
const int max_len=10010;

int sequence[max_color_num];
int strip[max_len];

//判断两个颜色组成的顺序是否为喜欢的
bool isRight(int before,int now){
	if(sequence[before]==0&&sequence[now]!=0){
		return true;
	}
	if(sequence[before]!=0&&sequence[before]<=sequence[now]){
		return true;
	}
	return false;
}
int color_num=0;
int love_num=0;
int len=0;
int getMaxLen(int nowLen,int nowIndex,int step){
	if(nowIndex+step>len){
		return nowLen;
	}
	
	if(isRight(strip[nowIndex],strip[nowIndex+step])){
		int len1=getMaxLen(nowLen+1,nowIndex+step,1);
		int len2=getMaxLen(nowLen,nowIndex,step+1);
		return max(len1,len2);
	}
	else{
		int len1=getMaxLen(0,nowIndex+step,1);
		int len2=getMaxLen(nowLen,nowIndex,step+1);
		return max(len1,len2);
	}
	

}

int main(){
	scanf("%d",&color_num);
	scanf("%d",&love_num);
	int temp;
	//给定一个数字，可以查得它应该在的位置
	for(int i=1;i<=love_num;++i){
		scanf("%d",&temp);
		sequence[temp]=i;
	}
	scanf("%d",&len);
	for(int i=1;i<=len;++i){
		scanf("%d",&temp);
		strip[i]=temp;
	}
	int max_len=getMaxLen(0,0,1);
	printf("%d\n",max_len);
	return 0;
}
