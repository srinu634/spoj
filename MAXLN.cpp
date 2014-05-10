#include<stdio.h>
#include<iostream>
using namespace std;
int main( ) {
long double m,t;
long double n;
cin>>t;
int i;
i = 0;

while(t--) {

cin>>n;

printf("Case %d: %.2llf\n",++i,4*n*n+0.25);
}


}

