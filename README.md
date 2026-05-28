# 📚 Library Management System in C

## 🔍 Overview

This is a simple **Library Management System** developed in the **C programming language** using **file handling** concepts. The program allows users to manage library books through a menu-driven interface.

The system stores book records in a binary file (`library.dat`) and supports basic operations like adding, searching, issuing, and returning books.

---

## ✨ Features

✔️ Add new books
✔️ Display all books
✔️ Search books by ID
✔️ Issue books
✔️ Return books
✔️ File handling using binary files

---

## 🛠️ Technologies Used

* 💻 C Programming Language
* 📚 Standard Libraries:

  * `stdio.h`
  * `stdlib.h`
  * `string.h`

---

## 📁 File Structure

| 📄 File Name  | 📌 Description                               |
| ------------- | -------------------------------------------- |
| `main.c`      | Source code of the Library Management System |
| `library.dat` | Binary file used to store book records       |

---

## 🧱 Structure Used

```c
struct Book {
    int id;
    char title[50];
    char author[50];
    int quantity;
};
```

---

## ⚙️ Functions

### 1️⃣ `addBook()`

➕ Adds a new book record to the file.

### 2️⃣ `displayBooks()`

📖 Displays all books stored in the file.

### 3️⃣ `searchBook()`

🔎 Searches for a book using its ID.

### 4️⃣ `issueBook()`

📕 Issues a book by reducing its quantity by 1.

### 5️⃣ `returnBook()`

📗 Returns a book by increasing its quantity by 1.

---

## ▶️ How to Compile and Run

### 🖥️ Using GCC Compiler

Compile the program:

```bash
gcc main.c -o library
```

Run the program:

```bash
./library
```

For Windows:

```bash
library.exe
```

---

## 📋 Sample Menu

```text
===== LIBRARY MANAGEMENT SYSTEM =====
1. Add Book
2. Display Books
3. Search Book
4. Issue Book
5. Return Book
6. Exit
```

---

## 🧪 Example Operations

### ➕ Add Book

Enter:

* 📌 Book ID
* 📘 Book Title
* ✍️ Author Name
* 🔢 Quantity

### 📕 Issue Book

* Enter Book ID
* Quantity decreases automatically

### 📗 Return Book

* Enter Book ID
* Quantity increases automatically

---

## ✅ Advantages

✔️ Simple and easy to understand
✔️ Demonstrates file handling in C
✔️ Beginner-friendly project
✔️ Useful for academic mini-projects

---

## ⚠️ Limitations

❌ No password/authentication system
❌ No duplicate ID checking
❌ No delete/update functionality
❌ Uses binary file storage only

---

## Future Improvements

* Add login system
* Add delete and update options
* Store issue/return history
* Use database integration
* Create GUI version

---

## Author

Developed as a mini project in C programming for learning file handling and structure concepts.

---



