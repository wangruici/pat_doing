#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
const int MAXN = 100000 + 5;
const int MAXM = 100000 + 5;
const int INF = 0x7f7f7f7f;
template <class XSD> inline XSD f_min(XSD a, XSD b) { if (a > b) a = b; return a; }
template <class XSD> inline XSD f_max(XSD a, XSD b) { if (a < b) a = b; return a; }
int n, m;
int cnt;
char s[MAXN];
double sum;

bool Is_legal(){
    int len=strlen(s), len0=len;
    int op=(s[0]=='-');
    for(int i=0; i<len; i++){
        if((s[i]<'0' || s[i]>'9') && s[i]!='.' && s[i]!='-') return false;///不合法ASCII
        if(s[i]=='-' && i) return false;///'-'首位
        if(s[i]=='.'){///精确度
            if(s[len] || len-i>3) return false;
            len = i;
        }
    }
    double inter=0, dot=0, ans;
    for(int i=op; i<len; i++) inter = inter*10+(s[i]-'0');///整数
    for(int i=len0-1; i>len; i--) dot = (dot+s[i]-'0')/10;///小数
    ans = inter+dot;
    if(ans>1000.0) return false;
    else{
        if(op) sum+=(-ans);
        else sum+=ans;
        //sum += (op?-1:1)*ans;
        return true;
    }

}
void Getdata(){
    sum=0.0;
    cnt=0;
    for(int i=0; i<n; i++){
        scanf("%s", s);
        if(Is_legal()) cnt++;
        else printf("ERROR: %s is not a legal number\n", s);
    }
}

void Solve(){
    if(!cnt) printf("The average of 0 numbers is Undefined\n");
    else printf("The average of %d number%s is %.2f\n", cnt, cnt==1?"":"s", sum/cnt);
}
int main(){
    while(~scanf("%d", &n)){
        Getdata();
        Solve();
    }
    return 0;
}
