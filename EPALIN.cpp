#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#define max 1000005
#include<string.h>
using namespace std;

int table[max];
string revstr,str;


void reverse(int n) {
int i;

for(i=0;i<n;i++)
	revstr[i] = str[n-i-1];
}

void solve(string w,int m,string p,int n) {
int i,j;
i = 0;
j = 0;
//cout<<w<<" "<<p<<endl;

while( i < n) {


if	( p[i] == w[j]) {
	i++;
	j++;
}


else
if ( w[j]!=p[i])
if ( j == 0 )
		i++;
else
	j = table[j-1];
	}
int nonpalin;
nonpalin = p.size() - j;
cout<<p;
for(i=nonpalin-1;i>=0;i--)
cout<<p[i]; cout<<endl;
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
	count = 0;
	//std::ios_base::sync_with_stdio(false);
    ch = '!'; //Dummy character;

    while(1){
	 if(!(cin>>str))
    		break;
			revstr = str;
			reverse(str.size());
    preprocess(revstr,revstr.size() );

		solve(revstr,revstr.size(),str,str.size() );
    }
}


