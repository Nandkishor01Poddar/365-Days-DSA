#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// ================= Method 1: Two Pointer =================
bool isPalindromeMethod1(string s) {
    int st = 0;
    int end = s.size() - 1;

    while (st < end) {

        // Skip non-alphanumeric characters from the left
        while (st < end && !isalnum(s[st]))
            st++;

        // Skip non-alphanumeric characters from the right
        while (st < end && !isalnum(s[end]))
            end--;

        // Compare characters ignoring case
        if (tolower(s[st]) != tolower(s[end]))
            return false;

        st++;
        end--;
    }

    return true;
}

// ================= Method 2: Remove + Lowercase =================
bool isPalindromeMethod2(string s) {

    // Remove non-alphanumeric characters
    s.erase(remove_if(s.begin(), s.end(),
                      [](unsigned char c) {
                          return !isalnum(c);
                      }),
            s.end());

    // Convert to lowercase
    for (char &c : s)
        c = tolower(c);

    // Check palindrome
    int st = 0;
    int end = s.size() - 1;

    while (st < end) {
        if (s[st] != s[end])
            return false;

        st++;
        end--;
    }

    return true;
}

// ================= Main Function =================
int main() {

    string s;

    cout << "Enter a string: ";
    getline(cin, s);

    cout << "\nMethod 1 (Two Pointer): ";
    if (isPalindromeMethod1(s))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    cout << "\nMethod 2 (Preprocessing): ";
    if (isPalindromeMethod2(s))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}