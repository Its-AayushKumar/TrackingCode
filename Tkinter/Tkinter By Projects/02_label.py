from tkinter import *

root = Tk() 

# Width x Height
root.geometry("500x300")

# width,height
root.minsize(250,150)

# width,height
root.maxsize(1200,1000)

a = Label(text = "Hi all")
a.pack()




root.mainloop()