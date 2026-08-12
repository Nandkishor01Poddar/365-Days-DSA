#include <iostream>
#include <vector>
using namespace std;

int longestOnes(vector<int>& nums, int k)
{
    int left = 0;
    int zeroCount = 0;
    int ans = 0;

    for (int right = 0; right < nums.size(); right++)
    {
        // Add current element
        if (nums[right] == 0)
        {
            zeroCount++;
        }

        // Shrink while zeros exceed k
        while (zeroCount > k)
        {
            // Remove left element
            if (nums[left] == 0)
            {
                zeroCount--;
            }

            left++;
        }

        // Update maximum window length
        ans = max(ans, right - left + 1);
    }

    return ans;
}

int main()
{
    int n;

    cout << "Enter array size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements (0 or 1): ";

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int k;

    cout << "Enter k: ";
    cin >> k;

    cout << "Maximum Consecutive Ones: "
         << longestOnes(nums, k)
         << endl;

    return 0;
}