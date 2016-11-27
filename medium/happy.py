from fractions import Fraction

def determinant(mat):
  res = Fraction(1, 1)
  n = len(mat)
  for i in range(n):
    if(mat[i][i] == Fraction(0)):
      for j in range(i+1, n):
        if(mat[j][i] != Fraction(0)):
          swap(mat[i][j])
          res *= -1.0
          break;
    if(mat[i][i] == 0):
      return Fraction(0)
    res *= mat[i][i]
    for j in range(i+1, n):
      f = Fraction(1) * mat[j][i] / mat[i][i]
      for k in range(i, n):
        mat[j][k] -= f*mat[i][k]
  return res

class UnionFind:
  def __init__(self, maxSize):
    self.parent = [i for i in range(maxSize)]
    self.treeHeight = [1 for i in range(maxSize)]
    self.treeSize = [1 for i in range(maxSize)]

  def find(self, x):
    root = x
    while(self.parent[root] != root):
      root = self.parent[root]
    climbingNode = x
    while(climbingNode != root):
      temp = self.parent[climbingNode]
      self.parent[climbingNode] = root
      climbingNode = temp
    return root

  def union(self, x, y):
    rootX = self.find(x)
    rootY = self.find(y)
    if(self.treeHeight[rootX] < self.treeHeight[rootY]):
      rootX, rootY = rootY, rootX
    if(self.treeHeight[rootX] == self.treeHeight[rootY]):
      self.treeHeight[rootX] += 1
    self.parent[rootY] = rootX
    self.treeSize[rootX] += self.treeHeight[rootY]

t = int(input())

for tests in range(t):

  n = int(input())
  graph = []
  for i in range(n):
    graph.append(list(map(int, list(input().strip()))))

  unf = UnionFind(n)

  m = int(input())
  notPossible = False
  favs = []
  for i in range(m):
    favs.append(list(map(int, list(input().strip().split()))))

  for i in range(m):
    a, b = favs[i]
    if(unf.find(a-1) == unf.find(b-1)):
      notPossible = True
      break
    unf.union(a-1, b-1)
  if(notPossible):
    print(0)
    continue

  parent = [unf.find(i) for i in range(n)]
  parent.sort()
  indices = [parent[0]]
  for i in parent[1:]:
    if(i != indices[-1]):
      indices.append(i)
  newSize = len(indices)

  newGraph = [[0 for i in range(newSize)] for j in range(newSize)]
  for i in range(n):
    for j in range(n):
      if(graph[i][j] == 1 and unf.find(i) != unf.find(j)):
        newGraph[indices.index(unf.find(i))][indices.index(unf.find(j))] -= 1

  if(newSize == 1):
    print(1)
    continue

  for i in range(newSize):
    newGraph[i][i] = -1*sum(newGraph[i])

  newGraph.pop()

  for i in range(len(newGraph)):
    newGraph[i].pop()

  for i in range(len(newGraph)):
    for j in range(len(newGraph)):
      newGraph[i][j] = Fraction(newGraph[i][j], 1)
  

  ans = int(determinant(newGraph))

  print(ans)
