=================================================================================
UNIVERSITY ACADEMIC & RECORD MANAGEMENT SYSTEM (UAMS)
=================================================================================
Course       : Object Oriented Concepts with UML (Subject Code: CE0316)
Program      : B. Tech CE / CSE / IT - Semester III (2026-2027)
Student Name : Aayush Panchal
Enrollment No: IU2541230476
Section      : E
Institution  : Indus Institute of Technology & Engineering, Indus University
GitHub Repo  : https://github.com/panchalaayush25cse-afk/UAMS-CPP-Project
=================================================================================

PROJECT OVERVIEW:
-----------------
The University Academic & Record Management System (UAMS) is an object-oriented
software developed in C++ satisfying all concepts specified in the CE0316 syllabus.
It manages university students, faculty members, teaching assistants, grading,
department audits, fee/salary accounts, and persistent binary records.

PROJECT DIRECTORY STRUCTURE:
----------------------------
IU2541230476_PROJECT/
  |-- Data/                       --> Persistent binary database files (.dat)
  |-- Diagrams/                   --> UML Diagrams (Class, Use Case, Activity, Sequence, State)
  |-- Executable/                 --> Standalone runnable .exe application
  |-- ProjectReport.DOCS/         --> Comprehensive formatted project report
  |-- Screenshots/                --> Console execution output screenshots
  |-- Source/                     --> C++ source code (main.cpp)
  |-- UniversityManagement.exe    --> Standalone executable (double-click to run)
  `-- README.txt                  --> Project summary and documentation

KEY OOP CONCEPTS DEMONSTRATED:
------------------------------
1. Encapsulation & Data Hiding (Private/Protected/Public access specifiers)
2. Constructors & Destructors (Default, Parameterized, Copy with deep copy)
3. Hybrid Inheritance & Virtual Base Class (Resolving the Diamond Problem for TeachingAssistant)
4. Operator Overloading (+, -, ==, <, >, ++ prefix/postfix, << and >> stream operators)
5. 3-Way Data Type Conversion (Basic to Class, Class to Basic, Class to Class)
6. Friend Functions across two independent classes (DepartmentBudget & ScholarshipFund)
7. Runtime Polymorphism & Dynamic Binding (Pure virtual functions in abstract base class)
8. Generic Programming / Templates (bubbleSort<T> and DynamicRepository<T> class template)
9. Binary File I/O & Random Access (seekg, seekp, tellg for in-place byte updates)
10. Stream Formatting Manipulators (setw, setfill, setprecision, fixed, left, right)

HOW TO RUN:
-----------
Method 1: Directly double-click 'UniversityManagement.exe'.
Method 2: Compile 'Source/main.cpp' in any C++ IDE (Code::Blocks, Dev-C++, Visual Studio, CLion)
          or terminal: g++ -std=c++11 Source/main.cpp -o UniversityManagement.exe
Method 3: Copy-paste 'Source/main.cpp' into OnlineGDB (https://www.onlinegdb.com/) and click Run.

Choose Option 8 from the menu to run the entire viva demonstration sequentially!
=================================================================================
