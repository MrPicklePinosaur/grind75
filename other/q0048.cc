
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose matrix
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i; j < matrix.size(); ++j) {
                // swap
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        // reverse each row
        for (int i = 0; i < matrix.size(); ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix.size(); ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        } 
    }

};
