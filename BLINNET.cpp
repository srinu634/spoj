 /*
 -> Build a tree like structure w.r.t set numbers
 -> Break the vertices into sets
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
#define rep(i,n) for(i=0;i<n;i++)
#define revrep(i,n) for(i=n-1;i>=0;i--)
#define scan(x) scanf("%lld",&x);
#define print(x) printf("%lld\n",x);
typedef long long int lli;
using namespace std;
int id[100005],size[1000005];

int Find(int i)
{
    if (id[i] == i)
        return i;
    id[i]= Find( id[i] );
 return id[i];
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
lli t1,t2,p,n,m,i,cost,cityid,count;
char str[40]; //i do not need need the city names, just assign a unique id to each id, say starting from 10008

scan(t1);
while(t1--){
    cost = 0;
    cityid=1;
    count = 0;
    m=0;
    cin>>n;
    for(i=0;i<=200009;i++)
        id[i]=i;
    for(i=1;i<=n;i++){
   scanf("%s",str); scan(p);
     while(p--){
        e[count].a = cityid;
        scan(e[count].b);scan(e[count].c);
        count++;
	}
    cityid++;
    }
    qsort(e,count,sizeof(struct edge),cmpfun);

    i = 0;

    while(i<count){
    if(Find(e[i].a)!=Find(e[i].b))
    {

        Union(e[i].a,e[i].b);
        cost += e[i].c;
    }
    i++;
    }
    print(cost);
}//t1



return 0;
}


