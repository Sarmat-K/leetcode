// Solution for problem 36 : Valid Sudoku
// Difficulty: Medium
// Topics: Array, Hash Table , Matrix

// Your solution code goes here.

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0 ; i < board.size();i++){
            unordered_map<char, int> table;
            for(int j = 0; j < board.size(); j++){
                table[board[i][j]]++;
                if (table[board[i][j]] > 1 && board[i][j] != '.')
                    return false;
            }
        }
        for(int i = 0 ; i < board.size();i++){
            unordered_map<char, int> table;
            for(int j = 0; j < board.size(); j++){
                table[board[j][i]]++;
                if (table[board[j][i]] > 1 && board[j][i] != '.')
                    return false;
            }
        }

        for (int row = 0; row < board.size(); row += 3) {
            for (int col = 0; col < board.size(); col += 3) {
                unordered_map<char, int> table;
                for (int i = row; i < row + 3; i++) {
                    for (int j = col; j < col + 3; j++) {
                        if (board[i][j] != '.') {
                            table[board[i][j]]++;
                            if (table[board[i][j]] > 1) {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;       
    }
};

// разеб написал код лучше чем gpt