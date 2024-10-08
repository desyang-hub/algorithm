#include "bits/stdc++.h"
#include "./backtrack/37_sudoku-solver.cpp"
#include "./link-list/707_design-linked-list.cpp"
using namespace std;

int main() {

    // map<int, int> mp;
    // mp[1] = 3;
    // mp[4] = 4;
    // mp[3] = 5;

    // for (auto &item : mp) {
    //     cout << item.first << " " << item.second << endl;
    // }


    // vector<int> a = {1,2, 34};
    // sort(a.begin(), a.end(), greater<int>());


    // cout << a.front() << endl;

    // cout << string(4, '.') << endl;

    // vector<string> board = {
    //     "5.6.3...1",
    //     "7....1..2",
    //     ".1..8....",

    //     "69...4.87",
    //     "..15.3...",
    //     "23.96...4",

    //     ".5...7.2.",
    //     "..98..4..",
    //     "....9...."
    // };

    // Game game;
    // game.solveSudoku(board);
    // cout << "row: 0 123456789" << endl;
    // cout << endl;
    // for (int i = 0; i < board.size(); ++i) {
    //     cout << "row: " << i + 1 << " " << board[i] << endl;
    // }

    // unordered_set<int> st;

    // st.insert(1);
    // st.insert(2);

    // for (auto &item : st) {
    //     cout << item << endl;
    // }

    MyLinkedList list;
    list.addAtHead(0);
    cout << list << endl;
    list.addAtIndex(1, 4);
    cout << list << endl;
    list.addAtTail(8);
    cout << list << endl;
    list.addAtHead(5);
    cout << list << endl;
    list.addAtIndex(4, 3);
    cout << list << endl;
    list.addAtTail(0);
    cout << list << endl;
    list.addAtTail(5);
    cout << list << endl;
    list.addAtIndex(6, 3);
    cout << list << endl;
    list.deleteAtIndex(7);
    cout << list << endl;
    list.deleteAtIndex(5);
    cout << list << endl;
    list.addAtTail(4);
    cout << list << endl;


    return 0;
}