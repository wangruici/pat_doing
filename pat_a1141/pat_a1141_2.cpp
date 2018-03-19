#include<bits/stdc++.h>
using namespace std;
struct node
{
	string id;
	int num;
	int ag,bg,tg;
	bool operator<(const node& en) const
	{
		int g1=ag+bg*2/3+tg*3/2;
		int g2=en.ag+en.bg*2/3+en.tg*3/2;
		if(g1!=g2)
		return g1>g2;
		else if(num!=en.num)
		return num<en.num;
		else
		return id<en.id;
	}
} no;
int main()
{
//	freopen("data2.txt","r",stdin);
	ios::sync_with_stdio(false);
	unordered_map<string,int> m;
	vector<node> v;
	string s1,s2;
	int n,x,c1,c2;
	cin>>n;
	for(;n--;)
	{
		cin>>s1>>x>>s2;
		for(auto &i:s2)
		{
			if(i<='Z'&&i>='A')
			i=i-'A'+'a';
		}
		auto itm=m.find(s2);
		if(itm==m.end())
		{
			m[s2]=v.size();
			no.ag=0;
			no.tg=0;
			no.bg=0;
			no.id=s2;
			no.num=1;
			v.push_back(no);
		}
		else
		v[itm->second].num++;
		if(s1[0]=='B')
		v[m[s2]].bg+=x;
		else if(s1[0]=='A')
		v[m[s2]].ag+=x;
		else if(s1[0]=='T')
		v[m[s2]].tg+=x;
	}

	sort(v.begin(),v.end());

	cout<<v.size()<<endl;
	int r,g=-1;
	for(int i=0;i<v.size();i++)
	{
		int vg=v[i].ag+v[i].bg*2/3+v[i].tg*3/2;
		if(vg!=g)
		{
			r=i+1;
			g=vg;
		}
		cout<<r<<" "<<v[i].id<<" "<<vg<<" "<<v[i].num<<endl;
	}
	return 0;
}
