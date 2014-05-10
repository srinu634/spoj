 /*
 -> Build a tree like structure w.r.t set numbers
 -> Break the vertices intosets
 -> If they belong to the same set, that means the edge will introduce a cycle
 -> The simplest form of Union-Find DS is enough to get an AC :)
 -> If you want to further have a look on Union-Find, please read this:
http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=disjointDataStructure
*/

#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include <cstdlib>
#include<string>
#include<algorithm>
#include<cstring>
#define true 1
#define false 0
typedef long long int lli;
using namespace std;
int id[1005];

int Find(int i)
{
    if (id[i] == i)
        return i;
    return Find( id[i] );
}

void Union(int x, int y)
{
    int xset = Find( x);
    int yset = Find( y);
    id[xset] = yset;
}

struct edge{
lli a;
lli b;
lli c;
}e[300100];

int cmpfun(const void *a, const void *b)
{
    const struct edge *ia = (const struct edge *)a; // casting pointer types
    const struct edge *ib = (const struct edge *)b;
    return (ia->c  - ib->c);
}

int main(){
lli t1,t2,p,n,m,count,i,cost;

cin>>t1;
while(t1--){
    cost = 0;
    count = 0;
    cin>>p>>n>>m;
    for(i=1;i<=n;i++)
        id[i] = i; //each vertex is a forest
    t2=m; i = 0;
    while(t2--){
        cin>>e[i].a>>e[i].b>>e[i].c;
        i++;
    }
    qsort(e,m,sizeof(struct edge),cmpfun);
    count = 0;
    i = 0;

    while(i<m){
    if(Find(e[i].a)!=Find(e[i].b))
    {

        Union(e[i].a,e[i].b);
        cost += e[i].c;
    }
    i++;
    }
    cout<<cost*p<<endl;
}//t1



return 0;
}
