from itertools import product

n = 4


# Массив, где индекс i - номер строки, 
# а i-тый элемент - это номер столбца, где стоит ферзь 
area = [i for i in range(n)] 



def cheking_dia(area):
    '''
    Проверка корректности росстановки по диагонали
    
    Два ферзя стоят на какой - либо диагонали,
    если сумма или разность их столбцов и строк одинакова
    
    '''
    for i in range(n):
        for j in range(i+1,n):
            if ((area[i] - i) == (area[j] - j)) or ((area[i] + i) == (area[j] + j)):
                return False
    
    return True


def queen(n):
    count = 0
    
    #Перебираем все возможные расстановки и проверяем на корректность
    for x in product(area,repeat=n):
        if len(x) == len(set(x)) and cheking_dia(x):
            count += 1


    return count

print(queen(n))
