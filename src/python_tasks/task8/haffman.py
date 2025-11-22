class TreeNode():
    def __init__(self,weight,left=None,right=None,symbol=None):
        self.symbol = symbol
        self.weight = weight
        self.right = right
        self.left = left

    def __lt__(self,other):
        return self.weight < other.weight
    

d = {"a":0.43,"b":0.36,"c":0.21}


def encode(msg:str) -> tuple[str, dict[str, str]]:
    listnode = [TreeNode(v,symbol=k) for k,v in d.items()]
    listnode.sort()

    if len(listnode) == 0:
        return
    # построение дерева
    while len(listnode) > 1:
        l1 = min(listnode)
        listnode.remove(l1)
        l2 = min(listnode)
        listnode.remove(l2)
        
        
        new_node = TreeNode(weight=l1.weight+l2.weight,left=l1,right=l2)
        listnode.append(new_node)
        listnode.sort()
        
    
    # выдача кодов

    root = listnode[0]
    table = []
    bank = ""
    
    #Проверка на 1 символ
    if root.symbol is not None:
        return [(root.symbol,"0")]
    
    def get_code(root,bank):
        node = root
        if node.symbol is not None:
            return table.append((node.symbol,bank))
            
        return get_code(node.left,bank+'0'), get_code(node.right,bank+'1')
        
    get_code(root,bank)
        
        
        
    return table


#print(encode(d))
res = encode(d)
print(res)
