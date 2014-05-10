#include<stdio.h>
#include<iostream>
using namespace std;



int main(){
int t,n,cre;
char ch;
long double sum;

cin>>t;
while(t--){
    cin>>n;
    sum=0;
    for(int i=0;i<n;i++){
        cin>>cre>>ch;
        if(ch=='S')
            sum+=10*cre;
        else if(ch=='A')
            sum+=9*cre;
             else if(ch=='B')
            sum+=8*cre;
             else if(ch=='c')
            sum+=7*cre;
             else if(ch=='D')
            sum+=6*cre;
            else sum+=5*cre;

}
sum/=n;
printf("%.2lf\n",sum);
}



return 0;
}
