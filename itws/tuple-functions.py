thistuple = ("apple", "cherry", "banana", "cherry")
tuple2 = (1, 2, 3)
print(thistuple)
for x in thistuple:
    print(x)
print(len(thistuple))
print(thistuple.count("cherry"))
print(thistuple.index("banana"))
print(tuple2 + thistuple)
