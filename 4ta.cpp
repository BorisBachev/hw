#include <iostream>

using namespace std;

const int MAX_ROWS = 100;
const int MAX_COLS = 100;

void modifyMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols, int result[MAX_ROWS][MAX_COLS]) {

    for (int col = 0; col < cols; ++col) {
        int shift = (col + 1) % rows;

        for (int row = 0; row < rows; ++row) {
            int newRow = (row + shift) % rows;
            result[newRow][col] = matrix[row][col];
        }
        
    }

}

int main() {

    int rows = 4, cols = 3;
    int matrix[MAX_ROWS][MAX_COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    };

    int result[MAX_ROWS][MAX_COLS];

    modifyMatrix(matrix, rows, cols, result);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
