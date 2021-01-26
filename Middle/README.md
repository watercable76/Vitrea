Class Point : 
  Construction : int, int
  Methods      : Reverse() - Returns the point in reverse (i.e. x, y => y, x)
                 Sum()     - Returns the sum of x and y
                 Mag()     - Returns the length of the diagonal described by x and y
  Members      : x - int
                 y - int

Class MovementStyle :
  Construction : Point, int
                 int, int, int
                 &MovementStyle
  Methods      : None
  Members      : slope     - Point
               : magnitude - int
Class Piece :
  Construction : int
  Methods      : addMovementStyle     (Point, int)     - Gives a piece a new movement style. 
                                      (int, int, int) 
                 place                (Point)          - Changes the position of the piece. Returns a reference to itself. Used for board setup.
                                      (int, int) 
                 toWhite              ()               - Changes the piece to be a white piece. Returns a reference to itself.
                 toBlack              ()               - Changes the piece to be a black piece. Returns a reference to itself.
                 MSCount              ()               - Returns the number of different movement styles a piece has.
                 getMovementStyle     (int)            - Returns a movement style the piece has.
                 getAllMovementStyles ()               - Returns all movement styles a piece has as a vector.
                 isFirstMove          ()               - Returns true if a piece has not moved.
                 isWhite              ()               - Returns true if a piece is white.
                 canJump              ()               - Returns true if a piece has the ability "Jump."
                 can****              ()               - Returns true if a piece has the ability "****."
                 isValidMove          (Point, bool)    - Returns a movement style that allows it to reach the given destination. Returns NULL if impossible.
                                      (int, int, bool)   Accepts optional second parameter allowing searches for a valid movement style for a capture.
                 move                 (Point)          - Informs a piece where it is being moved to. Used for gameplay.
                                      (int, int)
