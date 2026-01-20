# Here we are learning about different function and how can we use them to print 
name = input("What's your name :")
name2 = input("What's your name :")
name3 = input("What's your name :")
name4 = input("What's your name :").strip().title()


 
#Remove whitespace from str
name = name.strip() 
#There are also lstrip() and rstrip() but does not remove spaces in between

#Capitalize user's name 
n1 = name.capitalize()

#Capitalize first letter of every word
n2 = name2.title()

n3 = name3.strip().capitalize()

print(f"hello, {n1}")  

print(f"hello, {n2}")  

print(f"hello, {n3}")  

print(f"hello, {name4}")  

