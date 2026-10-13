/**
 * =========================================================================================
 * PROJECT TITLE: UNIVERSITY ACADEMIC & RECORD MANAGEMENT SYSTEM (UAMS)
 * COURSE       : Object Oriented Concepts with UML (CE0316)
 * INSTITUTION  : Indus University - Department of CE / CSE / IT
 * 
 * =========================================================================================
 * SYLLABUS CONCEPT COVERAGE INDEX:
 * -----------------------------------------------------------------------------------------
 * UNIT-I:
 *   - OOP Principles: Abstraction, Encapsulation, Inheritance, Polymorphism
 *   - C++ Basics: Namespace (CollegeSystem), Enum (RoleType, AccountType), Constants,
 *     Identifiers, Variables, Operators, Typecasting (static_cast & C-style)
 *   - Functions: Call by reference, Return by reference (lvalue assignment),
 *     Inline functions, Macro vs Inline function comparison, Function overloading,
 *     Default arguments, Friend functions.
 * 
 * UNIT-II:
 *   - Classes and Objects: Private, Protected, and Public access specifiers
 *   - Static Data Members and Static Member Functions (auto-id generation, instance counter)
 *   - Constructors: Default, Parameterized, and Copy Constructor (Deep Copy)
 *   - Destructors (Virtual destructors for polymorphic hierarchy)
 *   - Arrays & Strings: Standard C++ std::string and char arrays
 *   - Operator Overloading:
 *       * Unary Operator Overloading (++ prefix and postfix)
 *       * Binary Operator Overloading (+, -, ==, <)
 *       * Operator Overloading with Friend Function (<< and >>)
 *   - Data Conversion / Type Conversion:
 *       * Basic type to Class type (double -> Currency)
 *       * Class type to Basic type (Currency -> double)
 *       * Class to Class (CurrencyINR <-> CurrencyUSD)
 * 
 * UNIT-III:
 *   - Inheritance:
 *       * Single Inheritance (Person -> Student)
 *       * Multilevel Inheritance (Person -> Student -> GraduateStudent)
 *       * Multiple & Hybrid Inheritance with Virtual Base Class (Diamond Problem Resolution):
 *         Person (Virtual Base) -> Student, Faculty -> TeachingAssistant
 *       * Hierarchical Inheritance (Account -> StudentFeeAccount, FacultySalaryAccount)
 *       * Protected members & method overriding
 *       * Constructors in derived classes (Base initialization list)
 *   - Polymorphism:
 *       * Pointers in C++, Pointers to Objects, 'this' pointer
 *       * Virtual and Pure Virtual Functions (Abstract Base Class: ReportableEntity)
 *       * Dynamic Binding / Runtime Polymorphism via base pointers
 *       * Pointer to Member Functions and Pointer to Objects
 *   - I/O Management:
 *       * Streams: cin, cout objects, cerr
 *       * Formatted I/O & Manipulators: setw, setfill, setprecision, fixed, left, right
 *       * Unformatted I/O: cin.get(), cin.getline(), cout.put()
 * 
 * UNIT-IV:
 *   - File Management:
 *       * File streams: ifstream, ofstream, fstream
 *       * File modes: ios::in, ios::out, ios::binary, ios::app
 *       * Binary File I/O: read(), write()
 *       * Random Access & File Pointer Manipulation: seekg(), seekp(), tellg(), tellp()
 *   - Templates (Lab 10 & Outcomes):
 *       * Function Template: template bubbleSort(), template findMax()
 *       * Class Template: template class DynamicRepository<T>
 * =========================================================================================
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>

// =========================================================================================
// UNIT-I: MACRO VS INLINE FUNCTION DEMONSTRATION & CONSTANTS
// =========================================================================================
#define MAX_MARKS_MACRO(a, b) ((a) > (b) ? (a) : (b)) // Macro definition
const double PASSING_GRADE_PERCENTAGE = 40.0;          // Constant
const int MAX_SUBJECTS = 4;                            // Constant

// Namespace declaration
namespace CollegeSystem {

    // Enum declaration
    enum RoleType { STUDENT_ROLE = 1, FACULTY_ROLE = 2, TA_ROLE = 3 };
    enum AccountType { FEE_ACCOUNT = 1, SALARY_ACCOUNT = 2 };

    // Inline function comparison
    inline double calculatePercentage(double totalMarks, int subjectCount) {
        return (subjectCount > 0) ? (totalMarks / (subjectCount * 100.0)) * 100.0 : 0.0;
    }

    // Call and Return by Reference demonstration
    inline void swapGrades(double& gradeA, double& gradeB) {
        double temp = gradeA;
        gradeA = gradeB;
        gradeB = temp;
    }

    // Function Overloading & Default Arguments
    inline void printDivider(char symbol = '=', int length = 75) {
        std::cout << std::setfill(symbol) << std::setw(length) << "" << std::setfill(' ') << std::endl;
    }

    inline void printDivider(const std::string& title, char symbol = '-', int length = 75) {
        int pad = (length - static_cast<int>(title.length()) - 2) / 2;
        if (pad < 0) pad = 0;
        std::cout << std::setfill(symbol) << std::setw(pad) << "" << " " 
                  << title << " " 
                  << std::setw(pad) << "" << std::setfill(' ') << std::endl;
    }

    // Forward declaration for Friend function & Class to Class conversions
    class CurrencyUSD;

    // =====================================================================================
    // UNIT-II: DATA CONVERSION & OPERATOR OVERLOADING (Currency Classes)
    // =====================================================================================
    class CurrencyINR {
    private:
        int rupees;
        int paise;

    public:
        // Default Constructor
        CurrencyINR() : rupees(0), paise(0) {}

        // Parameterized Constructor
        CurrencyINR(int r, int p) : rupees(r + p / 100), paise(p % 100) {}

        // 1. Basic Type to Class Type Conversion (double -> CurrencyINR)
        CurrencyINR(double totalAmount) {
            rupees = static_cast<int>(totalAmount);
            paise = static_cast<int>(std::round((totalAmount - rupees) * 100));
            if (paise >= 100) {
                rupees += paise / 100;
                paise %= 100;
            }
        }

        // Copy Constructor
        CurrencyINR(const CurrencyINR& other) {
            this->rupees = other.rupees;
            this->paise = other.paise;
        }

        // Destructor
        ~CurrencyINR() {}

        // 2. Class Type to Basic Type Conversion (CurrencyINR -> double)
        operator double() const {
            return rupees + (paise / 100.0);
        }

        // Binary Operator Overloading (+)
        CurrencyINR operator+(const CurrencyINR& c) const {
            int totalPaise = (this->rupees + c.rupees) * 100 + (this->paise + c.paise);
            return CurrencyINR(totalPaise / 100, totalPaise % 100);
        }

        // Binary Operator Overloading (-)
        CurrencyINR operator-(const CurrencyINR& c) const {
            int diffPaise = ((this->rupees * 100) + this->paise) - ((c.rupees * 100) + c.paise);
            if (diffPaise < 0) diffPaise = 0;
            return CurrencyINR(diffPaise / 100, diffPaise % 100);
        }

        // Relational Operator Overloading (==, <, >)
        bool operator==(const CurrencyINR& c) const {
            return (this->rupees == c.rupees) && (this->paise == c.paise);
        }

        bool operator<(const CurrencyINR& c) const {
            return ((this->rupees * 100) + this->paise) < ((c.rupees * 100) + c.paise);
        }

        bool operator>(const CurrencyINR& c) const {
            return ((this->rupees * 100) + this->paise) > ((c.rupees * 100) + c.paise);
        }

        // Unary Operator Overloading (++ Prefix and Postfix)
        CurrencyINR& operator++() { // Prefix: adds 100 rupees
            this->rupees += 100;
            return *this;
        }

        CurrencyINR operator++(int) { // Postfix
            CurrencyINR temp = *this;
            this->rupees += 100;
            return temp;
        }

        // Friend Function for Stream Insertion (<<) and Extraction (>>)
        friend std::ostream& operator<<(std::ostream& out, const CurrencyINR& c);
        friend std::istream& operator>>(std::istream& in, CurrencyINR& c);

        // Friend function to add two different currency objects (Lab 5.3)
        friend CurrencyINR addCurrencyValues(const CurrencyINR& a, const CurrencyINR& b);

        // Friend class for Class-to-Class conversion
        friend class CurrencyUSD;

        int getRupees() const { return rupees; }
        int getPaise() const { return paise; }
    };

    // Implementation of friend stream operators
    std::ostream& operator<<(std::ostream& out, const CurrencyINR& c) {
        out << "Rs. " << c.rupees << "." << std::setfill('0') << std::setw(2) << c.paise << std::setfill(' ');
        return out;
    }

    std::istream& operator>>(std::istream& in, CurrencyINR& c) {
        double amount;
        in >> amount;
        c = CurrencyINR(amount); // Uses basic-to-class conversion
        return in;
    }

    CurrencyINR addCurrencyValues(const CurrencyINR& a, const CurrencyINR& b) {
        return a + b;
    }

    // 3. Class to Class Conversion Class
    class CurrencyUSD {
    private:
        double dollars;

    public:
        CurrencyUSD(double d = 0.0) : dollars(d) {}

        // Conversion Constructor: CurrencyINR to CurrencyUSD (Class-to-Class)
        CurrencyUSD(const CurrencyINR& inr) {
            double totalRupees = inr.getRupees() + (inr.getPaise() / 100.0);
            dollars = totalRupees / 83.0; // Approx exchange rate
        }

        double getDollars() const { return dollars; }

        void display() const {
            std::cout << "$" << std::fixed << std::setprecision(2) << dollars;
        }

        // Conversion Operator: CurrencyUSD to CurrencyINR (Class-to-Class)
        operator CurrencyINR() const {
            double inrValue = dollars * 83.0;
            return CurrencyINR(inrValue);
        }
    };

    // =====================================================================================
    // UNIT-IV / LAB 10: TEMPLATES (Class Template & Function Templates)
    // =====================================================================================
    template <typename T>
    void bubbleSort(T arr[], int size) {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    T temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    template <typename T>
    T findMaximum(T arr[], int size) {
        T maxVal = arr[0];
        for (int i = 1; i < size; ++i) {
            if (arr[i] > maxVal) {
                maxVal = arr[i];
            }
        }
        return maxVal;
    }

    // Generic Class Template (Safe Container / Dynamic Array)
    template <typename T>
    class DynamicRepository {
    private:
        T* data;
        int capacity;
        int count;

    public:
        DynamicRepository(int cap = 10) : capacity(cap), count(0) {
            data = new T[capacity];
        }

        ~DynamicRepository() {
            delete[] data;
        }

        void add(const T& item) {
            if (count < capacity) {
                data[count++] = item;
            }
        }

        int size() const { return count; }

        // Return by reference
        T& operator[](int index) {
            if (index < 0 || index >= count) {
                return data[0]; // fallback
            }
            return data[index];
        }

        const T& operator[](int index) const {
            if (index < 0 || index >= count) {
                return data[0];
            }
            return data[index];
        }
    };

    // =====================================================================================
    // UNIT-III: POLYMORPHISM & ABSTRACT BASE CLASS
    // =====================================================================================
    class ReportableEntity {
    public:
        // Pure virtual function making this an Abstract Base Class
        virtual void displayDetails() const = 0;
        virtual void printFormattedSummary() const = 0;

        // Virtual destructor for safe polymorphic cleanup
        virtual ~ReportableEntity() {}
    };

    // =====================================================================================
    // UNIT-III: HYBRID INHERITANCE WITH VIRTUAL BASE CLASS (Diamond Problem Solved)
    // 
    //            [Person]  <-- Virtual Base Class
    //            /      \
    //      [Student]   [Faculty]
    //            \      /
    //      [TeachingAssistant]
    // =====================================================================================
    class Person : public ReportableEntity {
    protected:
        int id;
        std::string name;
        std::string email;
        static int totalPeople; // Static data member

    public:
        // Default Constructor
        Person() : id(0), name("Unknown"), email("none@college.edu") {
            totalPeople++;
        }

        // Parameterized Constructor
        Person(int pId, const std::string& pName, const std::string& pEmail)
            : id(pId), name(pName), email(pEmail) {
            totalPeople++;
        }

        // Copy Constructor demonstrating deep copy
        Person(const Person& other) : id(other.id), name(other.name), email(other.email) {
            totalPeople++;
        }

        // Virtual Destructor
        virtual ~Person() {
            totalPeople--;
        }

        // Static member function
        static int getTotalPeopleCount() {
            return totalPeople;
        }

        // Getter with 'this' pointer disambiguation
        int getId() const { return this->id; }
        std::string getName() const { return this->name; }
        std::string getEmail() const { return this->email; }

        void setDetails(int id, const std::string& name, const std::string& email) {
            this->id = id;
            this->name = name;
            this->email = email;
        }

        // Base class implementation of pure virtual
        virtual void displayDetails() const override {
            std::cout << std::left << std::setw(8) << id 
                      << std::setw(22) << name 
                      << std::setw(28) << email;
        }

        virtual void printFormattedSummary() const override {
            std::cout << "[Person ID: " << id << " | Name: " << name << "]";
        }
    };

    // Initialize static data member
    int Person::totalPeople = 0;

    // Derived Class 1: Student (Virtual Inheritance from Person)
    class Student : virtual public Person {
    protected:
        std::string department;
        int semester;
        double marks[MAX_SUBJECTS];
        double totalMarks;
        double percentage;
        static int totalStudents;

    public:
        // Constructor in derived class calling base constructor
        Student() : Person(), department("CE"), semester(1), totalMarks(0.0), percentage(0.0) {
            for (int i = 0; i < MAX_SUBJECTS; ++i) marks[i] = 0.0;
            totalStudents++;
        }

        Student(int sId, const std::string& sName, const std::string& sEmail,
                const std::string& dept, int sem, const double subMarks[MAX_SUBJECTS])
            : Person(sId, sName, sEmail), department(dept), semester(sem) {
            totalMarks = 0.0;
            for (int i = 0; i < MAX_SUBJECTS; ++i) {
                marks[i] = subMarks[i];
                totalMarks += marks[i];
            }
            // Inline function call
            percentage = calculatePercentage(totalMarks, MAX_SUBJECTS);
            totalStudents++;
        }

        // Copy constructor
        Student(const Student& other) : Person(other) {
            department = other.department;
            semester = other.semester;
            totalMarks = other.totalMarks;
            percentage = other.percentage;
            for (int i = 0; i < MAX_SUBJECTS; ++i) {
                marks[i] = other.marks[i];
            }
            totalStudents++;
        }

        virtual ~Student() override {
            totalStudents--;
        }

        static int getTotalStudents() { return totalStudents; }

        double getPercentage() const { return percentage; }
        double getTotalMarks() const { return totalMarks; }
        int getSemester() const { return semester; }
        std::string getDepartment() const { return department; }

        // Return by reference (allows modification of marks directly)
        double& getSubjectMarkRef(int index) {
            if (index >= 0 && index < MAX_SUBJECTS) {
                return marks[index];
            }
            return marks[0];
        }

        void recalculateMarks() {
            totalMarks = 0.0;
            for (int i = 0; i < MAX_SUBJECTS; ++i) {
                totalMarks += marks[i];
            }
            percentage = calculatePercentage(totalMarks, MAX_SUBJECTS);
        }

        // Overriding virtual function
        virtual void displayDetails() const override {
            Person::displayDetails();
            std::cout << std::setw(8) << department 
                      << std::setw(6) << semester 
                      << std::right << std::fixed << std::setprecision(1) << std::setw(7) << percentage << "%" 
                      << std::setfill(' ') << std::endl;
        }

        virtual void printFormattedSummary() const override {
            std::cout << "Student: " << name << " (" << department << ", Sem " << semester 
                      << ") - Score: " << std::fixed << std::setprecision(1) << percentage << "%";
        }

        // Relational operator for sorting students by percentage
        bool operator>(const Student& other) const {
            return this->percentage > other.percentage;
        }
    };

    int Student::totalStudents = 0;

    // Derived Class 2: Faculty (Virtual Inheritance from Person)
    class Faculty : virtual public Person {
    protected:
        std::string designation;
        std::string department;
        CurrencyINR basicSalary;
        static int totalFaculty;

    public:
        Faculty() : Person(), designation("Lecturer"), department("CE"), basicSalary(45000.0) {
            totalFaculty++;
        }

        Faculty(int fId, const std::string& fName, const std::string& fEmail,
                const std::string& desig, const std::string& dept, CurrencyINR salary)
            : Person(fId, fName, fEmail), designation(desig), department(dept), basicSalary(salary) {
            totalFaculty++;
        }

        virtual ~Faculty() override {
            totalFaculty--;
        }

        static int getTotalFaculty() { return totalFaculty; }

        std::string getDesignation() const { return designation; }
        CurrencyINR getSalary() const { return basicSalary; }

        virtual void displayDetails() const override {
            Person::displayDetails();
            std::cout << std::left << std::setw(16) << designation 
                      << std::setw(8) << department 
                      << basicSalary << std::endl;
        }

        virtual void printFormattedSummary() const override {
            std::cout << "Faculty: " << name << " [" << designation << " in " << department << "]";
        }
    };

    int Faculty::totalFaculty = 0;

    // Derived Class 3: TeachingAssistant (Multiple & Hybrid Inheritance)
    // Inherits virtually from Person via Student and Faculty!
    class TeachingAssistant : public Student, public Faculty {
    private:
        int labHoursPerWeek;
        CurrencyINR stipend;

    public:
        // Diamond resolution: calls virtual base Person constructor directly!
        TeachingAssistant()
            : Person(0, "TA", "ta@college.edu"),
              Student(),
              Faculty(),
              labHoursPerWeek(10),
              stipend(15000.0) {}

        TeachingAssistant(int tId, const std::string& tName, const std::string& tEmail,
                          const std::string& dept, int sem, const double sMarks[MAX_SUBJECTS],
                          int labHours, CurrencyINR stipendAmount)
            : Person(tId, tName, tEmail),
              Student(tId, tName, tEmail, dept, sem, sMarks),
              Faculty(tId, tName, tEmail, "Teaching Assistant", dept, stipendAmount),
              labHoursPerWeek(labHours),
              stipend(stipendAmount) {}

        virtual ~TeachingAssistant() override {}

        int getLabHours() const { return labHoursPerWeek; }
        CurrencyINR getStipend() const { return stipend; }

        virtual void displayDetails() const override {
            Person::displayDetails();
            std::cout << std::setw(8) << Student::department 
                      << "Sem " << std::setw(3) << semester 
                      << "TA Labs: " << std::setw(3) << labHoursPerWeek << " hrs/wk | "
                      << "Stipend: " << stipend << std::endl;
        }

        virtual void printFormattedSummary() const override {
            std::cout << "Teaching Assistant: " << name << " | TA Duties: " 
                      << labHoursPerWeek << " hrs/week | Stipend: " << stipend;
        }
    };

    // =====================================================================================
    // UNIT-III: HIERARCHICAL INHERITANCE (Financial Accounts)
    // =====================================================================================
    class Account {
    protected:
        int accountNumber;
        std::string holderName;
        CurrencyINR balance;

    public:
        Account(int accNo = 0, const std::string& name = "", CurrencyINR initialBal = 0.0)
            : accountNumber(accNo), holderName(name), balance(initialBal) {}

        virtual ~Account() {}

        int getAccountNumber() const { return accountNumber; }
        std::string getHolderName() const { return holderName; }
        CurrencyINR getBalance() const { return balance; }

        // Return by reference
        CurrencyINR& getBalanceRef() { return balance; }

        virtual void deposit(CurrencyINR amount) {
            balance = balance + amount;
            std::cout << "Successfully deposited " << amount << ". New Balance: " << balance << std::endl;
        }

        virtual bool withdraw(CurrencyINR amount) {
            if (balance > amount || balance == amount) {
                balance = balance - amount;
                std::cout << "Withdrawn: " << amount << ". Remaining: " << balance << std::endl;
                return true;
            } else {
                std::cout << "[ERROR] Insufficient funds! Current balance: " << balance << std::endl;
                return false;
            }
        }

        virtual void printStatement() const = 0; // Pure virtual
    };

    // Derived Hierarchical Class 1: StudentFeeAccount
    class StudentFeeAccount : public Account {
    private:
        CurrencyINR totalAnnualFee;
        CurrencyINR feePaid;

    public:
        StudentFeeAccount(int accNo, const std::string& name, CurrencyINR annualFee, CurrencyINR initialPaid = 0.0)
            : Account(accNo, name, annualFee - initialPaid), totalAnnualFee(annualFee), feePaid(initialPaid) {}

        void payTuitionFee(CurrencyINR amount) {
            feePaid = feePaid + amount;
            balance = totalAnnualFee - feePaid;
            std::cout << "Payment Accepted: " << amount << " | Pending Balance: " << balance << std::endl;
        }

        virtual void printStatement() const override {
            std::cout << std::left << std::setw(12) << accountNumber
                      << std::setw(22) << holderName
                      << std::setw(16) << totalAnnualFee
                      << std::setw(16) << feePaid
                      << std::setw(16) << balance << std::endl;
        }
    };

    // Derived Hierarchical Class 2: FacultySalaryAccount
    class FacultySalaryAccount : public Account {
    private:
        double taxDeductionPercent;

    public:
        FacultySalaryAccount(int accNo, const std::string& name, CurrencyINR baseSal, double taxPct = 10.0)
            : Account(accNo, name, baseSal), taxDeductionPercent(taxPct) {}

        void creditMonthlySalary(CurrencyINR grossSalary) {
            double netAmount = static_cast<double>(grossSalary) * (1.0 - taxDeductionPercent / 100.0);
            CurrencyINR netCurrency(netAmount); // Basic to class conversion
            deposit(netCurrency);
        }

        virtual void printStatement() const override {
            std::cout << std::left << std::setw(12) << accountNumber
                      << std::setw(22) << holderName
                      << "Tax: " << std::fixed << std::setprecision(1) << std::setw(5) << taxDeductionPercent << "% "
                      << "Balance: " << balance << std::endl;
        }
    };

    // =====================================================================================
    // UNIT-IV: FILE MANAGEMENT (Binary Serialization Record Structure)
    // =====================================================================================
    struct StudentBinaryRecord {
        int id;
        char name[40];
        char department[10];
        int semester;
        double marks[MAX_SUBJECTS];
        double totalMarks;
        double percentage;
    };

    class StudentFileManager {
    private:
        std::string filename;

    public:
        StudentFileManager(const std::string& fname = "students.dat") : filename(fname) {}

        // Binary File Write
        bool saveStudentRecord(const Student& student) {
            std::ofstream outFile(filename.c_str(), std::ios::out | std::ios::binary | std::ios::app);
            if (!outFile) {
                std::cerr << "[ERROR] Cannot open file for writing: " << filename << std::endl;
                return false;
            }

            StudentBinaryRecord rec;
            rec.id = student.getId();
            std::strncpy(rec.name, student.getName().c_str(), sizeof(rec.name) - 1);
            rec.name[sizeof(rec.name) - 1] = '\0';

            std::strncpy(rec.department, student.getDepartment().c_str(), sizeof(rec.department) - 1);
            rec.department[sizeof(rec.department) - 1] = '\0';

            rec.semester = student.getSemester();
            for (int i = 0; i < MAX_SUBJECTS; ++i) {
                // Using non-const reference trick to demonstrate call/return
                Student temp = student;
                rec.marks[i] = temp.getSubjectMarkRef(i);
            }
            rec.totalMarks = student.getTotalMarks();
            rec.percentage = student.getPercentage();

            outFile.write(reinterpret_cast<const char*>(&rec), sizeof(StudentBinaryRecord));
            outFile.close();
            return true;
        }

        // Display all records using unformatted & formatted I/O manipulators
        void displayAllRecords() {
            std::ifstream inFile(filename.c_str(), std::ios::in | std::ios::binary);
            if (!inFile) {
                std::cout << "[INFO] No existing data file found (" << filename << "). Add records first." << std::endl;
                return;
            }

            printDivider("RECORDS READ FROM BINARY FILE (students.dat)");
            std::cout << std::left 
                      << std::setw(8) << "ID" 
                      << std::setw(22) << "Name" 
                      << std::setw(10) << "Dept" 
                      << std::setw(6) << "Sem" 
                      << std::setw(12) << "Total (400)" 
                      << std::right << std::setw(10) << "Percent" << std::endl;
            printDivider('-', 75);

            StudentBinaryRecord rec;
            int recordCount = 0;

            // Reading binary objects
            while (inFile.read(reinterpret_cast<char*>(&rec), sizeof(StudentBinaryRecord))) {
                recordCount++;
                std::cout << std::left 
                          << std::setw(8) << rec.id 
                          << std::setw(22) << rec.name 
                          << std::setw(10) << rec.department 
                          << std::setw(6) << rec.semester 
                          << std::setw(12) << std::fixed << std::setprecision(1) << rec.totalMarks 
                          << std::right << std::setw(9) << rec.percentage << "%" << std::endl;
            }

            inFile.close();
            printDivider('-', 75);
            std::cout << "Total records loaded: " << recordCount << std::endl;
        }

        // Random Access File Pointer Manipulation: seekg, tellg, seekp
        bool searchRecordById(int searchId) {
            std::ifstream inFile(filename.c_str(), std::ios::in | std::ios::binary);
            if (!inFile) {
                std::cout << "[ERROR] Cannot open file for reading." << std::endl;
                return false;
            }

            StudentBinaryRecord rec;
            bool found = false;
            std::streampos position;

            while (!inFile.eof()) {
                position = inFile.tellg(); // Get current file pointer position
                if (!inFile.read(reinterpret_cast<char*>(&rec), sizeof(StudentBinaryRecord))) {
                    break;
                }

                if (rec.id == searchId) {
                    found = true;
                    std::cout << "\n[MATCH FOUND at Byte Offset " << position << "]" << std::endl;
                    std::cout << "ID          : " << rec.id << std::endl;
                    std::cout << "Name        : " << rec.name << std::endl;
                    std::cout << "Department  : " << rec.department << std::endl;
                    std::cout << "Semester    : " << rec.semester << std::endl;
                    std::cout << "Percentage  : " << std::fixed << std::setprecision(2) << rec.percentage << "%\n";
                    break;
                }
            }
            inFile.close();

            if (!found) {
                std::cout << "[INFO] Student with ID " << searchId << " not found in binary file." << std::endl;
            }
            return found;
        }

        // Update record using random file access: seekp
        bool updateStudentPercentage(int targetId, double newPercentage) {
            std::fstream file(filename.c_str(), std::ios::in | std::ios::out | std::ios::binary);
            if (!file) {
                std::cout << "[ERROR] Could not open file for read/write." << std::endl;
                return false;
            }

            StudentBinaryRecord rec;
            bool updated = false;

            while (file.read(reinterpret_cast<char*>(&rec), sizeof(StudentBinaryRecord))) {
                if (rec.id == targetId) {
                    rec.percentage = newPercentage;
                    // Move write pointer back to the beginning of this record
                    std::streamoff recordSize = sizeof(StudentBinaryRecord);
                    file.seekp(-recordSize, std::ios::cur);
                    file.write(reinterpret_cast<const char*>(&rec), sizeof(StudentBinaryRecord));
                    updated = true;
                    std::cout << "[SUCCESS] Record updated at random access location!" << std::endl;
                    break;
                }
            }
            file.close();
            return updated;
        }
    };

} // namespace CollegeSystem

// =========================================================================================
// UNIT-I & II: FRIEND FUNCTIONS DEMONSTRATION ACROSS TWO DIFFERENT CLASSES (Lab 3.4 & 5.1)
// =========================================================================================
class ScholarshipFund; // Forward declaration

class DepartmentBudget {
private:
    std::string deptName;
    double reserveFunds;

public:
    DepartmentBudget(const std::string& name, double funds) : deptName(name), reserveFunds(funds) {}
    // Friend function declaration
    friend void auditAndBalance(DepartmentBudget& dept, ScholarshipFund& sch);
    friend void displayFinancialAudit(const DepartmentBudget& dept, const ScholarshipFund& sch);
};

class ScholarshipFund {
private:
    std::string category;
    double endowment;

public:
    ScholarshipFund(const std::string& cat, double endw) : category(cat), endowment(endw) {}
    // Friend function declaration
    friend void auditAndBalance(DepartmentBudget& dept, ScholarshipFund& sch);
    friend void displayFinancialAudit(const DepartmentBudget& dept, const ScholarshipFund& sch);
};

// Friend function accessing private members of two different classes
void auditAndBalance(DepartmentBudget& dept, ScholarshipFund& sch) {
    if (dept.reserveFunds > 500000.0) {
        double transfer = 50000.0;
        dept.reserveFunds -= transfer;
        sch.endowment += transfer;
        std::cout << "[AUDIT FRIEND FUNCTION] Transferred Rs. " << transfer 
                  << " from " << dept.deptName << " to " << sch.category << " Scholarship." << std::endl;
    }
}

void displayFinancialAudit(const DepartmentBudget& dept, const ScholarshipFund& sch) {
    std::cout << "Dept Reserve (" << dept.deptName << "): Rs. " << std::fixed << std::setprecision(2) << dept.reserveFunds
              << " | Scholarship (" << sch.category << "): Rs. " << sch.endowment << std::endl;
}

// =========================================================================================
// MAIN MENU DRIVEN DEMONSTRATION PROGRAM
// =========================================================================================
using namespace CollegeSystem;

void displayMainMenu() {
    printDivider('=', 78);
    std::cout << "      UNIVERSITY ACADEMIC & RECORD MANAGEMENT SYSTEM (C++ OOP PROJECT)\n";
    std::cout << "               Syllabus: CE0316 - Indus University\n";
    printDivider('=', 78);
    std::cout << " 1. [Polymorphism & Diamond Inheritance] View All Campus Roles (TA, Student, Faculty)\n";
    std::cout << " 2. [Operator Overloading & Type Conversion] Currency & Fee Operations\n";
    std::cout << " 3. [Friend Function Across Classes] Department & Scholarship Audit\n";
    std::cout << " 4. [Templates] Generic Array Storage & Bubble Sort for Student Ranks\n";
    std::cout << " 5. [File Management & Random Access] Save, View & Search Binary Records\n";
    std::cout << " 6. [Hierarchical Accounts] Student Fee & Faculty Salary Processing\n";
    std::cout << " 7. [Pointers & Dynamic Binding] Pointer-to-Object & Pointer-to-Member-Function\n";
    std::cout << " 8. Run All Demonstrations Sequentially (Complete Viva Showcase)\n";
    std::cout << " 9. Exit System\n";
    printDivider('-', 78);
    std::cout << "Enter your choice [1 - 9]: ";
}

void demoPolymorphismAndDiamond() {
    printDivider("1. RUNTIME POLYMORPHISM & DIAMOND INHERITANCE (VIRTUAL BASE CLASS)");
    std::cout << "Resolving Diamond problem using: class Person (Virtual Base)\n";
    std::cout << "Student : virtual public Person, Faculty : virtual public Person\n";
    std::cout << "TeachingAssistant : public Student, public Faculty\n\n";

    double s1Marks[MAX_SUBJECTS] = {85.5, 92.0, 78.5, 88.0};
    double s2Marks[MAX_SUBJECTS] = {65.0, 70.5, 60.0, 72.0};
    double taMarks[MAX_SUBJECTS] = {90.0, 94.5, 89.0, 96.0};

    Student st1(101, "Aarav Patel", "aarav@indus.edu", "CSE", 3, s1Marks);
    Student st2(102, "Diya Sharma", "diya@indus.edu", "CE", 3, s2Marks);
    Faculty prof(201, "Dr. Rajesh Shah", "rajesh.shah@indus.edu", "Professor", "CSE", CurrencyINR(95000.0));
    TeachingAssistant ta(301, "Rohan Verma", "rohan.ta@indus.edu", "CSE", 5, taMarks, 12, CurrencyINR(18500.0));

    // Array of Base class pointers to demonstrate dynamic binding
    ReportableEntity* campusEntities[4];
    campusEntities[0] = &st1;
    campusEntities[1] = &st2;
    campusEntities[2] = &prof;
    campusEntities[3] = &ta;

    std::cout << std::left 
              << std::setw(8) << "ID" 
              << std::setw(22) << "Name" 
              << std::setw(28) << "Email" 
              << "Role / Academic Details" << std::endl;
    printDivider('-', 78);

    for (int i = 0; i < 4; ++i) {
        // Polymorphic call resolved at runtime
        campusEntities[i]->displayDetails();
    }

    std::cout << "\nStatic Instance Counts Verified:" << std::endl;
    std::cout << " - Total Person instances  : " << Person::getTotalPeopleCount() << std::endl;
    std::cout << " - Total Student instances : " << Student::getTotalStudents() << std::endl;
    std::cout << " - Total Faculty instances : " << Faculty::getTotalFaculty() << std::endl;
}

void demoOperatorOverloadingAndConversions() {
    printDivider("2. OPERATOR OVERLOADING & TYPE CONVERSIONS (BASIC, CLASS, CLASS-TO-CLASS)");
    
    // 1. Basic to Class Conversion
    double primitiveAmount = 45250.75;
    CurrencyINR fee1 = primitiveAmount; // Basic -> Class
    std::cout << "[Basic to Class] Converted double (" << primitiveAmount << ") to CurrencyINR: " << fee1 << std::endl;

    CurrencyINR fee2(12000, 50);
    std::cout << "[Parameterized] CurrencyINR fee2: " << fee2 << std::endl;

    // Binary + Overload
    CurrencyINR totalFee = fee1 + fee2;
    std::cout << "[Binary + Overload] fee1 + fee2 = " << totalFee << std::endl;

    // Relational Operators (<, >, ==)
    std::cout << "[Relational Overload] Is fee1 > fee2? " << (fee1 > fee2 ? "YES (True)" : "NO (False)") << std::endl;

    // Unary ++ Prefix & Postfix Overload
    std::cout << "[Unary ++ Overload] Initial fee2: " << fee2 << std::endl;
    ++fee2;
    std::cout << "After Prefix ++fee2 (adds Rs 100): " << fee2 << std::endl;
    fee2++;
    std::cout << "After Postfix fee2++: " << fee2 << std::endl;

    // 2. Class to Basic Conversion
    double feeAsDouble = static_cast<double>(totalFee); // Class -> Basic
    std::cout << "[Class to Basic] Converted totalFee back to double: " 
              << std::fixed << std::setprecision(2) << feeAsDouble << std::endl;

    // 3. Class to Class Conversion (INR <-> USD)
    CurrencyUSD feeInUSD = totalFee; // INR -> USD
    std::cout << "[Class to Class (INR -> USD)] INR " << totalFee << " = ";
    feeInUSD.display();
    std::cout << std::endl;

    CurrencyINR convertedBackToINR = feeInUSD; // USD -> INR
    std::cout << "[Class to Class (USD -> INR)] Converted back to INR: " << convertedBackToINR << std::endl;
}

void demoFriendFunction() {
    printDivider("3. FRIEND FUNCTIONS ACROSS TWO DISTINCT CLASSES (LAB 3.4 & 5.1)");
    DepartmentBudget compDept("Computer Engineering", 650000.0);
    ScholarshipFund meritSch("Merit-cum-Means", 120000.0);

    std::cout << "Before audit transfer:" << std::endl;
    displayFinancialAudit(compDept, meritSch);

    std::cout << "\nExecuting friend function auditAndBalance()..." << std::endl;
    auditAndBalance(compDept, meritSch);

    std::cout << "\nAfter audit transfer:" << std::endl;
    displayFinancialAudit(compDept, meritSch);
}

void demoTemplates() {
    printDivider("4. FUNCTION TEMPLATE (BUBBLE SORT) & CLASS TEMPLATE (CONTAINER)");

    // Demonstrating Function Template with double array
    double percentages[] = {74.2, 88.5, 62.0, 95.4, 81.3};
    int count = sizeof(percentages) / sizeof(percentages[0]);

    std::cout << "Original Array: ";
    for (int i = 0; i < count; ++i) std::cout << percentages[i] << "% ";
    std::cout << std::endl;

    bubbleSort(percentages, count); // Template function

    std::cout << "Sorted Array (Ascending via template bubbleSort): ";
    for (int i = 0; i < count; ++i) std::cout << percentages[i] << "% ";
    std::cout << std::endl;

    std::cout << "Maximum Score (via template findMaximum): " 
              << findMaximum(percentages, count) << "%" << std::endl;

    // Demonstrating Generic Class Template
    std::cout << "\nClass Template DynamicRepository<std::string>:" << std::endl;
    DynamicRepository<std::string> courses(5);
    courses.add("CE0316: Object Oriented Concepts with UML");
    courses.add("CE0317: Data Structures & Algorithms");
    courses.add("CE0318: Database Management Systems");

    for (int i = 0; i < courses.size(); ++i) {
        std::cout << "  [" << (i + 1) << "] " << courses[i] << std::endl;
    }
}

void demoFileManager() {
    printDivider("5. FILE MANAGEMENT: BINARY FILE I/O & RANDOM ACCESS (LAB 11)");
    StudentFileManager fileMgr("college_students.dat");

    double marks1[MAX_SUBJECTS] = {88.0, 90.0, 92.0, 85.0};
    double marks2[MAX_SUBJECTS] = {76.0, 68.0, 74.0, 71.0};
    double marks3[MAX_SUBJECTS] = {94.0, 96.0, 91.0, 98.0};

    Student s1(101, "Kavya Joshi", "kavya@indus.edu", "CE", 3, marks1);
    Student s2(102, "Neil Mehta", "neil@indus.edu", "CSE", 3, marks2);
    Student s3(103, "Pooja Trivedi", "pooja@indus.edu", "IT", 3, marks3);

    std::cout << "Writing student objects to binary file using write()...\n";
    // Overwrite old file for clean demo
    std::ofstream reset("college_students.dat", std::ios::out | std::ios::binary | std::ios::trunc);
    reset.close();

    fileMgr.saveStudentRecord(s1);
    fileMgr.saveStudentRecord(s2);
    fileMgr.saveStudentRecord(s3);
    std::cout << "[SUCCESS] 3 Binary records stored successfully.\n\n";

    // Reading records
    fileMgr.displayAllRecords();

    // Random Access File pointer search
    std::cout << "\nSearching for Student with ID 102 via random file access (tellg/seekg)...";
    fileMgr.searchRecordById(102);

    // Random access record update
    std::cout << "\nUpdating percentage of Student ID 102 to 85.0% using seekp()...\n";
    fileMgr.updateStudentPercentage(102, 85.0);

    // Read back to confirm change
    std::cout << "\nVerifying file contents after random write update:\n";
    fileMgr.displayAllRecords();
}

void demoHierarchicalAccounts() {
    printDivider("6. HIERARCHICAL INHERITANCE: STUDENT & FACULTY ACCOUNTS");
    StudentFeeAccount stuAcc(5001, "Kavya Joshi", CurrencyINR(75000.0), CurrencyINR(35000.0));
    FacultySalaryAccount facAcc(6001, "Dr. Rajesh Shah", CurrencyINR(95000.0), 12.5);

    std::cout << "Initial Statements:\n";
    printDivider('-', 75);
    std::cout << std::left << std::setw(12) << "Acc No" << std::setw(22) << "Name" 
              << std::setw(16) << "Total Fee" << std::setw(16) << "Fee Paid" << "Pending Due\n";
    printDivider('-', 75);
    stuAcc.printStatement();

    std::cout << "\nProcessing Semester Fee Installment of Rs. 20,000 for Student...\n";
    stuAcc.payTuitionFee(CurrencyINR(20000.0));
    std::cout << "Updated Student Account Statement:\n";
    stuAcc.printStatement();

    std::cout << "\nProcessing Faculty Salary with Tax Deduction:\n";
    facAcc.printStatement();
    std::cout << "Crediting Monthly Gross Salary Rs. 1,00,000 (after 12.5% tax deduction):\n";
    facAcc.creditMonthlySalary(CurrencyINR(100000.0));
    facAcc.printStatement();
}

void demoPointersAndMemberFunctions() {
    printDivider("7. POINTER TO OBJECT & POINTER TO MEMBER FUNCTION (LAB 4.1 & 4.3)");

    double marks[MAX_SUBJECTS] = {89, 91, 87, 93};
    Student stu(105, "Manan Shah", "manan@indus.edu", "CSE", 3, marks);

    // Pointer to Object
    Student* stuPtr = &stu;
    std::cout << "Accessing object through pointer to object (stuPtr->getName()): " 
              << stuPtr->getName() << std::endl;

    // Pointer to Member Function
    double (Student::*getScoreFunc)() const = &Student::getPercentage;
    std::cout << "Invoking member function via pointer-to-member ((stuPtr->*getScoreFunc)()): " 
              << (stuPtr->*getScoreFunc)() << "%" << std::endl;

    // 'this' pointer return by reference demonstration
    std::cout << "Modifying subject mark 0 using return-by-reference: " << stu.getSubjectMarkRef(0);
    stu.getSubjectMarkRef(0) = 99.0; // lvalue assignment!
    stu.recalculateMarks();
    std::cout << " -> Updated to 99.0. New Total: " << stu.getTotalMarks() 
              << ", New Percentage: " << stu.getPercentage() << "%" << std::endl;
}

int main() {
    // Unformatted I/O demo: cout.put()
    std::cout.put('\n');

    int choice = 0;
    do {
        displayMainMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::string discard;
            std::getline(std::cin, discard); // Unformatted I/O: getline
            choice = 0;
            continue;
        }

        std::cout << "\n";
        switch (choice) {
            case 1:
                demoPolymorphismAndDiamond();
                break;
            case 2:
                demoOperatorOverloadingAndConversions();
                break;
            case 3:
                demoFriendFunction();
                break;
            case 4:
                demoTemplates();
                break;
            case 5:
                demoFileManager();
                break;
            case 6:
                demoHierarchicalAccounts();
                break;
            case 7:
                demoPointersAndMemberFunctions();
                break;
            case 8:
                demoPolymorphismAndDiamond();
                demoOperatorOverloadingAndConversions();
                demoFriendFunction();
                demoTemplates();
                demoFileManager();
                demoHierarchicalAccounts();
                demoPointersAndMemberFunctions();
                break;
            case 9:
                std::cout << "Exiting University Academic & Record Management System. Thank you!\n";
                break;
            default:
                std::cout << "[INVALID OPTION] Please enter a number between 1 and 9.\n";
                break;
        }

        if (choice != 9) {
            std::cout << "\nPress Enter to return to main menu...";
            std::cin.ignore(10000, '\n');
            std::cin.get(); // Unformatted I/O: cin.get()
            std::cout << "\n";
        }
    } while (choice != 9);

    return 0;
}
