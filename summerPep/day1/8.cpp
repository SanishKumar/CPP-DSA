#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    string name;
    vector<int> marks;
    float percentage;
    char grade;
};

bool isValidName(const string &name) {
    for(int i = 0; name[i] != '\0'; i++) {
        char ch = name[i];
        if(!((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))) 
            return false;
    }
    return true;
}

bool isValidMark(int mark) {
    return (mark >= 0 && mark <= 100);
}

void calculatePercentageAndGrade(Student &s) {
    int total = 0;
    for(int i = 0; i < s.marks.size(); i++) {
        total += s.marks[i];
    }
    if(s.marks.size() == 0) {
        s.percentage = 0;
        s.grade = 'F';
        return;
    }
    s.percentage = (float)total / s.marks.size();
    if(s.percentage >= 90) s.grade = 'A';
    else if(s.percentage >= 80) s.grade = 'B';
    else if(s.percentage >= 70) s.grade = 'C';
    else if(s.percentage >= 60) s.grade = 'D';
    else s.grade = 'F';
}

void addMarks(vector<Student> &students) {
    string name;
    int n, mark;
    cout << "Enter student name: ";
    cin >> name;
    if(!isValidName(name)) {
        cout << "Invalid name! Name should only contain alphabets.\n";
        return;
    }
    cout << "Enter number of subjects: ";
    cin >> n;
    Student s;
    s.name = name;
    cout << "Enter marks for " << n << " subjects: ";
    for(int i = 0; i < n; i++) {
        cin >> mark;
        if(!isValidMark(mark)) {
            cout << "Invalid mark! Marks should be between 0 and 100.\n";
            return;
        }
        s.marks.push_back(mark);
    }
    calculatePercentageAndGrade(s);
    students.push_back(s);
    cout << "Student added successfully.\n";
}

void deleteMarks(vector<Student> &students) {
    string name;
    cout << "Enter student name to delete: ";
    cin >> name;
    for(int i = 0; i < students.size(); i++) {
        if(students[i].name == name) {
            students.erase(students.begin() + i);
            cout << "Student deleted successfully.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

void updateMarks(vector<Student> &students) {
    string name;
    cout << "Enter student name to update: ";
    cin >> name;
    for(int i = 0; i < students.size(); i++) {
        if(students[i].name == name) {
            int n, mark;
            cout << "Enter number of subjects: ";
            cin >> n;
            students[i].marks.clear();
            cout << "Enter marks for " << n << " subjects: ";
            for(int j = 0; j < n; j++) {
                cin >> mark;
                if(!isValidMark(mark)) {
                    cout << "Invalid mark! Marks should be between 0 and 100.\n";
                    return;
                }
                students[i].marks.push_back(mark);
            }
            calculatePercentageAndGrade(students[i]);
            cout << "Student marks updated successfully.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

void displayAll(const vector<Student> &students) {
    cout << "Student Records:\n";
    for(int i = 0; i < students.size(); i++) {
        cout << "Name: " << students[i].name << endl;
        cout << "Marks: ";
        for(int j = 0; j < students[i].marks.size(); j++) {
            cout << students[i].marks[j] << " ";
        }
        cout << "\nPercentage: " << students[i].percentage << endl;
        cout << "Grade: " << students[i].grade << endl;
        cout << "---------------------\n";
    }
}

int main() {
    vector<Student> students;
    int choice;
    while(true) {
        cout << "\n1. Add\n2. Delete\n3. Update\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if(choice == 1) addMarks(students);
        else if(choice == 2) deleteMarks(students);
        else if(choice == 3) updateMarks(students);
        else if(choice == 4) displayAll(students);
        else if(choice == 5) break;
        else cout << "Invalid choice.\n";
    }
}