//
// Created by jpc on 1/07/21.
//

#ifndef TWODEE_GEOMETRY_H
#define TWODEE_GEOMETRY_H

struct Point {
    int x {0};
    int y {0};
    Point(int x, int y): x{x}, y{y}{}
    Point(){}
};

struct Dimension {
    int w {0};
    int h {0};
    Dimension(int w, int h): w{w}, h{h}{}
    Dimension(){}
};

struct Rect {
    Point lt;
    Dimension size;
};

#endif //TWODEE_GEOMETRY_H
