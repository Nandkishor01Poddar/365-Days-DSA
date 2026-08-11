#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_set<char> seen;

    int left = 0;
    int ans = 0;

    for (int right = 0; right < s.length(); right++)
    {
        // Shrink window while duplicate exists
        while (seen.count(s[right]))
        {
            seen.erase(s[left]);
            left++;
        }

        // Add current character
        seen.insert(s[right]);

        // Calculate current window length
        int windowLength = right - left + 1;

        // Update maximum answer
        ans = max(ans, windowLength);
    }

    return ans;
}

int main()
{
    string s;

    cout << "Enter string: ";
    cin >> s;

    cout << "Longest substring length: "
         << lengthOfLongestSubstring(s)
         << endl;

    return 0;
}