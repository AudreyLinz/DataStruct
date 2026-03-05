#include "Board.hpp"
#include <string>
#include <iostream>

Board::Board() {
    board_size = 8;
    std::string row(board_size, ' ');
    for(int i = 0; i < board_size; i++) {
    board.push_back(row);
    }
}

void Board::print() const {
    int i = 0;
    int j = board_size;
    std::cout << " ________\n";

    while (i < board_size) {
        std::cout << j << '|' << board[i] << '|' << std::endl;
        i++;
        j--;
    }

    std::cout << " --------\n";
    std::cout << " abcdefgh\n";
}

void Board::place_queens() {
}

bool has_char(const std::string& s, const char c, int n) {
    for(int i = 0; i < n; i++) {
        if (s[i] == c) {
            return true;
        }
    }
    return false;
}

bool Board::check_place(const int row, const int col) const {
    //NS
    int i = 0;
    int j = col;
    while (i < board_size) {
        if (board[i][j] == '*' && (i != row || j != col)) {
            return false;
        }
    i++;
    }
    i = row;
    j = col;
    //NE
    while (i >= 0 && j < board_size) {
        if (board[i][j] == '*' && (i != row || j != col)) {
            return false;
        }
    i--;
    j++;
    }
    i = row;
    j = 0;
    //WE
    while (j < board_size) {
        if (board[i][j] == '*' && (i != row || j != col)) {
            return false;
    }
    j++;
    }
//SE
    i = row;
    j = col;
    while (i < board_size && j < board_size) {
        if (board[i][j] == '*' && (i != row || j != col)) {
    return false;
    }
    j++;
    i++;
    }
    i = row;
    j = col;
    //SW
    while (i < board_size && j >= 0) {
        if (board[i][j] == '*' && (i != row || j != col)) {
            return false;
        }
        j--;
        i++;
    }
    //NW
    i = row;
    j = col;
    while (i >= 0 && j >= 0) {
        if (board[i][j] == '*' && (i != row || j != col)) {
            return false;
        }
        j--;
        i--;
    }
    return true;
}
