#include <iostream>
#include <vector>
using namespace std;

//---------------------------------------------------------
// Method 1: Brute Force (Linear Search)
// Time Complexity: O(n)
// Space Complexity: O(1)
//---------------------------------------------------------
int findMinBrute(vector<int>& nums) {

    // Assume the first element is the minimum
    int mini = nums[0];

    // Traverse the entire array
    for (int i = 1; i < nums.size(); i++) {

        // Update minimum if a smaller element is found
        if (nums[i] < mini) {
            mini = nums[i];
        }
    }

    return mini;
}

//---------------------------------------------------------
// Method 2: Binary Search
// Time Complexity: O(log n)
// Space Complexity: O(1)
//---------------------------------------------------------
int findMinBinary(vector<int>& nums) {

    int st = 0;
    int end = nums.size() - 1;

    // Initially assume first element is minimum
    int ans = nums[0];

    while (st <= end) {

        // Calculate middle index
        int mid = st + (end - st) / 2;

        /*
            If nums[mid] >= nums[0],
            then mid lies in the left sorted portion.

            Example:
            4 5 6 7 0 1 2
                ^
               mid

            Minimum must be on the right side.
        */
        if (nums[mid] >= nums[0]) {
            st = mid + 1;
        }

        /*
            Otherwise,
            mid lies in the right sorted portion.

            Example:
            4 5 6 7 0 1 2
                    ^
                   mid

            Store current value as a possible answer
            and continue searching left.
        */
        else {
            ans = nums[mid];
            end = mid - 1;
        }
    }

    return ans;
}

int main() {

    int n;

    // Read size of array
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    // Read array elements
    cout << "Enter " << n << " elements (Sorted Rotated Array):\n";

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Call both methods
    int bruteAns = findMinBrute(nums);
    int binaryAns = findMinBinary(nums);

    // Display results
    cout << "\n===== Brute Force =====" << endl;
    cout << "Minimum Element = " << bruteAns << endl;

    cout << "\n===== Binary Search =====" << endl;
    cout << "Minimum Element = " << binaryAns << endl;

    return 0;
}