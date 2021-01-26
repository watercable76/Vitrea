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
    
    Piece *              board[8][8];
    
    std::vector<Piece *> capturesWhite;
    std::vector<Piece *> capturesBlack;
    
public:
    Board();
    ~Board();
    
    void display    (Point perspective = Point(-1, -1));
    
    bool canMove    (Point to, Point from);
    int  move       (Point to, Point from, bool whiteTurn);
};

#endif /* board_hpp */
