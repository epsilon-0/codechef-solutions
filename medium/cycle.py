graph=[]
visited=[]

def dfs(v,parent):
    visited[v]=True
    iscycle=False
    for i in graph[v]:
        if(visited[i] and i!=parent):
            iscycle=True
            break
        if(not visited[i]):
            iscycle=dfs(i,v)
    return iscycle

def cycle():
    for i in range(len(graph)):
        if(not visited[i]):
               if(dfs(i,i)):
                   return True
    return False

def main():
    [n,m]=map(int,raw_input().split(" "))
    for i in range(n):
        graph.append([])
        visited.append(False)
    for i in range(m):
        [x,y]=map(int,raw_input().split(" "))
        x-=1
        y-=1
        graph[x].append(y)
        graph[y].append(x)
    print(cycle())
    
main()
