#include <iostream>
using namespace std;

int main() {
    int n;

    while (true) {
        cout << "Enter number of students (5-15): ";
        cin >> n;
        if (n >= 5 && n <= 15) break;
        cout << "Invalid input. Please try again." << endl;
    }

    int marks[15];

    for (int i = 0; i < n; i++) {
        int m;
        while (true) {
            cout << "Enter marks for student " << (i + 1) << " (0-100): ";
            cin >> m;
            if (m >= 0 && m <= 100) break;
            cout << "Invalid marks. Please try again." << endl;
        }
        marks[i] = m;
    }

    int comparisons = 0;
    int shifts = 0;

    for (int i = 1; i < n; i++) {
        int key = marks[i];
        int j = i - 1;

        while (j >= 0) {
            comparisons++;
            if (marks[j] < key) {
                marks[j + 1] = marks[j];
                shifts++;
                j--;
            } else {
                break;
            }
        }
        marks[j + 1] = key;
    }

    int highest = marks[0];
    int lowest = marks[0];
    int sum = 0;
    bool highAchiever = false;

    for (int i = 0; i < n; i++) {
        if (marks[i] > highest) highest = marks[i];
        if (marks[i] < lowest) lowest = marks[i];
        sum += marks[i];
        if (marks[i] >= 90) highAchiever = true;
    }

    double average = (double)sum / n;

    cout << endl;
    cout << "Total Comparisons: " << comparisons << endl;
    cout << "Total Shifts: " << shifts << endl;
    cout << endl;
    cout << "Highest Marks: " << highest << endl;
    cout << "Lowest Marks: " << lowest << endl;
    cout << "Average Marks: " << average << endl;

    cout << "Sorted Marks (Descending): ";
    for (int i = 0; i < n; i++) cout << marks[i] << " ";
    cout << endl;

    if (highAchiever) {
        cout << "High Achiever(s) Present" << endl;
    } else {
        cout << "No High Achiever" << endl;
    }

    return 0;
}
