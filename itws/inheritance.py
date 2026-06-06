class Parent:
    def __init__(self, fname, lname):
        self.firstname = fname
        self.lastname = lname
    def printname(self):
        print("Hello my name is " + self.firstname + self.lastname)

class Student(Parent):
    pass

x = Student("Mohammed", "Mudassir")
x.printname()
