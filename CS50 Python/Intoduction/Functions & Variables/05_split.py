name = input("Enter your name:").strip().title()

# Split user's name into first and last name 
first,last = name.split(" ")

print(f"hello, {first}")
print(f"hello, {last}")