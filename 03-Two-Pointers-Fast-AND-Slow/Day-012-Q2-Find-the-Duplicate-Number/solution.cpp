#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Better Approach (Using Hash Set)
int findDuplicateSet(vector<int>& nums)
{
    unordered_set<int> st;

    for (int num : nums)
    {
        if (st.count(num))
            return num;

        st.insert(num);
    }

    return -1;
}

// Optimal Approach (Floyd's Cycle Detection)
int findDuplicateFloyd(vector<int>& nums)
{
    int slow = 0, fast = 0;

    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    int n1 = 0;
    int n2 = slow;

    while (n1 != n2)
    {
        n1 = nums[n1];
        n2 = nums[n2];
    }

    return n1;
}

int main()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "\nDuplicate using Hash Set: "
         << findDuplicateSet(nums) << endl;

    cout << "Duplicate using Floyd's Cycle Detection: "
         << findDuplicateFloyd(nums) << endl;

    return 0;
}