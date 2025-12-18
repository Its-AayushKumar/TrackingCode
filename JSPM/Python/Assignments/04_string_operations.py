text = input("Enter a string:")

print("Concatination Example:",text+"Python")
print("Repetition Example:",text*2)

print("First character:",text[0])
print("Last character:",text[-1])
print("Slicing string (first 3 char):",text[:3])
print("Is alphabatic ?",text.isalpha())
print("Is digit ?",text.isdigit())
print("Is space ?",text.isspace())

vowels = "aeiouAEIOU"
v = 0
c = 0
for ch in text :
    if ch.isalpha():
        if ch in vowels :
            v += 1
        else :
            c += 1

print("Vowels:",v)
print("consonents:",c)
