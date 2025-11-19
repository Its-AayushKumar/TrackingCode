a = int(input("Enter your salary in INR:"))
if (0<=10000):
    print("Bonus amount is :",a/10)
    print("Total salary is :",a/10 + a)
elif (20000>=a>10000):
    print("Bonus amount is :",a/5)
    print("Total salary is :",a/5+ a)
else:# ( a>20000):
    print("Bonus amount is :",2*a/5)
    print("Total salary is :",2*a/5 + a)
    

