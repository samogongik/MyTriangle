#include <gtest/gtest.h>
#include "../MYFunctions.h"

TEST(e2e_test, first_test) {
    Point3D pt1(-3, 3, 0);Point3D pt2(3, 3, 0);Point3D pt3(-3, -3, 0);
    Tringle3D tringle1(pt1, pt2, pt3, 1);

    Point3D pt1_2(0, 0, 0);Point3D pt2_2(3, 0, 0);Point3D pt3_2(3, -3, 0);
    Tringle3D tringle2(pt1, pt2, pt3, 2);

    bool answer_correct = 1;
    bool answer_expected = intersection_checking_tringles(tringle1, tringle2);
}

TEST(e2e_test, second_test) {
    Point3D pt1(-1, 0, 0);Point3D pt2(1, 1, 0);Point3D pt3(1, -1, 0);
    Tringle3D tringle1(pt1, pt2, pt3, 1);

    Point3D pt1_2(-3, 0, 0);Point3D pt2_2(3, 3, 0);Point3D pt3_2(3, -3, 0);
    Tringle3D tringle2(pt1, pt2, pt3, 2);

    bool answer_correct = 1;
    bool answer_expected = intersection_checking_tringles(tringle1, tringle2);
}

TEST(e2e_test, thirth_test) {
    Point3D pt1(-3, -3, 0);Point3D pt2(-3, 3, 0);Point3D pt3(3, 3, 0);
    Tringle3D tringle1(pt1, pt2, pt3, 1);

    Point3D pt1_2(-1, -1, 0);Point3D pt2_2(-1, 3, 0);Point3D pt3_2(1, 3, 0);
    Tringle3D tringle2(pt1, pt2, pt3, 2);

    bool answer_correct = 1;
    bool answer_expected = intersection_checking_tringles(tringle1, tringle2);
}

TEST(e2e_test, fourth_test) {
    Point3D pt1(-3, 0, 0);Point3D pt2(-3, 3, 0);Point3D pt3(3, 0, 0);
    Tringle3D tringle1(pt1, pt2, pt3, 1);

    Point3D pt1_2(-2, 0, 0);Point3D pt2_2(-2, -3, 0);Point3D pt3_2(2, 0, 0);
    Tringle3D tringle2(pt1, pt2, pt3, 2);

    bool answer_correct = 1;
    bool answer_expected = intersection_checking_tringles(tringle1, tringle2);
}

TEST(e2e_test, fiveth_test) {
    Point3D pt1(-3, 3, 0);Point3D pt2(3, 3, 0);Point3D pt3(-3, -3, 0);
    Tringle3D tringle1(pt1, pt2, pt3, 1);

    Point3D pt1_2(-3, 3, 0);Point3D pt2_2(3, 3, 0);Point3D pt3_2(-3, 0, 0);
    Tringle3D tringle2(pt1, pt2, pt3, 2);

    bool answer_correct = 1;
    bool answer_expected = intersection_checking_tringles(tringle1, tringle2);
}

TEST(e2e_test, sixth_test) {
    Point3D pt1(-3, 3, 0);Point3D pt2(3, 3, 0);Point3D pt3(-3, -1, 0);
    Tringle3D tringle1(pt1, pt2, pt3, 1);

    Point3D pt1_2(3, -3, 0);Point3D pt2_2(-3, -3, 0);Point3D pt3_2(-3, 1, 0);
    Tringle3D tringle2(pt1, pt2, pt3, 2);

    bool answer_correct = 1;
    bool answer_expected = intersection_checking_tringles(tringle1, tringle2);
}

TEST(e2e_test, seventh_test) {
    Point3D pt1(-3, 3, 0);Point3D pt2(3, 3, 0);Point3D pt3(-3, -3, 0);
    Tringle3D tringle1(pt1, pt2, pt3, 1);

    Point3D pt1_2(3, 2, 0);Point3D pt2_2(-2, -3, 0);Point3D pt3_2(-2, 2, 0);
    Tringle3D tringle2(pt1, pt2, pt3, 2);

    bool answer_correct = 1;
    bool answer_expected = intersection_checking_tringles(tringle1, tringle2);
}

TEST(e2e_test, eighth_test) {
    Point3D pt1(-3, 3, 0);Point3D pt2(3, 3, 0);Point3D pt3(-3, -3, 0);
    Tringle3D tringle1(pt1, pt2, pt3, 1);

    Point3D pt1_2(3, 0, 0);Point3D pt2_2(3, -3, 0);Point3D pt3_2(-2, 2, 0);
    Tringle3D tringle2(pt1, pt2, pt3, 2);

    bool answer_correct = 1;
    bool answer_expected = intersection_checking_tringles(tringle1, tringle2);
}

TEST(e2e_test, nineth_test) {
    Point3D pt1(-1, 1, 0);Point3D pt2(3, 1, 0);Point3D pt3(-1, -3, 0);
    Tringle3D tringle1(pt1, pt2, pt3, 1);

    Point3D pt1_2(0, 0, 0);Point3D pt2_2(-3, 0, 0);Point3D pt3_2(0, 3, 0);
    Tringle3D tringle2(pt1, pt2, pt3, 2);

    bool answer_correct = 1;
    bool answer_expected = intersection_checking_tringles(tringle1, tringle2);
}

TEST(e2e_test, tenth_test) {
    Point3D pt1(-1, 1, 0);Point3D pt2(3, 1, 0);Point3D pt3(-1, -3, 0);
    Tringle3D tringle1(pt1, pt2, pt3, 1);

    Point3D pt1_2(0, 2, 0);Point3D pt2_2(3, -3, 0);Point3D pt3_2(0, -3, 0);
    Tringle3D tringle2(pt1, pt2, pt3, 2);

    bool answer_correct = 1;
    bool answer_expected = intersection_checking_tringles(tringle1, tringle2);
}

TEST(e2e_test, eleventh_test) {
    Point3D pt1(-2, 2, 0);Point3D pt2(3, 2, 0);Point3D pt3(-2, -3, 0);
    Tringle3D tringle1(pt1, pt2, pt3, 1);

    Point3D pt1_2(-3, 2, 0);Point3D pt2_2(0, 3, 0);Point3D pt3_2(0, -3, 0);
    Tringle3D tringle2(pt1, pt2, pt3, 2);

    bool answer_correct = 1;
    bool answer_expected = intersection_checking_tringles(tringle1, tringle2);
}

TEST(e2e_test, test_12) {
    Point3D pt1(0, 3, 0);Point3D pt2(-3, 0, 0);Point3D pt3(-3, 3, 0);
    Tringle3D tringle1(pt1, pt2, pt3, 1);

    Point3D pt1_2(3, 3, 0);Point3D pt2_2(0, 3, 0);Point3D pt3_2(3, 0, 0);
    Tringle3D tringle2(pt1, pt2, pt3, 2);

    bool answer_correct = 1;
    bool answer_expected = intersection_checking_tringles(tringle1, tringle2);
}

TEST(e2e_test, test_13) {
    Point3D pt1(0, 3, 0);Point3D pt2(-3, 0, 0);Point3D pt3(-3, 3, 0);
    Tringle3D tringle1(pt1, pt2, pt3, 1);

    Point3D pt1_2(3, 0, 0);Point3D pt2_2(3, -3, 0);Point3D pt3_2(0, -3, 0);
    Tringle3D tringle2(pt1, pt2, pt3, 2);

    bool answer_correct = 0;
    bool answer_expected = intersection_checking_tringles(tringle1, tringle2);
}

TEST(e2e_test, test_14) {
    Point3D pt1(-2, 0, 0);Point3D pt2(2, 0, 0);Point3D pt3(0, 0, 2);
    Tringle3D tringle1(pt1, pt2, pt3, 1);

    Point3D pt1_2(0, 0, 1);Point3D pt2_2(2, 2, 0);Point3D pt3_2(-2, -2, 0);
    Tringle3D tringle2(pt1, pt2, pt3, 2);

    bool answer_correct = 1;
    bool answer_expected = intersection_checking_tringles(tringle1, tringle2);
}

TEST(e2e_test, test_15) {
    Point3D pt1(0, -1.5, 0);Point3D pt2(0, -1, 0);Point3D pt3(2, 3, 2);
    Tringle3D tringle1(pt1, pt2, pt3, 1);

    Point3D pt1_2(-1.55, 1.34, 0);Point3D pt2_2(-1.83, -1.42, 0);Point3D pt3_2(-2.54, 1.3, 2);
    Tringle3D tringle2(pt1, pt2, pt3, 2);

    bool answer_correct = 0;
    bool answer_expected = intersection_checking_tringles(tringle1, tringle2);
}

TEST(e2e_test, test_16) {
    Point3D pt1(0, -1.5, 0);Point3D pt2(0, -1, 0);Point3D pt3(0, 0, 2);
    Tringle3D tringle1(pt1, pt2, pt3, 1);

    Point3D pt1_2(-1, 1.78, 0);Point3D pt2_2(-1, -2.38, 0);Point3D pt3_2(-1, 0, 3);
    Tringle3D tringle2(pt1, pt2, pt3, 2);

    bool answer_correct = 0;
    bool answer_expected = intersection_checking_tringles(tringle1, tringle2);
}

TEST(e2e_test, test_17) {
    Point3D pt1(201, -753, 646);Point3D pt2(-65, -910, -312);Point3D pt3(103, -13, -963);
    Tringle3D tringle1(pt1, pt2, pt3, 1);

    Point3D pt1_2(-85, -277, 871);Point3D pt2_2(670, -132, -661);Point3D pt3_2(-1000, 343, 585);
    Tringle3D tringle2(pt1, pt2, pt3, 2);

    bool answer_correct = 0;
    bool answer_expected = intersection_checking_tringles(tringle1, tringle2);
}

TEST(e2e_test, test_18) {
    Point3D pt1(201, -753, 646);Point3D pt2(-65, -910, -312);Point3D pt3(103, -13, -963);
    Tringle3D tringle1(pt1, pt2, pt3, 1);

    Point3D pt1_2(-736, 370, -74);Point3D pt2_2(-538, -307, -478);Point3D pt3_2(341, -773, 903);
    Tringle3D tringle2(pt1, pt2, pt3, 2);

    bool answer_correct = 0;
    bool answer_expected = intersection_checking_tringles(tringle1, tringle2);
}

TEST(e2e_test, test_19) {
    Point3D pt1(201, -753, 646);Point3D pt2(-65, -910, -312);Point3D pt3(103, -13, -963);
    Tringle3D tringle1(pt1, pt2, pt3, 1);

    Point3D pt1_2(644, 181, 138 );Point3D pt2_2(269, 679, 388);Point3D pt3_2(784, 669, 353);
    Tringle3D tringle2(pt1, pt2, pt3, 2);

    bool answer_correct = 0;
    bool answer_expected = intersection_checking_tringles(tringle1, tringle2);
}




