#include <iostream>
using namespace std;

int main() {
    int arr[] = {90, 20, 80, 30, 70, 40, 60, 50, 10};
    int n = 9;
    int totalComparisons = 0;
    int totalShifts = 0;

    for (int gap = n / 2; gap > 0; gap /= 2) {
        int gapComparisons = 0;
        int gapShifts = 0;

        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;

            while (j >= gap) {
                gapComparisons++;
                if (arr[j - gap] > temp) {
                    arr[j] = arr[j - gap];
                    gapShifts++;
                    j -= gap;
                } else {
                    break;
                }
            }
            arr[j] = temp;
        }

        totalComparisons += gapComparisons;
        totalShifts += gapShifts;

        cout << "Gap = " << gap << ": ";
        for (int k = 0; k < n; k++) cout << arr[k] << " ";
        cout << endl;
        cout << "Comparisons for this gap: " << gapComparisons << endl;
        cout << "Shifts for this gap: " << gapShifts << endl << endl;
    }

    cout << "Final sorted array: ";
    for (int k = 0; k < n; k++) cout << arr[k] << " ";
    cout << endl;
    cout << "Total comparisons: " << totalComparisons << endl;
    cout << "Total shifts: " << totalShifts << endl;

    return 0;
}
