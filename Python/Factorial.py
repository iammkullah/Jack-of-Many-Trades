def fac(a):
    if(a==1):
        return a
    else:
        return a*fac(a-1)

x=int(input("Number: "))
print(fac(x))
