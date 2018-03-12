#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
/*
并查集
*/
const int maxn=10000+5;
int vis[maxn];
struct UF{
    int father[maxn];
    void init(){
        for(int i=0;i<maxn;i++){
            father[i]=i;
        }
    }
    int find_root(int x){
        if(father[x]!=x){
            father[x]=find_root(father[x]);
        }
        return father[x];
    }
    void Union(int a,int b){
        int fa=find_root(a);
        int fb=find_root(b);
        if(fa!=fb){
            father[max(fa,fb)]=min(fa,fb); //最小编号的作为祖先
        }
    }
}uf;

struct Person{
    int id;
    int dad,mom;
    int k;
    int child[5];
    int m_estate;
    int area;
}person[maxn];

struct Family{
    int minid;  //家庭成员最小编号
    int m=0;  //家庭人口数
    int m_estate=0;  //总房产数目
    int totarea=0;   //总房产面积
    float AVG_sets;  //人均房产个数
    float AVG_area;  //人均房产面积
    bool operator<(const Family tmp)const{
        if(AVG_area==tmp.AVG_area){
            return minid<tmp.minid;
        }
        else{
            return AVG_area>tmp.AVG_area;
        }
    }
}family[maxn];

int main()
{
    int n,id;
    scanf("%d",&n);
    uf.init();
    memset(vis,0,sizeof(vis));
    for(int i=0;i<maxn;i++)
        person[i].id=-1;
    for(int i=0;i<n;i++){
        scanf("%d",&id);
        person[id].id=id;
        scanf("%d %d %d",&person[id].dad,&person[id].mom,&person[id].k);
        vis[person[id].id]=1; //标记出现过的编号
        if(person[id].dad!=-1){
            uf.Union(id,person[id].dad);
            vis[person[id].dad]=1;
        }
        if(person[id].mom!=-1){
            uf.Union(id,person[id].mom);
            vis[person[id].mom]=1;
        }
        for(int j=0;j<person[id].k;j++){
            scanf("%d",&person[id].child[j]);
            uf.Union(id,person[id].child[j]);
            vis[person[id].child[j]]=1;
        }
        scanf("%d %d",&person[id].m_estate,&person[id].area);
    }
    int idArray[maxn];
    int cnt=0;
    for(int i=0;i<maxn;i++){
        if(vis[i]==1){
            idArray[cnt++]=i;  //出现过的编号存起来
        }
    }
    memset(vis,0,sizeof(vis));
    int u,fa;
    for(int i=0;i<cnt;i++){
        u=idArray[i];
        fa=uf.find_root(idArray[i]);
        vis[fa]=1;  //标记父亲节点
        family[fa].minid=fa;
        family[fa].m++;
        if(person[u].id!=-1){
            family[fa].totarea+=person[u].area;
            family[fa].m_estate+=person[u].m_estate;
        }
    }
    int familyNum=0;
    for(int i=0;i<maxn;i++){
        if(vis[i]){
            familyNum++;
            family[i].AVG_sets=family[i].m_estate*1.0f/family[i].m;
            family[i].AVG_area=family[i].totarea*1.0f/family[i].m;
        }
    }
    sort(family,family+maxn);
    printf("%d\n",familyNum);
    for(int i=0;i<familyNum;i++){
        printf("%04d %d %.3f %.3f\n",family[i].minid,family[i].m,family[i].AVG_sets,family[i].AVG_area);
    }
    return 0;
}
