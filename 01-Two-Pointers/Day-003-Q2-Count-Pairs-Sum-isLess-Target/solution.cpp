#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countPairs(vector<int>& nums, int target)
{
    // Sort the array
    sort(nums.begin(), nums.end());

    int i = 0;
    int j = nums.size() - 1;
    int count = 0;

    // Time Complexity: O(n log n)
    // Space Complexity: O(log n) (due to sorting recursion stack)

    // Eg :- [3, 0, 1, 4, 2].  target = 4
    // sort :-   0, 1, 2, 3, 4 .  target = 4
    //                 i      
    //                 j
    //           count = 0 + 3 + 1 = 4 ans.

    while (i < j)
    {
        int sum = nums[i] + nums[j];

        if (sum < target)
        {
            // All pairs from i+1 to j are valid
            count += (j - i);
            i++;
        }
        else
        {
            j--;
        }
    }

    return count;
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

    int ans = countPairs(nums, target);

    cout << "\nNumber of pairs with sum less than target = " << ans << endl;

    return 0;
}