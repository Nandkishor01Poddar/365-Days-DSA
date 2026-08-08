#include <iostream>
#include <vector>
using namespace std;

int numOfSubarrays(vector<int>& arr, int k, int threshold)
{
    int n = arr.size();

    // Minimum sum required for a valid subarray
    int target = k * threshold;

    int windowSum = 0;
    int count = 0;

    // Build the first window
    for (int i = 0; i < k; i++)
    {
        windowSum += arr[i];
    }

    // Check the first window
    if (windowSum >= target)
    {
        count++;
    }

    // Slide the window
    for (int i = k; i < n; i++)
    {
        // Remove the outgoing element
        windowSum -= arr[i - k];

        // Add the incoming element
        windowSum += arr[i];

        // Check the current window
        if (windowSum >= target)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    int n;

    // Enter array size
    cin >> n;

    vector<int> arr(n);

    // Enter array elements
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    int threshold;

    // Enter window size
    cin >> k;

    // Enter threshold
    cin >> threshold;

    // Check invalid k
    if (k <= 0 || k > n)
    {
        cout << "Invalid value of k" << endl;
        return 0;
    }

    cout << numOfSubarrays(arr, k, threshold) << endl;

    return 0;
}