#include <iostream>
#include <vector>
using namespace std;

// ===============================
// Brute Force Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
// ===============================
vector<int> searchRangeBrute(vector<int>& nums, int target) {
    int first = -1, last = -1;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            if (first == -1)
                first = i;
            last = i;
        }
    }

    return {first, last};
}

// ===============================
// Binary Search Helper
// Time Complexity: O(log n)
// ===============================
int helperSearchRange(vector<int>& nums, int target, bool findFirst) {
    int st = 0;
    int end = nums.size() - 1;
    int ans = -1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (nums[mid] == target) {
            ans = mid;

            if (findFirst)
                end = mid - 1;
            else
                st = mid + 1;
        }
        else if (nums[mid] < target) {
            st = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return ans;
}

// ===============================
// Binary Search Approach
// ===============================
vector<int> searchRangeBinary(vector<int>& nums, int target) {
    return {
        helperSearchRange(nums, target, true),
        helperSearchRange(nums, target, false)
    };
}

// ===============================
// Main Function
// ===============================
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
    cout << "1. Brute Force\n";
    cout << "2. Binary Search\n";
    cout << "Enter choice: ";

    int choice;
    cin >> choice;

    vector<int> ans;

    if (choice == 1) {
        ans = searchRangeBrute(nums, target);

        cout << "\nBrute Force Result\n";
        cout << "First Occurrence : " << ans[0] << endl;
        cout << "Last Occurrence  : " << ans[1] << endl;
    }
    else if (choice == 2) {
        ans = searchRangeBinary(nums, target);

        cout << "\nBinary Search Result\n";
        cout << "First Occurrence : " << ans[0] << endl;
        cout << "Last Occurrence  : " << ans[1] << endl;
    }
    else {
        cout << "Invalid Choice!" << endl;
    }

    return 0;
}