// A DP based solution
// state[i][j] represents minrisk to reach from 0th to ith station within time j
// Approach somewhat similar to O(sum*n) for subset sum problem

#include<iostream>
#define inf 1000000
using namespace std;


int main(){

    int t,T,n,ti[120][120],risk[120][120],i,j,k;



    while(1){
        cin>>n>>t;

        if(n==0 && t==0) break;

        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>ti[i][j];

        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>risk[i][j];

        int dp[120][1000];

        for(i=0;i<n;i++)
            for(j=0;j<=t;j++)
                dp[i][j] = inf;

        for(i=0;i<=t;i++)
            dp[0][i] = 0;     // Base Case

        for(i=1;i<=t;i++)
            for(j=1;j<n;j++){
                int temp;
                temp = inf;
                for(k=0;k<n;k++)
                    if(i - ti[k][j] >= 0)
                        temp = min(temp,dp[ k ][ i - ti[k][j] ] + risk[k][j]);
                dp[j][i] = min(dp[j][i-1] ,temp );
                }

        for(i=t;i>=1;i--)
            if(dp[n-1][i] != dp[n-1][t])
                break;
        cout<<dp[n-1][t]<<" "<<i+1<<endl;

        }

    return 0;
}
