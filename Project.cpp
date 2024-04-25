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
    printColor(BLUE ,"1. Add new student\n",false);
    printColor(BLUE ,"2. Register subjects for a student\n",false);
    printColor(BLUE ,"3. Change subjects for a student\n",false);
    printColor(BLUE ,"4. Add new subject code\n",false);
    printColor(BLUE ,"5. View enrolled courses for a student\n",false);
    printColor(BLUE ,"6. Calculate GPA for a student\n",false);
    printColor(BLUE ,"7. Exit\n",false); }                   ///MASRKAI
////////////////////////////////////////////////////////////////////////////////////////


struct Student{
    string ID;
    string name;
    string faculty; };

    int ACTUAL_REGISTERS = 0;
    const int NUM_FACULTIES = 4, MAX_STUDENTS = 100 ;
    string Pre_Def_Fac[NUM_FACULTIES] = {"Computer Science", "Engineering", "Human Rights", "Arts and Design"};

// Function to handle faculty selection
string chooseFaculty(const string faculties[], int F_nums) {
    int facultyChoice;
    cout << "Faculty:\n";
    for (int j = 0; j < F_nums; ++j) {
        cout << j + 1 << ". " << faculties[j] << endl;
    }
    cout << "Enter a number (1-" << F_nums << ") to choose a faculty: ";
    cin >> facultyChoice;
    while (facultyChoice < 1 || facultyChoice > F_nums) {
        cout << "Invalid faculty choice. Please enter a number between 1 and " << F_nums << ": ";
        cin >> facultyChoice;
    }
    return faculties[facultyChoice - 1];
}

// Function to add a new student
void addStudent(Student students[], int& numStudents) {
    if (numStudents >= MAX_STUDENTS) {
        cout << "Maximum number of students reached." << endl;
        return;
    }
    Student newStudent;
    cout << "\nEnter information for student " << numStudents + 1 << ":" << endl;
    cout << "ID: ";
    cin >> newStudent.ID;
    // Validate ID uniqueness (you can implement this)
    cout << "Name: ";
    cin.ignore();
    getline(cin, newStudent.name);
    newStudent.faculty = chooseFaculty(Pre_Def_Fac, NUM_FACULTIES);
    students[numStudents] = newStudent;
    numStudents++;
    cout << "Successfully Registered." << endl;
}

// Function to display student information
void displayStudents(const Student students[], int numStudents) {
    cout << "\nStudents Information:\n";
    for (int i = 0; i < numStudents; ++i) {
        cout << "ID: " << students[i].ID << ", Name: " << students[i].name << ", Faculty: " << students[i].faculty << endl; }}///MASRKAI
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


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
    int choice;
    Student students[MAX_STUDENTS];
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
                addStudent(students, numStudents);
                break;
            case 2:
                // Add logic for registering subjects
                break;
            case 3:
                // Add logic for changing subjects
                break;
            case 4:
                // Add logic for adding new subject code
                break;
            case 5:
                // Add logic for viewing enrolled courses
                break;
            case 6:
                // Add logic for calculating GPA
                break;
            case 7:
                cout << "Exiting the program. Goodbye!\n"; Limiter(); ClearTerminal();
                break;
            default:
                cout << "Invalid choice. Please try again ~ "; Limiter(); ClearTerminal();
                break; }
    } while (choice != 7);

    // Display student information before exiting
    displayStudents(students, numStudents);

    return 0;
}