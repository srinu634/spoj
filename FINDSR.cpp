#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#define max 1000005
#include<string.h>
using namespace std;

int table[max];





void solve(string w,int n) {
	int root;
    int i,j,count;
    table[0] = 0; i = 1; j = 0;
    count=0;
	root = 1;
    while(i<n){
        if (w[i] == w[j])
         table[i++] = ++j  ;
        else if(j == 0)
            table[i++] = 0; //No prefix/suffix match
        else
            j = table[j-1];//That is, the suffix which is less than w[1..j]

	}

//	for(i=0;i<n;i++)
i = n-1;
		if( table[i]>0 && (i+1)%(i+1-table[i]) == 0)
			if (  (i+1)/( (i+1)-table[i] ) >root)
				root = (i+1)/ (( i+1)-table[i]);


	cout<<root;
cout<<endl;//printf("\n");
}

int main( ) {
    int t,i,n,count;
    string str;
count = 0;
 std::ios_base::sync_with_stdio(false);

    while(1){
      ; //scanf("%d",&n);
         cin>>str   ;//scanf("%s",str);;
        	if ( str[0] == '*' ) break;
		solve(str,str.size() );
    }
}




