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
using namespace std;



int main(){
    int i,t,m,n,u,v,flag,visited[100000];
    cin>>m>>n;
    t=n;
    flag=true;
    for(i=0;i<m;i++)
        visited[i]=false;

    while(t--){
            scanf("%d %d",&u,&v);
        if(visited[u]&&visited[v])
            flag=false;
        visited[u]=true;visited[v]=true;
    }
    if((m != n+1) || flag==false)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;


return 0;
}

