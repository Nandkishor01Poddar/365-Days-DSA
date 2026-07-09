#include <iostream>
#include <vector>
#include <algorithm> // For sort()
#include <cmath>     // For abs()
using namespace std;

// ================= Method 1: Two Pointer =================
// Time Complexity: O(n)
// Space Complexity: O(n)
vector<int> sortedSquaresTwoPointer(vector<int> &nums)
{
    vector<int> res(nums.size());

    int i = 0, j = nums.size() - 1, k = nums.size() - 1;

    // eg :- [-7, -3, 2, 3, 11]
    //                i
    //.               j
    //        k
    // res = [4, 9, 9, 49, 121]

    while (i <= j)
    {
        if (abs(nums[i]) > abs(nums[j]))
        {
            res[k] = nums[i] * nums[i];
            i++;
        }
        else
        {
            res[k] = nums[j] * nums[j];
            j--;
        }
        k--;
    }

    return res;
}

// ================= Method 2: Square + Sort =================
// Time Complexity: O(n log n)
// Space Complexity: O(1) (excluding sorting's internal stack)
vector<int> sortedSquaresSort(vector<int> nums)
{
    // Square every element
    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = nums[i] * nums[i];
    }

    // Sort the squared values
    sort(nums.begin(), nums.end());

    return nums;
}

// ================= Main =================
int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter " << n << " sorted integers:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // Uncomment the method you want to test

    // Method 1: Two Pointer
    vector<int> result = sortedSquaresTwoPointer(nums);

    // Method 2: Square + Sort
    // vector<int> result = sortedSquaresSort(nums);

    cout << "Sorted Squares: ";
    for (int x : result)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}