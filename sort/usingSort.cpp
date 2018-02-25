#include <algorithm>
#include <cstdio>
#include <string.h>
using std::sort;

struct Student{
	char name[10];//姓名
	char id[10];//准考证号
	int score;//分数
	int r;//排名

}stu[10010];
bool cmp(Student a,Student b){
	if(a.score!=b.score){
		return a.score>b.score;
	}
	else{
		return strcmp(a.name,b.name)<0;
	}
}

//sort函数的使用方法
//sort(首元素地址（必填）,尾元素地址的下一个地址(必填),比较函数（非必填）)
//比较函数cmp
//bool cmp(element1,element2)
/*
	{
		return element1>element2;
	}
	//这代表从大到小排序
	{
		return element1<element2;
	}
	//这代表从小到大排序
*/
//对整数进行排序
int main(){
	int a[6]={9,4,2,5,6,-1};
	sort(a,a+6);
	for(int i=0;i<6;++i){
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}