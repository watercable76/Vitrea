using System.Collections;
using System.Collections.Generic;
using UnityEngine;

//note this is mostly cpp
class Point
{
    public int x;
    public int y;
    //initalizer for setting where the peice is and can go.
    public Point(int X, int Y) => x = X, 

}

//here on is c#
public class Abilities(){
    //var directions = new List<MovementStyle>{};

    //could make these like the attributes with dominance and ressessiveness...??
    bool jump;          // Knight's jump
    bool earlyAccel;    // Pawn's two-move
    bool forwardMarch;  // Pawn's inability to move anywhere but forward
    bool sideStep;      // Pawn's Diagonal take
    bool sacrificabilitiy; //Get to end of board and then get a new peice from your set or graveyard.
}

class Apperance(){
    /*
    must figure out how to alter strings/genomes without using list so we don't have
    to read through a list every single time we want to do something.
    */
    
    //first value = dominance, second = resessive, need to figure out co-dominance/recessive type genes for mixes
    val color_eye  = new List<string>{"123456", "789abc"};
    char size = "Tt";
    //actually just some int
    //A = Dominance, a = Resessive
    char style_head =  "FF";
    char style_body =  "Ff";
    char style_base =  "ff";
    //below is basically the id of the peice
    char piece_style = "Pawnid"; //recessive and Dominance for Piece sprite to be how it looks and where it can go on the board
}

class MovementStyle(){
    // Constructors
    MovementStyle(Point s,int m) : slope(s), magnitude(m) {};
    MovementStyle(int x = 0, int y = 0, int m = 0) : slope(Point(x, y)), magnitude(m) {};
    MovementStyle(const MovementStyle &that)
    {
        this->slope     = that.slope;
        this->magnitude = that.magnitude;
    }
    
    Point slope;
    int   magnitude;
}

class Piece(){
    Point position;
    bool hasMoved;

    void load(int id = -1);

    iece(int id = -1) {hasMoved = false; load(id);}
    
    // Value Editing Methods
    // // Movement Styles
    void addMovementStyle (Point s, int m)  {movementStyle.push_back(MovementStyle(s, m)) ;}
    void addMovementStyle (int x, int y, int m)  {addMovementStyle(Point(x, y), m);}
    // // Location
    Piece * place            (Point pos                  )  {position = pos                  ; return this;}
    Piece * place            (int   x,  int y            )  {position = Point(x, y)          ; return this;}
    
    // Value Collection Methods
    long                       MSCount                   (     )  {return movementStyle.size()                  ;}
    MovementStyle              getMovementStyle          (int i)  {return movementStyle[i]                      ;}
    std::vector<MovementStyle> getAllMovementStyles      (     )  {return movementStyle                         ;}
    bool                       isFirstMove               (     )  {return hasMoved                              ;}
    bool                       isWhite                   (     )  {return white                                 ;}
    // // Ability Checks
    Abilities ability_check;
    
    // Movement Methods
    MovementStyle * isValidMove    (Point move      , bool take = false);
    MovementStyle * isValidMove    (int   x,   int y, bool take = false)  {return isValidMove(Point(x, y), take);}
    void            move           (Point pos                  )  {position = pos              ; hasMoved = true;}
    void            move           (int   x,  int y            )  {position = Point(x, y)      ; hasMoved = true;}
    
}