#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int st = 0, end = numbers.size() - 1;

    while (st < end) {
        int sum = numbers[st] + numbers[end];

        if (sum > target)
            end--;
        else if (sum < target)
            st++;
        else
            return {st + 1, end + 1};   // 1-based indexing
    }

    return {};
}

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> numbers(n);

    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int target;
    cout << "Enter the target value: ";
    cin >> target;

    vector<int> ans = twoSum(numbers, target);

    if (!ans.empty()) {
        cout << "Indices (1-based): " << ans[0] << " " << ans[1] << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}