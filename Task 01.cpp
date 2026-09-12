#include <iostream>
using namespace std;

int main() {
    int arr[] = {45, 12, 78, 34, 23, 90};
    int n = 6;
    int passes = 0;
    int comparisons = 0;
    int swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
                swapped = true;
            }
        }
        passes++;
        cout << "Pass " << passes << ": ";
        for (int k = 0; k < n; k++) cout << arr[k] << " ";
        cout << endl;
        if (!swapped) break;
    }

    cout << endl;
    cout << "Number of passes: " << passes << endl;
    cout << "Total comparisons: " << comparisons << endl;
    cout << "Total swaps: " << swaps << endl;

    cout << "Final sorted array: ";
    for (int k = 0; k < n; k++) cout << arr[k] << " ";
    cout << endl;

    return 0;
}
