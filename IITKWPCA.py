#WA
from sets import Set
from sys import stdin


lines = stdin.readlines()
for read in lines[1:]:
    
    a = Set([])
    read = read.strip()
    #read = " ".join(read.split())
    tokens = read.split( )
    length = len(tokens)
    for token in tokens: 
        a.add(token)
    if( len(a) != 0 ):
        print len(a)
	

