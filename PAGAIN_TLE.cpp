#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0
#define scan(x) scanf("%lld",&x);
#define print(x) printf("%lld\n",x);
typedef unsigned long long int lli;
using namespace std;

lli overflowmult(lli a,lli b,lli mod)
{
	lli  c;
	long double ans;
	a=a%mod;
	b=b%mod;

	ans=(long double)a*b;
	a=a*b;
	c=(long long)(ans/mod);
	a=a-c*mod;

	a=a%mod;
	if(a<0)
	  a=a+mod;

	return a;
}

lli fastexp(lli base,lli  exp,lli mod)
{
	lli ans=1;
	base=base%mod;
	while(exp>0)
	{
		if(exp&1==1)
			ans=overflowmult(ans,base,mod);

		base=overflowmult(base,base,mod);
		exp=exp>>1;
	}

	return ans;
}

lli isProbablePrime(lli n,lli k){
lli s,d,a,i,j,t,x;
if(n%2==0)
    return false;
d=n-1;
while(d%2==0)
    d/=2;

for(i = 0;i < k; i++) {
    a  = rand()%(n-1) + 1; // [1..n-1]
    t = d;
    x = fastexp(a,d,n);

   while(t!=n-1 && x!=1 && x!=n-1)
   {
       t *= 2;
       x = (x*x)%n;
   }
   if(x!=n-1 && t%2==0)
    return false;
}
return true;
}  //isProbablePrime




int main(){
int t,n;


cin>>t;

while(t--){
cin>>n;
n--;
if(n==2){ cout<<n<<endl; continue;} //base case
while(n){
        if( isProbablePrime(n,2) == true)
         {
             cout<<n<<endl;
             break;
         }
         n--;
}

}
return 0;
}
