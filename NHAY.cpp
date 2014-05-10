#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#define max 1000005
#include<string.h>
using namespace std;

int table[max];



void solve(string w,int m,string p,int n) {
int i,j;
i = 0;
j = 0;


while( i < n) {
	//Do something magically awesome/ Implement KMP.

if	( p[i] == w[j]) {
	i++;
	j++;
}


if (j == m ){
	cout<<i - j<<endl;
	j = table[j-1];
}

else
if ( w[j]!=p[i])
if ( j == 0 )
		i++;
else
	j = table[j-1];
	}
cout<<endl;
	}



void preprocess(string w,int n) {
    int i,j,count;
    table[0] = 0; i = 1; j = 0;

    while(i<n){
        if (w[i] == w[j])
         table[i++] = ++j  ;
        else if(j == 0)
            table[i++] = 0; //No prefix/suffix match
        else
            j = table[j-1];//That is, the suffix which is less than w[1..j]

	}
}

int main( ) {
    int t,i,n,count;
    char ch;
	string p,w;
	count = 0;
	std::ios_base::sync_with_stdio(false);
    ch = '!'; //Dummy character;

    while(1){
	 if(!(cin>>n))
    		break;

        cin>>w;
	cin>>p;

    preprocess(w,w.size() );

		solve(w,w.size(),p,p.size() );
    }
}

