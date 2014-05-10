#include<iostream>
#include<cmath>
#define max 10005
#define MAX 10005
using namespace std;

long long int dp[max];
int prime[max],primecount;
int n[max];

void generatePrimes()  {         // Sieve of Eratosthenes
int i,j; //iterators
primecount=0;

for(i=0;i<MAX+1;i++)
n[i]=i;

for(i=2;i<MAX+1;i++)
	if( n[i]!=0 )
		for(j=2*n[i];j<MAX+1;j+=n[i])
			n[j]=0;

for(i=2;i<MAX+1;i++)
	if(n[i] != 0)
		prime[primecount++]=n[i];
}

void generateDP(){

int i,j;
long long int ans;
//For each of the 10^4 elements, see which prime numbers divide the,store the totient.

for(i=1;i<=10000;i++){
        ans = i;
    for(j=0;j<primecount;j++)
        if(i%prime[j] == 0 ) {
            ans *= (prime[j] -1);
            ans /= prime[j];
        }
    dp[i] = ans;
}


for(i=2;i<=10000;i++)
    dp[i] += dp[i-1];

}

int main( ) {
int t,a,b;
cin>>t;
generatePrimes();
generateDP();
//cout<<primecount<<endl;

while(t--){
    cin>>a;
    cout<<dp[a]*dp[a]<<endl;
}


return 0;
}
