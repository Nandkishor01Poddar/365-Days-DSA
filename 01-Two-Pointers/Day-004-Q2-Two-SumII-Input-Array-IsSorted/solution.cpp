#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void twoSumHelper(int f, vector<vector<int>>& res, const vector<int>& nums) {
    int st = f + 1;
    int end = nums.size() - 1;

    while (st < end) {
        int sum = nums[f] + nums[st] + nums[end];

        if (sum > 0)
            end--;
        else if (sum < 0)
            st++;
        else {
            res.push_back({nums[f], nums[st], nums[end]});

            st++;
            end--;

            // Skip duplicates
            while (st < end && nums[st] == nums[st - 1])
                st++;

            while (st < end && nums[end] == nums[end + 1])
                end--;
        }
    }
}

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> res;

    for (int f = 0; f < nums.size(); f++) {

        if (nums[f] > 0)
            break;

        // Skip duplicate first elements
        if (f == 0 || nums[f] != nums[f - 1]) {
            twoSumHelper(f, res, nums);
        }
    }

    return res;
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> ans = threeSum(nums);

    if (ans.empty()) {
        cout << "No triplets found." << endl;
    } else {
        cout << "Triplets are:\n";

        for (const auto& triplet : ans) {
            cout << "[ ";
            for (int num : triplet)
                cout << num << " ";
            cout << "]" << endl;
        }
    }

    return 0;
}