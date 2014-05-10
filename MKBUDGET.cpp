#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i,n) for(i=1;i<=n;i++)
typedef long long ll;

int main(){

    ll mon,cnt[30],sal,sev,hir,dp[30][30],i,j,k,count;

    count = 0;

    while(true){

        cin>>mon;
        if(mon==0)  break;

        cin>>hir>>sal>>sev;

        for(i=1;i<=mon;i++)
            cin>>cnt[i];

        //1st month
        rep(i,mon)
            rep(j,30)
            dp[i][j] = 100000000;

        for(i=cnt[1];i<=30;i++)
            dp[1][i] = (hir+sal)*i;    //base case

        for(i=2;i<=mon;i++)
            for(j=1;j<=30;j++)
                if(j >= cnt[i])
                    for(k=1;k<=30;k++)
                        if(k<j)
                            dp[i][j] = min( dp[i][j], dp[i-1][k] + (j-k)*hir  + sal*j) ;
                        else
                            dp[i][j] = min( dp[i][j], dp[i-1][k] + (k-j)*sev  + sal*j);

        ll temp;
        temp = dp[mon][1];

        rep(i,30)
            if(temp > dp[mon][i])
                temp = dp[mon][i];

        cout<<"Case "<<++count<<","<<" cost = $"<<temp<<endl;

    }

    return 0;
}
