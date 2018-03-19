//先对齐节点的深度，再一齐向上搜索的方式
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int r;
	int l;
	int d;
	int root;
	int h;
} no;
vector<int> v1,v2;
vector<node> v;
inline void rt(int b1,int b2,int s,int root)
{
	if(s)
	{
		auto itv=find(v1.begin()+b1,v1.begin()+b1+s,v2[b2]);
		int rs=s+b1+v1.begin()-itv-1;
		int ls=itv-v1.begin()-b1;
		if(root<0)
		{
			no.d=*itv;
			no.h=0;
			no.root=0;
			no.l=-1;
			no.r=-1;
			v.push_back(no);
			rt(b1,b2+1,ls,0);
			rt(b1+ls+1,b2+1+ls,rs,0);
		}
		else
		{
			int ro=v.size();
			no.d=*itv;
			no.h=v[root].h+1;
			no.root=root;
			
			if(*itv<v[root].d)
			v[root].l=ro;	
			else
			v[root].r=ro;
			
			no.l=-1;
			no.r=-1;
			v.push_back(no);
			rt(b1,b2+1,ls,ro);
			rt(b1+ls+1,b2+1+ls,rs,ro);	
		}
	}
}
inline int bstfind(int d)
{
	for(int i=0;i>-1;)
	{
		if(d<v[i].d)
		i=v[i].l;
		else if(d>v[i].d)
		i=v[i].r;
		else
		return i;
	}
	return -1;
}
int main()
{
//	freopen("data4.txt","r",stdin);
	ios::sync_with_stdio(false);
	int n,m,c1,c2;
	cin>>n>>m;
	v2.resize(m);
	for(int i=0;i<m;i++)
	{
		cin>>v2[i];
	}
	v1=v2;
	sort(v1.begin(),v1.end());
	rt(0,0,v1.size(),-1);
	for(;n--;)
	{
		cin>>c1>>c2;
		int i1=bstfind(c1);
		int i2=bstfind(c2);
		if(i1<0&&i2<0)
			cout<<"ERROR: "<<c1<<" and "<<c2<<" are not found.\n";
		else if(i1<0)
			cout<<"ERROR: "<<c1<<" is not found.\n";
		else if(i2<0)
			cout<<"ERROR: "<<c2<<" is not found.\n";
		else
		{
			int ii1=i1,ii2=i2;
			for(;ii1!=ii2;)
			{
				if(v[ii1].h>v[ii2].h)
				ii1=v[ii1].root;
				else if(v[ii1].h<v[ii2].h)
				ii2=v[ii2].root;
				else
				{
					ii1=v[ii1].root;
					ii2=v[ii2].root;
				}
			}
			if(ii1==i1)
			cout<<c1<<" is an ancestor of "<<c2<<"."<<endl;
			else if(ii1==i2)
			cout<<c2<<" is an ancestor of "<<c1<<"."<<endl;
			else
			cout<<"LCA of "<<c1<<" and "<<c2<<" is "<<v[ii1].d<<"."<<endl;
		}			
	}
	return 0;
}
