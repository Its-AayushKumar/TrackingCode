name = input("What's your name :")
 # name is the the variable that stores the 
 # '=' is used the assign the value 

print("hello,")
print(name)

# we can use comments to write pseudocode to structure our program first and then start writing

print("hello, "+ name ) # '+' is used to concatinate the strings
print("hello,", name )

print("hello, ",end="") # end="" is used to control what is printed at the end of print statement 
print(name)             # bydefault it is end="\n" -->means a new line


print("hello,",end="...")
print(name)

print("hello,",name,sep="??") 
#sep controls what gets printed between multiple values inside print().

print(1, 2, 3, sep="-")

print("CS50", "Python", sep=" -> ", end=" !!!")

