word = input("Enter a word :")

if word == word[::-1]:
    print(f"{word} is palimdrone")
else :
    print(f"{word} is not palimdrone")
