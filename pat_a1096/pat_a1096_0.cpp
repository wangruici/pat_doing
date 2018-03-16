#include<iostream>
#include<map>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<set>
#include<stack>
#include<cmath>
#include<vector>
#include<hash_map>
#define ll long long
#define inf 24*60*60
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int maxx=-5;
    int biaoji;
    int r=n;
    int sum=0;
    int flag=0;
    int mark;
    for(int i=2;i<=r;i++)
    {
        if(r%i==0)
        {
            if(flag==0)
            {
                mark=i;
                flag=1;
            }
            sum++;
            if(sum>maxx)
            {
                maxx=sum;
                biaoji=i;
            }
            r/=i;
        }
        else
        {
            if(flag==1)
            {
                sum=0;
                r=n;   
                flag=0;
                i=mark;
            }
            if(i>sqrt(r))
            {
              break;
            }
        }
    }
    if(maxx==-5)
    {
        printf("1\n");
        printf("%d",n);
        return 0;
    }
    printf("%d\n",maxx);
    for(int i=biaoji-maxx+1;i<=biaoji;i++)
    {
        if(i==biaoji-maxx+1)
        {
            printf("%d",i);
        }
        else
        {
            printf("*%d",i);
        }
    }
}

