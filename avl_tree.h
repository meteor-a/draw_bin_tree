#pragma once
#include "ITree.h"
#include <algorithm>
#include <iostream>

struct node {
  int element;
  node *left;
  node *right;
  int height;
  node(int k) { element = k; left = right = NULL; height = 1; }
};

typedef struct node *nodeptr;

class avl_tree : public ITree{
public:
    avl_tree();

    void insert(int);
    void del(int);
    nodeptr findmax_in_tree();
    nodeptr findmin_in_tree();

    void inorder() { inorder__(Top_of_Tree); }

    long long getSize() { return size__;}

    nodeptr getFirst() { return Top_of_Tree; }

    void removeAll() {
        clearTree__(&Top_of_Tree);
        Top_of_Tree = NULL;
    }


private:

    long long size__ = 0;

    void inorder__(nodeptr p) {
      if (p != NULL) {
        inorder__(p->left);
        std::cout << p->element << "\t";
        inorder__(p->right);
      }
    }

    nodeptr Top_of_Tree;

    void clearTree__(nodeptr*);
    int bfactor(nodeptr);
    void fixheight(nodeptr);
    nodeptr rotateright(nodeptr);
    nodeptr rotateleft(nodeptr);
    nodeptr balance(nodeptr);
    nodeptr insert__(nodeptr, int);
    nodeptr findmin(nodeptr);
    nodeptr removemin(nodeptr);
    nodeptr remove(nodeptr, int);
    unsigned char height(nodeptr);
};
