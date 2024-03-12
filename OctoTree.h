#include <iostream>
#include <vector>
#include <unordered_map>
#include "MyFunctions.h"

class Octree final {
public:
    friend bool intersection_checking(const Tringle3D& tringle1, const Tringle3D& tringle2);
    Octree(Point3D min, Point3D max, int maxDepth): maxDepth(maxDepth) {
        root = new OctreeNode(min, max);
    }

    ~Octree(){
        destroy(root);
    }

    void insert(Tringle3D tringle){
        insert(root, tringle, 0);
    }

    void insert(OctreeNode* node, Tringle3D tringle, int depth){
        for(int i = 0; i < node->tringles.size(); i++){
           bool flag = intersection_checking_tringles(tringle, node->tringles[i]);
           if (flag){
               if (data.find(tringle.number) == data.end()){
                   data[tringle.number] = tringle.number;
               }
               if (data.find(node->tringles[i].number) == data.end()){
                   data[node->tringles[i].number] = node->tringles[i].number;
               }
           }
        }

        if (depth == maxDepth){
            node->tringles.push_back(tringle);
            return;
        }

        int index = getOctant(node, tringle);

        bool flag = false;
        if (node->children[index] == nullptr) {
           flag = createChild(node, index, tringle);
        }

        if (flag){
            insert(node->children[index], tringle, depth + 1);
        }
        else {
            node->tringles.push_back(tringle);
            return;
        }

    }

    int getOctant(OctreeNode* node, Tringle3D tringle){
        int index = 0;
        double xMid = (node->min.x + node->max.x) / 2.0f;
        double yMid = (node->min.y + node->max.y) / 2.0f;
        double zMid = (node->min.z + node->max.z) / 2.0f;

        if (tringle.pt1.x > xMid && tringle.pt2.x > xMid && tringle.pt3.x > xMid) index |= 1;
        if (tringle.pt1.y > yMid && tringle.pt2.y > yMid && tringle.pt3.y > yMid) index |= 2;
        if (tringle.pt1.z > zMid && tringle.pt2.z > zMid && tringle.pt3.z > zMid) index |= 4;

        return index;
    }

    bool createChild(OctreeNode* node, int index, const Tringle3D& tringle) {
        Point3D min = node->min;
        Point3D max = node->max;
        double xMid = (min.x + max.x) / 2.0f;
        double yMid = (min.y + max.y) / 2.0f;
        double zMid = (min.z + max.z) / 2.0f;

        if (index & 1) min.x = xMid;
        else max.x = xMid;
        if (index & 2) min.y = yMid;
        else max.y = yMid;
        if (index & 4) min.z = zMid;
        else max.z = zMid;

        if ((node->min.x < tringle.pt1.x && tringle.pt1.x < node->max.x) &&
            (node->min.x < tringle.pt2.x && tringle.pt2.x < node->max.x) &&
            (node->min.x < tringle.pt3.x && tringle.pt3.x < node->max.x) &&

            (node->min.y < tringle.pt1.y && tringle.pt1.y < node->max.y) &&
            (node->min.y < tringle.pt2.y && tringle.pt2.y < node->max.y) &&
            (node->min.y < tringle.pt3.y && tringle.pt3.y < node->max.y) &&

            (node->min.z < tringle.pt1.z && tringle.pt1.z < node->max.z) &&
            (node->min.z < tringle.pt2.z && tringle.pt2.z < node->max.z) &&
            (node->min.z < tringle.pt3.z && tringle.pt3.z < node->max.z)) {

            node->children[index] = new OctreeNode(min, max);
            return true;
        }
        else {
            return false;
        }


    }

    void destroy(OctreeNode* node) {
        if (node == nullptr) return;

        for (int i = 0; i < 8; ++i) {
            destroy(node->children[i]);
        }

        delete node;
    }

    void print(int amount){
        for(int i = 0; i < amount; i++){
            if (data.find(i) != data.end()) {
                std::cout << i << " " << std::endl;
            }
        }

        std::cout << std::endl;
        return;
    }
    std::vector<int> get_answer (const int& amount){
        std::vector<int> answer;
        answer.reserve(amount);
        for (int i = 0; i < amount; i++){
            if (data.find(i) != data.end()){
                answer.push_back(i);
            }
        }
        return answer;
    }

private:
    int maxDepth;
    OctreeNode *root;
    std::unordered_map<int, int> data;
};
