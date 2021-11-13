from collections import defaultdict

class Graph:
  def __init__(self):
    self.graph = defaultdict(set)

  def connect_node(self, fromNode, toNode):
    self.graph[fromNode].add(toNode)


  def bfs(self, source):
    visited = [False] * (max(self.graph) + 1)
    q = []

    q.append(source)
    visited[source] = True

    while q:
      s = q.pop(0)
      print(s, end=" ")
      for i in self.graph[s]:
        if visited[i] == False:
          q.append(i)
          visited[i] = True




g = Graph()
g.connect_node(0,1)
g.connect_node(0,2)
g.connect_node(1,0)
g.connect_node(1,2)
g.connect_node(2,0)
g.connect_node(2,3)
g.connect_node(3,2)

g.bfs(3)