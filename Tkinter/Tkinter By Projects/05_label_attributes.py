from tkinter import *
root = Tk()
root.geometry("500x400")
root.title("Learning GUI")

# Important Label Options 

# text - adds the text 
# bd - background
# fg - foreground 
# font - sets the font 
# 1. font = ("comicsansms",20,"bold")
# 2. font = "comicsansms 20 italic"
# padx - x padding 
# pady - y padding 
# relief - border styling - SUNKEN , RAISED , GROOVE , RIDGE

title_label = Label(text= '''Tkinter is a binding to the Tk GUI toolkit for Python. It is the standard Python interface to the Tk GUI toolkit,[1] and is Python's de facto standard GUI.[2] Tkinter is included with standard Linux, Microsoft Windows and macOS installs of Python.

\nThe name Tkinter comes from Tk interface. Tkinter was written by Steen Lumholt and Guido van Rossum,[3] then later revised by Fredrik Lundh.[4]

\nTkinter is free software released under a Python license.[5]''',bg = "red",fg= "black",padx=35,pady=50,font = "comicsansms 10 italic",borderwidth=10,
relief=SUNKEN)

# Important Pack options
# anchor = nw,ne,se,sw ,center (any of this can be used)
# side = top , bottom , left , right
# fill
# padx 
# pady

# title_label.pack(side=TOP,anchor="center",fill= X)
title_label.pack(side=LEFT,fill= Y,padx=45,pady=45)

root.mainloop()