#include <iostream>
#include <vector>
using namespace std;

int helperForNumOfOccur(vector<int> &arr, int target, bool findFirst) {

    int st = 0;
    int end = arr.size() - 1;
    int ans = -1;

    while (st <= end) {

        int mid = st + (end - st) / 2;

        if (arr[mid] == target) {
            ans = mid;

            if (findFirst)
                end = mid - 1;
            else
                st = mid + 1;
        }
        else if (arr[mid] < target) {
            st = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return ans;
}

vector<int> numOfOccur(vector<int> &arr, int target) {

    int first = helperForNumOfOccur(arr, target, true);

    if (first == -1)
        return {0};

    int last = helperForNumOfOccur(arr, target, false);

    int count = last - first + 1;

    return {count};
}

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter " << n << " sorted elements: ";

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int target;

    cout << "Enter target: ";
    cin >> target;

    cout << "Number of Occurrence = " << numOfOccur(nums, target)[0];

    return 0;
}