#include <iostream>
using namespace std;

int cubeRoot(int x) {

    if (x < 2)
        return x;

    int st = 0;
    int end = x;
    int ans = 0;

    while (st <= end) {

        int mid = st + (end - st) / 2;

        long long cube = 1LL * mid * mid * mid;

        if (cube == x) {
            return mid;
        }
        else if (cube < x) {
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

    int n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Cube Root = " << cubeRoot(n);

    return 0;
}