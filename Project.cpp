//College-management-System
//Libraries used
#include <iostream>
 #include <string>
 #include <vector>
 #include <cmath>
 #include <cstdlib>  // For system function
 #include <chrono>    // For delay
 #include <thread>    // For delay
 using namespace std;

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
        this_thread::sleep_for(chrono::milliseconds(100)); }                                         ///MASRKAI
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
    printColor(BLUE ,"8. Exit\n",false); }                   ///MASRKAI
////////////////////////////////////////////////////////////////////////////////////////
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
    string getFaculty() const { return faculty; }
};

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
        cin >> facultyChoice;
        while (facultyChoice < 1 || facultyChoice > Pre_Def_Fac.size()) {
            cout << "Invalid faculty choice. Please enter a number between 1 and " << Pre_Def_Fac.size() << ": ";
            cin >> facultyChoice;
        }
        return Pre_Def_Fac[facultyChoice - 1]; }

    // Function to add a new student
    void addStudent() {
        if (students.size() >= MAX_STUDENTS) {
            cout << "Maximum number of students reached." << endl;
            return; }

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
            cout << "ID: " << student.getID() << ", Name: " << student.getName() << ", Faculty: " << student.getFaculty() << endl; } } }; ///MASRKAI
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// Define the Course class
class Course {
  private:
    string courseCode, name, description, instructor;
  public:
  //--Constructor
      Course(string code, string n, string desc, string instr) : courseCode(code), name(n), description(desc), instructor(instr) {}
  //--Method to display course details
      void displayCourseDetails() {
          cout << "Course Code: " << courseCode  << endl;
          cout << "Name: "        << name        << endl;
          cout << "Description: " << description << endl;
          cout << "Instructor: "  << instructor  << endl; } };
  
  //--Fn to register subjects for a student
  void registerSubjects() { cout << "Registering subjects for a student...\n";
  //--Getting input from user for course details
   string code, name, description, instructor;
      cout << "Enter course code: "; cin >> code;
      cout << "Enter course name: "; cin.ignore(); getline(cin, name);
      cout << "Enter course description: "; getline(cin, description);
      cout << "Enter course instructor: ";  getline(cin, instructor);
  
  //--Create a new Course using constructor
      Course newCourse(code, name, description, instructor);
  
  //--Displaying confirmation message
      cout << "Course registered successfully!\n";}       //MASRKAI
////////////////////////////////////////////////////////////////

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
      cout << "Viewing enrolled courses for a student...\n";
  }
  
  // Function to calculate GPA for a student
  void calculateGPA() {
      // Implementation to calculate GPA for a student
      cout << "Calculating GPA for a student...\n";
  }                                                      //Masrkai
//////////////////////////////////////////////////////////////////



int main() {
    University university;
    int choice;
    int numStudents = 0;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Invalid input. Please enter a number (1-7): ";
            Limiter();
            ClearTerminal();
            continue;
        }

        switch (choice) {
            case 1:
                university.displayStudents();
                break;
            case 2:
                university.addStudent();
                break;
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
                // Add logic for calculating GPA
                break;
            case 8:
                cout << "Exiting the program. Goodbye!\n"; Limiter(); ClearTerminal();
                break;
            default:
                cout << "Invalid choice. Please try again ~ "; Limiter(); ClearTerminal();
                break; }
    } while (choice != 8);

    // Display student information before exiting
    university.displayStudents();

    return 0; }                                                                      //MASRKAI
//////////////////////////////////////////////////////////////////////////////////////////////