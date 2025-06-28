#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

double myPow(double x, int n) 
{
    if(n==0)
        return 1.0;
    return x*myPow(x,n-1);
}
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check rows and columns
        for (int i = 0; i < 9; ++i) {
            unordered_set<char> rowSet, colSet;
            for (int j = 0; j < 9; ++j) {
                // Row check
                if (board[i][j] != '.') {
                    if (rowSet.count(board[i][j]))
                        return false;
                    rowSet.insert(board[i][j]);
                }
                // Column check
                if (board[j][i] != '.') {
                    if (colSet.count(board[j][i]))
                        return false;
                    colSet.insert(board[j][i]);
                }
            }
        }

        // Check 3x3 boxes
        for (int boxRow = 0; boxRow < 9; boxRow += 3) {
            for (int boxCol = 0; boxCol < 9; boxCol += 3) {
                unordered_set<char> boxSet;
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        char val = board[boxRow + i][boxCol + j];
                        if (val != '.') {
                            if (boxSet.count(val))
                                return false;
                            boxSet.insert(val);
                        }
                    }
                }
            }
        }

        return true;
    }
};

int main()
{
    int i; double j;
    cout<<"Enter base";
    cin>>j;
    cout<<"Enter power";
    cin>>i;
    cout<<"Result of "<<j<<" raised to the power "<<i<<" is: ";
    cout<< myPow(j,i) <<endl;
}
