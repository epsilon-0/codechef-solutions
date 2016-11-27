import sys
Input = [ i.strip() for i in sys.stdin.readlines()];
tlength = len(Input);
 
## Global Variables.
t1 = 0
n = 0;
p = 0;
Nodes = 0;
Inp = []
troublers = []
Parent = []
newGraph = []
newMatrix = []
 
 
def getNext():
    global t1;
    while(Input[t1] == ""):
        t1 += 1;
    assert t1 < tlength; t1 += 1
    return Input[t1-1]
 
def gcd(x,y):
    if(not y):
        return x;
    return gcd(y,x%y);
 
def getParent(x):
    global Parent;
    if(Parent[x] != x):
        Parent[x] = getParent(Parent[x]);
    return Parent[x]
 
def doUnion(x,y):
    Parent[getParent(x)] = getParent(y); 
 
def Determinant():
    global newMatrix;
    ret = Div = 1;
    for i in xrange(0,Nodes):
        tmp = i;
        while(tmp < Nodes and (not newMatrix[tmp][i])): 
            tmp += 1;
        if(tmp == Nodes):
            return 0
        if(tmp != i):
            newMatrix[i], newMatrix[tmp] = newMatrix[tmp], newMatrix[i];
            ret *= -1
        for j in xrange(i+1,Nodes):
            if(not newMatrix[j][i]):
                continue;
            tmp  = gcd(newMatrix[i][i], newMatrix[j][i]);
            tmp1 = newMatrix[i][i] / tmp;
            tmp2 = newMatrix[j][i] / tmp;
            
            for k in xrange(i,Nodes):
                newMatrix[j][k] = newMatrix[j][k] * tmp1 - newMatrix[i][k] * tmp2;
            Div *= tmp1;
    
    for i in xrange(0,Nodes):
        ret *= newMatrix[i][i];
    return ret/Div;
            
        
 
kases = int(getNext())
for tkases in xrange(0,kases):
    
    Inp = []
    troublers = []
    
    n = int(getNext());
    for i in xrange(0,n):
        Inp.append(getNext());
    
    p = int(getNext());
    
    for i in xrange(0,p):
        x,y = map(int,getNext().split(' '));
        x -= 1; y -= 1;
        troublers.append((x,y));
    
    ## Start Processing.
    Parent = [i for i in xrange(0,n+1)];
    isCycle = False;
    
    for i in xrange(0,p):
        x,y = troublers[i]
        if(getParent(x) == getParent(y)):
            isCycle = True;
            break;
        doUnion(x,y);
    
    if(isCycle):
        print '0';
        continue;
    
    Index = [-1 for i in xrange(0,n+1)];
    actualParents = [0 for i in xrange(0,n+1)]
 
    Nodes = 0;
    

    for i in xrange(0,n):
        actualParents[i] = x = getParent(i);
        if(Index[x] == -1):
            Index[x] = Nodes;
            Nodes += 1
    
    newGraph = [[0 for i in xrange(0,n+1)] for j in xrange(0,n+1)]
    
    for i in xrange(0,n):
        for j in xrange(0,n):
            if(Inp[i][j] == '1' and (actualParents[i] != actualParents[j])):
                newGraph[Index[actualParents[i]]][Index[actualParents[j]]] += 1
                 
    ## Now we have got the newGraph.
    
    Nodes -= 1;
    newMatrix = [[0 for i in xrange(0,Nodes)] for j in xrange(0,Nodes)];
    for i in xrange(0,Nodes):
        tmp = 0;
        for j in xrange(0,Nodes):
            tmp += newGraph[i][j]
            newMatrix[i][j] = -newGraph[i][j]
        newMatrix[i][i] = tmp + newGraph[i][Nodes];
        
    ## Now Determinant of newMatrix is our answer.

    ans = Determinant();
    print ans 