//==========================================================================
// Reverse Words in a String
//
// METHOD 1 : trim() + stringstream + vector
// METHOD 2 : stringstream + vector
// METHOD 3 : Two Pointer (Optimal)
//
// Time Complexity
// Method 1 : O(n)
// Method 2 : O(n)
// Method 3 : O(n)
//
// Space Complexity
// Method 1 : O(n)
// Method 2 : O(n)
// Method 3 : O(1) Extra Space
//
// Input
// Enter a sentence:
//     Hello      World      from      C++
//
// Output
// Method 1 : C++ from World Hello
// Method 2 : C++ from World Hello
// Method 3 : C++ from World Hello
//==========================================================================

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string_view>

using namespace std;

//==========================================================================
// METHOD 1
// trim() + stringstream
//==========================================================================

string_view trim(string_view s)
{
    // Remove spaces from left
    while (!s.empty() && isspace(s.front()))
        s.remove_prefix(1);

    // Remove spaces from right
    while (!s.empty() && isspace(s.back()))
        s.remove_suffix(1);

    return s;
}

string reverseWords_Method1(string s)
{
    // Remove leading & trailing spaces
    string_view sv = trim(s);

    // Convert into stream
    stringstream ss{string(sv)};

    vector<string> words;
    string word;

    // Extract words
    while (ss >> word)
    {
        words.push_back(word);
    }

    // Reverse vector
    reverse(words.begin(), words.end());

    // Build answer
    string ans;

    for (int i = 0; i < words.size(); i++)
    {
        ans += words[i];

        if (i != words.size() - 1)
            ans += " ";
    }

    return ans;
}

//==========================================================================
// METHOD 2
// stringstream only
//==========================================================================

string reverseWords_Method2(string s)
{
    stringstream ss(s);

    vector<string> words;
    string word;

    while (ss >> word)
    {
        words.push_back(word);
    }

    reverse(words.begin(), words.end());

    string ans;

    for (int i = 0; i < words.size(); i++)
    {
        if (i > 0)
            ans += " ";

        ans += words[i];
    }

    return ans;
}

//==========================================================================
// METHOD 3
// Optimal Two Pointer
//
// Steps
// 1. Trim
// 2. Remove multiple spaces
// 3. Reverse complete string
// 4. Reverse every word
//==========================================================================

string reverseWords_Method3(string s)
{
    //------------------------------------------------------
    // STEP 1 : Trim
    //------------------------------------------------------

    int left = 0;
    int right = s.size() - 1;

    while (left <= right && s[left] == ' ')
        left++;

    while (left <= right && s[right] == ' ')
        right--;

    s = s.substr(left, right - left + 1);

    //------------------------------------------------------
    // STEP 2 : Remove multiple spaces
    //------------------------------------------------------

    int read = 0;
    int write = 0;

    while (read < s.size())
    {
        // Skip spaces
        while (read < s.size() && s[read] == ' ')
            read++;

        // Copy one word
        while (read < s.size() && s[read] != ' ')
            s[write++] = s[read++];

        // Skip remaining spaces
        while (read < s.size() && s[read] == ' ')
            read++;

        // Put one space if another word exists
        if (read < s.size())
            s[write++] = ' ';
    }

    s.resize(write);

    //------------------------------------------------------
    // STEP 3 : Reverse complete string
    //------------------------------------------------------

    reverse(s.begin(), s.end());

    //------------------------------------------------------
    // STEP 4 : Reverse every word
    //------------------------------------------------------

    int start = 0;

    for (int end = 0; end <= s.size(); end++)
    {
        if (end == s.size() || s[end] == ' ')
        {
            reverse(s.begin() + start, s.begin() + end);

            start = end + 1;
        }
    }

    return s;
}

//==========================================================================
// MAIN
//==========================================================================

int main()
{
    string s;

    cout << "Enter a sentence:\n";
    getline(cin, s);

    cout << "\n======================================\n";
    cout << "Method 1 : trim() + stringstream\n";
    cout << reverseWords_Method1(s);

    cout << "\n\n======================================\n";
    cout << "Method 2 : stringstream only\n";
    cout << reverseWords_Method2(s);

    cout << "\n\n======================================\n";
    cout << "Method 3 : Optimal Two Pointer\n";
    cout << reverseWords_Method3(s);

    cout << "\n";

    return 0;
}