#include <iostream>
#include <vector>
using namespace std;

// Function to calculate K-Radius Subarray Averages
vector<int> getAverages(vector<int>& nums, int k) {

    int n = nums.size();
    vector<int> ans(n, -1);

    // If k is 0, every element is its own average
    if (k == 0)
        return nums;

    // Window size
    int window = 2 * k + 1;

    // If window size is greater than array size
    if (window > n)
        return ans;

    long long sum = 0;

    // Build first window
    for (int i = 0; i < window; i++)
        sum += nums[i];

    // Store first average
    ans[k] = sum / window;

    // Slide the window
    for (int i = window; i < n; i++) {
        sum -= nums[i - window];   // Remove left element
        sum += nums[i];            // Add right element

        ans[i - k] = sum / window;
    }

    return ans;
}

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int k;
    cin >> k;

    vector<int> ans = getAverages(nums, k);

    for (int x : ans)
        cout << x << " ";

    return 0;
}