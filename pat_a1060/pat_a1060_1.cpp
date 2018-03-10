#include<iostream>
#include<map>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<list>
#include<set>
#include<stack>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    string s1;
    string s2;
    cin>>s1>>s2;
    int mark1=150;
    int mark2=150;
    int len1=s1.size();
    int len2=s2.size();
    int flag1=0;
    int flag2=0;
    int num=0;
   while(s1[0]=='0'&&len1!=1&&s1[1]!='.')
   {
       s1.erase(s1.begin());
       len1--;
   }
      while(s2[0]=='0'&&len2!=1&&s2[1]!='.')
   {
       s2.erase(s2.begin());
       len2--;
   }
    if(s1[0]=='0')
    {
        int i;
        for(i=2;i<len1;i++)
        {
            if(s1[i]!='0'||i>=len1-2)
            {
                break;
            }
                num++;
        }
        if(i==len1-2&&s1[len1-1]!='0')
        {
            num++;
        }
        mark1=0-num;
    }
    else{
    for(int i=0;i<len1;i++)
    {
        if(s1[i]=='.')
        {
            mark1=i;
            break;
        }
    }
    if(mark1==150)
    {
        mark1=len1;
    }
    }
    string ans1="0.";
    int it=s1.find(".",0);
    if(it!=-1)
    {
        s1.erase(it,1);
        len1--;
    }
    int flag=0;
    int tt=n;
    for(int i=0;i<tt;i++)
    {
        if(i>=len1)
        {
            ans1+="0";
        }
        else
        {
            if(s1[i]!='0'||flag==1)
            {
                ans1+=s1[i];
                flag=1;
            }
            else
            {
                tt++;
            }
        }
    }
    ans1+="*10^";
     for(int i=0;i<len1;i++)
    {
        if(s1[i]!='0'&&s1[i]!='.')
        {
            flag1=1;
            break;
        }
    }
    if(flag1==0)
        mark1=0;
    num=0;
    if(s2[0]=='0')
    {
        int i;
        for(i=2;i<len2;i++)
        {
           if(s2[i]!='0'||i>=len2-2)
           {
               break;
           }
           num++;
        }
        if(i==len2-2&&s2[len2-1]!='0')
        {
            num++;
        }
        mark2=0-num;
    }
    else{
     for(int i=0;i<len2;i++)
    {
        if(s2[i]=='.')
        {
            mark2=i;
            break;
        }
    }
    if(mark2==150)
    {
        mark2=len2;
    }
    }
    string ans2="0.";
    it=s2.find(".",0);
    if(it!=-1)
    {
        s2.erase(it,1);
        len2--;
    }
    flag=0;
    for(int i=0;i<n;i++)
    {
        if(i>=len2)
        {
            ans2+="0";
        }
        else
        {
             if(s2[i]!='0'||flag==1)
            {
                ans2+=s2[i];
                flag=1;
            }
            else
            {
                n++;
            }
        }
    }
    ans2+="*10^";
     for(int i=0;i<len2;i++)
    {
        if(s2[i]!='0'&&s2[i]!='.')
        {
            flag2=1;
            break;
        }
    }
    if(flag2==0)
        mark2=0;
    if(ans1==ans2&&mark1==mark2)
    {
        printf("YES ");
        cout<<ans1<<mark1;
    }
    else
    {
        printf("NO ");
        cout<<ans1<<mark1<<" ";
        cout<<ans2<<mark2;
    }
}

