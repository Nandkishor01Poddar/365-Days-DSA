#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int totalFruit(vector<int>& fruits)
{
    unordered_map<int, int> freq;

    int left = 0;
    int ans = 0;

    for (int right = 0; right < fruits.size(); right++)
    {
        // Add current fruit
        freq[fruits[right]]++;

        // Shrink while more than 2 types exist
        while (freq.size() > 2)
        {
            // Remove leftmost fruit
            freq[fruits[left]]--;

            // Remove fruit type when frequency becomes zero
            if (freq[fruits[left]] == 0)
            {
                freq.erase(fruits[left]);
            }

            left++;
        }

        // Update maximum window length
        ans = max(ans, right - left + 1);
    }

    return ans;
}

int main()
{
    int n;

    cout << "Enter array size: ";
    cin >> n;

    vector<int> fruits(n);

    cout << "Enter fruit types: ";

    for (int i = 0; i < n; i++)
    {
        cin >> fruits[i];
    }

    cout << "Maximum fruits collected: "
         << totalFruit(fruits)
         << endl;

    return 0;
}