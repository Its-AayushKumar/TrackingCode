from tkinter import *

root = Tk() 

root.geometry("800x500")
photo = PhotoImage(file=r"Tkinter\Tkinter By Projects\1.png")

img = Label(image = photo)
img.pack()

root.mainloop()