#include "FindTree.h"

FindTree::FindTree() {
    Top_of_Tree = nullptr;
}

void FindTree::clearTree__(TreeNode** p) {
	if ((*p) != nullptr)           //  если дерево не пусто
	{
		clearTree__(&(*p)->left);   //  удаляем левое поддерево     
		clearTree__(&(*p)->right);  //  удаляем правое поддерево    
		delete* p; //Удаляем указатель на текущий узел
		*p = nullptr;//Присваиваем ему пустой указатель
	}
}

int FindTree::insert__(int x) {
	TreeNode* n = new TreeNode(nullptr, nullptr, nullptr, x);
	TreeNode* ptr;
	TreeNode* ptr1 = nullptr;

	if (x > max_in_find_tree) {
		max_in_find_tree = x;
	}
	if (x < min_in_find_tree) {
		min_in_find_tree = x;
	}

	n->parent = n->left = n->right = nullptr;
	ptr = Top_of_Tree;
	while (ptr != nullptr)
	{
		ptr1 = ptr;
		if (x < ptr->data)
			ptr = ptr->left;
		else
			ptr = ptr->right;
	}
	n->parent = ptr1;
	if (ptr1 == nullptr) {
		Top_of_Tree = n;
		min_in_find_tree = x;
		max_in_find_tree = x;
	}
	else
	{
		if (x < ptr1->data)
			ptr1->left = n;
		else
			ptr1->right = n;
	}
	return 0;
}

void FindTree::del(int val) {
	delete__(find_node(Top_of_Tree, val));
}

void FindTree::insert(int data) {
	insert__(data);
}

TreeNode* FindTree::delete__(TreeNode* z) {
	TreeNode* y;
	TreeNode* x;
	if (z->left == nullptr || z->right == nullptr)
		y = z;
	else
		y = find_succsessor(z->data);
	if (y->left != nullptr)
		x = y->left;
	else
		x = y->right;
	if (x != nullptr)
		x->parent = y->parent;
	if (y->parent == nullptr)
		Top_of_Tree = x;
	else
	{
		if (y == (y->parent)->left)
			(y->parent)->left = x;
		else
			(y->parent)->right = x;
	}
	if (y != z)
		z->data = y->data;
	return y;
}

TreeNode* FindTree::find_max(TreeNode* x) {
	while (x->right != nullptr)
		x = x->right;
	return x;
}

int FindTree::HeightOfTree(TreeNode* node)
{
	if (node == 0)
		return 0;
	int left, right;
	if (node->left != nullptr) {
		left = HeightOfTree(node->left);
	}
	else
		left = -1;
	if (node->right != nullptr) {
		right = HeightOfTree(node->right);
	}
	else
		right = -1;
	int max = left > right ? left : right;
	return max + 1;
}

TreeNode* FindTree::find_min(TreeNode* x) {
	while (x->left != nullptr)
		x = x->left;
	return x;
}

TreeNode* FindTree::find_node(TreeNode* n, const int& val) {
	if (n == nullptr || val == n->data)
		return n;
	if (val > n->data)
		return find_node(n->right, val);
	else
		return find_node(n->left, val);
}

TreeNode* FindTree::find_succsessor(const int& val) {
	TreeNode* x = find_node(Top_of_Tree, val);
	TreeNode* y;
	if (x == nullptr)
		return nullptr;
	if (x->right != nullptr)
		return find_min(x->right);
	y = x->parent;
	while (y != nullptr && x == y->right)
	{
		x = y;
		y = y->parent;
	}
	return y;
}

TreeNode* FindTree::getFirst()
{
	return Top_of_Tree;
}
