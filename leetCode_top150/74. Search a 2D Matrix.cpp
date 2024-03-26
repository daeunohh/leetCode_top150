#include "main.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowIdx = 0; int colIdx = 0;
        
        int first = 0; int last = matrix.size() - 1;
        while (last >= first) {
            int middle = (last + first) / 2;
            if (matrix[middle][0] <= target && matrix[middle][matrix[0].size() - 1] >= target) {
                rowIdx = middle;
                break;
            }


            if (target < matrix[middle][0]) {
                last = middle - 1;
            }
            else {
                first = middle + 1;
            }
        }
        
        cout << rowIdx << endl;

        first = 0; last = matrix[0].size() - 1;
        while (last >= first) {
            int middle = (last + first) / 2;
            if (matrix[rowIdx][middle] == target) return true;

            if (matrix[rowIdx][middle] > target) {
                last = middle - 1;
            }
            else {
                first = middle + 1;
            }
        }

        return (matrix[0][0] == target);
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = { {1}, {3} };
    s.searchMatrix(matrix, 3);
}