/*
Longest Common Subsequence Problem using O(n*m) Dynamic Programming
Bottom Up
*/

#include<iostream>
#include<vector>
#include <cstdlib>
#define MAX 2005
#define INF 1000000
typedef unsigned long long int ll;
using namespace std;

ll dp[MAX][MAX];

ll lcs(string str1,string str2){
         ll n,m,i,j;

         n = str1.length();
         m = str2.length();

         for(i=0;i<=n;i++)
                  for(j=0;j<=m;j++)
                           if(i==0 || j==0)
                                    dp[i][j] = 0;
                           else if( str1[i] == str2[j])
                                    dp[i][j] = 1 + dp[i-1][j-1];
                           else
                                    dp[i][j] = max( dp[i-1][j],dp[i][j-1] );
return dp[n][m];
}

int main(){
string str1,str2;

cin>>str1>>str2;
cout<<"Length of LCS is: "<<lcs(str1,str2)<<endl;

return 0;
}//lis
