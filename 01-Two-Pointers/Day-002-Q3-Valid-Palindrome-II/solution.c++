#include <iostream>
using namespace std;

// ================= Helper Function =================
// T.C: O(n), S.C: O(1)
bool palindromeHelper(int i, int j, string s)
{
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++,j--;
    }
    return true;
}

// ===================================================
// Method 1: Two Pointer (Optimal)
// T.C: O(n), S.C: O(1)
// ===================================================
bool validPalindromeTwoPointer(string s)
{
    int i = 0, j = s.size() - 1;

    while (i < j)
    {
        if (s[i] != s[j])
        {
            return palindromeHelper(i + 1, j, s) ||
                   palindromeHelper(i, j - 1, s);
        }

        i++,j--;
    }

    return true;
}

// ===================================================
// Method 2: Brute Force
// T.C: O(n²), S.C: O(1)
// ===================================================

// Checks if an entire string is a palindrome
bool isPalindrome(string str)
{
    int i = 0, j = str.size() - 1;

    while (i < j)
    {
        if (str[i] != str[j])
            return false;

        i++;
        j--;
    }

    return true;
}

bool validPalindromeBruteForce(string s)
{
    // Already a palindrome
    if (isPalindrome(s))
        return true;

    // Remove each character once
    for (int i = 0; i < s.size(); i++)
    {
        string temp = s.substr(0, i) + s.substr(i + 1);

        if (isPalindrome(temp))
            return true;
    }

    return false;
}

// ================= Main =================
int main()
{
    string s;

    cout << "Enter a string: ";
    cin >> s;

    // Method 1 (Optimal)
    cout << "Method 1 (Two Pointer): ";
    if (validPalindromeTwoPointer(s))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    // Method 2 (Brute Force)
    cout << "Method 2 (Brute Force): ";
    if (validPalindromeBruteForce(s))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}