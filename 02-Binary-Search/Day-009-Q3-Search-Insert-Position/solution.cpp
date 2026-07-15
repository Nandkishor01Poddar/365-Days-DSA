#include <iostream>
#include <vector>
using namespace std;

// Method 1: Linear Search
// Time Complexity: O(n)
// Space Complexity: O(1)
int searchLinear(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] >= target)
            return i;
    }
    return nums.size();
}

// Method 2: Binary Search
// Time Complexity: O(log n)
// Space Complexity: O(1)
int searchBinary(vector<int>& nums, int target) {
    int st = 0, end = nums.size() - 1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            st = mid + 1;
        else
            end = mid - 1;
    }

    return st;
}

int main() {
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    cout << "\nChoose Method\n";
    cout << "1. Linear Search\n";
    cout << "2. Binary Search\n";
    cout << "Enter choice: ";

    int choice;
    cin >> choice;

    int ans;

    if (choice == 1) {
        ans = searchLinear(nums, target);
        cout << "\nInsertion Position (Linear Search): " << ans << endl;
    }
    else if (choice == 2) {
        ans = searchBinary(nums, target);
        cout << "\nInsertion Position (Binary Search): " << ans << endl;
    }
    else {
        cout << "\nInvalid Choice!" << endl;
    }

    return 0;
}