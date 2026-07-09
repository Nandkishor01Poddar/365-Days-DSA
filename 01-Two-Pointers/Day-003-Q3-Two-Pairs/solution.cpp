#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
    unordered_map<int, int> mapSt;

    // Time Complexity: O(n)
    // Space Complexity: O(n)

    // Example:
    // nums = [2, 3, 7], target = 9
    // map = {2:0, 3:1}
    // Answer = [2, 0]

    for (int i = 0; i < nums.size(); i++)
    {
        int lookingFor = target - nums[i];

        // Check if the required number already exists
        if (mapSt.count(lookingFor))
        {
            return {mapSt[lookingFor], i};
        }

        // Store current number and its index
        mapSt[nums[i]] = i;
    }

    return {};
}

int main()
{
    int n, target;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter target: ";
    cin >> target;

    vector<int> ans = twoSum(nums, target);

    if (!ans.empty())
    {
        cout << "\nIndices: " << ans[0] << " " << ans[1] << endl;
        cout << "Values : " << nums[ans[0]] << " " << nums[ans[1]] << endl;
    }
    else
    {
        cout << "\nNo valid pair found." << endl;
    }

    return 0;
}