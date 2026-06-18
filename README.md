# Library Management System

A console-based Library Management System developed in C++ that helps manage library operations efficiently through file handling. The application allows users to maintain book records, manage borrower information, and track issued books using a simple and interactive interface.

## Overview

This project is designed to streamline the process of managing a library by providing functionalities for maintaining book inventories and borrower records. All data is stored using text files, ensuring persistence between program executions without requiring a database.

## Features

### Book Management
- Add new books to the library
- View available book stock
- Update existing book records
- Delete books from the catalog
- Search and display book details

### Borrower Management
- Register new borrowers
- Update borrower information
- Remove borrower records
- View borrower details

### Borrowing & Tracking
- Track borrowed books
- Monitor borrowing duration
- Check remaining borrowing time
- Maintain accurate lending records

## How to Run

### Compile

```bash
g++ library-management.cpp -o library
```

### Execute

```bash
./library
```

For Windows:

```bash
g++ library-management.cpp -o library.exe
library.exe
```

## Learning Outcomes

This project demonstrates practical applications of:

- Object-Oriented Programming (OOP)
- File Handling in C++
- Data Management
- CRUD Operations
- Console-Based Application Development

## Future Improvements

- User authentication system
- Fine and overdue fee calculation
- Advanced search and filtering
- Book reservation functionality
- Database integration
- Graphical User Interface (GUI)
