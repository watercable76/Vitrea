# Classes
[Point](#Point)

[MovementStyle](#)
[]()


# Point
##  Construction
int, int
##  Methods
Reverse() - Returns the point in reverse (i.e. x, y => y, x)

Sum()     - Returns the sum of x and y

Mag()     - Returns the length of the diagonal described by x and y
##  Members
x - int

y - int

# MovementStyle 
## Construction 
Point, int

int, int, int

&MovementStyle

## Members       
slope     - Point

magnitude - int

# Piece 
## Construction
int
## Methods      
addMovementStyle     (Point, int)/(int, int, int)     - Gives a piece a new movement style. 

place                (Point)/(int, int)               - Changes the position of the piece. Returns a reference to itself. Used for board setup.

toWhite              ()                               - Changes the piece to be a white piece. Returns a reference to itself.

toBlack              ()                               - Changes the piece to be a black piece. Returns a reference to itself.

MSCount              ()                               - Returns the number of different movement styles a piece has.

getMovementStyle     (int)                            - Returns a movement style the piece has.

getAllMovementStyles ()                               - Returns all movement styles a piece has as a vector.

isFirstMove          ()                               - Returns true if a piece has not moved.

isWhite              ()                               - Returns true if a piece is white.

canJump              ()                               - Returns true if a piece has the ability "Jump."

canXxxx              ()                               - Returns true if a piece has the ability "Xxxx."

isValidMove          (Point, bool)/(int, int, bool)   - Returns a movement style that allows it to reach the given destination. Returns NULL if impossible. Accepts optional second parameter allowing searches for a valid movement style for a capture.

move                 (Point)/(int, int)               - Informs a piece where it is being moved to. Used for gameplay.
