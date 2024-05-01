//College-management-System
  //Contributors:- 
  /* {
  Ahmed Allam ~ Masrkai //AIS
  Mariam Othman         //AIS
  
  } */
////////
//Libraries used
#include <iostream>
 #include <string>
 #include <vector>
 #include <cmath>
 #include <cstdlib>  // For system function
 #include <chrono>    // For delay
 #include <thread>    // For delay
 using namespace std; ///MASRKAI
/////////////////////////////////

void ClearTerminal() {  // Ergonomics
 #ifdef _WIN32
     system("cls");
 #else
     system("clear");
 #endif
 }                      ///MASRKAI
/////////////////////////////////

#ifdef _WIN32       //--System Integrity & Cross platform support
 #include <windows.h>
 #define RESET_COLOR SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)
 #else
 #define RESET_COLOR "\033[0m"
 #endif                                                                                                                   ///MASRKAI
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Function to print colored and bold text
void printColor(const string& color, const string& text, bool bold = false) {
 #define RED     "\033[31m"                                   //Defining color
 #define GREEN   "\033[32m"
 #define YELLOW  "\033[33m"
 #define BLUE    "\033[34m"
 #define MAGENTA "\033[35m"
 #define CYAN    "\033[36m"
 #define BOLD    "\033[1m"
                cout << (bold ? BOLD : "") << color << text << RESET_COLOR; } ///MASRKAI
////////////////////////////////////////////////////////////////////////////////////////

void Limiter() {
    printColor(RED, "Limiter is Active", true);
    for (int i = 0; i <= 9; ++i){
        cout << " -"; // --- -
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "\b\b";
        cout.flush();
        cout << " /"; // --- /
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "\b\b";
        cout.flush();
        cout << " |"; // --- |
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "\b\b";
        cout.flush();
 //cout << " \\"; // --- "\\"  BLOCKING OUT FOR ANIMATION LIKE BEHAVIOR literally a bug into a feature XD
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "\b\b";
        cout.flush(); }
        this_thread::sleep_for(chrono::milliseconds(100)); }                                  ///MASRKAI
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CLimiter() {
    for (int i = 0; i <= 11; ++i){
        cout << " -"; // --- -
        this_thread::sleep_for(chrono::milliseconds(50));
        cout << "\b\b";
        cout.flush();
        cout << " /"; // --- /
        this_thread::sleep_for(chrono::milliseconds(50));
        cout << "\b\b";
        cout.flush();
        cout << " |"; // --- |
        this_thread::sleep_for(chrono::milliseconds(50));
        cout << "\b\b";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(50));
        cout << "\b\b";
        cout.flush(); }
        this_thread::sleep_for(chrono::milliseconds(50)); } ///MASRKAI
/////////////////////////////////////////////////////////////////////////////////

// Function to display the menu
void displayMenu() {
    printColor(GREEN,"\n***** Welcome to GU SIS *****\n",true);
    printColor(BLUE ,"1. List all students\n",false);
    printColor(BLUE ,"2. Add new student\n",false);
    printColor(BLUE ,"3. Register subjects for a student\n",false);
    printColor(BLUE ,"4. Change subjects for a student\n",false);
    printColor(BLUE ,"5. Add new subject code\n",false);
    printColor(BLUE ,"6. View enrolled courses for a student\n",false);
    printColor(BLUE ,"7. Calculate GPA for a student\n",false);
    printColor(YELLOW ,"8. Clean Terminal\n",false);
    printColor(RED ,"9. Exit\n",false);       }                ///MASRKAI
//////////////////////////////////////////////////////////////////////////////////////////

class Student {
 private:
    string ID;
    string name;
    string faculty;

 public:
    // Constructor
    Student(string id, string n, string fac) : ID(id), name(n), faculty(fac) {}

    // Getters
    string getID() const { return ID; }
    string getName() const { return name; }
    string getFaculty() const { return faculty; } };    //MASRKAI
/////////////////////////////////////////////////////////////////

class GPA {
 private:
    vector<float> grades;
    vector<int> creditHours;
    int totalCredit;
    float gpaSum;

 public:
    void enterGrade(int number_of_subjects) {
        totalCredit = 0;
        for (int i = 0; i < number_of_subjects; i++) {
            float grade;
            int creditHour;

            cout << "Please enter the grade of " << i + 1 << " subject:";
            cin >> grade;
            if (cin.fail()) {
                cout << "ERROR\n";
                cin.clear();
                cin.ignore(256, '\n'); }

            cout << "Please enter the credit hour of " << i + 1 << " subject:";
            cin >> creditHour;
            if (cin.fail()) {
                cout << "ERROR\n";
                cin.clear();
                cin.ignore(256, '\n'); }

            grades.push_back(grade);
            creditHours.push_back(creditHour);
            totalCredit += creditHour; } }

    void evaluate() {
        gpaSum = 0.0f;
        for (int i = 0; i < grades.size(); i++) {
            float gpa = calculateGpa(grades[i]);
            gpaSum += gpa * creditHours[i]; } }

    float calculateGpa(float grade) {
        if (grade >= 0 && grade <= 4.0) {
            if (grade >= 3.85) return 4.0f;
            else if (grade >= 3.5) return 3.7f;
            else if (grade >= 3.15) return 3.3f;
            else if (grade >= 2.85) return 3.0f;
            else if (grade >= 2.5) return 2.7f;
            else if (grade >= 2.15) return 2.3f;
            else if (grade >= 1.85) return 2.0f;
            else if (grade >= 1.5) return 1.7f;
            else if (grade >= 1.15) return 1.3f;
            else if (grade >= 0.85) return 1.0f;
            else return 0.0f; }

        // Handle invalid grades (optional)
        return 0.0f; }

    float TotalGpa() {
        if (totalCredit == 0)
            return 0.0f; // Avoid division by zero
        return (gpaSum / totalCredit); } };             //MASRKAI
/////////////////////////////////////////////////////////////////

class University {
 private:
    const int MAX_STUDENTS = 100;
    const vector<string> Pre_Def_Fac = {"Computer Science", "Engineering", "Human Rights", "Arts and Design"};
    vector<Student> students;

 public:
    // Function to handle faculty selection
    string chooseFaculty() const {
        int facultyChoice;
        cout << "Faculty:\n";
        for (size_t j = 0; j < Pre_Def_Fac.size(); ++j) {
            cout << j + 1 << ". " << Pre_Def_Fac[j] << endl;
        }
        cout << "Enter a number (1-" << Pre_Def_Fac.size() << ") to choose a faculty: ";
    FAC:
        cin >> facultyChoice;
        if (facultyChoice < 1 || facultyChoice > Pre_Def_Fac.size()) {
            cout << "Invalid faculty choice. Please enter a number between 1 and " << Pre_Def_Fac.size() << ": ";
            goto FAC;
        }

        return Pre_Def_Fac[facultyChoice - 1];
    }

    // Function to add a new student
    void addStudent() {
        if (students.size() >= MAX_STUDENTS) {
            cout << "Maximum number of students reached." << endl;
            return;
        }

        string id, name;
        cout << "\nEnter information for student " << students.size() + 1 << ":" << endl;
        cout << "ID: ";
        cin >> id;
        // Validate ID uniqueness (you can implement this)
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        string faculty = chooseFaculty();
        students.push_back(Student(id, name, faculty));
        cout << "Successfully Registered." << endl;
    }

    // Function to display student information
    void displayStudents() const {
        cout << "\nStudents Information:\n";
        for (const auto& student : students) {
            cout << "ID: " << student.getID() << ", Name: " << student.getName() << ", Faculty: " << student.getFaculty() << endl;
        }
    }

    // Function to calculate and display GPA for a student
    void calculateAndDisplayGPA() {
        if (students.empty()) {
            cout << "No students registered yet." << endl;
            return;
        }

        int studentIndex;
        cout << "Enter the index of the student to calculate GPA (1-" << students.size() << "): ";
    STUDENT_INDEX:
        cin >> studentIndex;
        if (studentIndex < 1 || studentIndex > students.size()) {
            cout << "Invalid index. Please enter a number between 1 and " << students.size() << ": ";
            goto STUDENT_INDEX;
        }

        GPA gpa;
        int numSubjects;
        cout << "Enter the number of subjects for " << students[studentIndex - 1].getName() << ": ";
        cin >> numSubjects;

        gpa.enterGrade(numSubjects);
        gpa.evaluate();
        cout << "GPA for student " << students[studentIndex - 1].getName() << " ("
        << students[studentIndex - 1].getID() << "): " << gpa.TotalGpa() << endl; } };          //MASRKAI
/////////////////////////////////////////////////////////////////////////////////////////////////////////

//Pending
//--Fn to change subjects for a student
  void changeSubjects() {
      // Implementation to change subjects for a student
      cout << "Changing subjects for a student...\n";
  }

  // Function to add a new subject code
  void addNewSubjectCode() {
      // Implementation to add a new subject code
      cout << "Adding a new subject code...\n";
  }

  // Function to view enrolled courses for a student
  void viewEnrolledCourses() {
      // Implementation to view enrolled courses for a student
      cout << "Viewing enrolled courses for a student...\n"; } //Masrkai
////////////////////////////////////////////////////////////////////////

int main() {
    ClearTerminal();
    University university; GPA GNU;
    int choice, numStudents = 0;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Invalid input. Please enter a number (1-9): ";
            Limiter();
            ClearTerminal();
            continue; }

        switch (choice) {
            case 1:
                university.displayStudents();                       break;
            case 2:
                university.addStudent();                            break;
            case 3:
                // Add logic for Registering subjects for student
                break;
            case 4:
                // Add logic for changing subjects
                break;
            case 5:
                // Add logic for adding new subject code
                break;
            case 6:
                // Add logic for viewing enrolled courses
                break;
            case 7:
                university.calculateAndDisplayGPA();                break;
            case 8:
                printColor(MAGENTA,"Clearing your Terminal", true   ); CLimiter(); ClearTerminal();
                break;
             case 9:
                cout << "Exiting the program. Goodbye!\n"; Limiter(); ClearTerminal();
                break;
            default:
                cout << "Invalid choice. Please try again ~ "; Limiter(); ClearTerminal();
                break; }
    } while (choice != 9);

    //-->Display student information before exiting
    university.displayStudents(); return 0; }                                        //MASRKAI
//////////////////////////////////////////////////////////////////////////////////////////////