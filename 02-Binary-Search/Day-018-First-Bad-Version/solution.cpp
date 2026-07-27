#include <iostream>
using namespace std;

// Simulate the first bad version
int firstBad;

// Simulated API
bool isBadVersion(int version) {
    return version >= firstBad;
}

// Function to find the first bad version
int firstBadVersion(int n) {
    int low = 1, high = n;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (isBadVersion(mid))
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}

int main() {
    int n;

    cout << "Enter total number of versions: ";
    cin >> n;

    cout << "Enter the first bad version: ";
    cin >> firstBad;

    cout << "First Bad Version = " << firstBadVersion(n) << endl;

    return 0;
}