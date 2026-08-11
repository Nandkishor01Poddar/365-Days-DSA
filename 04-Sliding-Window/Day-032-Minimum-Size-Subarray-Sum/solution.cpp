#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums)
{
    int n = nums.size();

    int left = 0;
    int sum = 0;

    int ans = INT_MAX;

    for (int right = 0; right < n; right++)
    {
        // Expand window
        sum += nums[right];

        // Shrink while sum is valid
        while (sum >= target)
        {
            // Update minimum length
            ans = min(ans, right - left + 1);

            // Remove left element
            sum -= nums[left];

            left++;
        }
    }

    // No valid subarray found
    if (ans == INT_MAX)
        return 0;

    return ans;
}

int main()
{
    int n;

    cout << "Enter array size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int target;

    cout << "Enter target: ";
    cin >> target;

    cout << "Minimum Subarray Length: "
         << minSubArrayLen(target, nums)
         << endl;

    return 0;
}