import tkinter as tk
from tkinter import ttk, messagebox
import pandas as pd
import os

# --------------------- DATA & GLOBALS ---------------------
books = []
recent_books = []
MAX_QUEUE_SIZE = 5

# --------------------- DATA STRUCTURE FUNCTIONS ---------------------
def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr)//2]['Title']
    left = [x for x in arr if x['Title'].lower() < pivot.lower()]
    middle = [x for x in arr if x['Title'].lower() == pivot.lower()]
    right = [x for x in arr if x['Title'].lower() > pivot.lower()]
    return quick_sort(left) + middle + quick_sort(right)

def load_books():
    global books
    if os.path.exists("books.xlsx"):
        df = pd.read_excel("books.xlsx")
        books = df.to_dict('records')
    else:
        # Preload dummy data
        books.extend([
            {"Title":"Harry Potter and the Sorcerer's Stone","Author":"J.K. Rowling","ISBN":"9780747532743","Year":1997},
            {"Title":"The Hobbit","Author":"J.R.R. Tolkien","ISBN":"9780345339683","Year":1937},
            {"Title":"Pride and Prejudice","Author":"Jane Austen","ISBN":"9781503290563","Year":1813},
            {"Title":"To Kill a Mockingbird","Author":"Harper Lee","ISBN":"9780061120084","Year":1960},
            {"Title":"The Great Gatsby","Author":"F. Scott Fitzgerald","ISBN":"9780743273565","Year":1925},
            {"Title":"1984","Author":"George Orwell","ISBN":"9780451524935","Year":1949},
            {"Title":"The Catcher in the Rye","Author":"J.D. Salinger","ISBN":"9780316769488","Year":1951},
            {"Title":"The Alchemist","Author":"Paulo Coelho","ISBN":"9780061122415","Year":1988},
            {"Title":"The Da Vinci Code","Author":"Dan Brown","ISBN":"9780307474278","Year":2003},
            {"Title":"The Kite Runner","Author":"Khaled Hosseini","ISBN":"9781594631931","Year":2003}
        ])
        save_books()

def save_books():
    df = pd.DataFrame(books)
    df.to_excel("books.xlsx", index=False)
    update_count_label()

# --------------------- BOOK OPERATIONS ---------------------
def add_book():
    title = title_var.get()
    author = author_var.get()
    isbn = isbn_var.get()
    year = year_var.get()

    if not title or not author or not isbn:
        messagebox.showwarning("Warning","Please fill in all fields!")
        return

    books.append({"Title":title,"Author":author,"ISBN":isbn,"Year":year})
    recent_books.append(title)
    if len(recent_books) > MAX_QUEUE_SIZE:
        recent_books.pop(0)
    save_books()
    refresh_table()
    messagebox.showinfo("Success",f"Book '{title}' added successfully!")

def delete_book():
    selected = tree.focus()
    if not selected:
        messagebox.showwarning("Warning","Select a book to delete!")
        return
    values = tree.item(selected,"values")
    title_to_delete = values[1]
    global books
    books = [b for b in books if b["Title"] != title_to_delete]
    save_books()
    refresh_table()
    messagebox.showinfo("Deleted",f"Book '{title_to_delete}' deleted.")

def search_books():
    keyword = search_var.get().strip().lower()
    if not keyword:
        messagebox.showinfo("Info","Enter a keyword to search.")
        return
    mode = search_mode.get()
    for row in tree.get_children():
        tree.delete(row)

    found = False
    for i, book in enumerate(books):
        if (mode=="Title" and keyword in book["Title"].lower()) or \
           (mode=="Author" and keyword in book["Author"].lower()) or \
           (mode=="ISBN" and keyword in book["ISBN"].lower()):
            tree.insert("", "end", values=(i+1, book["Title"], book["Author"], book["ISBN"], book["Year"]))
            found = True
    if not found:
        messagebox.showinfo("No Results","No books found matching your keyword.")

def display_all():
    refresh_table()

def show_recent():
    if not recent_books:
        messagebox.showinfo("Recent Books","No recent books added yet.")
        return
    msg = "\n".join(recent_books)
    messagebox.showinfo("Recently Added Books",msg)

# --------------------- GUI SETUP ---------------------
root = tk.Tk()
root.title("📚 Library Management System")
root.geometry("950x650")
root.configure(bg="#F0F4F8")

# Header
header = tk.Label(root, text="Library Management System", font=("Helvetica", 20, "bold"), bg="#4A90E2", fg="white", pady=15)
header.pack(fill=tk.X)

# Entry Frame
frame = tk.Frame(root, bg="#F0F4F8", padx=20, pady=10)
frame.pack(fill=tk.X)

tk.Label(frame,text="Title:",bg="#F0F4F8").grid(row=0,column=0,sticky=tk.W)
tk.Label(frame,text="Author:",bg="#F0F4F8").grid(row=1,column=0,sticky=tk.W)
tk.Label(frame,text="ISBN:",bg="#F0F4F8").grid(row=0,column=2,sticky=tk.W)
tk.Label(frame,text="Year:",bg="#F0F4F8").grid(row=1,column=2,sticky=tk.W)

title_var = tk.StringVar()
author_var = tk.StringVar()
isbn_var = tk.StringVar()
year_var = tk.StringVar()
search_var = tk.StringVar()
search_mode = tk.StringVar(value="Title")

tk.Entry(frame,textvariable=title_var,width=25).grid(row=0,column=1,padx=5,pady=5)
tk.Entry(frame,textvariable=author_var,width=25).grid(row=1,column=1,padx=5,pady=5)
tk.Entry(frame,textvariable=isbn_var,width=25).grid(row=0,column=3,padx=5,pady=5)
tk.Entry(frame,textvariable=year_var,width=25).grid(row=1,column=3,padx=5,pady=5)

# Buttons
btn_frame = tk.Frame(root,bg="#F0F4F8",pady=10)
btn_frame.pack()
tk.Button(btn_frame,text="Add Book",command=add_book,bg="#4CAF50",fg="white",width=15).grid(row=0,column=0,padx=5)
tk.Button(btn_frame,text="Delete Book",command=delete_book,bg="#E53935",fg="white",width=15).grid(row=0,column=1,padx=5)
tk.Button(btn_frame,text="Display All",command=display_all,bg="#1E88E5",fg="white",width=15).grid(row=0,column=2,padx=5)
tk.Button(btn_frame,text="Show Recent",command=show_recent,bg="#FDD835",fg="black",width=15).grid(row=0,column=3,padx=5)

# Search Frame
search_frame = tk.Frame(root,bg="#F0F4F8")
search_frame.pack(pady=10)
tk.Label(search_frame,text="Search by:",bg="#F0F4F8").pack(side=tk.LEFT,padx=5)
search_dropdown = ttk.Combobox(search_frame,textvariable=search_mode,values=["Title","Author","ISBN"],width=10,state="readonly")
search_dropdown.pack(side=tk.LEFT,padx=5)
tk.Entry(search_frame,textvariable=search_var,width=30).pack(side=tk.LEFT,padx=5)
tk.Button(search_frame,text="Search",command=search_books,bg="#00796B",fg="white",width=10).pack(side=tk.LEFT,padx=5)

# Treeview
columns=("S.No","Title","Author","ISBN","Year")
tree = ttk.Treeview(root,columns=columns,show="headings",height=15)
for col in columns:
    tree.heading(col,text=col)
    tree.column(col,width=160)
tree.pack(padx=10,pady=10,fill=tk.BOTH,expand=True)

# Scrollbar
scrollbar = ttk.Scrollbar(root,orient="vertical",command=tree.yview)
tree.configure(yscroll=scrollbar.set)
scrollbar.pack(side=tk.RIGHT,fill=tk.Y)

# Book count label
count_label = tk.Label(root,text="",bg="#F0F4F8",font=("Helvetica",12,"bold"),fg="#0D47A1")
count_label.pack(pady=5)

# --------------------- REFRESH & UPDATE ---------------------
def refresh_table():
    for row in tree.get_children():
        tree.delete(row)
    sorted_books = quick_sort(books)
    for i, book in enumerate(sorted_books):
        tree.insert("", "end", values=(i+1, book["Title"], book["Author"], book["ISBN"], book["Year"]))
    update_count_label()

def update_count_label():
    count_label.config(text=f"📘 Total Books: {len(books)}")

load_books()
refresh_table()
root.mainloop()
