#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include <cstdlib>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;

#define mod 1000000007
#define pi 3.14159265358979323846264338327950288419716939937510582
#define inf 1000000000+100

#define loop(i,n) for(i=0;i<n;i++)
#define revfor(i,n) for(i=n-1;i>=0;i--)
#define scan(x) scanf("%lld",&x);
#define print(x) printf("%lld\n",x);

typedef long long int lli;
typedef unsigned long long int llu;
lli gcd(lli a,lli b){ if(a<b) swap(a,b); if(b==0)return a; return gcd(b,b%a); }


lli dp[1050][2000];

int main(){
lli t,a,h,i,j;


for(i=1;i<=5;i++)
    for(j=1;j<=1500;j++)
        dp[i][j] = 1;

for(i=6;i<=20;i++){
    for(j=1;j<=10;j++)
        dp[i][j] = 1;
    for(j=11;j<=1500;j++)
        dp[i][j] = 2 + dp[i-2][j-8];
}

for(i=21;i<=1020;i++) {
    for(j=1;j<=10;j++)
        dp[i][j] = 2 + dp[i-17][j+7];

    for(j=11;j<=1500;j++)
        dp[i][j] = 2 + max(dp[i-2][j-8],dp[i-17][j+7]);
}


cin>>t;
while(t--){
        cin>>h>>a;

    h +=3; a+=2;
cout<<dp[h][a]<<endl;

}//t


return 0;
}//main

