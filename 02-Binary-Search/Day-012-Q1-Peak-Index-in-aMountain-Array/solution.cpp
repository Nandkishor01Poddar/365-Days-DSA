#include <iostream>
#include <vector>
using namespace std;

//---------------------------------------------------------
// Method 1: Linear Search
// Time Complexity: O(n)
// Space Complexity: O(1)
//---------------------------------------------------------
int findPeakElement(vector<int>& arr) {
    int n = arr.size();

    // If the array contains only one element,
    // that element is the peak.
    if (n == 1)
        return 0;

    // Check if the first element is a peak.
    // It only has one neighbor.
    if (arr[0] > arr[1])
        return 0;

    // Check all middle elements.
    // A peak is greater than both left and right neighbors.
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
            return i;
    }

    // Check if the last element is a peak.
    if (arr[n - 1] > arr[n - 2])
        return n - 1;

    // If no peak exists (generally won't happen for valid inputs)
    return -1;
}

//---------------------------------------------------------
// Method 2: Binary Search
// Time Complexity: O(log n)
// Space Complexity: O(1)
//---------------------------------------------------------
int findPeakElementM2(vector<int>& arr) {

    // Search space
    int st = 0;
    int end = arr.size() - 1;

    // Continue until only one element remains
    while (st < end) {

        // Find middle index
        int mid = st + (end - st) / 2;

        /*
            Compare mid with its right neighbor.

            Case 1:
            arr[mid] > arr[mid + 1]

            This means we are on the descending slope,
            so the peak lies at mid or on the left side.

            Example:
            1 3 7 5 2
                  ^
                 mid
        */
        if (arr[mid] > arr[mid + 1]) {
            end = mid;
        }

        /*
            Case 2:
            arr[mid] < arr[mid + 1]

            This means we are on the ascending slope,
            so the peak must lie on the right side.

            Example:
            1 3 5 7 6
                ^
               mid
        */
        else {
            st = mid + 1;
        }
    }

    // When st == end, both point to the peak element.
    return st;
}

int main() {

    int n;

    // Read size of array
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    // Read array elements
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Find peak using Linear Search
    int linearIndex = findPeakElement(arr);

    // Find peak using Binary Search
    int binaryIndex = findPeakElementM2(arr);

    // Display result of Linear Search
    cout << "\n===== Linear Search =====\n";
    cout << "Peak Index   : " << linearIndex << endl;
    cout << "Peak Element : " << arr[linearIndex] << endl;

    // Display result of Binary Search
    cout << "\n===== Binary Search =====\n";
    cout << "Peak Index   : " << binaryIndex << endl;
    cout << "Peak Element : " << arr[binaryIndex] << endl;

    return 0;
}