#include<set>
#include<vector>
#include<cstdio>
using namespace std;
const int maxn = 50000 + 10;
int counts[maxn] = { 0 };
struct r
{
	int v;
	int count;
	r(int v1,int c1)
	{
		v = v1;
		count = c1;
	}
	r():v(0),count(0){}
	bool operator<(const r &r1)const//注意大括号前的const和形参类型前加const
	{
		if (count != r1.count)
			return count > r1.count;
		else
			return v < r1.v;
	}
}R;
set<r> s;
int N, K;
int main()
{
	scanf("%d%d", &N, &K); int t;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &t);		
		if (i)
		{
			printf("%d:", t); int j = 0;
			for (set<r>::iterator it
				= s.begin(); it != s.end()&&j<K; it++,j++)
			{
				printf(" %d", it->v);
			}
			printf("\n");
		}
		counts[t]++;
		R.v = t;
		R.count = counts[t];
		if (s.find(r(t, counts[t] - 1)) != s.end())
		{
			s.erase(s.find(r(t, counts[t] - 1)));
		}
		s.insert(R);
	}
	return 0;
}
