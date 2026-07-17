#include <iostream>
#include <unordered_set>
using namespace std;

/*
==========================================
Problem:
Given an integer n, determine whether it is
a Happy Number.

A happy number eventually reaches 1 after
repeatedly replacing the number by the sum
of the squares of its digits.

Example:
19
1² + 9² = 82
8² + 2² = 68
6² + 8² = 100
1² + 0² + 0² = 1

Output: Happy Number
==========================================
*/


//------------------------------------------------------------
// Function to calculate sum of squares of digits
//------------------------------------------------------------
int sumOfSqDigit(int n)
{
    int sum = 0;

    while (n > 0)
    {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }

    return sum;
}

/*
=============================================================
Brute Force Approach (Using HashSet)

Idea:
Store every generated number.
If a number repeats, then a cycle exists.
Hence, it is NOT a happy number.

Time Complexity:
O(log n)

Space Complexity:
O(log n)
=============================================================
*/

bool isHappyBrute(int n)
{
    unordered_set<int> visited;

    while (n != 1)
    {
        if (visited.count(n))
            return false;

        visited.insert(n);

        n = sumOfSqDigit(n);
    }

    return true;
}


/*
=============================================================
Optimal Approach (Floyd Cycle Detection)

Idea:
Treat sequence as a linked list.

Slow Pointer:
Moves one step.

Fast Pointer:
Moves two steps.

If fast reaches 1
=> Happy Number

If slow == fast
=> Cycle detected
=> Not Happy

Time Complexity:
O(log n)

Space Complexity:
O(1)
=============================================================
*/

bool isHappyOptimal(int n)
{
    int slow = n;
    int fast = n;

    while (true)
    {
        // Move slow by one step
        slow = sumOfSqDigit(slow);

        // Move fast by two steps
        fast = sumOfSqDigit(sumOfSqDigit(fast));

        if (fast == 1)
            return true;

        if (slow == fast)
            return false;
    }
}

int main()
{
    int t;

    cout << "Enter number of test cases: ";
    cin >> t;

    while (t--)
    {
        int n;

        cout << "\nEnter Number: ";
        cin >> n;

        cout << "Brute Force : ";

        if (isHappyBrute(n))
            cout << "Happy Number\n";
        else
            cout << "Not Happy Number\n";

        cout << "Optimal     : ";

        if (isHappyOptimal(n))
            cout << "Happy Number\n";
        else
            cout << "Not Happy Number\n";
    }

    return 0;
}