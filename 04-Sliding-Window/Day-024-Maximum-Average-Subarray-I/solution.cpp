#include <iostream>
#include <vector>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    double windowSum = 0;

    // Step 1: Calculate sum of first window
    for (int i = 0; i < k; i++) {
        windowSum += nums[i];
    }

    double maxSum = windowSum;

    // Step 2: Slide the window
    for (int i = k; i < nums.size(); i++) {
        windowSum += nums[i];      // Add new element
        windowSum -= nums[i - k];  // Remove old element

        if (windowSum > maxSum) // use:-  max(maxSum, windowSum)
            maxSum = windowSum;
    }

    return maxSum / k;
}

int main() {
    int n, k;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter window size (k): ";
    cin >> k;

    cout << "Maximum Average = " << findMaxAverage(nums, k);

    return 0;
}