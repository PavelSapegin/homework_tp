def rec_queens(n, row=0, area=None):

    if row == 0: # Создаем пустое начальное поле
        area = [-1 for i in range(n)]

    if row == n: # Возращаем 1, если смогли дойти до конца поля
        return True

    count = 0

    for col in range(n):
        
        # Проверка на размещение ферзя
        flag = True
        for i in range(row):
            if area[i] == col or abs(area[i] - col) == abs(i - row):
                flag = False
                break

        if flag: # Если смогли разместить, то ставим дальше
            area[row] = col
            count += rec_queens(n, row + 1, area)

    return count

n = 10

res = rec_queens(n)
print(res)
