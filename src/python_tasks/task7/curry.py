def curry(f, n):
    def wrapper(*args):
        if len(args) == n:
            return f(*args)

        return lambda x: wrapper(*(args + (x,)))

    return wrapper


def uncurry(func, n):
    def wrapper(*args):
        temp_func = func
        for i in args:
            temp_func = temp_func(i)

        return temp_func

    return wrapper


def sum3(x, y, z, w):
    return x + y + z + w


print(sum3)


