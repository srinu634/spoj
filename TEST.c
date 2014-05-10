#include <stdio.h>
#include<iostream>
using namespace std;
int main(){
int x;
  unsigned int size;
  size = sizeof(long double);
  if(size==8)
	return 0;
  scanf ("%d",&x);
  while (x != 42){

    cout<<x<<"\n";

      scanf ("%d",&x);

    }

}
