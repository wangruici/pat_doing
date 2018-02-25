#include <iostream>
#include <cstdio>
#include <set>

using namespace std;
double poly[1000];
//greater是一个比较器
set<int,greater<int>> mst;

//主要思路：
//将各项系数储存在一个长度为1000的double数组中
//这样计算各项系数就很简单了可以随机存取
//为了整体输出
//使用set结构来记录哪几项是有效的数据

int main(){
	int k,n;
	double a;
	cin>>k;
	while(k--){
		cin>>n>>a;
		poly[n]+=a;
		mst.insert(n);
	}
	cin>>k;
	while(k--){
		cin>>n>>a;
		poly[n]+=a;
		//去除因为计算导致无效的项
		if(poly[n]==0)
			mst.erase(n);
		else
			mst.insert(n);
	}
	cout<<mst.size();
	for(auto x:mst){
		//输出宽度.小数位宽度
		printf(" %d %.1lf",x,poly[x]);
	}
	return 0;
}