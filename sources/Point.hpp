#ifndef POINT
#define POINT

#include <string>
#include <iostream>

class Point{
    double value_x;
    double value_y;

    public:
        void print();
        Point(double value_x, double value_y);
        double distance(const Point& other);
        static Point moveTowards(Point src, Point des, double distance);
    };

#endif