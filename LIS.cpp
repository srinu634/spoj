/*
Longest Increasing Subsequence Problem using O(n^2) Dynamic Programming
Bottom Up
*/

#include<iostream>
#include<vector>
#include <cstdlib>
#define MAX 700000
#define INF 1000000
typedef unsigned long long int ll;
using namespace std;

ll lis(ll arr[],ll dp_lis[]){
ll i,j,index;

for(i=0;i<MAX;i++)
         dp_lis[i] = 1;

for(i=0;i<MAX;i++)
         for(j=0;j<i;j++)
                  if( arr[j]<arr[i] && dp_lis[i] < (1+dp_lis[j]))
                           dp_lis[i] = dp_lis[j] + 1;
index = 0;
for(i=1;i<MAX;i++)
         if(dp_lis[index] < dp_lis[i])
                  index = i;

return dp_lis[index];
}

int main(){

ll dp_lis[MAX],i;
ll arr[] ={1,5,4,2,6,7,3};

//for(i=0;i<MAX;i++)
        // cout<<arr[i]<<" ";cout<<endl;

cout<<"Length is: "<<lis(arr,dp_lis)<<endl;

return 0;
}//lis
