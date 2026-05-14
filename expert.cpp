// Implement any one of the following Expert System 
// I        Information management 
// II       Hospitals and medical facilities 
// III      Help desks management 
// IV      Employee performance evaluation 
// V       Stock market trading 
// VI      Airline scheduling and cargo schedules  

#include <iostream>
using namespace std;

struct Employee {
    string name;
    string jobTitle;
    int workScore;
    int attendance;
    int projectScore;
    int projectsHandled;
    float performance;
};

// Function to calculate performance
void calculatePerformance(Employee emp[], int n) {
    for (int i = 0; i < n; i++) {
        emp[i].performance = (emp[i].workScore * 0.3) +
                             (emp[i].attendance * 0.2) +
                             (emp[i].projectScore * 0.5);
    }
}



// Selection Sort (descending order)
void selectionSort(Employee emp[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (emp[j].performance > emp[maxIndex].performance) {
                maxIndex = j;
            }
        }

        // Swap
        Employee temp = emp[i];
        emp[i] = emp[maxIndex];
        emp[maxIndex] = temp;
    }
}


// Display employees
void display(Employee emp[], int n) {
    cout << "\nEmployee Rankings:\n";

    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". Name: " << emp[i].name
             << " | Job Title: " << emp[i].jobTitle
             << " | Projects Handled: " << emp[i].projectsHandled
             << " | Score: " << emp[i].performance
             << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    Employee emp[n];
    string commonJobTitle;

    cout << "Enter common Job Title for all employees: ";
    cin >> commonJobTitle;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Employee " << i + 1 << ":\n";

        cout << "Name: ";
        cin >> emp[i].name;

        emp[i].jobTitle = commonJobTitle;

        cout << "Work Score: ";
        cin >> emp[i].workScore;

        cout << "Attendance: ";
        cin >> emp[i].attendance;

        cout << "Project Score: ";
        cin >> emp[i].projectScore;

        cout << "Number of Projects Handled: ";
        cin >> emp[i].projectsHandled;
    }

    calculatePerformance(emp, n);
    selectionSort(emp, n);
    display(emp, n);

    return 0;
}