def refact(x):
    if x == 1:
        return 1
    else:
        return(x * refact(x - 1))
num = int(input("no: "))
if num >= 1:
    print('factorial of no is', refact(num))
