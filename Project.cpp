//College-management-System
//Libraries used
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>  // For system function
#include <chrono>    // For delay
#include <thread>    // For delay
using namespace std;

void ClearTerminal() {  // Ergonomics By MASRKAI
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
#define RED     "\033[31m" // Defining color macros
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
//      cout << " \\"; // --- "\\"  BLOCKING OUT FOR ANIMATION LIKE BEHAVIOR literally a bug into a feature XD
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "\b\b";
        cout.flush(); }
        this_thread::sleep_for(chrono::milliseconds(100)); }                                         ///MASRKAI
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


// Function to display the menu
void displayMenu() {
    printColor(GREEN,"\n***** Menu *****\n",true);
    printColor(BLUE ,"1. Add new student\n",false);
    printColor(BLUE ,"2. Register subjects for a student\n",false);
    printColor(BLUE ,"3. Change subjects for a student\n",false);
    printColor(BLUE ,"4. Add new subject code\n",false);
    printColor(BLUE ,"5. View enrolled courses for a student\n",false);
    printColor(BLUE ,"6. Calculate GPA for a student\n",false);
    printColor(BLUE ,"7. Exit\n",false); }                   ///MASRKAI
///////////////////////////////////////////////////////////////////////


const int MAX_STUDENTS = 100;   // Maximum number of students
const int NUM_FACULTIES = 4;    // Number of predefined faculties
string studentIDs[MAX_STUDENTS], studentNames[MAX_STUDENTS];
string predefinedFaculties[NUM_FACULTIES] = { "Computer Science", "Arts and Design", "Engineering", "Human Rights" }; ///MASRKAI
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Fn to handle faculty selection
string chooseFaculty(const string faculties[], int numFaculties) {

  int facultyChoice; string newFaculty; bool validChoice = true;
  cout << "  Faculty:\n";

  for (int j = 0; j < numFaculties; ++j) { cout << "    " << j + 1 << ". " << faculties[j] << endl; }
  cout << "    Enter a number (1-" << numFaculties << ") to choose a faculty or enter a new faculty name: ";

  // Input validation loop
  while (!(cin >> facultyChoice) || (facultyChoice < 1 || facultyChoice > numFaculties)) { cin.clear();
    cout << "Invalid faculty choice. Please enter a number between 1 and " << numFaculties; Limiter(); }

  if (facultyChoice > 0) {
    return faculties[facultyChoice - 1];
    } else {
    cin.ignore(); // Ignore newline character after number input
    getline(cin, newFaculty);
    return newFaculty; } }


//fn to add a new student
void addStudent() {

  int numStudents , ACTUAL_REGISTERS;
  cout << "Enter the number of students you want to register (up to " << MAX_STUDENTS << "): ";   // Input validation for number of students
  cin >> numStudents;

while (numStudents < 1 || numStudents > MAX_STUDENTS) {                                         // Check Function
    cout << "Invalid number of students. Please enter a value between 1 and " << MAX_STUDENTS << ": ";
    cin >> numStudents;
}

// Loop to get student information
for (int i = 0; i < numStudents; ++i) {
    cout << "\nEnter information for student " << i + 1 << ":" << endl;
    cout << "  ID: ";
    cin >> studentIDs[i];
    cout << "  Name: ";
    cin.ignore(); // Ignore newline character
    getline(cin, studentNames[i]);
    studentNames[i] = chooseFaculty(predefinedFaculties, NUM_FACULTIES); // Faculty selection with helper function
    ACTUAL_REGISTERS++; }


  cout << "\nStudent Information:\n";   // Display student information
  for (int i = 0; i < ACTUAL_REGISTERS; ++i) {
    cout << "ID: " << studentIDs[ACTUAL_REGISTERS] << ", Name: " << studentNames[ACTUAL_REGISTERS] << endl; }  ///MASRKAI
}//////////////////////////////////////////////////////////////////////////////////////////


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
}



int main(){ int choice;
do{ displayMenu();

    cout << "Enter your choice: "; cin >> choice;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Invalid input. Please enter a number (1-7): "; Limiter(); ClearTerminal();
        continue; }

    switch (choice){
    case 1: addStudent();                                                                break;
    case 2: registerSubjects();                                                          break;
    case 3: changeSubjects();                                                            break;
    case 4: addNewSubjectCode();                                                         break;
    case 5: viewEnrolledCourses();                                                       break;
    case 6: calculateGPA();                                                              break;
    case 7:  cout << "Exiting the program. Goodbye!\n";     Limiter(); ClearTerminal();  break;
    default: cout << "Invalid choice. Please try again ~ "; Limiter(); ClearTerminal();  break;
    } } while (choice != 7); return 0;}