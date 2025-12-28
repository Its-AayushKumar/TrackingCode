from tkinter import *
root = Tk()
root.geometry("650x390")
f1 = Frame(root,bg="yellow",borderwidth=7,relief=SUNKEN)
f1.pack(side=LEFT,fill= Y,pady=120)

f2 = Frame(root,borderwidth=8,bg="grey",relief=GROOVE)
f2.pack(side=TOP,fill=X)

l = Label(f1,text = "HEllO I AM AAYUSH")
l.pack(pady = 120)

l = Label(f2,text = "WELCOME TO MY WORLD")
l.pack(padx=  120)

root.mainloop()