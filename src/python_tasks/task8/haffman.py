from collections import Counter
import json
import os


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


def char_analisys(s: str) -> dict[str, str]:
    """
    Функция для частотного анализа строки\n
    Возращает dict с вероятностями символов
    """
    d = Counter(s)
    LEN = len(s)
    for k in d.keys():
        d[k] /= LEN

    return d


def encode(msg: str) -> tuple[str, dict[str, str]]:
    """
    Функция кодирования строк по алгоритму Хаффмана
    """
    d = char_analisys(msg)
    listnode = [TreeNode(v, symbol=k) for k, v in d.items()]
    listnode.sort()

    if len(listnode) == 0:
        return None
    
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
        return (root.symbol, "0")

    def get_code(root: TreeNode, bank: str):
        node = root
        if node.symbol is not None:
            return table.append((node.symbol, bank))

        if node.left:
            get_code(node.left, bank + "0")

        if node.right:
            get_code(node.right, bank + "1")

    get_code(root, bank)

    table = dict(table)

    def transform(msg: str) -> str:
        return "".join([table[c] for c in msg])

    result_string = transform(msg)

    return (result_string, table)


def decode(encoded: str, table: dict[str, str]) -> str:
    """
    Функция декдирования строки по алгоритму Хаффмана
    """
    bank = ""
    result_string = ""
    reversed_table = dict([(v, k) for k, v in table.items()])
    for i in range(len(encoded)):
        bank += encoded[i]
        if bank in reversed_table.keys():
            result_string += reversed_table[bank]
            bank = ""

    return result_string


def fileencode(filename: str) -> None:
    """
    Функция кодирования текстового файла
    """
    with open(filename, "r") as f:
        text = f.read().strip()
        res = encode(text)
        if res is None:
            return

    with open(filename, "w") as f:
        f.write(f"{res[0]}$$")
        json.dump(res[1], f)


def filedecode(filename: str) -> None:
    """
    Функция декодирования текстового файла
    """
    with open(filename, "r") as f:
        s, table_json = f.read().split("$$")
        table = json.loads(table_json)

    decoded_s = decode(s, table)

    with open(filename, "w") as f:
        f.write(decoded_s)


if __name__ == "__main__":
    filename = input("Введите путь к файлу:")
    if not os.path.isfile(filename):
        raise FileNotFoundError("Файл не найден")

    print("Выберите тип операции -")
    choice = int(input("1 - Кодирование\n2 - Декодирование\n"))

    if choice == 1:
        try:
            fileencode(filename)
            print(f"Файл {filename} успешно закодирован")

        except ValueError:
            print("Возникла ошибка. Файл уже закодирован")

    elif choice == 2:
        try:
            filedecode(filename)
            print(f"Файл {filename} успешно декодирован")

        except ValueError:
            print("Возникла ошибка. Файл уже декодирован или пуст")

    else:
        raise ValueError("Некорректный ввод")
