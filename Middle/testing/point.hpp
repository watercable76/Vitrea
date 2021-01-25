//
//  point.hpp
//  testing
//
//  Created by Brendan Koetting on 1/19/21.
//

#ifndef point_hpp
#define point_hpp

#include <math.h>

/*
* Point
* Literally just an x, y coordinate
* You can add and subtract them
* Even multiply (you're welcome)
*/
class Point
{
public:
    Point(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }

    int x;
    int y;
    
    Point reverse() {return Point(this->y, this->x);}
    
    int sum() {return this->x + this->y;}
    int mag() {return pow(pow(this->x, 2) + pow(this->y, 2), 0.5);}

    Point operator+  (const Point& that)
    {
        Point out;
        out.x = this->x + that.x;
        out.y = this->y + that.y;
        return out;
    }
    void operator+= (const Point& that)
    {
        this->x += that.x;
        this->y += that.y;
    }
    Point operator-  (const Point& that)
    {
        Point out;
        out.x = this->x - that.x;
        out.y = this->y - that.y;
        return out;
    }
    void operator-= (const Point& that)
    {
        this->x -= that.x;
        this->y -= that.y;
    }
    Point operator* (const Point& that)
    {
        Point out;
        out.x = this->x * that.x;
        out.y = this->y * that.y;
        return out;
    }
    void operator*= (const Point& that)
    {
        this->x *= that.x;
        this->y *= that.y;
    }
    bool operator== (const Point& that)
    {
        return this->x == that.x && this->y == that.y;
    }
    bool operator!= (const Point& that)
    {
        return not (this->x == that.x && this->y == that.y);
    }
};


#endif /* point_hpp */
