#pragma once
#include <stdlib.h>
#include "ITree.h"


struct TreeNode {
    TreeNode* left;           /* указатель на левого ребенка */
    TreeNode* right;          /* указатель на правого ребенка */
    TreeNode* parent;         /* указатель на родителя */
    int data;            /* ключ */
    TreeNode(TreeNode* lhs, TreeNode* rhs, TreeNode* par, int d) :
        left(lhs), right(rhs), parent(par), data(d) {}
};

class FindTree : public ITree {
public:
    FindTree();
//    ~FindTree();
    void insert(int);
    void del(int);

    TreeNode* getFirst() { return Top_of_Tree; }
    TreeNode* getMaxNode(TreeNode*);
    int HeightOfTree(TreeNode*);

private:
    TreeNode* Top_of_Tree;

    #define CMP_EQ(a, b) ((a) == (b))
    #define CMP_LT(a, b) ((a) < (b))
    #define CMP_GT(a, b) ((a) > (b))

    TreeNode* getFreeNode(int value, TreeNode* parent);
    void insert__(TreeNode** head, int value);

    TreeNode* getMinNode(TreeNode*);
    TreeNode* getNodeByValue(TreeNode* root, int value);

    void removeNodeByPtr(TreeNode*);

};

