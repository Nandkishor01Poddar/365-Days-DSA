#include <iostream>
#include <algorithm>
using namespace std;

// ================= Method 1: Two Pointer =================
// Time Complexity: O(n)
// Space Complexity: O(1)
void reverseStringTwoPointer(string &s)
{
    int st = 0, end = s.size() - 1;

    while (st < end)
    {
        swap(s[st], s[end]);
        st++;
        end--;
    }
}

// ================= Method 2: STL reverse() =================
// Time Complexity: O(n)
// Space Complexity: O(1)
void reverseStringSTL(string &s)
{
    reverse(s.begin(), s.end());
}

// ================= Main =================
int main()
{
    string s;

    cout << "Enter a string: ";
    cin >> s;

    // Uncomment the method you want to test

    // Method 1
    reverseStringTwoPointer(s);

    // Method 2
    // reverseStringSTL(s);

    cout << "Reversed string: " << s << endl;

    return 0;
}