#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();

    int left = 0, right = m * n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        int row = mid / n;
        int col = mid % n;

        if (matrix[row][col] == target)
            return true;
        else if (matrix[row][col] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return false;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int target;
    cin >> target;

    if (searchMatrix(matrix, target))
        cout << "true";
    else
        cout << "false";

    return 0;
}