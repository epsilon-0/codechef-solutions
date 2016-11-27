import random

nodes = 30

print(1)
print(nodes)
graph = [[0]*nodes for i in range(nodes)]

for i in range(nodes):
  for j in range(i+1, nodes):
    if(random.random() < 0.3):
      graph[i][j] = graph[j][i] = 1

for i in range(nodes):
  print("".join(map(str, graph[i])))

print(6)
print("2 14")
print("3 17")
print("1 10")
print("12 17")
print("11 19")
print("6 15")