name = input("What's your name ?")

# if name == "Harry":
#     print("Gryffindor")
# elif name == "Hermione":
#     print("Gryffindor")
# elif name == "Ron":
#     print("Gryffindor")
# elif name == "Draco":
#     print("Slytherin")
# else :
#     print("Who?")

# The above code can be simplified as -->

# if name == "Harry" or name == "Hermione" or name == "Ron":
#     print("Gryffindor")
# elif name == "Draco":
#     print("Slytherin")
# else :
#     print("Who?")

# Match case can be also used 

match name :             # Here name is compared to each case and when found block the run 
    case "Harry":
        print("Gryffindor")
    case "Hermione":
        print("Gryffindor")
    case "Ron":
        print("Gryffindor")
    case "Draco":
        print("slytherin")
    case _:                # If no case matches case _: blocks the run.
        print("Who?")
    