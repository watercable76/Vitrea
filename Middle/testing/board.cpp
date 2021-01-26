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
    board[0][1] = new Piece(4, 1, 0, true, 'N');
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
    board[7][0] = new Piece(5, 0, 7, false, 'r');
    board[7][1] = new Piece(4, 1, 7, false, 'n');
    board[7][2] = new Piece(3, 2, 7, false, 'b');
    board[7][3] = new Piece(2, 3, 7, false, 'q');
    board[7][4] = new Piece(1, 4, 7, false, 'k');
    board[7][5] = new Piece(3, 5, 7, false, 'b');
    board[7][6] = new Piece(4, 6, 7, false, 'n');
    board[7][7] = new Piece(5, 7, 7, false, 'r');
    //Black Pawns
    board[6][0] = new Piece(0, 0, 6, false, 'p');
    board[6][1] = new Piece(0, 1, 6, false, 'p');
    board[6][2] = new Piece(0, 2, 6, false, 'p');
    board[6][3] = new Piece(0, 3, 6, false, 'p');
    board[6][4] = new Piece(0, 4, 6, false, 'p');
    board[6][5] = new Piece(0, 5, 6, false, 'p');
    board[6][6] = new Piece(0, 6, 6, false, 'p');
    board[6][7] = new Piece(0, 7, 6, false, 'p');
    
    //Test Pieces
    //board[0][1] = new Piece(6, 1, 0, false, '?'); // Knight with EA
}

Board::~Board()
{
    for (int y = 0; y < 8; y++) for (int x = 0; x < 8; x++) if (board[y][x]) delete board[y][x];
    capturesWhite.clear();
    capturesBlack.clear();
}

void Board::display(Point perspective)
{
    char highlight;
    std::cout << ",---,---,---,---,---,---,---,---,\n";
    for (int y = 7; y >= 0; y--)
    {
        std::cout << y;
        for (int x = 0; x < 8; x++)
        {
            if (perspective > Point(-1, -1) && perspective < Point(8, 8))
                if (board[perspective.y][perspective.x])
                    if (canMove(Point(x, y), perspective))
                        highlight = '-';
                    else
                        highlight = ' ';
                else
                    highlight = ' ';
            else
                highlight = ' ';
            if (board[y][x])
                std::cout << highlight << board[y][x]->name << highlight << "|";
            else
                std::cout << highlight << " " << highlight << "|";
        }
        std::cout << "\n";
        if (y != 0)
            std::cout << "}---+---+---+---+---+---+---+---{\n";
        else
            std::cout << "'-0-'-1-'-2-'-3-'-4-'-5-'-6-'-7-'\n";
    }
}

bool Board::canMove(Point to, Point from)
{
    Piece * fmP = board[from.y][from.x];
    Piece * toP = board[to.y][to.x];
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
        Point dir = to - from;
        if (dir.x >= 0) {dir.x =  1;}
        else            {dir.x = -1;}
        if (dir.y >= 0) {dir.y =  1;}
        else            {dir.y = -1;}
        
        int  reversePath      = -1;
        bool pathClear        = true;
        bool pathClearReverse = true;
        
        for (int m = 1; m <= path->magnitude && reversePath == -1; m++)
        {
            Point there         = from + (dir * Point(m, m) * path->slope          );
            Point thereReversed = from + (dir * Point(m, m) * path->slope.reverse());
            
            if      (there         == to)
                reversePath = 0;
            else if (thereReversed == to)
                reversePath = 1;
            else
            {
                if (board[there        .y][there        .x] && !fmP->canJump())
                    pathClear        = false;
                if (board[thereReversed.y][thereReversed.x] && !fmP->canJump())
                    pathClearReverse = false;
            }
        }
        delete path;
        return (!reversePath && pathClear) || (reversePath && pathClearReverse);
    }
    
    delete path;
    return false;
}

int Board::move(Point to, Point from, bool whiteTurn)
{
    if (to   < Point(0, 0) || to   > Point(7, 7) ||
        from < Point(0, 0) || from > Point(7, 7))
        return 1; // Something is out of bounds
    
    if (!board[from.y][from.x])
        return 2; // No piece at "from"
    
    if (board[from.y][from.x]->isWhite() != whiteTurn)
        return 3; // Piece does not belong to player
    
    if (!canMove(to, from))
        return 4; // Illegal move
    
    Piece * fmP = board[from.y][from.x];
    board[from.y][from.x] = NULL;
    
    if (board[to.y][to.x])
    {
        if (fmP->isWhite())
            capturesWhite.push_back(board[to.y][to.x]);
        else
            capturesBlack.push_back(board[to.y][to.x]);
    }
    board[to.y][to.x] = fmP;
    fmP->move(to);
    
    return 0;
}
