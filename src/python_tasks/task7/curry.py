def curry(func, n):
    """Функция каррирования"""

    def wrapper(*args):
        if n <= 0 or not isinstance(n, int):
            raise ValueError("Арность должна быть больше 0 и целым числом")
        if len(args) > n:
            raise ValueError("Арность дожна равняться количеству переданных аргументов")

        if len(args) == n:  # Вызываем функцию, когда набрали нужное число аргументов
            return func(*args)

        return lambda x: wrapper(*(args + (x,)))  # Набираем аргументы

    return wrapper


def uncurry(func, n):
    """Функция антикаррирования"""

    def wrapper(*args):
        if len(args) > n:
            raise ValueError(
                "Арность должна равняться количеству переданных аргументов"
            )
            
        if n <= 0 or not isinstance(n,int):
            raise ValueError(
                "Арность должна быть целым неотрицательным числом"
            )
        temp_func = func  # берем функцию без аргументов
        for i in args:
            # накапливаем вызовы с постуающими аргументами
            temp_func = temp_func(i)

        return temp_func # возвращаем функцию с накопленными аргументами

    return wrapper



