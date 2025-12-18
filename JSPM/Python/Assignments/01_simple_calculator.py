a = int(input("Enter the first number:"))
b = int(input("Enter the second number:"))
c = input("Enter operation you want to perform (+,-,*,/):")

if ( c == '+'):
    print(f"{a}+{b}=",a+b)
elif( c == '-'):
    print(f"{a}-{b}=",a-b)
elif( c == '*'):
    print(f"{a}*{b}=",a*b)
elif( c == '/'):
    print(f"{a}/{b}=",a/b)
else :
    print("!!Enter a valid operator!!")







