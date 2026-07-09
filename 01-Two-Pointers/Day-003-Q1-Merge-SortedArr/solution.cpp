#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1, j = n - 1, k = m + n - 1;

    // Time Complexity: O(m + n)
    // Space Complexity: O(1)

    // Eg :- nums1 = 1 2 2 3 5 6, m = 3
    //.                i
    //.                  k
    //       nums2 = 2 5 6    n = 3
    //               j

    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k] = nums1[i];
            i--;
        }
        else
        {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // Copy remaining elements of nums2 (if any)
    while (j >= 0)
    {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

int main()
{
    int m, n;

    cout << "Enter number of elements in nums1: ";
    cin >> m;

    cout << "Enter number of elements in nums2: ";
    cin >> n;

    vector<int> nums1(m + n);
    vector<int> nums2(n);

    cout << "Enter " << m << " sorted elements of nums1: ";
    for (int i = 0; i < m; i++)
    {
        cin >> nums1[i];
    }

    cout << "Enter " << n << " sorted elements of nums2: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums2[i];
    }

    merge(nums1, m, nums2, n);

    cout << "Merged Array: ";
    for (int x : nums1)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}