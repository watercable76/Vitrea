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
    Piece p = *Piece(5).toWhite()->place(3, 4);
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
    
    Point input;
    while (true)
    {
        std::cout << "x : ";
        std::cin >> input.x;
        std::cout << "y : ";
        std::cin >> input.y;
        b.display(input);
    }
    
    return 0;
}
