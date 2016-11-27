from math import *
from sys import setrecursionlimit,exit

setrecursionlimit(1000100)

graph=[]
visited=[]
pw=[1]

def pow2(n):
     while (len(pw)<n+1):
         pw.append(2*pw[-1])
     return pw[n]

def ordinalSum(x,tp=1):
    if(tp==0):
        if(x>=0):
            x+=1
        else:
            t=int(floor(x))
            t*=-1
            t+=1
            x+=t
            x/=pow2(t-1)
    else:
        if(x<=0):
            x-=1
        else:
            t=int(floor(x))
            t+=2
            x-=t
            x/=pow2(t-1)
    return(x)

def dfs(vert):
    ans=0.0
    visited[vert]=True
    for nbh in graph[vert]:
        if(visited[nbh[0]]):
            continue
        tmp=dfs(nbh[0])
        tmp=ordinalSum(tmp,nbh[1])
        ans+=tmp
    return(ans)

def main():
    t=int(input())
    for iii in xrange(t):
        n=int(input())
        graph[:]=[[] for i in xrange(n)]
        visited[:]=[False for i in xrange(n)]
        for i in xrange(n-1):
            (u,v,c)=map(int,raw_input().split(" "))
            graph[u-1].append((v-1,c));
            graph[v-1].append((u-1,c));
        ans=dfs(0)
        if(ans>0):
            print("Chef Chef")
        elif(ans<0):
            print("Ksen Ksen")
        else:
            print("Ksen Chef")
 
    exit(0)
main()
