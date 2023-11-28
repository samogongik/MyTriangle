#include <iostream>
#include <vector>
#include <unordered_map>
#include "MyFunctions.h"

class Octree {
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
        if (node->children[index] == nullptr) {
            createChild(node, index);
        }

        if ((node->children[index]->min.x < tringle.pt1.x && tringle.pt1.x < node->children[index]-> max.x) &&
            (node->children[index]->min.x < tringle.pt2.x && tringle.pt2.x < node->children[index]->max.x) &&
            (node->children[index]->min.x < tringle.pt3.x && tringle.pt3.x < node->children[index]->max.x) &&

            (node->children[index]->min.y < tringle.pt1.y && tringle.pt1.y < node->children[index]->max.y) &&
            (node->children[index]->min.y < tringle.pt2.y && tringle.pt2.y < node->children[index]->max.y) &&
            (node->children[index]->min.y < tringle.pt3.y && tringle.pt3.y < node->children[index]->max.y) &&

            (node->children[index]->min.z < tringle.pt1.z && tringle.pt1.z < node->children[index]->max.z) &&
            (node->children[index]->min.z < tringle.pt2.z && tringle.pt2.z < node->children[index]->max.z) &&
            (node->children[index]->min.z < tringle.pt3.z && tringle.pt3.z < node->children[index]->max.y)) {

            insert(node->children[index], tringle, depth + 1);
        }
        else {
            node->tringles.push_back(tringle);
            return;
        }

    }

    int getOctant(OctreeNode* node, Tringle3D tringle){
        int index = 0;
        float xMid = (node->min.x + node->max.x) / 2.0f;
        float yMid = (node->min.y + node->max.y) / 2.0f;
        float zMid = (node->min.z + node->max.z) / 2.0f;

        if (tringle.pt1.x > xMid && tringle.pt2.x > xMid && tringle.pt3.x > xMid) index |= 1;
        if (tringle.pt1.y > yMid && tringle.pt2.y > yMid && tringle.pt3.y > yMid) index |= 2;
        if (tringle.pt1.z > zMid && tringle.pt2.z > zMid && tringle.pt3.z > zMid) index |= 4;

        return index;
    }

    void createChild(OctreeNode* node, int index) {
        Point3D min = node->min;
        Point3D max = node->max;
        float xMid = (min.x + max.x) / 2.0f;
        float yMid = (min.y + max.y) / 2.0f;
        float zMid = (min.z + max.z) / 2.0f;

        if (index & 1) min.x = xMid;
        else max.x = xMid;
        if (index & 2) min.y = yMid;
        else max.y = yMid;
        if (index & 4) min.z = zMid;
        else max.z = zMid;


        node->children[index] = new OctreeNode(min, max);
    }

    void destroy(OctreeNode* node) {
        if (node == nullptr) return;

        for (int i = 0; i < 8; ++i) {
            destroy(node->children[i]);
        }

        delete node;
    }

    void print(int amount){
        for(int i = 1; i <= amount; i++){
            if (data.find(i) != data.end()) {
                std::cout << i << " ";
            }
        }

        std::cout << std::endl;
        return;
    }

private:
    int maxDepth;
    OctreeNode *root;
    std::unordered_map<int, int> data;
};
