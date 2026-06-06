def disp_message():
    text = "hello !! I am going to print a message."
    # the variable message is local to the function itself
    print(text)
disp_message()
# print(text)  # this will cause an error since a local variable cannot be accessible here
