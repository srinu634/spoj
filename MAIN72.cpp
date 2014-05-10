#include<stdio.h>
#include<iostream>
#include<cmath>
#include<map>
#define true 1
#define false 0
#define INF 100000
#define MAX 100008
#define N 105
#define print(x) printf("%d\n",x);
#define scan(x) scanf("%d",&x);
using namespace std;
typedef long double ld;
typedef int ll;

ll dp[MAX][N],a[N],isTrue[MAX];

ll solve(ll n,ll sum){
ll i,j,res;

for(i=0;i<=n;i++)
         dp[0][i] = true; //We always select Empty set in this case

for(i=1;i<=sum;i++)
         dp[i][0] = false;

for(i=0;i<=sum;i++)
         isTrue[i] = false;


for(i=1;i<=sum;i++)
         for(j=1;j<=n;j++){
                  dp[i][j] = dp[i][j-1]; // excluding
                  if( i - a[j] >= 0)
                           dp[i][j] = dp[i][j] || dp[i - a[j]] [j-1];
                  if(dp[i][j] == true)
                           isTrue[i] = true;
}

res = 0;
for(i=0;i<=sum;i++)
         if(isTrue[i] == true)
                  res += i;
return res;
}//solve


int main() {
ll n,t,i,j,sum;

scan(t);

while(t--){

scan(n);


for(i=1;i<=n;i++)
         scan(a[i]);
sum = 0;
for(i=1;i<=n;i++)
         sum += a[i];
print(solve(n,sum));
}

return 0;
}
