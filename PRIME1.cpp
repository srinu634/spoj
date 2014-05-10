#include <iostream>
#include<stdio.h>
typedef long long int lli;
#define scan(x) scanf("%lld",&x);
#define print(x) printf("%lld\n",x);
#define MAX 400001
using namespace std;

lli n[MAX],prime[MAX],primecount,sieve[100000];

void generatePrime()  {         // Sieve of Eratosthenes
int i,j; //iterators
primecount=0;

for(i=0;i<=MAX;i++)
n[i]=i;

for(i=2;i<=MAX;i++)
	if( n[i]!=0 )
		for(j=2*n[i];j<=MAX;j+=n[i])
			n[j]=0;

for(i=2;i<=MAX;i++)
	if(n[i] != 0)
		prime[primecount++]=n[i];
}

lli solve(lli l,lli r) {
lli diff,i,j,count;

diff = r-l+1;

for(i=0;i<diff;i++)
	sieve[i] = 1; //All are true initially

for(i=0;i<primecount;i++) { lli start;
if ( l%prime[i]==0)
	start = l;
else
	start = ( l/prime[i])*(prime[i]) + prime[i];

if ( start == prime[i]) start += prime[i];
while(start <=  r) {	sieve[start-l] = 0;  start += prime[i]; }
}

if(l==1)
	sieve[0] = 0;

for(i=0;i<diff;i++)
	if(sieve[i] !=0 )
		cout<<l+i<<endl;

}//solve




int main() {

lli l,r,t;
generatePrime();
cin>>t;

while(t--) {
cin>>l; cin>>r;
solve(l,r) ;
}

	return 0;
}
