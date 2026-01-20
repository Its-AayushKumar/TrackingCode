# x = int(input("Enter value of x:"))

# if x % 2 == 0 :
#     print("Even")
# else :
#     print("Odd")

def main():
    x = int(input("Enter value of x:")) 
    if is_even(x):
        print("Even")
    else :
        print("Odd")

# def is_even(n):
#     if n%2 == 0 :
#         return True 
#     else :
#         return False
    
def is_even (n):
    # return True if n % 2 == 0 else False

    return n%2 == 0 


main()
