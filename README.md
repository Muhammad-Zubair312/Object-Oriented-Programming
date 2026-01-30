# Object-Oriented-Programming

# C++ Object Oriented Programming Portfolio

This repository contains a collection of C++ projects and assignments demonstrating core Object-Oriented Programming (OOP) concepts, ranging from basic classes to complex file-handling systems.

## 📂 Project Structure

### [01-Basics](./01-Basics/)
*   **Concepts:** Classes, Objects, Constructors, Destructors, Encapsulation.
*   **Key Files:** `Employee-Class.cpp`, `Basics-Q14.cpp`.
*   **Description:** Fundamental examples of defining classes and managing object state.

### [02-Operator-Overloading](./02-Operator-Overloading/)
*   **Concepts:** Operator Overloading (+, -, <<, >>, ++, etc.), Friend Functions.
*   **Key File:** `Point-Operator-Overloading.cpp`.
*   **Description:** A complete `Point` class implementation showing how to overload mathematical and stream operators for custom types.

### [03-Polymorphism-Shapes](./03-Polymorphism-Shapes/)
*   **Concepts:** Inheritance, Virtual Functions, Abstract Classes, Polymorphism.
*   **Key File:** `Shape-Polymorphism.cpp`.
*   **Description:** A classic shapes hierarchy (`Shape` -> `Triangle`, `Square`) demonstrating runtime polymorphism and virtual destructors.

### [04-Course-Management-Sys](./04-Course-Management-Sys/)
*   **Concepts:** Complex Inheritance, Vectors, Dynamic Casting, Role-Based logic.
*   **Key File:** `CourseSystem.cpp`.
*   **Description:** A mini-system managing `Admin`, `Teacher`, and `Student` users. Features include course creation, enrollment, and grade assignment using polymorphic behavior.

### [05-Student-Record-App](./05-Student-Record-App/)
*   **Concepts:** File Handling (`fstream`), Binary Files, CRUD Operations, Indexing.
*   **Key File:** `StudentRecordSystem.cpp`.
*   **Description:** A full-featured console application for managing student records.
    *   **Features:** Add, Update, Delete, Search (by Roll No, CGPA, City).
    *   **Tech:** Uses binary file storage (`students.dat`) and a custom index file (`index.dat`) for fast lookup.

## 🚀 How to Run
1.  Navigate to any project folder.
2.  Compile using g++:
    ```bash
    g++ FileName.cpp -o OutputName
    ```
3.  Run the executable:
    ```bash
    ./OutputName
    ```

## 🛠️ Skills Demonstrated
*   **C++ Fundamentals** (Pointers, References, Memory Management)
*   **OOP Principles** (Encapsulation, Inheritance, Polymorphism, Abstraction)
*   **Advanced C++** (Operator Overloading, Virtual Functions, Vectors)
*   **Data Persistence** (Binary File I/O, File pointers)
