# University Academic & Record Management System (UAMS)

**Student:** Aayush Panchal  
**Enrollment No:** IU2541230476  
**Section:** E  
**Subject:** CE0316 — Object Oriented Concepts with UML  
**Semester:** III | **Academic Year:** 2026–2027  
**Institution:** Indus University — IITE

---

## Project Description

A comprehensive menu-driven C++ console application that manages university students, faculty, teaching assistants, academic grading, fee/salary accounts, and persistent binary file storage — demonstrating **every OOP concept** from the CE0316 syllabus.

## Syllabus Concepts Covered

| Concept | Implementation |
|---------|---------------|
| Namespace, Enum, Constants | `namespace CollegeSystem`, `enum RoleType` |
| Inline Functions vs Macros | `#define MAX_MARKS_MACRO` vs `inline calculatePercentage()` |
| Call & Return by Reference | `swapGrades(double&, double&)`, `double& getSubjectMarkRef()` |
| Function Overloading & Default Args | Overloaded `printDivider()` with defaults |
| Friend Functions | `friend void auditAndBalance()` across two classes |
| Static Members & Functions | `static int totalPeople`, `Person::getTotalPeopleCount()` |
| Constructors (Default/Param/Copy) | Deep-copy constructors, Virtual destructors |
| Operator Overloading | `+`, `-`, `==`, `<`, `>`, `++` (prefix/postfix), `<<`, `>>` |
| Data Conversion (3 types) | Basic→Class, Class→Basic, Class→Class (INR↔USD) |
| Single, Hierarchical Inheritance | `Person→Student`, `Account→FeeAccount/SalaryAccount` |
| Diamond Problem (Virtual Base) | `Person(virtual)→Student,Faculty→TeachingAssistant` |
| Pure Virtual & Abstract Classes | `ReportableEntity` with `= 0` functions |
| Runtime Polymorphism | `ReportableEntity*` array with dynamic dispatch |
| Pointer to Object & Member Function | `stuPtr->*getScoreFunc` |
| Formatted & Unformatted I/O | `setw`, `setfill`, `cin.get()`, `cout.put()` |
| Binary File I/O | `write()`, `read()` with `reinterpret_cast` |
| Random Access File Pointers | `seekg()`, `seekp()`, `tellg()` |
| Function & Class Templates | `bubbleSort<T>()`, `DynamicRepository<T>` |

## How to Compile and Run

### Using GCC / MinGW
```bash
g++ -std=c++11 -Wall main.cpp -o uams.exe
./uams.exe
```

### Using any IDE (Code::Blocks / Dev-C++ / Visual Studio)
1. Open `main.cpp` in the IDE
2. Build & Run (F9 / F5)

### Using Online Compiler
1. Copy contents of `main.cpp`
2. Paste into [OnlineGDB](https://www.onlinegdb.com/)
3. Click Run

## Folder Structure
```
IU2541230476_PROJECT/
├── PROJECT SOURCE CODE/
│   └── main.cpp              # Complete C++ source code
├── UML Diagrams/
│   └── UML_Diagrams.html     # Interactive UML diagrams
├── Screenshots/
│   └── (add after running)   # Console output screenshots
├── Project_Report.html       # Formatted report (print to PDF)
└── README.md                 # This file
```

## License
This project is submitted as academic coursework for CE0316, Indus University.
