
#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <string>

class Board {
public:
    Board();
    void print() const;
    void place_queens();
private:
    bool check_place(const int row, const int col) const;
    std::vector<std::string> board;
    unsigned board_size;
};

#endif
