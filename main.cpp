#include <iostream>
#include <vector>
#include <cassert>
#include "OctoTree.h"


int main() {
    int amount = 0;
    std::cin >> amount;
    assert(std::cin.good());

     int min_int = -2147483648;
     int max_int = 2147483647;
    Point3D min(max_int, max_int, max_int);
    Point3D max(min_int, min_int, min_int);
    std::vector<Tringle3D> tringles;

    for (int i = 0; i < amount; i++){
        std::vector<Point3D> points;
        for(int j = 0; j < 3; j++) {
            double x,y,z;
            std::cin >> x >> y >> z;
            assert(std::cin.good());

            if (min.x > x) {min.x = x;}
            if (min.y > y) {min.y = y;}
            if (min.z > z) {min.z = z;}

            if (max.x < x) {max.x = x;}
            if (max.y < y) {max.y = y;}
            if (max.z < z) {max.z = z;}

            Point3D point(x, y, z);
            points.push_back(point);
        }

        Tringle3D tringle(points[0], points[1], points[2], i);
        tringles.push_back(tringle);
    }

    Octree octree(min, max, 8);
    for(int i = 0; i < amount; i++){

        octree.insert(tringles[i]);
    }

    octree.print(amount);

}


