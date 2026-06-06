string_name = "DECCAN"
# slicing the string in reverse fashion
for element in string_name[::-1]:
    print(element, end = ' ')
print('\n')

# Code 2
string_name = "HYDERABAD"
# Getting length of string
ran = len(string_name)
# using reversed() function
for element in reversed(range(0, ran)):
    print(string_name[element])
