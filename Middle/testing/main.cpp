//
//  main.cpp
//  testing
//
//  Created by Brendan Koetting on 1/19/21.
//

#include <iostream>
#include <vector>
#include "pieces.hpp"
#include "point.hpp"
#include "board.hpp"

void test()
{
    std::cout << "Begin test.\n\n";
    
    std::cout << "Creating Testing Board.\n";
    
    bool test[8][8] =
    {
        {0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0},
        {1, 1, 1, 0, 1, 1, 1, 1},
        {0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0}
    };
    
    std::cout << "Creating a Rook at 3, 4.\n";
    Piece p = Piece(5, 3, 4, true, 'R');
    std::cout << "Commencing test.\n";
    int failures = 0;
    bool take = false;
    for (int x = 0; x < 8; x++)
    {
        for (int y = 0; y < 8; y++)
        {
            if (test[y][x] && p.isValidMove(Point(x, y), take))  {}
            else if (!test[y][x] && !p.isValidMove(Point(x, y), take)) {}
            else
            {
                failures++;
                std::cout << "Failed at " << x << ", " << y << ".\n";
                std::cout << " > Returned " << p.isValidMove(Point(x, y), take) << "\n";
                std::cout << " > Expected " << test[y][x] << "\n";
            }
        }
    }
    std::cout << "Test complete with " << failures << " failures.\n";
}

int main()
{
    Board b;
    
    Point to;
    Point from;
    bool turn = true;
    int error;
    while (true)
    {
        b.display();
        std::cout << "select a piece\n";
        std::cout << "x y : ";
        std::cin >> from.x;
        std::cin >> from.y;
        b.display(from);
        std::cout << "select a destination\n";
        std::cout << "x y : ";
        std::cin >> to.x;
        std::cin >> to.y;
        error = b.move(to, from, turn);
        if (error)
            switch (error)
            {
                case 1:
                    std::cout << "Cannot Move : Out of bounds.\n";
                    break;
                case 2:
                    std::cout << "Cannot Move : No piece found.\n";
                    break;
                case 3:
                    std::cout << "Cannot Move : Piece does not belong to player.\n";
                    break;
                case 4:
                    std::cout << "Cannot Move : Illegal move.\n";
                    break;
                default:
                    std::cout << "Cannot Move : Unknown.\n";
                    break;
            }
        else turn = !turn;
    }
    
    return 0;
}
