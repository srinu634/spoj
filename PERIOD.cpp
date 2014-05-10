#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#define max 1000005
#include<string.h>
using namespace std;

int table[max];


int gcd(int a,int b){
if ( a < b)
	swap(a,b);
if( b==0 )
	return a;
return gcd(b,b%a);
}


void solve(string w,int n) {
    int i,j,count;
    table[0] = 0; i = 1; j = 0;
    count=0;
    while(i<n){
        if (w[i] == w[j])
         table[i++] = ++j  ;
        else if(j == 0)
            table[i++] = 0; //No prefix/suffix match
        else
            j = table[j-1];//That is, the suffix which is less than w[1..j]

	}

	for(i=0;i<n;i++)
		if( table[i]>0 && (i+1)%(i+1-table[i]) == 0)
			printf("%d %d\n",(i+1),(i+1)/((i+1)-table[i]));;;



printf("\n");
}

int main( ) {
    int t,i,n,count;
    string str;
count = 0;
 //std::ios_base::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n; //scanf("%d",&n);
        cin>>str; //scanf("%s",str);;
        	printf("Test case #%d\n",++count);
		solve(str,str.size() );
    }
}


