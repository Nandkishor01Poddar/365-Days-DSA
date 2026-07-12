#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution
{
public:
    // ==========================================================
    // Method 1 : Brute Force (Build Rotated String)
    // ==========================================================
    bool isStrobogrammatic_Method1(string num)
    {
        // Valid rotations
        const map<char, char> Map = {
            {'0', '0'},
            {'1', '1'},
            {'8', '8'},
            {'6', '9'},
            {'9', '6'}};

        // Store the rotated number
        string rotated = "";

        // Traverse from right to left because
        // rotation reverses the order.
        for (int i = num.size() - 1; i >= 0; i--)
        {
            // If current digit is invalid
            // (2,3,4,5,7)
            if (!Map.contains(num.at(i)))
                return false;

            // Append its rotated value
            rotated += Map.at(num.at(i));
        }

        // Compare rotated string with original string
        return rotated == num;
    }

    /*
        Time Complexity  : O(n)
        Space Complexity : O(n)

        Reason:
        - Traverse the string once.
        - Extra string "rotated" of size n is created.
    */

    // ==========================================================
    // Method 2 : Optimized (Two Pointers)
    // ==========================================================

    bool isStrobogrammaticNum(const map<char, char> &Map, string num)
    {
        // Left pointer
        int i = 0;

        // Right pointer
        int j = num.size() - 1;

        // Continue until pointers meet
        while (i <= j)
        {
            char l = num.at(i);
            char r = num.at(j);

            // Check whether left character
            // exists in the map.
            if (Map.contains(l))
            {
                // Check rotated value
                if (Map.at(l) != r)
                    return false;

                // Move both pointers
                i++;
                j--;
            }
            else
            {
                // Invalid digit found
                return false;
            }
        }

        return true;
    }

    bool isStrobogrammatic_Method2(string num)
    {
        const map<char, char> Map = {
            {'0', '0'},
            {'1', '1'},
            {'8', '8'},
            {'6', '9'},
            {'9', '6'}};

        return isStrobogrammaticNum(Map, num);
    }

    /*
        Time Complexity  : O(n)
        Space Complexity : O(1)

        Reason:
        - Each character is visited only once.
        - Map contains only 5 fixed entries,
          so it is considered constant space.
    */
};

int main()
{
    Solution sol;

    string num;

    cout << "Enter a number: ";
    cin >> num;

    // ==========================================================
    // Choose any one method
    // ==========================================================

    // Method 1 : Brute Force
    // bool result = sol.isStrobogrammatic_Method1(num);

    // Method 2 : Optimized (Two Pointers)
    bool result = sol.isStrobogrammatic_Method2(num);

    if (result)
        cout << num << " is a Strobogrammatic Number." << endl;
    else
        cout << num << " is NOT a Strobogrammatic Number." << endl;

    return 0;
}