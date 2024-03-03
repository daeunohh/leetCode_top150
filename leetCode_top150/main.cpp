#include "main.h"

class Solution {
public:
    int totalSz = 0;
    vector<vector<int>>* grid;

    bool isLeaf(int x, int y, int sz) {
        int defaultValue = (*grid)[x][y];
        for (int i = x; i < x + sz; i++) {
            for (int j = y; j < y + sz; j++) {
                if ((*grid)[i][j] != defaultValue) return false;
            }
        }
        return true;
    }

    Node* check(int x, int y, int sz) {
        Node* head = new Node();
        head->isLeaf = isLeaf(x, y, sz);
        // std::cout << head->isLeaf << std::endl;
        if (head->isLeaf) {
            head->val = (*grid)[x][y];
            return head;
        }

        head->topLeft = check(x, y, sz / 2);
        head->bottomLeft = check(x + sz / 2, y, sz / 2);
        head->topRight = check(x, y + sz / 2, sz / 2);
        head->bottomRight = check(x + sz / 2, y + sz / 2, sz / 2);

        return head;
    }

    Node* construct(vector<vector<int>>& grid) {
        this->grid = &grid;
        totalSz = grid.size();
        return check(0, 0, totalSz);
    }
};




