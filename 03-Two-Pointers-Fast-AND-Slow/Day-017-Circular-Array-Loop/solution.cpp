#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int nextIndex(vector<int>& nums, int i) {
        int n = nums.size();
        return ((i + nums[i]) % n + n) % n;
    }

    bool circularArrayLoop(vector<int>& nums) {

        int n = nums.size();

        for (int i = 0; i < n; i++) {

            if (nums[i] == 0)
                continue;

            bool forward = nums[i] > 0;

            cout << "\n---------------------------------\n";
            cout << "Starting from index : " << i << endl;
            cout << "Direction : " << (forward ? "Forward" : "Backward") << endl;

            int slow = i;
            int fast = i;

            while (true) {

                int nextSlow = nextIndex(nums, slow);

                if ((nums[nextSlow] > 0) != forward) {
                    cout << "Slow changed direction.\n";
                    break;
                }

                int nextFast = nextIndex(nums, fast);

                if ((nums[nextFast] > 0) != forward) {
                    cout << "Fast changed direction.\n";
                    break;
                }

                nextFast = nextIndex(nums, nextFast);

                if ((nums[nextFast] > 0) != forward) {
                    cout << "Fast changed direction.\n";
                    break;
                }

                slow = nextSlow;
                fast = nextFast;

                cout << "Slow = " << slow
                     << " , Fast = " << fast << endl;

                if (slow == fast) {

                    if (slow == nextIndex(nums, slow)) {
                        cout << "Self-loop found. Invalid.\n";
                        break;
                    }

                    cout << "Valid Cycle Found!\n";
                    return true;
                }
            }

            // Mark visited nodes
            int curr = i;

            while ((nums[curr] > 0) == forward) {

                int nxt = nextIndex(nums, curr);

                cout << "Marking index " << curr << " as visited.\n";

                nums[curr] = 0;

                if (curr == nxt)
                    break;

                curr = nxt;
            }
        }

        return false;
    }
};

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements:\n";

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    Solution obj;

    bool ans = obj.circularArrayLoop(nums);

    cout << "\nFinal Answer : ";

    if (ans)
        cout << "True";
    else
        cout << "False";

    return 0;
}