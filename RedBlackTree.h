#include <iostream>
#include "ITree.h"

struct Node_RB {
	int key; 
	Node_RB* parent;
	Node_RB* left;
	Node_RB* right;
	int color; // 1 -> Red, 0 -> Black
	Node_RB() { key = NULL; parent = left = right = NULL; color = -1; }
};

typedef Node_RB* NodePtrRB;

class RBTree : public ITree{
public:
	RBTree() {
		TNULL = new Node_RB;
		TNULL->color = 0;
		TNULL->left = nullptr;
		TNULL->right = nullptr;
		root = TNULL;
	}

	NodePtrRB getFirst() {
		return root;
	}

	NodePtrRB getTNULL() {
		return TNULL;
	}

	NodePtrRB searchTree(int k) {
		return searchTreeHelper(this->root, k);
	}

	NodePtrRB minimum(NodePtrRB node);
	NodePtrRB maximum(NodePtrRB node);
	NodePtrRB successor(NodePtrRB x);
	NodePtrRB predecessor(NodePtrRB x);

	void leftRotate(NodePtrRB x);
	void rightRotate(NodePtrRB x);
	

	NodePtrRB getRoot() {
		return this->root;
	}

	void del(int data) {
		deleteNodeHelper(this->root, data);
	}

	long long getMaxHeight() {
		return HeightOfTree(root);
	}

	void insert(int key) {
		insert__(key);
	}

	void removeAll() {
		clearTree__(&root);
		root = TNULL;
	}

private:
	NodePtrRB root;
	NodePtrRB TNULL;

	void clearTree__(NodePtrRB* p);

	void insert__(int key);
	void initializeNULLNode(NodePtrRB node, NodePtrRB parent);
	int HeightOfTree(NodePtrRB node);
	NodePtrRB searchTreeHelper(NodePtrRB node, int key);
	void fixDelete(NodePtrRB x);
	void rbTransplant(NodePtrRB u, NodePtrRB v);
	void deleteNodeHelper(NodePtrRB node, int key);
	void fixInsert(NodePtrRB k);
};