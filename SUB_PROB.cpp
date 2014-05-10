#include<string.h>
#include<stdio.h>
#define max 100005


int table[max],flag;



void solve(char * w,int m,char * p,int n) {
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
	flag = 1;
	return;
	j = table[j-1];
}

else
    if ( w[j]!=p[i]){
        if ( j == 0 )
            i++;
        else
            j = table[j-1];
	}
    }
	}



void preprocess(char * w,int n) {
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
	char str[2100],str1[100005];
	count = 0;

    scanf("%s",str1);

     scanf("%d",&n);

    while(n--){
        flag = 0;
         scanf("%s",str);

        preprocess(str,strlen(str) );
		solve(str,strlen(str),str1,strlen(str1) );

        if(flag == 0 )
            printf("N\n");
        else
            printf("Y\n");
    }

    return 0;
}
