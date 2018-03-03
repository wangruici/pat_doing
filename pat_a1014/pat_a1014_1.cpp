#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=1000+5;
int n,m,k,q;
struct Customer{
    int line;
    int start_time=0;
    int end_time=0;
    int process_time;
    bool operator<(const Customer tmp)const{
        /*
        取队列中最早结束的，如果时间一样，取窗口id最小的
        */
        if(end_time==tmp.end_time)
            return line>tmp.line;
        else
            return end_time>tmp.end_time;
    }
}cus[maxn];
int query[maxn];
int finish_time[maxn];
int main()
{
    scanf("%d %d %d %d",&n,&m,&k,&q);
    for(int i=1;i<=k;i++){
        scanf("%d",&cus[i].process_time);
    }
    for(int i=1;i<=q;i++){
        scanf("%d",&query[i]);
    }
    priority_queue<Customer>queueline;
    int cnt=0;
    Customer tmp;
    int linetime[maxn];
    memset(linetime,0,sizeof(linetime));
    //对于前m*n个人，往队列里插即可
    for(int i=1;i<=m && cnt<k;i++){
        for(int j=0;j<n && cnt<k;j++){
            cnt++;
            tmp.line=j;
            tmp.start_time=linetime[j];
            tmp.end_time=linetime[j]=tmp.start_time+cus[cnt].process_time;
            cus[cnt].line=j;
            cus[cnt].start_time=tmp.start_time;
            cus[cnt].end_time=tmp.end_time;
            queueline.push(tmp);
        }
    }
    Customer c;
    for(int i=cnt+1;i<=k;i++){
        //取出结束时间最早的
        tmp=queueline.top();
        queueline.pop();
        c.line=tmp.line;
        c.start_time=linetime[tmp.line];
        c.end_time=linetime[tmp.line]=c.start_time+cus[i].process_time;
        cus[i].line=c.line;
        cus[i].start_time=c.start_time;
        cus[i].end_time=c.end_time;
        queueline.push(c);
    }
    int cid;
    int maxtime=(17-8)*60;
    for(int i=1;i<=q;i++){
        cid=query[i];
        ///原来开始的时间包括17:00。。。只要是17:00或者是以后的，就不被服务
        ///原来写的是>，结果一部分样例一直没过，还以为自己前面写错了
        if(cus[cid].start_time>=maxtime)
            printf("Sorry\n");
        else{
            int hour=cus[cid].end_time/60;
            int minu=cus[cid].end_time%60;
            printf("%02d:%02d\n",hour+8,minu);
        }
    }
    return 0;
}
