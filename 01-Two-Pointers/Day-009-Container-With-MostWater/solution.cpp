#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
-------------------------------------------------------
BRUTE FORCE APPROACH
-------------------------------------------------------
Idea:
- Check every possible pair of lines.
- Calculate the water stored between them.
- Keep track of the maximum area.

Time Complexity : O(n^2)
Space Complexity: O(1)
*/

int maxAreaBruteForce(vector<int>& height) {
    int n = height.size();
    int maxWater = 0;

    // Select first line
    for (int i = 0; i < n; i++) {

        // Select second line
        for (int j = i + 1; j < n; j++) {

            // Width between two lines
            int width = j - i;

            // Height is determined by the shorter line
            int h = min(height[i], height[j]);

            // Area formed
            int area = width * h;

            // Update maximum area
            maxWater = max(maxWater, area);
        }
    }

    return maxWater;
}


/*
-------------------------------------------------------
OPTIMAL TWO POINTER APPROACH
-------------------------------------------------------
Idea:
- Start with two pointers:
      left = 0
      right = n-1

- Calculate area between them.

- Move the pointer having smaller height because:
  The smaller height limits the area.
  Moving the taller line cannot increase the height,
  while width also decreases.

- Continue until pointers meet.

Time Complexity : O(n)
Space Complexity: O(1)
*/

int maxAreaOptimal(vector<int>& height) {

    int left = 0;
    int right = height.size() - 1;

    int maxWater = 0;

    while (left < right) {

        // Current width
        int width = right - left;

        // Current height
        int h = min(height[left], height[right]);

        // Current area
        int area = width * h;

        // Update answer
        maxWater = max(maxWater, area);

        /*
        Move the pointer with smaller height.
        Because the smaller height is the limiting factor.
        */
        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return maxWater;
}


int main() {

    int n;

    // Take size of array
    cout << "Enter number of heights: ";
    cin >> n;

    vector<int> height(n);

    // Take heights dynamically
    cout << "Enter the heights:\n";
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    cout << "\nMaximum Area (Brute Force) : "
         << maxAreaBruteForce(height) << endl;

    cout << "Maximum Area (Optimal)     : "
         << maxAreaOptimal(height) << endl;

    return 0;
}