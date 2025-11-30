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
    Содержит список всех узлов listnode и корень root\n
    как элемент listnode с индексом 0\n
    Метод dfs() проходит граф в глубину и \n
    возвращает список number посещенных вершин\n
    Граф реализован как итерируемый объект
    '''
    def __init__(self, listnode: list[Node]):
        self.listnode = listnode
        self.root = listnode[0]

    def dfs(self) -> list[Node]:

        '''
        Метод dfs() проходит граф в глубину и возращает список посещенных вершин (объекты Node)
        '''
        root = self.listnode[0]

        result = []
        visited = set()

        def recsearch(root: Node) -> None:
            visited.add(root)
            result.append(root)
            for child in root.children:
                if child not in visited:
                    recsearch(child)

            

        recsearch(root)
        return result

    def __iter__(self):
        '''
        Граф итерируется в порядке DFS, возращая объекты Node
        '''
        for node in self.dfs():
            yield node




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
