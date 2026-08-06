#include <iostream>
#include <string>
using namespace std;

int minimumRecolors(string blocks, int k) {

    int n = blocks.size();

    int whiteCount = 0;

    // Count whites in the first window
    for (int i = 0; i < k; i++) {
        if (blocks[i] == 'W')
            whiteCount++;
    }

    int ans = whiteCount;

    // Slide the window
    for (int i = k; i < n; i++) {

        // Remove outgoing character
        if (blocks[i - k] == 'W')
            whiteCount--;

        // Add incoming character
        if (blocks[i] == 'W')
            whiteCount++;

        ans = min(ans, whiteCount);
    }

    return ans;
}

int main() {

    string blocks;
    int k;

    cout << "Enter blocks (W/B): ";
    cin >> blocks;

    cout << "Enter k: ";
    cin >> k;

    cout << "Minimum Recolors: "
         << minimumRecolors(blocks, k);

    return 0;
}