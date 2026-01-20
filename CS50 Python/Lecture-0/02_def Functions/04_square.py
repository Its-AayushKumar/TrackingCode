def main():
    x = int(input("Enter value of x:"))
    print("x squared is =",square(x))

def square(n):
    # return n*n
    # return pow(n,2) --> In built function for raising power
    return n**2 # '**' is used to raise to power

main()