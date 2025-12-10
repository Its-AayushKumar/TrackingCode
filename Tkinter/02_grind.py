import tkinter as tk

root = tk.Tk()

# Creating a Label Widget
myLabel1 = tk.Label(root,text = "Hello World")
myLabel2 = tk.Label(root,text = "Hi I am Aayush!")
myLabel3 = tk.Label(root,text = "               ")

# Shoving it onto the screen
myLabel1.grid(row=0,column=0)
myLabel2.grid(row=1,column=5) #column = 5 does not prints it in column 5 
                              # because in between other are empty
myLabel3.grid(row=1,column=1)

root.mainloop()