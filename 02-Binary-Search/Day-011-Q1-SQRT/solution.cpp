#include <iostream>
using namespace std;

int integerSqrt(int x) {
    // Edge cases
    if (x < 2)
        return x;

    int st = 0, end = x;
    int ans = 0;

    while (st <= end) {
        int mid = st + (end - st) / 2;
        long long sq = 1LL * mid * mid;   // Prevent integer overflow

        if (sq == x) {
            return mid;
        }
        else if (sq < x) {
            ans = mid;
            st = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return ans;
}

int main() {
    int x;

    cout << "Enter a number: ";
    cin >> x;

    cout << "Integer Square Root = " << integerSqrt(x);

    return 0;
}