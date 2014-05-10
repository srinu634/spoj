/*
-> To implement Djikstra's algorithm using Heaps
-> Each operation takes O(logn)
-> So , the algorithm is : O( E+V )*logn
-> I can also use #include<queue>
-> The main problem comes when searching in heap, this can be reduced to O(logn)
         by using maps to store index of each element in the heap
*/

#include<iostream>
#include<cmath>
#include<cstdio>
#include <cstdlib>
#include<string>
#include<algorithm>
#include<cstring>
#include<map>
#define MAX 10008
#define INF 10000000
#define true 1
#define false 0
using namespace std;
typedef long long ll;
map<string, ll> str_int;
map<ll,ll> m; // To find the heapindex using map in O(logv)

struct node {
ll d;
ll c;
struct node *next;
};

struct node * v[MAX];
ll visited[MAX],pq[MAX];

ll t,n,p,dest,cost,source,a,b,q,i,j,len;

ll djikstra(ll s,ll d){
ll i,j;

}//djikstra

void add(ll s,ll d,ll c){
struct node * temp;

temp = v[s];

v[s] = (struct node *) malloc(sizeof(struct node));
v[s]->d = d;
v[s]->c = c;
v[s]->next = temp;

}

void swim_down(ll index) { // O(logn)

         int left,right,min_index;
         left = 2*index+1;
         right= 2*index+2;

         if(left>len)
                  return; //Out of index : Base Case
         if(left<=len)
                  min_index =  pq[index] < pq[left]? index:left ;

         if(right<=len)
                  min_index = pq[min_index] < pq[right]? min_index:right ;

         swap(pq[min_index],pq[index]);

         if(min_index != index)
                  swim_down(min_index);   //Recursive
}

void swim_up(ll index){
int p_index;
if(index&1)
         p_index = (index-1)/2;
else
         p_index = (index-2)/2;

if(p_index < 0)
         return;

if( pq[p_index] > pq[index]){
         swap(pq[p_index],pq[index]);
         swim_up(p_index);
         }
}


ll remove_min( ){   //O(logn)
int min;

min = pq[0]; // Min PQ
if(len == 0){
         len = len  - 1;
         return min;
}
if(len == -1)
         return -1;

pq[0] = pq[len];
len = len - 1;
swim_down(0);
return min;
}

void heapify( ){
ll i;

for(i = len/2 ; i>=0; i--)
         swim_down(i);
}



int  main(){
string str,str1,str2;
std::ios_base::sync_with_stdio(false);

cin>>t;

while(t--){
cin>>n;

for(i=0;i<MAX;i++)
        v[i] = NULL;

         for(i=0;i<n;i++)
         {
                  cin>>str;
                  str_int[str]=i;
                  cin>>p;
                  while(p--){
                  cin>>dest>>cost;
                  dest--; // 0 based index
                  add(i,dest,cost); //Add the vertex
                  }
         }

cin>>q;

while(q--){
         len = n - 1;
         cin>>str1>>str2;
         a = str_int.find(str1)->second;
         b = str_int.find(str2)->second;
         djikstra(a,b);
}//q
 }//t


return 0;
}//main


