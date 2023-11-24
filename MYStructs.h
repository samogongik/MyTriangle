#include<iostream>
#include<vector>
struct Point3D{
    double x, y, z;

    Point3D(double x, double y, double z): x(x), y(y), z(z){}
};

struct Straight{
    Point3D pt, guide_vector;

    Straight(Point3D pt, Point3D guide_vector): pt(pt), guide_vector(guide_vector){}
};

struct Line_segment{
    Point3D A, B;

    Line_segment(Point3D A, Point3D B): A(A), B(B){}
};

struct Plane{
    double A, B, C, D;

    Plane(double A, double B, double C, double D): A(A), B(B), C(C), D(D){}
};

struct Tringle3D{
    Point3D pt1, pt2, pt3;
    int number;

    Tringle3D(Point3D pt1, Point3D pt2, Point3D pt3, int number): pt1(pt1), pt2(pt2), pt3(pt3), number(number){}
};

struct OctreeNode{
    Point3D min;
    Point3D max;
    std::vector<Tringle3D> tringles;
    OctreeNode *children[8];

    OctreeNode(Point3D min, Point3D max): min(min), max(max){
        for (int i = 0; i < 8; i++){
            children[i] = nullptr;
        }
    }
};
