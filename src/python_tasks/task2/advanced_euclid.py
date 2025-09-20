def advanced_euclid(a,b):
    if a % b == 0:
        return (b,0,1)
    
    d,x0,y0 = advanced_euclid(a,a%b)

    x = y0
    y = x0 - (a//b)*y0

    return (abs(d),x,y)



print(advanced_euclid(30,12))