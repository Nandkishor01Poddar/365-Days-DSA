#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> window;

    for (int i = 0; i < nums.size(); i++) {
        if (window.count(nums[i])) {
            return true;
        }

        window.insert(nums[i]);

        if (window.size() > k) {
            window.erase(nums[i - k]);
        }
    }

    return false;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;
    cout << "Enter k: ";
    cin >> k;

    if (containsNearbyDuplicate(nums, k))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}