#include <iostream>
#include <vector>
using namespace std;

// =====================================================
// Brute Force Approach (Linear Search)
// Time Complexity:
//   Best Case    : O(1)
//   Average Case : O(n)
//   Worst Case   : O(n)
//
// Space Complexity: O(1)
// =====================================================
int linearSearch(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target)
            return i;
    }
    return -1;
}

// =====================================================
// Optimal Approach (Binary Search)
// Note: Array must be sorted.
//
// Time Complexity:
//   Best Case    : O(1)
//   Average Case : O(log n)
//   Worst Case   : O(log n)
//
// Space Complexity: O(1)
// =====================================================
int binarySearch(vector<int>& nums, int target) {
    int st = 0;
    int end = nums.size() - 1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            end = mid - 1;
        else
            st = mid + 1;
    }

    return -1;
}

int main() {
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter target element: ";
    cin >> target;

    // Brute Force Result
    int linearIndex = linearSearch(nums, target);

    cout << "\n========== Brute Force (Linear Search) ==========\n";
    if (linearIndex != -1)
        cout << "Element found at index: " << linearIndex << endl;
    else
        cout << "Element not found." << endl;

    // Optimal Result
    int binaryIndex = binarySearch(nums, target);

    cout << "\n========== Optimal (Binary Search) ==========\n";
    if (binaryIndex != -1)
        cout << "Element found at index: " << binaryIndex << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}