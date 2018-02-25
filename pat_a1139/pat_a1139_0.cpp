#include <bits/stdc++.h>
using namespace std;

//结构体，储存每一对朋友
struct friends
{
	int x,y;
	friends(int a,int b):x(a),y(b){}
};
//vector可以存储全部的4-digit ID
//v是一个向量数组，数组的每个元素都是一个向量，每个向量又可以存储多个整型
vector<int> v[10000];
//以图的形式储存，邻接矩阵
bool matrix[10000][10000];
//v存储了全部的同性关系，而路径搜索要求从同行关系开始
//a,b是两个人，a crush on b.
void search(vector<friends> &ans,int a,int b)
{
	for(int x:v[a])
	{
		//a的同性朋友
		for(int y:v[b])
		{
			//b的同性朋友
			//有三种情况不计入循环，
			//情况一：a,b同性时,a,b可能有一个共同的同性朋友，这种情况现实中可以直接认识，但不合题意，略
			//情况二：a的同性朋友直接认识b,根据题意，必须要有另外一个人作为媒介，略
			//情况三：与情况二完全对称相同
			if(x==y||x==b||y==a)continue;//same gender circumstance
			//如果不符合上述三种情况，且x,y确实存在朋友关系，将其写入答案
			if(matrix[x][y])ans.push_back(friends(x,y));
		}
	}
}
//为了输出使用的排序函数如果x相同，则按照y的顺序排列否则按照x的顺序排列
bool cmp(const friends &a,const friends &b)
{
	return a.x==b.x?a.y<b.y:a.x<b.x;
}
int main()
{
	//freopen("1.txt","r",stdin);
	int n,m,k;
	//n是总人数，m是总的关系数
	cin>>n>>m;
	//将全部的关系读入内存并存储下来
	for(int i=0;i<m;++i)
	{
		string a,b;
		cin>>a>>b;
		//可以用大小来判断是否是相同的性别
		if(a.size()==b.size())//same gender
		{
			//stoi函数将字符串转化为整型(string->int)
			//abs将负数变为正数
			v[abs(stoi(a))].push_back(abs(stoi(b)));//这个是stdlib.h里面的函数stoi
			v[abs(stoi(b))].push_back(abs(stoi(a)));
		}
		//无论性别是否相同，要将数据写入到邻接矩阵中构成一个图
		matrix[abs(stoi(a))][abs(stoi(b))]=matrix[abs(stoi(b))][abs(stoi(a))]=true;//are friends
	}
	//读入查询数量
	cin>>k;
	//将每一个查询读入内存中，并且寻找路径，并且排序输出
	while(k--)
	{
		int a,b;
		cin>>a>>b;
		//将答案全部放入ans中去
		vector<friends> ans;//collect answer
		search(ans,abs(a),abs(b));
		sort(ans.begin(),ans.end(),cmp);
		cout<<ans.size()<<endl;
		for(auto w:ans)
			printf("%04d %04d\n",w.x,w.y);
	}
	return 0;
}