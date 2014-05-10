#Working,but TLE
 
import math
import sys
import random
import string
 
def isProbablePrime(n,k):
    if(n%2==0):
        return False
    d = n - 1
    s = 0
    while(d%2==0):
        d  = d//2
        s = s + 1
    #print s,d
    for i in range(0,k): # [0..k-1]
        a = random.randint(2, n-1 ) # [1..n-1]
        x = fastexp(a,d,n) #x as a variable name?duhh?! Algebra \m/
        temp = d
        while( temp!=n-1 and x!=1 and x!=n-1):
            temp = temp*2
            x = (x*x)%n
        if(x!=n-1 and temp%2==0):
            return False
    return True
 
def fastexp(a,b,mod):
    if(b==0):
        return 1
    if(b==1):
        return a
    result = fastexp(a,b//2,mod)
    if(b%2==0):
        return (result*result)%mod
    else:
        return (result*result*a)%mod #PYTHON, no overflows \m/
        
    
def main():
    a2i = string.atoi
    t = int(sys.stdin.readline())
    #t = map(a2i,sys.stdin.readline().split())
    #t =  int( input() )
    while(t>0):
        t = t - 1
        n = int(sys.stdin.readline())
        if(n==2):
            print "yes"
            continue
        if( isProbablePrime(n,5) == True ):
                print "YES"
        else:
                print "NO"
        
 
main()
