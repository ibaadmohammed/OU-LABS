# the function table(n) prints the table of n
def table(n):
    return lambda a: a * n
# a will contain the iteration variable i and a multiple of n is returned at each function call
n = int(input("Enter the number? "))
b = table(n)
# the entered number is passed into the function table
# b will contain a lambda function which is called again and again with the iteration variable i
for i in range(1, 11):
    print(n, "x", i, "=", b(i))  # the lambda function b is called with the iteration variable i
