#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <bitset>
#include <functional>

using namespace std;

#define LL long long
const int INF = 0x3f3f3f3f;

int n, x[1005], visit[1005];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		memset(visit, 0, sizeof visit);
		int flag = 1;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &x[i]);
			if (visit[x[i]]) flag = 0;
			visit[x[i]] = 1;
		}
		if (!flag) { printf("NO\n"); continue; }
		for (int i = 2; i <= n; i++)
			for (int j = 1; j < i; j++)
				if (abs(i - j) == abs(x[i] -x[j])) { flag = 0; break; }
		if (flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
