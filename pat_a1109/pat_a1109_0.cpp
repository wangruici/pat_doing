#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<iomanip>
using namespace std;
struct stu
{
	string name;
	int height;
	bool operator<(stu s)
	{
		if (height != s.height)
			return height > s.height;
		else
			return name < s.name;
	}//重载小于号
};
int main()
{
	int N, K;
	cin >> N >> K;
	stu t;
	deque<stu> v;//双端队列
	int N1 = N;
	while (N--)
	{
		cin >> t.name >> t.height;
		v.push_back(t);
	}
	sort(v.begin(), v.end()); 
	N = N1;
	int p = N / K;
	int lastrow = N - p*(K - 1);
	deque<stu> vv;
	for (int i = 0; i < v.size()||vv.size(); i++)
	{
		if (i < lastrow)//设定lastrow对最后一排进行特殊处理
		{
			if (i % 2 == 0)
				vv.push_back(v[i]);
			else
				vv.push_front(v[i]);//利用双端队列的特性，可以往前插
		}
		else
		{
			if (i == lastrow||vv.size()==p)//当一排排完时
			{
				for (int j = 0; j < vv.size(); j++)
				{
					cout << vv[j].name;
					if (j != vv.size() - 1)
						cout << " ";
					else
						cout << endl;
				}
				vv.clear();//一定要记得清空
			}
			if(i<v.size()){
				if (vv.size() % 2 == 0)//交替插入
					vv.push_back(v[i]);
				else
					vv.push_front(v[i]);
			}
		}
	}
	
	return 0;
}
