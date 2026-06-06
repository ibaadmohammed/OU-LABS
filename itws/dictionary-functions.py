thisdict = {
"brand": "Ford",
"model": "Mustang",
"year": 1964
}
print(thisdict)
x = thisdict.get("model")
thisdict["year"] = 2018
print(x, thisdict)
print(len(thisdict))
thisdict["color"] = "red"
print(thisdict)
thisdict.pop("model")
print(thisdict)
x = thisdict.keys()
print(x)
x = thisdict.items()
print(x)
