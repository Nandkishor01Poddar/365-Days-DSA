#include <iostream>
#include <vector>
using namespace std;

void inp(vector<int> &arr) {
    cout << "Enter array elements: ";
    for (int i = 0; i < arr.size(); i++) {
        cin >> arr[i];
    }
}

int countTheZero(vector<int> &arr) {

    int st = 0;
    int end = arr.size() - 1;
    int firstZero = arr.size();

    while (st <= end) {

        int mid = st + (end - st) / 2;

        if (arr[mid] == 1) {
            st = mid + 1;
        }
        else {
            firstZero = mid;
            end = mid - 1;
        }
    }

    return arr.size() - firstZero;
}

int main() {

    int num;

    cout << "Enter array size: ";
    cin >> num;

    vector<int> arr(num);

    inp(arr);

    cout << "Zero = " << countTheZero(arr);

    return 0;
}