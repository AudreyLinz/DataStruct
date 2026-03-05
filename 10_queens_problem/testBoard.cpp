
#include "Board.hpp"

int main(void) {
    Board chess;
    chess.print();
    chess.place_queens();
    chess.print();
    return 0;
}
