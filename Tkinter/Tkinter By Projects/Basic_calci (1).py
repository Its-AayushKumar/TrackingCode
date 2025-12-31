import tkinter as tk
def btn_click(item):
    """Adds the clicked button value to the display."""
    current = display.get()
    display.delete(0, tk.END)
    display.insert(0, current + str(item))
def btn_clear():
    """Clears the input field."""
    display.delete(0, tk.END)
def btn_equal():
    expression = display.get()  
    # 1. Check if the screen is empty
    if expression == "":
        return # Do nothing      
    # 2. Check for Syntax Error: Ending with an operator
    # Example: User types "50+" and hits "="
    if expression[-1] in "+-*/":
        display.delete(0, tk.END)
        display.insert(0, "Error")
        return
    # 3. Check for Division by Zero
    # We check if the forbidden string "/0" exists in the math
    # Note: This is a basic check. It blocks "5/0", but sadly also blocks "20/0.5"
    if "/0" in expression:
        display.delete(0, tk.END)
        display.insert(0, "Error")
        return

    # 4. If all checks pass, it is likely safe to calculate
    result = eval(expression) 
    display.delete(0, tk.END)
    display.insert(0, result)

# --- GUI Setup ---
root = tk.Tk()
root.title("Basic Calculator")
root.geometry("300x400")
root.configure(bg="cyan") # Main background

# --- Display Screen ---
# A simple entry widget to show numbers
display = tk.Entry(root, width=15, font=("Arial", 24), borderwidth=0, justify="right")
display.grid(row=0, column=0, columnspan=4, padx=10, pady=20, sticky="nsew")
display.configure(bg="white", fg="black") # White screen, black text

# --- Button Configuration ---
# Layout: Button Text, Row, Column
buttons = [
    ('7', 1, 0), ('8', 1, 1), ('9', 1, 2), ('/', 1, 3),
    ('4', 2, 0), ('5', 2, 1), ('6', 2, 2), ('*', 2, 3),
    ('1', 3, 0), ('2', 3, 1), ('3', 3, 2), ('-', 3, 3),
    ('C', 4, 0), ('0', 4, 1), ('=', 4, 2), ('+', 4, 3),
]
# Configure grid weights so buttons expand to fill space
for i in range(5):
    root.grid_rowconfigure(i, weight=1)
for i in range(4):
    root.grid_columnconfigure(i, weight=1)

# Loop to create buttons automatically
for (text, row, col) in buttons:
    if text == '=':
        cmd = btn_equal
    elif text == 'C':
        cmd = btn_clear
    else:
        # Use lambda to pass the specific number/symbol to the function
        cmd = lambda x=text: btn_click(x)
    
    tk.Button(root, text=text, font=("Arial", 18), 
              bg="black", fg="white", # Black button, white text
              activebackground="gray", activeforeground="white",
              relief="flat", command=cmd).grid(row=row, column=col, sticky="nsew", padx=1, pady=1)

root.mainloop()