//
//  board.hpp
//  testing
//
//  Created by Brendan Koetting on 1/24/21.
//

#ifndef board_hpp
#define board_hpp

#include <iostream>
#include <vector>
#include "pieces.hpp"
#include "point.hpp"

class Board
{
private:
    
    Piece * board[8][8];
    
public:
    Board();
    ~Board();
    
    void display    (Point perspective = Point(-1, -1));
    
    bool canMove    (Point to, Point from);
    bool checkPath  (Point to, Point from, MovementStyle ms, Piece * p);
};

#endif /* board_hpp */
