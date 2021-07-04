/*
Given a N by M matrix of numbers, print out the matrix in a clockwise spiral.

For example, given the following matrix:

[[1,  2,  3,  4,  5],
 [6,  7,  8,  9,  10],
 [11, 12, 13, 14, 15],
 [16, 17, 18, 19, 20]]
You should print out the following:

1
2
3
4
5
10
15
20
19
18
17
16
11
6
7
8
9
14
13
12
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    void printClockWiseSpiral(vector<vector<int>> &matrix) {
        int end_row = matrix.size() - 1;
        if (!end_row) {
            return;
        }
        int end_col = matrix[0].size() - 1;
        int start_row = 0;
        int start_col = 0;

        while (start_row < end_row) {
            for (int j = start_col; j <= end_col; ++j)
                cout << matrix[start_row][j] << "\n";

            for (int i = start_row + 1; i <= end_row; ++i)
                cout << matrix[i][end_col] << "\n";

            for (int j = end_col - 1; j >= start_col; --j)
                cout << matrix[end_row][j] << "\n";

            for (int i = end_row - 1; i > start_row; --i)
                cout << matrix[i][start_col] << "\n";

            ++start_row; ++start_col;
            --end_row; --end_col;
        }

        if (start_row == end_row) {
            for (int j = start_col; j <= end_col; ++j)
                cout << matrix[start_row][j] << "\n";
        }
    }
};

int main() {
    vector<vector<int>> matrix {
            {1, 2, 3, 4, 5},
            {6, 7, 8, 9 , 10},
            {11, 12, 13, 14, 15},
            {16, 17, 18, 19, 20}
    };

    vector<vector<int>> matrix1{
            {1, 2, 3, 4, 5},
            {6, 7, 8, 9, 10},
            {11, 12, 13, 14, 15}
    };

    Solution s;
    cout << "MATRIX: \n";
    s.printClockWiseSpiral(matrix);
    cout << "MATRIX1: \n";
    s.printClockWiseSpiral(matrix1);
    return 0;
}
