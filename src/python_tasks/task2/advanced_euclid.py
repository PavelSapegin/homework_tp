def advanced_euclid(a,b):
    if a % b == 0:
        return (b,0,1)
    
    a,b = abs(a),abs(b)
    d,x0,y0 = advanced_euclid(a,a%b)

    x = y0
    y = x0 - (a//b)*y0

    return f"{abs(d)} = {a}*{x} + {b}*{y}"


#Example
print(advanced_euclid(30,-12))