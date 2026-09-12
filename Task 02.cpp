#include <iostream>
using namespace std;

int main() {
    int original[] = {55, 61, 67, 72, 78, 81, 80, 85};
    int n = 8;

    int arr1[8];
    for (int i = 0; i < n; i++) arr1[i] = original[i];

    int modPasses = 0;
    int modComparisons = 0;
    int modSwaps = 0;
    int sortedAtPass = 0;

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            modComparisons++;
            if (arr1[j] > arr1[j + 1]) {
                int temp = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = temp;
                modSwaps++;
                swapped = true;
            }
        }
        modPasses++;
        if (!swapped) {
            sortedAtPass = modPasses;
            break;
        }
    }

    int arr2[8];
    for (int i = 0; i < n; i++) arr2[i] = original[i];

    int stdPasses = 0;
    int stdComparisons = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            stdComparisons++;
            if (arr2[j] > arr2[j + 1]) {
                int temp = arr2[j];
                arr2[j] = arr2[j + 1];
                arr2[j + 1] = temp;
            }
        }
        stdPasses++;
    }

    cout << "Modified Bubble Sort:" << endl;
    cout << "Sorted after pass: " << sortedAtPass << endl;
    cout << "Comparisons: " << modComparisons << endl;
    cout << "Swaps: " << modSwaps << endl;
    cout << "Sorted array: ";
    for (int k = 0; k < n; k++) cout << arr1[k] << " ";
    cout << endl << endl;

    cout << "Standard Bubble Sort:" << endl;
    cout << "Passes: " << stdPasses << endl;
    cout << "Comparisons: " << stdComparisons << endl;

    return 0;
}
