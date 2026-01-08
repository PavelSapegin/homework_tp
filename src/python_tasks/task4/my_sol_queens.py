def my_queens(n,row=0, cols=set(), dia1=set(), dia2=set()):

    if row == n: # Возравщаем 1, если сомгли разместить всех
        return True

    count = 0
    
    for col in range(n): # перебираем все колонки
        if col not in cols \
            and (row + col) not in dia1 \
            and (row - col) not in dia2:
            rownext = row + 1
            colsnext = cols | {col}
            dia1next = dia1 | {row + col}
            dia2next = dia2 | {row - col}
            count += my_queens(n,rownext, colsnext, dia1next, dia2next)

    return count


print(my_queens(10))
