//
//  pieces.cpp
//  testing
//
//  Created by Brendan Koetting on 1/19/21.
//

#include "pieces.hpp"

MovementStyle * Piece::isValidMove(Point move, bool take)
{
    // A piece cannot move to a square it already occupies.
    if (move == position)
        return NULL;
    
    // Create a copy of movementStyle to be edited by various abilities.
    // This is to prevent harm to the piece's "true" movement style.
    std::vector<MovementStyle> ms = movementStyle;
    
    // Determine the direction the piece is attempting to move.
    Point direction = move - position;
    if      (direction.x > 0) {direction.x =  1;}
    else if (direction.x < 0) {direction.x = -1;}
    else                      {direction.x =  0;}
    if      (direction.y > 0) {direction.y =  1;}
    else if (direction.y < 0) {direction.y = -1;}
    else                      {direction.y =  0;}
    
    if (take) // -------------------------------------------------------------------------------- Capture Abilities ----------
    {
        /*
         sideStep (Capture)
          - lineage  : Pawn
          - function : Movement Styles that usually capture diagonally now capture horizontally,
                       and vice-versa. Does not effect other capture methods. (i.e., bishop
                       now captures like a rook, but still moves like a bishop. Knights
                       unaffected.)
         */
        if (sideStep)
        {
            std::vector<MovementStyle> hold;
            for (int i = 0; i < movementStyle.size(); i++)
                if      (movementStyle[i].slope == Point(1, 1))
                     hold.push_back(MovementStyle(1, 0, movementStyle[i].magnitude));
                else if (movementStyle[i].slope == Point(1, 0) ||
                         movementStyle[i].slope == Point(0, 1))
                     hold.push_back(MovementStyle(1, 1, movementStyle[i].magnitude));
                else hold.push_back(movementStyle[i]);
            ms = hold;
        }
    }
    else // ------------------------------------------------------------------------------ Movement (Non-Capture) Abilities --
    {
        /*
         earlyAcceleration (Movement)
          - lineage  : Pawn
          - function : On a piece's first move, magnitude  of all movement styles is increased
                       by one.
         */
        if (earlyAccel && !hasMoved)
            for (int i = 0; i < ms.size(); i++)
                ms[i].magnitude += 1;
    }
    
    // ------------------------------------------------------------------------------------------ Passive Abilities ----------
    /*
     forwardMarch (Passive)
      - lineage  : Pawn
      - function : Restricts all movement to the forwards direction. If a piece attempts to move
                   sideways or backwards, it cannot move.
     */
    if (forwardMarch)
    {
        if ( white && direction.y !=  1)
            return NULL;
        if (!white && direction.y != -1)
            return NULL;
    }
    
    // -----------------------------------------------------------------------------------------------------------------------
    
    // Directions of 0 are not acceptable in the following formula, and are thus changed to
    // directions of positive one.
    if (direction.x == 0) {direction.x = 1;}
    if (direction.y == 0) {direction.y = 1;}
    
    // After all abilities are activated, check to see if the piece can move to the desired
    // destination using any of its various movement styles.
    for (int i = 0; i < ms.size(); i++)
        for (int m = 1; m <= ms[i].magnitude; m++)
            if (position +  (ms[i].slope           * Point(m, m) * direction) == move ||
                position +  (ms[i].slope.reverse() * Point(m, m) * direction) == move)
                return new MovementStyle(ms[i]);
    return NULL;
}

int presets[16][16] =
{
   //0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
    {1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1}, // 0 - Pawn
    {1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // 1 - King
    {1, 1, 1, 7, 1, 1, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0}, // 2 - Queen
    {1, 1, 1, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 3 - Bishop
    {1, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, // 4 - Knight
    {1, 1, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 5 - Rook
    {1, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0}  // 6 - Knight w/ ea
    
    //0 - MovementStyleOneExists
    //1 - MovementStyleOneSlopeX
    //2 - MovementStyleOneSlopeY
    //3 - MovementStyleOneMagnitude
    //4 - MovementStyleTwoExists
    //5 - MovementStyleTwoSlopeX
    //6 - MovementStyleTwoSlopeY
    //7 - MovementStyleTwoMagnitude
    //8 - MovementStyleThreeExists
    //9 - MovementStyleThreeSlopeX
    //A - MovementStyleThreeSlopeY
    //B - MovementStyleThreeMagnitude
    //C - CanJump
    //D - CanEarlyAccellerate
    //E - CanSideStep
    //F - CanForwardMarch
    
};


void Piece::load(int id)
{
    if (id == -1)
        return;
    
    for (int i = 0; i < 3; i++)
        if (presets[id][0 + 4 * i])
            movementStyle.push_back(MovementStyle(presets[id][1 + 4 * i], presets[id][2 + 4 * i], presets[id][3 + 4 * i]));
    
    jump         = presets[id][12];
    earlyAccel   = presets[id][13];
    forwardMarch = presets[id][14];
    sideStep     = presets[id][15];
    
}
