#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<string> courseNames(numCourses);
    vector<double> grades(numCourses);
    vector<int> credits(numCourses);

    double totalCredits = 0, totalGradePoints = 0;

    cout << "\nEnter details for each course:\n";
    for (int i = 0; i < numCourses; i++) {
        cout << "\nCourse " << i + 1 << " name: ";
        cin >> courseNames[i];
        cout << "Grade (on 10-point scale): ";
        cin >> grades[i];
        cout << "Credit Hours: ";
        cin >> credits[i];

        totalCredits += credits[i];
        totalGradePoints += (grades[i] * credits[i]);
    }

    double GPA = totalGradePoints / totalCredits;

    // Display results
    cout << "\n-------------------------------------\n";
    cout << "Course-wise Grades:\n";
    for (int i = 0; i < numCourses; i++) {
        cout << courseNames[i] << " => Grade: " << grades[i]
             << " , Credits: " << credits[i] << endl;
    }
    cout << "-------------------------------------\n";
    cout << fixed << setprecision(2);
    cout << "Final CGPA = " << GPA << endl;
    cout << "-------------------------------------\n";

    return 0;
}

