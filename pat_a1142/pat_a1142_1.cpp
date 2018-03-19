#include<bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("data3.txt","r",stdin);
	ios::sync_with_stdio(false);
	int n,m,c1,c2,k;
	cin>>n>>m;
	set<pair<int,int> > s;
	pair<int,int> p;
	for(;m--;)
	{
		cin>>p.first>>p.second;
		if(p.first>p.second)
		swap(p.first,p.second);
		s.insert(p);
	}
	cin>>m;
	for(;m--;)
	{
		cin>>k;
		bool flag=true;
		vector<bool> vb(n+1,true);
		vector<int> v;
		for(;k--;)
		{
			cin>>c2;
			for(auto i:v)
			{
				p.first=min(i,c2);
				p.second=max(i,c2);
				if(s.find(p)==s.end())
				{
					flag=false;
					break;
				}
			}
			v.push_back(c2);
			vb[c2]=false;
		}
		if(flag)
		{
			bool flagg=true;
			for(int i=1;i<=n&&flagg;i++)
			{
				if(vb[i])
				{
					bool flaggg=true;
					for(int j=0;j<v.size()&&flaggg;j++)
					{
						p.first=min(v[j],i);
						p.second=max(v[j],i);
						if(s.find(p)==s.end())
						flaggg=false;
					}
					if(flaggg)
					flagg=false;
				}
			}
			if(flagg)
			cout<<"Yes\n";
			else
			cout<<"Not Maximal\n";
		}
		else
		cout<<"Not a Clique\n";
	}
	return 0;
}
