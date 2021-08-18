#include <cstdlib>
#include "ITree.h"

struct TreeNode {
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;
	int data;
	TreeNode(TreeNode* lhs, TreeNode* rhs, TreeNode* p, int t) : left(lhs),
		right(rhs), parent(p), data(t) {}
};

class FindTree : public ITree{
public:
	FindTree();
	void del(int);
	void insert(int);
	TreeNode* getFirst();
	TreeNode* find_max(TreeNode*);
	int HeightOfTree(TreeNode*);
	bool is_InTree(int key) {
		if (find_node(Top_of_Tree, key) == nullptr) {
			return false;
		}
		else {
			return true;
		}
	}

	int getMax() {
		return max_in_find_tree;
	}

	int getMin() {
		return min_in_find_tree;
	}

	void removeAll() {
		clearTree__(&Top_of_Tree);
	}
	
private:
	TreeNode* Top_of_Tree;
	int min_in_find_tree;
	int max_in_find_tree;

	void clearTree__(TreeNode**);
	int insert__(int);
	TreeNode* delete__(TreeNode*);
	
	TreeNode* find_min(TreeNode*);
	TreeNode* find_node(TreeNode*, const int&);
	TreeNode* find_succsessor(const int&);
	
};