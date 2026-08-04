#include <iostream>
#include <vector>
using namespace std;

vector<int> decrypt(vector<int>& code, int k) {
    int n = code.size();
    vector<int> ans(n, 0);

    if (k == 0)
        return ans;

    int windowSum = 0;

    if (k > 0) {
        for (int i = 1; i <= k; i++) {
            windowSum += code[i % n];
        }

        for (int i = 0; i < n; i++) {
            ans[i] = windowSum;
            windowSum -= code[(i + 1) % n];
            windowSum += code[(i + k + 1) % n];
        }
    } else {
        k = -k;

        for (int i = 1; i <= k; i++) {
            windowSum += code[(n - i) % n];
        }

        for (int i = 0; i < n; i++) {
            ans[i] = windowSum;
            windowSum -= code[(i - k + n) % n];
            windowSum += code[i];
        }
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> code(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> code[i];
    }

    int k;
    cout << "Enter k: ";
    cin >> k;

    vector<int> ans = decrypt(code, k);

    cout << "Output: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}