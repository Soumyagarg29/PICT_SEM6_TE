class Node:
    def __init__(self, x, y) -> None:
        self.x=x
        self.y=y
        self.gcost=100
        self.hcost = 100
        self.parent = None

    def equals(self, other):
        return self.x==other.x and self.y==other.y

    def neighbours(self):
        return [
            Node(self.x+1, self.y),
            Node(self.x-1, self.y),
            Node(self.x, self.y-1),
            Node(self.x, self.y+1),
        ]

def heuristic( a, b):
    return abs(a.x-b.x)+abs(a.y-b.y)

def astar(grid, start, end):
    startNode=Node(start[0], start[1])
    endNode = Node(end[0], end[1])
    openset, closedset = [], []
    startNode.gcost = 0
    startNode.hcost = heuristic(startNode, endNode)
    openset.append(startNode)

    while openset:

        openset = sorted(openset, key=lambda x: x.hcost)
        currentNode = openset.pop(0)
        closedset.append(currentNode)

        if currentNode.equals(endNode):
            return currentNode.gcost, currentNode 
        
        for neighbour in currentNode.neighbours():
            if neighbour not in closedset and not grid[neighbour.x][neighbour.y] and neighbour.x>=0 and neighbour.y>=0 and neighbour.x<len(grid) and neighbour.y<len(grid[0]):
                cost = currentNode.gcost + heuristic(currentNode, neighbour)
                if cost < neighbour.gcost:
                    neighbour.gcost = cost
                    neighbour.hcost = cost + heuristic(neighbour, endNode)
                    neighbour.parent = currentNode

                    if neighbour not in openset:
                        openset.append(neighbour)

    return None, None


grid = [[1, 1, 1, 1, 1, 1, 1],
        [1, 0, 0, 0, 0, 0, 1],
        [1, 1, 0, 1, 0, 0, 1],
        [1, 0, 0, 1, 0, 0, 1],
        [1, 0, 0, 0, 0, 0, 1],
        [1, 1, 1, 1, 1, 1, 1]
        ]
start = (1, 1)
end = (3,2)
min_distance, last = astar(grid, start, end)
#print(f"Optimal Distance : {min_distance}")
if(min_distance==None or last==None):
    print("No Path Found")
    
print("PATH: ")
while(not last==None):

    grid[last.x][last.y]=2
    print("->" , last.x, last.y)
    last=last.parent

print("Minimum Distance: ", min_distance)
for row in grid:
    print(row)