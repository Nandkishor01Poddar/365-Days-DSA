#include <iostream>
#include <string>
using namespace std;

// Function to check whether a character is a vowel
bool isVowel(char ch)
{
    return ch == 'a' || ch == 'e' || ch == 'i' ||
           ch == 'o' || ch == 'u';
}

// Function to find the maximum number of vowels
// in any substring of length k
int maxVowels(string s, int k)
{
    int n = s.length();

    // Count vowels in the first window
    int vowelCount = 0;

    for (int i = 0; i < k; i++)
    {
        if (isVowel(s[i]))
            vowelCount++;
    }

    // Initialize answer
    int ans = vowelCount;

    // Slide the window
    for (int i = k; i < n; i++)
    {
        // Remove outgoing character
        if (isVowel(s[i - k]))
            vowelCount--;

        // Add incoming character
        if (isVowel(s[i]))
            vowelCount++;

        // Update maximum vowels
        ans = max(ans, vowelCount);
    }

    return ans;
}

int main()
{
    string s;
    int k;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter window size (k): ";
    cin >> k;

    // Edge Case
    if (k > s.length())
    {
        cout << "Window size cannot be greater than string length." << endl;
        return 0;
    }

    cout << "\nMaximum Number of Vowels = "
         << maxVowels(s, k) << endl;

    return 0;
}