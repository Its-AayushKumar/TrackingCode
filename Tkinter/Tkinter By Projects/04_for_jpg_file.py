from tkinter import *
from PIL import Image, ImageTk

root = Tk() 

root.geometry("800x500")

# For jpg images
img = Image.open(r"Tkinter\Tkinter By Projects\panda.jpg")
photo = ImageTk.PhotoImage(img)

a = Label(image=photo)
a.pack()

a.pack()

root.mainloop()