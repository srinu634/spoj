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
#define MAX 50006
#define scan(x) scanf("%lld",&x);
#define print(x) printf("%lld\n",x);
typedef unsigned long long int lli;
using namespace std;

void add(lli a,lli b,lli c);
void display(struct node*);
void dfs(lli vno,lli);

lli visited[MAX],maxcost,vnum;

struct node{
lli a;
lli b;
lli c;
struct node *next;
}*v[MAX];


int main(){
lli t1,t2,n,a,b,i,c;
scan(t1);

while(t1--){
    scan(n);
    for(i=1;i<=n;i++){
        visited[i]=false;
        v[i]=NULL;
    }

    t2=n-1;
    while(t2--){
        scan(a);scan(b);scan(c);
        add(a,b,c);
        add(b,a,c);
    }
    maxcost = 0;vnum=1; //Global variables
    dfs(vnum,0); //start dfs from vertex#1
    //cout<<maxcost<<" "<<vnum<<endl;
     for(i=1;i<=n;i++)
        visited[i]=false;
    dfs(vnum,0); //Start from the most distant from this vertex
   // cout<<maxcost<<" "<<vnum<<endl; //Global variable updated during dfs
   print(maxcost);
}

return 0;
}

void dfs(lli vno,lli cost){
    struct node *trav,*prev;
    trav=v[vno];
    prev=NULL;
    visited[vno]=true;
    //cout<<"visited so far: "<<vno<<endl;
    while(trav!=NULL){
        if(visited[trav->b]==false){
               // cout<<trav->b<<endl;
            visited[trav->b]=true;
            dfs(trav->b,cost+trav->c);
        }
        prev=trav;
        trav = trav->next;
    }

    if(maxcost<cost){
        maxcost=cost;
        vnum=prev->a;
    }
   // cout<<"cost till here: "<<cost<<endl;

}

void display(struct node *temp){
if(temp==NULL){
    cout<<endl;
    return;
}
cout<<temp->a<<" "<<temp->b<<" "<<temp->c<<endl;
display(temp->next);
}

void add(lli a,lli b,lli c){
struct node* temp;
temp = v[a];
v[a] = (struct node *)malloc(sizeof(struct node));
    v[a]->next=temp;
    v[a]->a=a;
    v[a]->b=b;
    v[a]->c=c;
}
