#include <iostream>
#include <vector>
#include <cmath>

#include "MYStructs.h"

Plane calculate_plane(const Tringle3D& tringle){
    Point3D v1(tringle.pt2.x - tringle.pt1.x, tringle.pt2.y - tringle.pt1.y, tringle.pt2.z - tringle.pt1.z);
    Point3D v2(tringle.pt3.x - tringle.pt1.x, tringle.pt3.y - tringle.pt1.y, tringle.pt3.z - tringle.pt1.z);

    double A = v1.y * v2.z - v1.z * v2.y;
    double B = v1.z * v2.x - v1.x * v2.z;
    double C = v1.x * v2.y - v1.y * v2.x;

    double length = std::sqrt(A*A + B*B + C*C);
    A = A / length;
    B = B / length;
    C = C / length;

    double D = -A * tringle.pt1.x - B * tringle.pt1.y - C * tringle.pt1.z;

    return Plane(A, B, C, D);
}

bool coinciding_planes(const Plane& plane, const Tringle3D& tringle){
    if(fabs(plane.A * tringle.pt1.x + plane.B * tringle.pt1.y + plane.C * tringle.pt1.z + plane.D) < 0.0001 &&
       fabs(plane.A * tringle.pt2.x + plane.B * tringle.pt2.y + plane.C * tringle.pt2.z + plane.D) < 0.0001 &&
       fabs(plane.A * tringle.pt3.x + plane.B * tringle.pt3.y + plane.C * tringle.pt3.z + plane.D) < 0.0001) {
        return true;
    }

    return false;
}

bool plane_parallel(const Plane& plane1, const Plane& plane2){

    double scalar_product = plane1.A * plane2.A + plane1.B * plane2.B + plane1.C * plane2.C;
    double corner = std::acos(scalar_product);

    if (corner == 0.0 || corner == M_PI) {
        return true;
    }
    else {
        return false;
    }
}

Point3D calculate_guide_vector(Point3D pt1, Point3D pt2){
    double x = pt2.x - pt1.x;
    double y = pt2.y - pt1.y;
    double z = pt2.z - pt1.z;

    return Point3D(x, y, z);
}

bool checking_nested_segments(const Line_segment& segment1, const Line_segment& segment2) {
    if ((segment1.A.x <= segment2.A.x && segment1.A.y <= segment2.A.y && segment1.A.z <= segment2.A.z)
        && (segment2.A.x <= segment1.B.x && segment2.A.y <= segment1.B.y && segment2.A.z <= segment1.B.z)) {
        return true;
    }

    if ((segment1.A.x <= segment2.B.x && segment1.A.y <= segment2.B.y && segment1.A.z <= segment2.B.z)
        && (segment2.B.x <= segment1.B.x && segment2.B.y <= segment1.B.y && segment2.B.z <= segment1.B.z)) {
        return true;
    }

    if ((segment2.A.x <= segment1.A.x && segment2.A.y <= segment1.A.y && segment2.A.z <= segment1.A.z)
        && (segment1.A.x <= segment2.B.x && segment1.A.y <= segment2.B.y && segment1.A.z <= segment2.B.z)) {
        return true;
    }

    if ((segment2.A.x <= segment1.B.x && segment2.A.y <= segment1.B.y && segment2.A.z <= segment1.B.z)
        && (segment1.B.x <= segment2.B.x && segment1.B.y <= segment2.B.y && segment1.B.z <= segment2.B.z)) {
        return true;
    }

    return false;
}

bool nested_segments(const Tringle3D& tringle1, const Tringle3D& tringle2) {
    Line_segment X1Y1(tringle1.pt1, tringle1.pt2);
    Line_segment X1Z1(tringle1.pt1, tringle1.pt3);
    Line_segment Y1Z1(tringle1.pt3, tringle1.pt3);

    std::vector<Line_segment> sides1;
    sides1.push_back(X1Y1);
    sides1.push_back(X1Z1);
    sides1.push_back(Y1Z1);

    Line_segment X2Y2(tringle2.pt1, tringle2.pt2);
    Line_segment X2Z2(tringle2.pt1, tringle2.pt3);
    Line_segment Y2Z2(tringle2.pt3, tringle2.pt3);

    std::vector<Line_segment> sides2;
    sides2.push_back(X2Y2);
    sides2.push_back(X2Z2);
    sides2.push_back(Y2Z2);

    for (int i = 0; i < sides1.size(); i++) {
        for (int j = 0; j < sides2.size(); j++){

            bool flag = checking_nested_segments(sides1[i], sides2[j]);
            if (flag) {
                return flag;
            }
        }
    }

    return false;
}

bool checking_parallelism_of_segments(const Straight& side1, const Straight& side2) {
    double length1 = std::sqrt(side1.guide_vector.x * side1.guide_vector.x + side1.guide_vector.y * side1.guide_vector.y
                               + side1.guide_vector.z * side1.guide_vector.z);

    double length2 = std::sqrt(side2.guide_vector.x * side2.guide_vector.x + side2.guide_vector.y * side2.guide_vector.y
                               + side2.guide_vector.z * side2.guide_vector.z);

    double scalar_product = side1.guide_vector.x * side2.guide_vector.x + side1.guide_vector.y * side2.guide_vector.y
                            + side1.guide_vector.z * side2.guide_vector.z;

    double cos_corner = scalar_product / (length1 * length2);
    if (fabs(fabs(cos_corner) - 1) < 0.0001) {
        cos_corner = 1;
    }
    double corner = std::acos(cos_corner);

    return (corner == 0.0 || corner == M_PI);
}

Point3D intersection_straights(const Straight& side1, const Straight& side2) {
    double t = 0;

    if (side1.guide_vector.x * side2.guide_vector.y != side1.guide_vector.y * side2.guide_vector.x) {
         double x = side2.pt.x - side1.pt.x;
         double y = side2.pt.y - side1.pt.y;
         double det = side1.guide_vector.x * side2.guide_vector.y - side1.guide_vector.y * side2.guide_vector.x;

         t = (side2.guide_vector.y * x - side1.guide_vector.y * y) / det;
    }
    else if (side1.guide_vector.x * side2.guide_vector.z != side1.guide_vector.z * side2.guide_vector.x) {
        double x = side2.pt.x - side1.pt.x;
        double z = side2.pt.z - side1.pt.z;
        double det = side1.guide_vector.x * side2.guide_vector.z - side1.guide_vector.z * side2.guide_vector.x;

        t = (side2.guide_vector.z * x - side1.guide_vector.z * z) / det;
    }
    else {
        double y = side2.pt.y - side1.pt.y;
        double z = side2.pt.z - side1.pt.z;
        double det = side1.guide_vector.y * side2.guide_vector.z - side1.guide_vector.z * side2.guide_vector.y;

        t = (side2.guide_vector.z * y - side1.guide_vector.z * z) / det;
    }

    Point3D intersection(side1.pt.x + t * side1.guide_vector.x,
                         side1.pt.y + t * side1.guide_vector.y,
                         side1.pt.z + t * side1.guide_vector.z);

    return intersection;
}

bool intersection_check_of_sides(const Straight& side1, const Point3D& intersection){
    Point3D point1(side1.guide_vector.x + side1.pt.x, side1.guide_vector.y + side1.pt.y, side1.guide_vector.z + side1.pt.z);
    Line_segment segment1(side1.pt, point1);

    bool flag = false;
    if ((segment1.A.x <= intersection.x && segment1.A.y <= intersection.y && segment1.A.z <= intersection.z) &&
        (intersection.x <= segment1.B.x && intersection.y <= segment1.B.y && intersection.z <= segment1.B.z)){
        flag = true;
    }
    if ((segment1.B.x <= intersection.x && segment1.B.y <= intersection.y && segment1.B.z <= intersection.z) &&
        (intersection.x <= segment1.A.x && intersection.y <= segment1.A.y && intersection.z <= segment1.A.z)){
        flag = true;
    }

    return flag;
}


bool intersection_of_sides(const Tringle3D& tringle1, const Tringle3D& tringle2){
    Straight X1Y1(tringle1.pt1, calculate_guide_vector(tringle1.pt1, tringle1.pt2 ));
    Straight X1Z1(tringle1.pt1, calculate_guide_vector(tringle1.pt1, tringle1.pt3 ));
    Straight Y1Z1(tringle1.pt2, calculate_guide_vector(tringle1.pt2, tringle1.pt3 ));

    std::vector<Straight> sides1;
    sides1.push_back(X1Y1);
    sides1.push_back(X1Z1);
    sides1.push_back(Y1Z1);

    Straight X2Y2(tringle2.pt1, calculate_guide_vector(tringle2.pt1, tringle2.pt2 ));
    Straight X2Z2(tringle2.pt1, calculate_guide_vector(tringle2.pt1, tringle2.pt3 ));
    Straight Y2Z2(tringle2.pt2, calculate_guide_vector(tringle2.pt2, tringle2.pt3 ));

    std:: vector<Straight> sides2;
    sides2.push_back(X2Y2);
    sides2.push_back(X2Z2);
    sides2.push_back(Y2Z2);

    for (int i = 0; i < sides1.size(); i++) {
        for (int j = 0; j < sides2.size(); j++) {
            bool flag = checking_parallelism_of_segments(sides1[i], sides2[j]);

            if (!flag){

                Point3D intersection = intersection_straights(sides2[j], sides2[i]);
                bool flag1 = intersection_check_of_sides(sides1[i], intersection);
                bool flag2 = intersection_check_of_sides(sides2[j], intersection);

                if (flag1 && flag2) {
                    return true;
                }
            }
        }
    }

    return false;
}

Point3D crossProduct(const Point3D& a, const Point3D& b) {
    return Point3D(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

Point3D orientedArea(const Point3D& a, const Point3D& b, const Point3D& point) {
    Point3D v1(a.x - point.x, a.y - point.y, a.z - point.z);
    Point3D v2(b.x - point.x, b.y - point.y, b.z - point.z);
    return crossProduct(v1, v2);

}
int check_sign(const Point3D& normal1, const Point3D& normal2) {
    double length1 = sqrt(normal1.x * normal1.x + normal1.y * normal1.y + normal1.z * normal1.z);
    double length2 = sqrt(normal2.x * normal2.x + normal2.y * normal2.y + normal2.z * normal2.z);
    double scalar_product = normal1.x * normal2.x + normal1.y * normal2.y + normal1.z * normal2.z;
    if (length1 == 0 || length2 == 0){
        return 0;
    }
    double corner = acos(scalar_product / (length2 * length1));

    if (corner == 0) {
        return 1;
    }

    if (corner == M_PI) {
        return -1;
    }

}
bool tringle_and_point(const Tringle3D& tringle, const Point3D& point){
    Point3D area1 = orientedArea(tringle.pt1, tringle.pt2, point);
    Point3D area2 = orientedArea(tringle.pt2, tringle.pt3, point);
    Point3D area3 = orientedArea(tringle.pt3, tringle.pt1, point);

    Plane Alpha = calculate_plane(tringle);
    Point3D normal(Alpha.A, Alpha.B, Alpha.C);

    int sign1 = check_sign(area1, normal);
    int sign2 = check_sign(area2, normal);
    int sign3 = check_sign(area3, normal);

    if ((sign1 == 1 && sign2 == 1 && sign3 == 1) || (sign1 == -1 && sign2 == -1 && sign3 == -1)){
        return true;
    }
    return false;
}

bool nested_triangles(const Tringle3D& tringle1, const Tringle3D tringle2){
    bool flag1 = tringle_and_point(tringle1, tringle2.pt1);
    bool flag2 = tringle_and_point(tringle2, tringle1.pt1);

    if (flag1 || flag2){
        return true;
    }

    return false;
}

Straight find_for_straight_intersection_of_planes(const Plane& plane1, const Plane& plane2){
    Point3D vector_norm1(plane1.A, plane1.B, plane1.C);
    Point3D vector_norm2(plane2.A, plane2.B, plane2.C);

    Point3D guide_vector = crossProduct(vector_norm1, vector_norm2);

    double x = (plane1.B * plane2.D - plane1.D * plane2.B) / (plane1.A * plane2.B - plane2.A * plane1.B);
    double y = (plane2.A * plane1.D - plane2.D * plane1.A) / (plane1.A * plane2.B - plane2.A * plane1.B);
    double z = 0;

    Point3D point(x, y, z);
    Straight straight_intersection(point, guide_vector);

    return straight_intersection;
}

bool intersection_checking_straight_with_tringles(const Tringle3D& tringle1, const Tringle3D& tringle2, const Straight straight_intersection){
    Straight X1Y1(tringle1.pt1, calculate_guide_vector(tringle1.pt1, tringle1.pt2 ));
    Straight X1Z1(tringle1.pt1, calculate_guide_vector(tringle1.pt1, tringle1.pt3 ));
    Straight Y1Z1(tringle1.pt1, calculate_guide_vector(tringle1.pt2, tringle1.pt3 ));

    std::vector<Straight> sides1;
    sides1.push_back(X1Y1);
    sides1.push_back(X1Z1);
    sides1.push_back(Y1Z1);

    Straight X2Y2(tringle2.pt1, calculate_guide_vector(tringle2.pt1, tringle2.pt2 ));
    Straight X2Z2(tringle2.pt1, calculate_guide_vector(tringle2.pt1, tringle2.pt3 ));
    Straight Y2Z2(tringle2.pt1, calculate_guide_vector(tringle2.pt2, tringle2.pt3 ));

    std:: vector<Straight> sides2;
    sides2.push_back(X2Y2);
    sides2.push_back(X2Z2);
    sides2.push_back(Y2Z2);

    for (int i = 0; i < sides1.size(); i++){
        bool flag1 = false;
        bool flag2 = false;

        bool flag = checking_parallelism_of_segments(sides1[i], straight_intersection);
        if (!flag){
            Point3D intersection = intersection_straights(sides1[i], straight_intersection);
            if (intersection_check_of_sides(sides1[i], intersection)){
                flag1 = tringle_and_point(tringle2, intersection);
            }
        }

             flag = checking_parallelism_of_segments(sides2[i], straight_intersection);
        if (!flag){
            Point3D intersection = intersection_straights(sides2[i], straight_intersection);
             flag2 = tringle_and_point(tringle1, intersection);
        }

        if (flag1 || flag2){
            return true;
        }
    }

    return false;
}

bool intersection_checking_tringles(const Tringle3D& tringle1, const Tringle3D& tringle2){
    Plane plane1 = calculate_plane(tringle1);
    Plane plane2 = calculate_plane(tringle2);

    bool answer = coinciding_planes(plane1, tringle2);

    if (answer){
        bool flag1 = nested_segments(tringle1, tringle2);
        if (flag1){
            return true;
        }
        bool flag2 = intersection_of_sides(tringle1, tringle2);
        if (flag2) {
            return true;
        }

        bool flag3 = nested_triangles(tringle1, tringle2);
        if (flag3){
            return true;
        }
    }
    else {
        answer = plane_parallel(plane1, plane2);
        if (answer){
            return false;
        }
        Straight straight_intersection = find_for_straight_intersection_of_planes(plane1, plane2);
        bool flag = intersection_checking_straight_with_tringles(tringle1, tringle2, straight_intersection);

        if (flag){
            return true;
        }
        else return false;
    }

}