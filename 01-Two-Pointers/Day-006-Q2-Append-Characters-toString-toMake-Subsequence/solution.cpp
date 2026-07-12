#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    // ==========================================================
    // Method 1 : Brute Force (Nested Loop Search)
    // ==========================================================
    int appendCharacters_Method1(string s, string t)
    {
        // Start searching from the beginning of string s
        int start = 0;

        // Traverse every character of string t
        for (int j = 0; j < t.size(); j++)
        {
            bool found = false;

            // Search the current character of t
            // in the remaining part of s
            for (int i = start; i < s.size(); i++)
            {
                if (s.at(i) == t.at(j))
                {
                    found = true;

                    // Next search will begin after
                    // the matched character
                    start = i + 1;

                    break;
                }
            }

            // Character not found
            if (!found)
                return t.size() - j;
        }

        // Entire string t is already a subsequence
        return 0;
    }

    /*
        Time Complexity  : O(n + m)

        Space Complexity : O(1)

        Reason:
        - Although there are two nested loops,
          the 'start' pointer only moves forward.
        - Each character of string 's' is visited
          at most once.
        - Each character of string 't' is processed once.
        - No extra data structure is used.
    */

    // ==========================================================
    // Method 2 : Optimized (Two Pointers)
    // ==========================================================
    int appendCharacters_Method2(string s, string t)
    {
        // i -> pointer for string s
        // j -> pointer for string t
        int i = 0, j = 0;

        // Traverse both strings
        while (i < s.size() && j < t.size())
        {
            // Characters match
            if (s.at(i) == t.at(j))
            {
                i++;
                j++;
            }
            // Characters do not match
            else
            {
                i++;
            }
        }

        // Remaining characters of t
        // need to be appended
        return t.size() - j;
    }

    /*
        Time Complexity  : O(n + m)

        Space Complexity : O(1)

        Reason:
        - Pointer 'i' traverses string 's' only once.
        - Pointer 'j' traverses string 't' only once.
        - No extra space is used except variables.
    */
};

int main()
{
    Solution sol;

    string s, t;

    // Take input from the user
    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter string t: ";
    cin >> t;

    // ==========================================================
    // Choose any one method
    // ==========================================================

    // Method 1 : Brute Force
    // int result = sol.appendCharacters_Method1(s, t);

    // Method 2 : Optimized (Two Pointers)
    int result = sol.appendCharacters_Method2(s, t);

    cout << "Minimum characters to append: " << result << endl;

    return 0;
}