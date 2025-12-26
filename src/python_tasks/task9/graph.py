class Node:
    '''
    Класс узла для графа\n
    Каждый узел имеет number и children
    '''
    def __init__(self, number: int, children: list | None = None):
        self.number = number
        self.children = children if children is not None else []


class Graph:
    '''
    Класс графа\n
    Содержит список всех узлов listnode\n
    как элемент listnode с индексом 0\n
    Метод dfs() проходит граф в глубину и \n
    возвращает список  посещенных вершин\n
    Граф реализован как итерируемый объект
    '''
    def __init__(self, listnode: list[Node]):
        self.listnode = listnode
        

    def dfs(self) -> list[Node]:

        '''
        Метод dfs() проходит граф в глубину и возращает список посещенных вершин (объекты Node)
        '''
        
        return list(self)

    def __iter__(self):
        '''
        Граф итерируется в порядке DFS, возращая объекты Node
        '''
        
        if not self.listnode:
            return
        
        visited = set()
        stack = [self.listnode[0]]
        
        while stack:
            node = stack.pop()
            
            if node not in visited:
                visited.add(node)
                yield node
                
            
            for child in reversed(node.children):
                if child not in visited:
                    stack.append(child)




node1 = Node(number=1)
node2 = Node(number=2)
node3 = Node(number=3, children=[node2])
node4 = Node(number=4, children=[node1, node2, node3])
node5 = Node(number=5)
node1.children = [node5]

gr = Graph([node4, node3, node2, node1])
dfs_nodes = gr.dfs()
print([node.number for node in dfs_nodes])

for node in gr:
    print(node.number)
