#include <gtest/gtest.h>
#include "../OctoTree.h"


TEST(e2e_test, first_test) {
    Point3D pt1(-3, 3, 0);Point3D pt2(3, 3, 0);Point3D pt3(-3, -3, 0);
    Tringle3D tringle1(pt1, pt2, pt3, 0);

    Point3D pt1_2(0, 0, 0);Point3D pt2_2(3, 0, 0);Point3D pt3_2(3, -3, 0);
    Tringle3D tringle2(pt1_2, pt2_2, pt3_2, 1);

    Point3D min(-3, -3, 0);
    Point3D max(3, 3, 0);
    Octree octree(min, max, 4);

    octree.insert(tringle1);
    octree.insert(tringle2);

    std::vector<int> answer_correct = {0, 1};
    std::vector<int> answer_expected = octree.get_answer(2);

    ASSERT_EQ(answer_correct, answer_expected) << "Test failed";

}

TEST(e2e_test, second_test) {
    Point3D pt1(-1, 0, 0);Point3D pt2(1, 1, 0);Point3D pt3(1, -1, 0);
    Tringle3D tringle1(pt1, pt2, pt3, 0);

    Point3D pt1_2(-3, 0, 0);Point3D pt2_2(3, 3, 0);Point3D pt3_2(3, -3, 0);
    Tringle3D tringle2(pt1_2, pt2_2, pt3_2, 1);

    Point3D min(-3, -3, 0);
    Point3D max(3, 3, 0);
    Octree octree(min, max, 4);

    octree.insert(tringle1);
    octree.insert(tringle2);

    std::vector<int> answer_correct = {0, 1};
    std::vector<int> answer_expected = octree.get_answer(2);


    ASSERT_EQ(answer_correct, answer_expected) << "Test failed";
}

TEST(e2e_test, thirth_test) {
    Point3D pt1(-3, -3, 0);Point3D pt2(-3, 3, 0);Point3D pt3(3, 3, 0);
    Tringle3D tringle1(pt1, pt2, pt3, 0);

    Point3D pt1_2(-1, -1, 0);Point3D pt2_2(-1, 3, 0);Point3D pt3_2(1, 3, 0);
    Tringle3D tringle2(pt1_2, pt2_2, pt3_2, 1);

    Point3D min(-3, -3, 0);
    Point3D max(3, 3, 0);
    Octree octree(min, max, 4);

    octree.insert(tringle1);
    octree.insert(tringle2);

    std::vector<int> answer_correct = {0, 1};
    std::vector<int> answer_expected = octree.get_answer(2);


    ASSERT_EQ(answer_correct, answer_expected) << "Test failed";
}


TEST(e2e_test, test_4) {
    Point3D pt1(1, 0, 0);Point3D pt2(0, 1, 0);Point3D pt3(0, 0, 1);
    Tringle3D tringle1(pt1, pt2, pt3, 0);

    Point3D pt1_2(5, 5, 5);Point3D pt2_2(0, 0, 0);Point3D pt3_2(5, 3, 0);
    Tringle3D tringle2(pt1_2, pt2_2, pt3_2, 1);



    Point3D min(0, 0, 0);
    Point3D max(5, 5, 0);
    Octree octree(min, max, 4);

    octree.insert(tringle1);
    octree.insert(tringle2);

    std::vector<int> answer_correct = {0, 1};
    std::vector<int> answer_expected = octree.get_answer(2);


    ASSERT_EQ(answer_correct, answer_expected) << "Test failed";
}

TEST(e2e_test, test_5) {
    Point3D pt1(0, 0, 0);Point3D pt2(81, 0, 0);Point3D pt3(0, 78, 0);
    Tringle3D tringle1(pt1, pt2, pt3, 0);

    Point3D pt1_2(-320, 320, 0);Point3D pt2_2(-238, 320, 0);Point3D pt3_2(-320, 399, 0);
    Tringle3D tringle2(pt1_2, pt2_2, pt3_2, 1);

    Point3D min(-320, 0, 0);
    Point3D max(81, 399, 0);
    Octree octree(min, max, 4);

    octree.insert(tringle1);
    octree.insert(tringle2);

    std::vector<int> answer_correct = {};
    std::vector<int> answer_expected = octree.get_answer(2);

    ASSERT_EQ(answer_correct, answer_expected) << "Test failed";
}

TEST(e2e_test, test_6) {
    Point3D pt1(0, 0, 0);Point3D pt2(2, 0, 0);Point3D pt3(0, 2, 0);
    Tringle3D tringle1(pt1, pt2, pt3, 0);

    Point3D pt1_2(-2, -2, 0);Point3D pt2_2(-2, 2, 0);Point3D pt3_2(2, 2, 0);
    Tringle3D tringle2(pt1_2, pt2_2, pt3_2, 1);

    Point3D pt1_3(0, 0, 1);Point3D pt2_3(2, 0, 1);Point3D pt3_3(0, 2, 1);
    Tringle3D tringle3(pt1_3, pt2_3, pt3_3, 2);

    Point3D min(-2, -2, 0);
    Point3D max(2, 2, 1);
    Octree octree(min, max, 4);

    octree.insert(tringle1);
    octree.insert(tringle2);
    octree.insert(tringle3);

    std::vector<int> answer_correct = {0, 1};
    std::vector<int> answer_expected = octree.get_answer(2);

    ASSERT_EQ(answer_correct, answer_expected) << "Test failed";
}

TEST(e2e_test, test_7) {
    Point3D pt1(73.2058, 12.201, 0);Point3D pt2(155.092, 12.201, 0);Point3D pt3(73.2058, 90.6641, 0);
    Tringle3D tringle1(pt1, pt2, pt3, 0);

    Point3D pt1_2(146.412, 24.4019, 0);Point3D pt2_2(228.297, 24.4019, 0);Point3D pt3_2(146.412, 102.865, 0);
    Tringle3D tringle2(pt1_2, pt2_2, pt3_2, 1);

    Point3D pt1_3(219.617, 36.6029, 0);Point3D pt2_3(301.503, 36.6029, 0);Point3D pt3_3(219.617, 115.066, 0);
    Tringle3D tringle3(pt1_3, pt2_3, pt3_3, 2);

    Point3D min(0, 0, 0);
    Point3D max(301.503, 115.066, 0);
    Octree octree(min, max, 4);

    octree.insert(tringle1);
    octree.insert(tringle2);
    octree.insert(tringle3);

    std::vector<int> answer_correct = {};
    std::vector<int> answer_expected = octree.get_answer(3);

    ASSERT_EQ(answer_correct, answer_expected) << "Test failed";
}

TEST(e2e_test, test_8) {
    Point3D pt1(2, 2, -10);Point3D pt2(-2, 3, -10);Point3D pt3(0, 0, -10);
    Tringle3D tringle1(pt1, pt2, pt3, 0);

    Point3D pt1_2(2, 2, -7);Point3D pt2_2(-2, 3, -7);Point3D pt3_2(0, 0, -7);
    Tringle3D tringle2(pt1_2, pt2_2, pt3_2, 1);

    Point3D pt1_3(15, 15, -1);Point3D pt2_3(-15, 3, -1);Point3D pt3_3(0, 0, -1);
    Tringle3D tringle3(pt1_3, pt2_3, pt3_3, 2);

    Point3D pt1_4(2, 2, 0);Point3D pt2_4(2, -6, 0);Point3D pt3_4(0, 0, 0);
    Tringle3D tringle4(pt1_4, pt2_4, pt3_4, 3);

    Point3D pt1_5(2, 0, 0);Point3D pt2_5(2, 9, 0);Point3D pt3_5(9, 9, 0);
    Tringle3D tringle5(pt1_5, pt2_5, pt3_5, 4);

    Point3D pt1_6(-3, -3, -3);Point3D pt2_6(6, 6, 6);Point3D pt3_6(2, 2, 0);
    Tringle3D tringle6(pt1_6, pt2_6, pt3_6, 5);

    Point3D min(-15, -6, -10);
    Point3D max(15, 15, 6);
    Octree octree(min, max, 4);

    octree.insert(tringle1);
    octree.insert(tringle2);
    octree.insert(tringle3);
    octree.insert(tringle4);
    octree.insert(tringle5);
    octree.insert(tringle6);

    std::vector<int> answer_correct = {2, 3, 4, 5};
    std::vector<int> answer_expected = octree.get_answer(6);

    ASSERT_EQ(answer_correct, answer_expected) << "Test failed";
}

TEST(e2e_test, test_9) {
    Point3D pt1(30, 90, 90);Point3D pt2(90, 30, 90);Point3D pt3(90, 30, 70);
    Tringle3D tringle1(pt1, pt2, pt3, 0);

    Point3D pt1_2(50, 80, 80);Point3D pt2_2(80, 50, 80);Point3D pt3_2(80, 50, 70);
    Tringle3D tringle2(pt1_2, pt2_2, pt3_2, 1);

    Point3D pt1_3(10, 90, 90);Point3D pt2_3(90, 10, 90);Point3D pt3_3(90, 10, 70);
    Tringle3D tringle3(pt1_3, pt2_3, pt3_3, 2);

    Point3D pt1_4(80, 90, 95);Point3D pt2_4(90, 80, 95);Point3D pt3_4(90, 80, 75);
    Tringle3D tringle4(pt1_4, pt2_4, pt3_4, 3);

    Point3D min(10, 10, 70);
    Point3D max(90, 90, 95);
    Octree octree(min, max, 4);

    octree.insert(tringle1);
    octree.insert(tringle2);
    octree.insert(tringle3);
    octree.insert(tringle4);

    std::vector<int> answer_correct = {};
    std::vector<int> answer_expected = octree.get_answer(4);

    ASSERT_EQ(answer_correct, answer_expected) << "Test failed";
}

TEST(e2e_test, test_10) {
    Point3D pt1(1, 1, 1);Point3D pt2(2, 2, 2);Point3D pt3(4, 4, 0);
    Tringle3D tringle1(pt1, pt2, pt3, 0);

    Point3D pt1_2(0.01, 0.01, 0.01);Point3D pt2_2(0.02, 0.02, 0.02);Point3D pt3_2(0.04, 0.04, 0);
    Tringle3D tringle2(pt1_2, pt2_2, pt3_2, 1);

    Point3D pt1_3(-20, 20, -1);Point3D pt2_3(20, 20, -1);Point3D pt3_3(0, -40, -1);
    Tringle3D tringle3(pt1_3, pt2_3, pt3_3, 2);

    Point3D pt1_4(-20, 20, -1.0001);Point3D pt2_4(20, 20, -1.0001);Point3D pt3_4(0, -40, -0.999);
    Tringle3D tringle4(pt1_4, pt2_4, pt3_4, 3);

    Point3D pt1_5(-15, -15, -15);Point3D pt2_5(-15, 15, -15);Point3D pt3_5(-10, -10, -10);
    Tringle3D tringle5(pt1_5, pt2_5, pt3_5, 4);

    Point3D min(-15, -6, -10);
    Point3D max(15, 15, 6);
    Octree octree(min, max, 4);

    octree.insert(tringle1);
    octree.insert(tringle2);
    octree.insert(tringle3);
    octree.insert(tringle4);
    octree.insert(tringle5);

    std::vector<int> answer_correct = {2, 3};
    std::vector<int> answer_expected = octree.get_answer(5);

    ASSERT_EQ(answer_correct, answer_expected) << "Test failed";
}






