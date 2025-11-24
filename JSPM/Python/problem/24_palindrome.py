pa=input("Enter a number to check if its a palindrome or not")
ndrome=pa[::-1]
if(pa == ndrome):
    print("Its a palindrome")
else:
    print("Its not a palindrome")