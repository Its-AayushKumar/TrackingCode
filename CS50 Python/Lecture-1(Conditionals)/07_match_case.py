name = input("What's your name :")

match name :
    case "Harry" | "Hermione" | "Ron" : # '|' this works as or statement inside case 
        print("Gryffindor")
    case "Draco":
        print("Slytherin")
    case _:
        print("Who?")