from itertools import product


def checking_dia(area):
    """
    Проверка корректности расстановки по диагонали
    Два ферзя стоят на какой - либо диагонали,
    если сумма или разность их столбцов и строк одинакова

    """
    for i in range(n):
        for j in range(i + 1, n):
            if ((area[i] - i) == (area[j] - j)) or ((area[i] + i) == (area[j] + j)):
                return False

    return True


def brute_queen(n):
    count = 0

    #area[i] — столбец, где стоит ферзь в строке i
    area = [i for i in range(n)]

    # Перебираем все возможные расстановки и проверяем на корректность
    for x in product(area, repeat=n):
        if len(x) == len(set(x)) and checking_dia(x):
            count += 1

    return count


def my_queens(n, row=0, cols=set(), dia1=set(), dia2=set()):

    if row == n:  # Возравщаем 1, если сомгли разместить всех
        return True

    count = 0

    for col in range(n):  # перебираем все колонки
        if col not in cols and (row + col) not in dia1 and (row - col) not in dia2:
            row_next = row + 1
            cols_next = cols | {col}
            dia1_next = dia1 | {row + col}
            dia2_next = dia2 | {row - col}
            count += my_queens(n, row_next, cols_next, dia1_next, dia2_next)

    return count


def rec_queens(n, row=0, area=None):

    if row == 0:  # Создаем пустое начальное поле
        area = [-1 for _ in range(n)]

    if row == n:  # Возращаем 1, если смогли дойти до конца поля
        return True

    count = 0

    for col in range(n):

        # Проверка на размещение ферзя
        flag = True
        for i in range(row):
            if area[i] == col or abs(area[i] - col) == abs(i - row):
                flag = False
                break

        if flag:  # Если смогли разместить, то ставим дальше
            area[row] = col
            count += rec_queens(n, row + 1, area)

    return count


n = 10

brute = brute_queen(n)
rec = rec_queens(n)
my = my_queens(n)
print(brute, rec, my)
