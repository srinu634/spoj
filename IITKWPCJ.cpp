#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#define max 1000005
#include<string.h>
using namespace std;

int table[max];

int preprocess(string w,int n) {
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

	if(table[n-1]>0 && (n)%(n-table[n-1])==0)
        return n/((n)/(n-table[n-1])); //len/period
    else
        return -1;
}

int main( ) {
    int t,i,n,count,flag;
	string p,w,tstr;
	int wroot,proot;
	std::ios_base::sync_with_stdio(false);

    cin>>t;

    while(t--){
    cin>>w;
	cin>>p;
    flag = 1;
	if( w.size()>p.size()){
        tstr = w;
        w = p;
        p = tstr;
	}

    wroot = preprocess(w,w.size() );
    proot = preprocess(p,p.size() );
    cout<<wroot<<" "<<proot<<endl;

    if(wroot == -1 && proot == -1){
        if(w==p) flag = 1; else flag = 0;
    }
    else if (wroot == -1 && proot != -1){
        if(w.size()!=proot)       flag=0;
        else  for(i=0;i<proot;i++) if(w[i]!=p[i]) flag = 0;
    }
    else if( wroot !=-1 && proot == -1)
        flag = 0;
    else {
        if(wroot !=proot)
            flag = 0;
            else
    for(i=0;i<wroot;i++)
        if(w[i]!=p[i])
            flag=0;

    }


    if(flag==0)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
    }

    }



