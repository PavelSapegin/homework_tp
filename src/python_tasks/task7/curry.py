def curry(func, n):
    """Функция каррирования"""

    if n <= 0 or not isinstance(n, int):
            raise ValueError("Арность должна быть больше 0 и целым числом")
        
    def inner(accum_args):
       
        if len(accum_args) == n:  # Вызываем функцию, когда набрали нужное число аргументов
            try:
                return func(*accum_args)
            except ValueError:
                raise ValueError("Заданная арность n не соответствует фактической арности функции")
        
        return lambda x: inner(accum_args + (x,))  # Набираем аргументы

    return inner(())


def uncurry(func, n):
    """Функция антикаррирования"""

    if n <= 0 or not isinstance(n,int):
            raise ValueError(
                "Арность должна быть целым неотрицательным числом"
            )
            
    def wrapper(*args):
        if len(args) != n:
            raise ValueError(
                "Арность должна равняться количеству переданных аргументов"
            )
            
        
        temp_func = func  # берем функцию без аргументов
        for i in args:
            # накапливаем вызовы с постуающими аргументами
            temp_func = temp_func(i)

        return temp_func # возвращаем функцию с накопленными аргументами

    return wrapper


if __name__ == '__main__':
    def sum3(x, y, z):
        return x + y + z

    sum3_curry = curry(sum3, 3)
    sum3_uncurry = uncurry(sum3_curry, 3)
    print(sum3_curry(1)(2)(3))    # 6
    print(sum3_uncurry(1, 2, 3))  # 6 


