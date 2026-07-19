#include <iostream>
#include <vector>
using namespace std;

//---------------------------------------------------------
// Method 1: Brute Force (Linear Search)
// Time Complexity: O(n)
// Space Complexity: O(1)
//---------------------------------------------------------
int searchBrute(vector<int>& nums, int target) {

    // Traverse the entire array
    for (int i = 0; i < nums.size(); i++) {

        // If target is found, return its index
        if (nums[i] == target)
            return i;
    }

    // Target not found
    return -1;
}

//---------------------------------------------------------
// Method 2: Binary Search
// Time Complexity: O(log n)
// Space Complexity: O(1)
//---------------------------------------------------------
int searchBinary(vector<int>& nums, int target) {

    int st = 0;
    int end = nums.size() - 1;

    while (st <= end) {

        // Find middle index
        int mid = st + (end - st) / 2;

        // Target found
        if (nums[mid] == target)
            return mid;

        /*
            Check whether the LEFT half is sorted.

            Example:
            4 5 6 7 0 1 2
              ^   ^
             st  mid

            If nums[mid] >= nums[st],
            then left portion is sorted.
        */
        if (nums[mid] >= nums[st]) {

            /*
                Check whether target lies inside
                the left sorted portion.
            */
            if (target >= nums[st] && target < nums[mid]) {
                end = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }

        /*
            Otherwise, the RIGHT half is sorted.

            Example:
            4 5 6 7 0 1 2
                    ^   ^
                   mid end
        */
        else {

            /*
                Check whether target lies inside
                the right sorted portion.
            */
            if (target > nums[mid] && target <= nums[end]) {
                st = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
    }

    // Target not found
    return -1;
}

int main() {

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter " << n << " elements (Sorted Rotated Array):\n";

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;

    cout << "Enter target element: ";
    cin >> target;

    // Brute Force
    int bruteIndex = searchBrute(nums, target);

    // Binary Search
    int binaryIndex = searchBinary(nums, target);

    cout << "\n===== Brute Force =====" << endl;

    if (bruteIndex != -1)
        cout << "Target found at index = " << bruteIndex << endl;
    else
        cout << "Target not found" << endl;

    cout << "\n===== Binary Search =====" << endl;

    if (binaryIndex != -1)
        cout << "Target found at index = " << binaryIndex << endl;
    else
        cout << "Target not found" << endl;

    return 0;
}