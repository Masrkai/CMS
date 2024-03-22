//Libraries used
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>  // For system function
#include <chrono>    // For delay
#include <thread>    // For delay
using namespace std;

//--Ergonomics
void ClearTerminal() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}     

//--System Integrity & Cross platform support
#ifdef _WIN32
#include <windows.h>
#define RESET_COLOR SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)
#else
#define RESET_COLOR "\033[0m"
#endif

// Define color macros
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

// Function to print colored and bold text
void printColor(const string& color, const string& text, bool bold = false) {
    // Print color and bold attributes
    cout << (bold ? BOLD : "") << color << text << RESET_COLOR; }

void Limiter() {
    printColor(RED, "Limiter is Active", true);
    for (int i = 0; i <= 9; ++i) {
// ---  -        
        cout << " -";
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "\b\b";
        cout.flush();
// --- /
        cout << " /";
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "\b\b";
        cout.flush();
// --- |
        cout << " |";
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "\b\b";
        cout.flush();
// --- \\
        cout << " \\";
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "\b\b";
        cout.flush(); }
        this_thread::sleep_for(chrono::milliseconds(100)); }

// Function prototypes //Why ? because in our approach we are putting functions after main for cleaner code
void displayMenu(); void addStudent(); void registerSubjects(); void calculateGPA();
void changeSubjects(); void addNewSubjectCode(); void viewEnrolledCourses();

int main(){ int choice;
do{ displayMenu();
    cout << "Enter your choice: "; cin >> choice;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Invalid input. Please enter a number (1-7): "; Limiter(); ClearTerminal();
        continue; }

    switch (choice){
    case 1: addStudent();                                    break;
    case 2: registerSubjects();                              break;
    case 3: changeSubjects();                                break;
    case 4: addNewSubjectCode();                             break;
    case 5: viewEnrolledCourses();                           break;
    case 6: calculateGPA();                                  break;
//------    
    case 7:  cout << "Exiting the program. Goodbye!\n";     Limiter(); ClearTerminal();  break;
    default: cout << "Invalid choice. Please try again ~ "; Limiter(); ClearTerminal();  break; }} 
while (choice != 7);
return 0;}

// Function to display the menu
void displayMenu() {
    printColor(GREEN,"\n***** Menu *****\n",true);
    printColor(BLUE ,"1. Add new student\n",false);
    printColor(BLUE ,"2. Register subjects for a student\n",false);
    printColor(BLUE ,"3. Change subjects for a student\n",false);
    printColor(BLUE ,"4. Add new subject code\n",false);
    printColor(BLUE ,"5. View enrolled courses for a student\n",false);
    printColor(BLUE ,"6. Calculate GPA for a student\n",false);
    printColor(BLUE ,"7. Exit\n",false); }

// Define the Student class
class Student {
private:
   string studentID, name, email;
   string* enrolledCourses; //--Pointer to the dynamically allocated "array" of course codes
   int courseCount; //--Number of enrolled courses
public:
//--Constructor x Initializer 
   Student(string id, string n, string e) : studentID(id), name(n), email(e), enrolledCourses(nullptr), courseCount(0){}

//--Destructor to deallocate memory  //why: "Advanced approach" For memory safety & efficiency // why: BECAUSE I CAN'T USE #include <vector> yet 
//why: because we did't use it ever in lectures so i don't expect us to be allowed to use it
   ~Student(){ delete[] enrolledCourses; }
   
//--Fn to add a course
void addCourse(string course) {
//--Increment the course count
        courseCount++;
//--Create a new dynamic array to store enrolled courses
    string* newCourses = new string[courseCount];

//--Copy existing enrolled courses to the new array
    for (int i = 0; i < courseCount - 1; ++i) {newCourses[i] = enrolledCourses[i];}

//--Add the new course to the end of the array
    newCourses[courseCount - 1] = course;

//--Deallocate memory for the old array
    delete[] enrolledCourses;

//--Update the enrolled courses pointer to point to the new array
        enrolledCourses = newCourses; }

//fn to display enrolled courses
void viewCourses() {cout << "Enrolled Courses:\n";
   for (int i = 0; i < courseCount; ++i) { cout << enrolledCourses[i] << endl; } } };

//fn to add a new student
void addStudent() {
  string id, name, email;
    cout << "Enter student ID: "; cin >> id;
    cout << "Enter student name: "; cin.ignore(); // Ignore newline character from previous input //SELF LEARNING

//--FIX-ED conflict with when using specific names voided by using getline 
    getline(cin, name);
    cout << "Enter student email: "; cin >> email;

//--Add a new Student using the constructor
    Student newStudent(id, name, email);

//--Display confirmation message
    cout << "Student added successfully!\n"; }         ///MASRKAI
////////////////////////////////////////////////////////////////

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
