#include <iostream>
#include <iomanip> // for setprecision
#include <string>

using namespace std;

// Function to convert grade to grade point
float getGradePoint(string grade) {
    if (grade == "A" || grade == "a") return 4.0;
    else if (grade == "A-" || grade == "a-") return 3.7;
    else if (grade == "B+" || grade == "b+") return 3.3;
    else if (grade == "B" || grade == "b") return 3.0;
    else if (grade == "B-" || grade == "b-") return 2.7;
    else if (grade == "C+" || grade == "c+") return 2.3;
    else if (grade == "C" || grade == "c") return 2.0;
    else if (grade == "C-" || grade == "c-") return 1.7;
    else if (grade == "D+" || grade == "d+") return 1.3;
    else if (grade == "D" || grade == "d") return 1.0;
    else if (grade == "F" || grade == "f") return 0.0;
    else return -1.0; // Invalid input
}

// Function to calculate CGPA
float calculateCGPA(int numSubjects, int credits[], string grades[]) {
    float totalGradePoints = 0;
    int totalCredits = 0;

    for (int i = 0; i < numSubjects; i++) {
        float gradePoint = getGradePoint(grades[i]);
        if (gradePoint == -1.0) {
            cout << "Invalid grade entered for subject " << (i + 1) << ". Exiting...\n";
            return -1.0;
        }
        totalGradePoints += gradePoint * credits[i];
        totalCredits += credits[i];
    }

    return (totalCredits == 0) ? 0 : totalGradePoints / totalCredits;
}

// Program-specific CGPA calculator
void programSpecificCGPA() {
    const int NUM_SUBJECTS = 7;
    string subjects[NUM_SUBJECTS] = {
        "Programming Technique I", "Digital Logic", "Data Analysis",
        "Islamic Studies", "Critical Thinking",
        "Technical Writing", "Co-Curriculum I"
    };
    int credits[NUM_SUBJECTS] = { 3, 3, 3, 2, 2, 2, 1 };
    string grades[NUM_SUBJECTS];

    cout << "\nEnter your grades for the following subjects:\n";
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        cout << subjects[i] << " (Credit hours: " << credits[i] << "): ";
        cin >> grades[i];
    }

    float cgpa = calculateCGPA(NUM_SUBJECTS, credits, grades);
    if (cgpa != -1.0) {
        cout << fixed << setprecision(2);
        cout << "\nYour CGPA is: " << cgpa << endl;
    }
}

// Main Program
int main() {
    int choice;
    cout << "====== CGPA Calculator ======\n";
    cout << "1. Normal CGPA Calculation\n";
    cout << "2. Program-Specific CGPA Calculation\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        int numSubjects;
        cout << "\nEnter the number of subjects: ";
        cin >> numSubjects;

        int* credits = new int[numSubjects];
        string* grades = new string[numSubjects];

        for (int i = 0; i < numSubjects; i++) {
            cout << "Enter credit hours for subject " << (i + 1) << ": ";
            cin >> credits[i];
            cout << "Enter grade for subject " << (i + 1) << ": ";
            cin >> grades[i];
        }

        float cgpa = calculateCGPA(numSubjects, credits, grades);
        if (cgpa != -1.0) {
            cout << fixed << setprecision(2);
            cout << "\nYour CGPA is: " << cgpa << endl;
        }

        delete[] credits;
        delete[] grades;
    }
    else if (choice == 2) {
        programSpecificCGPA();
    }
    else {
        cout << "Invalid choice. Please select 1 or 2.\n";
    }

    return 0;
}