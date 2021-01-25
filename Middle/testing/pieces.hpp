//
//  pieces.hpp
//  testing
//
//  Created by Brendan Koetting on 1/19/21.
//

#ifndef pieces_hpp
#define pieces_hpp

#include <vector>
#include "point.hpp"

class MovementStyle
{
public:
    // Constructors
    MovementStyle(Point s    ,            int m    ) : slope(s          ), magnitude(m) {}
    MovementStyle(int   x = 0, int y = 0, int m = 0) : slope(Point(x, y)), magnitude(m) {}
    MovementStyle(const MovementStyle &that) {this->slope = that.slope; this->magnitude = that.magnitude;}
    
    Point slope;
    int   magnitude;
};

class Piece
{
protected:
    // Location
    Point position;
    bool  white;
    bool  hasMoved;
    
    // Movement Styles
    std::vector<MovementStyle> movementStyle;

    // Abilities
    bool jump;          // Knight's jump
    bool earlyAccel;    // Pawn's two-move
    bool forwardMarch;  // Pawn's inability to move anywhere but forward
    bool sideStep;      // Pawn's Diagonal take
  //bool block;         // Blocking a Knight jump? Somehow?

    // Appearance
    /*
      - RGB values?
      - varying ids for body parts? i.e. int bodyType; int headType; etc.
     */
    
    // Save / Load
    // // PLACEHOLDER METHOD ONLY. DO NOT USE.
    void load(int id = -1);
    
public:
    // Public Constructor
    Piece(int id = -1) {hasMoved = false; load(id);}
    
    // Value Editing Methods
    // // Movement Styles
    void          addMovementStyle (Point s,         int m     )  {movementStyle.push_back(MovementStyle(s, m)) ;}
    void          addMovementStyle (int   x,  int y, int m     )  {addMovementStyle(Point(x, y), m)             ;}
    // // Location
    Piece*        place            (Point pos                  )  {position = pos                  ; return this;}
    Piece*        place            (int   x,  int y            )  {position = Point(x, y)          ; return this;}
    Piece*        toWhite          (                           )  {white  = true                 ; return this;}
    Piece*        toBlack          (                           )  {white  = false                ; return this;}
    
    // Value Collection Methods
    long                       MSCount                   (     )  {return movementStyle.size()                  ;}
    MovementStyle              getMovementStyle          (int i)  {return movementStyle[i]                      ;}
    std::vector<MovementStyle> getAllMovementStyles      (     )  {return movementStyle                         ;}
    bool                       isFirstMove               (     )  {return hasMoved                              ;}
    bool                       isWhite                   (     )  {return white                                 ;}
    // // Ability Checks
    bool                       canJump                   (     )  {return jump                                  ;}
    bool                       canEarlyAccel             (     )  {return earlyAccel                            ;}
    bool                       canForwardMarch           (     )  {return forwardMarch                          ;}
    bool                       canSideStep               (     )  {return sideStep                              ;}
    
    
    // Movement Methods
    MovementStyle * isValidMove    (Point move      , bool take = false);
    MovementStyle * isValidMove    (int   x,   int y, bool take = false)  {return isValidMove(Point(x, y), take);}
    void            move           (Point pos                  )  {position = pos              ; hasMoved = true;}
    void            move           (int   x,  int y            )  {position = Point(x, y)      ; hasMoved = true;}
    
    // TESTING ONLY, NOT TO BE USED.
    char name;
    Piece* n(char x) {name = x; return this;}
    Piece(int id, int x, int y, bool isWhite, char n) : position(Point(x, y)), white(isWhite), name(n)
    {hasMoved = false; load(id);}
};

#endif /* pieces_hpp */
