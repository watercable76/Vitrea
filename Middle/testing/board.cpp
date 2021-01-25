//
//  board.cpp
//  testing
//
//  Created by Brendan Koetting on 1/24/21.
//

#include "board.hpp"

Board::Board()
{
    for (int x = 0; x < 8; x++)
        for (int y = 0; y < 8; y++)
            board[y][x] = NULL;
    
    //White Pieces
    board[0][0] = new Piece(5, 0, 0, true, 'R');
    board[0][1] = new Piece(6, 1, 0, true, 'N');
    board[0][2] = new Piece(3, 2, 0, true, 'B');
    board[0][3] = new Piece(2, 3, 0, true, 'Q');
    board[0][4] = new Piece(1, 4, 0, true, 'K');
    board[0][5] = new Piece(3, 5, 0, true, 'B');
    board[0][6] = new Piece(4, 6, 0, true, 'N');
    board[0][7] = new Piece(5, 7, 0, true, 'R');
    //White Pawns
    board[1][0] = new Piece(0, 0, 1, true, 'P');
    board[1][1] = new Piece(0, 1, 1, true, 'P');
    board[1][2] = new Piece(0, 2, 1, true, 'P');
    board[1][3] = new Piece(0, 3, 1, true, 'P');
    board[1][4] = new Piece(0, 4, 1, true, 'P');
    board[1][5] = new Piece(0, 5, 1, true, 'P');
    board[1][6] = new Piece(0, 6, 1, true, 'P');
    board[1][7] = new Piece(0, 7, 1, true, 'P');
    
    //Black Pieces
    board[7][0] = new Piece(5, 0, 7, false, 'R');
    board[7][1] = new Piece(4, 1, 7, false, 'N');
    board[7][2] = new Piece(3, 2, 7, false, 'B');
    board[7][3] = new Piece(2, 3, 7, false, 'Q');
    board[7][4] = new Piece(1, 4, 7, false, 'K');
    board[7][5] = new Piece(3, 5, 7, false, 'B');
    board[7][6] = new Piece(4, 6, 7, false, 'N');
    board[7][7] = new Piece(5, 7, 7, false, 'R');
    //Black Pawns
    board[6][0] = new Piece(0, 0, 6, false, 'P');
    board[6][1] = new Piece(0, 1, 6, false, 'P');
    board[6][2] = new Piece(0, 2, 6, false, 'P');
    board[6][3] = new Piece(0, 3, 6, false, 'P');
    board[6][4] = new Piece(0, 4, 6, false, 'P');
    board[6][5] = new Piece(0, 5, 6, false, 'P');
    board[6][6] = new Piece(0, 6, 6, false, 'P');
    board[6][7] = new Piece(0, 7, 6, false, 'P');
}

Board::~Board()
{
    for (int y = 0; y < 8; y++) for (int x = 0; x < 8; x++) if (board[y][x]) delete board[y][x];
}

void Board::display(Point perspective)
{
    char highlight;
    std::cout << ",---,---,---,---,---,---,---,---,\n";
    for (int y = 7; y >= 0; y--)
    {
        std::cout << "|";
        for (int x = 0; x < 8; x++)
        {
            if (perspective != Point(-1, -1))
                if (canMove(Point(x, y), perspective))
                    
            if (board[y][x])
                std::cout << " " << board[y][x]->name << " |";
            else
                if (perspective != Point(-1, -1))
                    if (canMove(Point(x, y), perspective))
                        std::cout << " X |";
                    else
                        std::cout << "   |";
                else
                    std::cout << "   |";
        }
        std::cout << "\n";
        if (y != 0)
            std::cout << "}---+---+---+---+---+---+---+---{\n";
        else
            std::cout << "'---'---'---'---'---'---'---'---'\n";
    }
}

bool Board::checkPath(Point to, Point from, MovementStyle ms, Piece * p)
{
    Point dir = to - from;
    if (dir.x >= 0) {dir.x =  1;}
    else            {dir.x = -1;}
    if (dir.y >= 0) {dir.y =  1;}
    else            {dir.y = -1;}
    
    bool reversePath      = true;
    bool pathClear        = true;
    bool pathClearReverse = true;
    
    for (int m = 1; m <= ms.magnitude; m++)
        if      (from + (dir * Point(m, m) * ms.slope          ) == to)
            reversePath = false;
        else if (from + (dir * Point(m, m) * ms.slope.reverse()) == to)
            reversePath = true;
        else
            if      (board[(from + (dir * Point(m, m) * ms.slope          )).y]
                          [(from + (dir * Point(m, m) * ms.slope          )).x] &&
                          !p->canJump())
                pathClear        = false;
            else if (board[(from + (dir * Point(m, m) * ms.slope.reverse())).y]
                          [(from + (dir * Point(m, m) * ms.slope.reverse())).x] &&
                          !p->canJump())
                pathClearReverse = false;
            
    return (!reversePath && pathClear) || (reversePath && pathClearReverse);
}

bool Board::canMove(Point to, Point from)
{
    Piece * fmP = board[from.y][from.x];
    Piece * toP = board[to.y  ][to.y  ];
    MovementStyle * path;
    
    if (toP)
        if (toP->isWhite() == fmP->isWhite())
            return false;
        else
            path = fmP->isValidMove(to, true);
    else
        path = fmP->isValidMove(to);
        
    if (path)
    {
        bool clear = checkPath(to, from, *path, fmP);
        delete path;
        return clear;
    }
    
    delete path;
    return false;
}
