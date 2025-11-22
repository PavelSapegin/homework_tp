from collections import Counter


class TreeNode:
    """
    Класс узла для построения дерева\n
    Каждый узел обязательно имеет weight - свой вес (вероятность)\n
    Листы (символы) имеют свой символ

    """

    def __init__(self, weight, left=None, right=None, symbol=None):
        self.symbol = symbol
        self.weight = weight
        self.right = right
        self.left = left

    def __lt__(self, other):
        return self.weight < other.weight


string = "aaabbbccc"


def char_analisys(s: str) -> dict[str, str]:
    """
    Функция для частотного анализа строки\n
    Возращает dict с вероятностями символов
    """
    d = Counter(string)
    LEN = len(string)
    for k in d.keys():
        d[k] /= LEN

    return d


def encode(msg: str) -> tuple[str, dict[str, str]]:
    d = char_analisys(msg)
    listnode = [TreeNode(v, symbol=k) for k, v in d.items()]
    listnode.sort()

    if len(listnode) == 0:
        return
    # построение дерева
    while len(listnode) > 1:
        l1 = min(listnode)
        listnode.remove(l1)
        l2 = min(listnode)
        listnode.remove(l2)

        new_node = TreeNode(weight=l1.weight + l2.weight, left=l1, right=l2)
        listnode.append(new_node)
        listnode.sort()

    # выдача кодов

    root = listnode[0]
    table = []
    bank = ""

    # Проверка на 1 символ
    if root.symbol is not None:
        return [(root.symbol, "0")]

    def get_code(root, bank):
        node = root
        if node.symbol is not None:
            return table.append((node.symbol, bank))

        return get_code(node.left, bank + "0"), get_code(node.right, bank + "1")

    get_code(root, bank)

    table = dict(table)

    def transform(msg):
        for symbol, code in table.items():
            msg = msg.replace(symbol, code)

        return msg

    result_string = transform(msg)

    return (result_string, table)


def decode(encoded: str, table: dict[str, str]) -> str:
    bank = ""
    result_string = ""
    reversed_table = dict([(v, k) for k, v in table.items()])
    for i in range(len(encoded)):
        bank += encoded[i]
        if bank in reversed_table.keys():
            result_string += reversed_table[bank]
            bank = ""

    return result_string


res1 = encode(string)
print(res1)
res2 = decode(*res1)
print(res2)
