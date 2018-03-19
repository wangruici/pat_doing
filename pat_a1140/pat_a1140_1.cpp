#include<bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("data1.txt","r",stdin);
	ios::sync_with_stdio(false);
	vector<int> v;
	int n,m;
	cin>>n>>m;
	m--;
	v.push_back(n);
	for(;m--;)
	{
		vector<int> v0;
		int v00=v[0];
		int ii=1;
		for(int i=1;i<v.size();i++)
		{
			if(v[i]!=v00)
			{
				v0.push_back(v00);
				v0.push_back(ii);
				v00=v[i];
				ii=1;

			}
			else
			ii++;
		}
		v0.push_back(v00);
		v0.push_back(ii);
		v=v0;
	}
	for(auto i:v)
	cout<<i;
	return 0;
}
