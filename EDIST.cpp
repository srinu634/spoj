 #include<iostream>
 #include<algorithm>
 #define maxi 2500
 using namespace std;
 
 int mini(int a,int b,int c ) { 
 int t;  t = a;
if (b<t ) t = b;
if (c<t) t = c;
 return t;
 }
 
 int main( ) { 
	
	int i,j,t,xlen,ylen;
	int dp[maxi][maxi];
	string x,y;
	cin>>t;
	while(t--) { 
	cin>>x ;
	cin>>y;
	
	for(i=0;i<maxi;i++)
		for(j=0;j<maxi;j++)
			dp[i][j] = 0;
	
	xlen = x.size();
	ylen = y.size();
	
	dp[0][0] = x[0]==y[0]?1:0;
	for(i=1;i<xlen;i++)
		dp[0][i] = 1 + dp[0][i-1];
	for(i=1;i<ylen;i++)
		dp[i][0] = 1 + dp[i-1][0];
		
	for(i=0;i<xlen;i++)
		for(j=0;j<ylen;j++)
			if (i==0 || j==0 )
				continue;
			else
			{   int temp; 
				temp = x[i]==y[j]?0:1;
				dp[i][j] = mini( dp[i-1][j-1] ,1 + dp[i-1][j], 1 + dp[i][j-1]  ); 
			}
	cout<<dp[xlen-1][ylen-1]<<endl;;
	}
 
 
 return 0;
 }