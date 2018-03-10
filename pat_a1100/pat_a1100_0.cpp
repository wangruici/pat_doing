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
char a[13][5]={"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
char b[13][5]={"tret","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
char c[105][50];
map<string,int> mm;
map<string,int> nn;
int main()
{
    int n;
    for(int i=0;i<13;i++)
    {
        string s=a[i];
        string ss=b[i];
        mm[s]=i;
        nn[ss]=i;
    }
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {
        gets(c[i]);
        if(c[i][0]>='0'&&c[i][0]<='9')
        {
            int sum=0;
            for(int j=0;j<strlen(c[i]);j++)
            {
                sum*=10;
                sum+=c[i][j]-'0';
            }
            if(sum/13==0)
            {
                printf("%s\n",a[sum]);
            }
            else
            {
                int tmp=sum/13;
                printf("%s",b[tmp]);
                if(sum%13==0)
                {
                    printf("\n");
                }
                else
                {
                    printf(" %s\n",a[sum%13]);
                }
            }
        }
        else
        {
            string tmp="";
            int flag=0;
            int j;
            for( j=0;j<strlen(c[i]);j++)
            {
                if(c[i][j]==' ')
                {
                    flag=1;
                    break;
                }
                else
                {
                    tmp+=c[i][j];
                }
            }
            if(flag==0)
            {
                if(mm.find(tmp)==mm.end())
                {
                    printf("%d\n",nn[tmp]*13);
                }
                else
                {
                    printf("%d\n",mm[tmp]);
                }
            }
            else
            {
                string gg="";
                for(int z=j+1;z<strlen(c[i]);z++)
                {
                    gg+=c[i][z];
                }
                printf("%d\n",nn[tmp]*13+mm[gg]);
            }
        }
    }

}
