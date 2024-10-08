#include "bits/stdc++.h"
using namespace std;


/**
 * @brief 编写一个程序，通过填充空格来解决数独问题。

数独的解法需 遵循如下规则：

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
数独部分空格内已填入了数字，空白格用 '.' 表示。c
 * 
 */
class Solution {
    int cnt = 0;
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool res = backtrace(board);
        cout << res << endl;
    }

    bool backtrace(vector<vector<char>>& board) {

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == '.') {
                    for (char ch = '1'; ch <= '9'; ++ch) {
                        if (check(board, i, j, ch)) {
                            board[i][j] = ch;
                            if (backtrace(board)) {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool check(vector<vector<char>>& board, int x, int y, char ch) {
        for (int i = 0; i < 9; ++i) {
            if (ch == board[x][i] || ch == board[i][y]) {
                return false;
            }
        }

        // 所属于的9个格子内也需要满足9个数字唯一
        int row = x / 3;
        int col = y / 3;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int a = row * 3 + i;
                int b = col * 3 + j;
                if (board[a][b] == ch) {
                    return false;
                }
            }
        }

        return true;
    }
};


class Game {
    int cnt = 0;
public:
    void solveSudoku(vector<string>& board) {
        bool res = backtrace(board);
        cout << res << endl;
    }

    bool backtrace(vector<string>& board) {

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == '.') {
                    for (char ch = '1'; ch <= '9'; ++ch) {
                        if (check(board, i, j, ch)) {
                            board[i][j] = ch;
                            if (backtrace(board)) {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool check(vector<string>& board, int x, int y, char ch) {
        for (int i = 0; i < 9; ++i) {
            if (ch == board[x][i] || ch == board[i][y]) {
                return false;
            }
        }

        // 所属于的9个格子内也需要满足9个数字唯一
        int row = x / 3;
        int col = y / 3;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int a = row * 3 + i;
                int b = col * 3 + j;
                if (board[a][b] == ch) {
                    return false;
                }
            }
        }

        return true;
    }
};