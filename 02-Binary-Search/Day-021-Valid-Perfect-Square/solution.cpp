#include <iostream>
using namespace std;

bool isPerfectSquare(int num) {
    if (num < 2) return true;

    int st = 1, end = num / 2;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (mid == num / mid && num % mid == 0)
            return true;
        else if (mid > num / mid)
            end = mid - 1;
        else
            st = mid + 1;
    }

    return false;
}

int main() {
    int num;

    cout << "Enter a number: ";
    cin >> num;

    if (isPerfectSquare(num))
        cout << num << " is a perfect square." << endl;
    else
        cout << num << " is NOT a perfect square." << endl;

    return 0;
}