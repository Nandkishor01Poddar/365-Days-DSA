#include <iostream>
using namespace std;

int pick;

// Simulated LeetCode API
int guess(int num) {
    if (num == pick)
        return 0;
    else if (num > pick)
        return -1;
    else
        return 1;
}

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int res = guess(mid);

            if (res == 0)
                return mid;
            else if (res == -1)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return -1;
    }
};

int main() {
    int n;

    cout << "Enter n: ";
    cin >> n;

    cout << "Enter picked number (1 to " << n << "): ";
    cin >> pick;

    Solution obj;
    cout << "Guessed number: " << obj.guessNumber(n) << endl;

    return 0;
}