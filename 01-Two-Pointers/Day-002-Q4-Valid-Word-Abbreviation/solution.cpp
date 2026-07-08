#include <iostream>
#include <cctype> // For isdigit()
using namespace std;

// ================= Method 1: Two Pointer =================
// T.C: O(n + m), S.C: O(1)
bool validWordAbbreviation(string word, string abbr)
{
    int i = 0, j = 0;

    while (i < word.size() && j < abbr.size())
    {
        // If current abbreviation character is a digit
        if (isdigit(abbr[j]))
        {
            // Leading zero is invalid
            if (abbr[j] == '0')
                return false;

            int num = 0;

            // Form the complete number
            while (j < abbr.size() && isdigit(abbr[j]))
            {
                num = num * 10 + (abbr[j] - '0');
                j++;
            }

            // Skip 'num' characters in the original word
            i += num;
        }
        else
        {
            // Characters must match
            if (word[i] != abbr[j])
                return false;

            i++;
            j++;
        }
    }

    return (i == word.size() && j == abbr.size());
}

// ================= Main =================
int main()
{
    string word, abbr;

    cout << "Enter the original word: ";
    cin >> word;

    cout << "Enter the abbreviation: ";
    cin >> abbr;

    if (validWordAbbreviation(word, abbr))
        cout << "Valid Abbreviation" << endl;
    else
        cout << "Invalid Abbreviation" << endl;

    return 0;
}