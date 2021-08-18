#include "RedBlackTree.h"

void RBTree::initializeNULLNode(NodePtrRB node, NodePtrRB parent) {
	node->key = 0;
	node->parent = parent;
	node->left = nullptr;
	node->right = nullptr;
	node->color = 0;
}

int RBTree::HeightOfTree(NodePtrRB node) {
	if (node == 0)
		return 0;
	int left, right;
	if (node->left != NULL) {
		left = HeightOfTree(node->left);
	}
	else
		left = -1;
	if (node->right != NULL) {
		right = HeightOfTree(node->right);
	}
	else
		right = -1;
	int max = left > right ? left : right;
	return max + 1;
}

NodePtrRB RBTree::searchTreeHelper(NodePtrRB node, int key) {
	if (node == TNULL || key == node->key) {
		return node;
	}

	if (key < node->key) {
		return searchTreeHelper(node->left, key);
	}
	return searchTreeHelper(node->right, key);
}

void RBTree::fixDelete(NodePtrRB x) {
	NodePtrRB s;
	while (x != root && x->color == 0) {
		if (x == x->parent->left) {
			s = x->parent->right;
			if (s->color == 1) {
				s->color = 0;
				x->parent->color = 1;
				leftRotate(x->parent);
				s = x->parent->right;
			}

			if (s->left->color == 0 && s->right->color == 0) {
				s->color = 1;
				x = x->parent;
			}
			else {
				if (s->right->color == 0) {
					s->left->color = 0;
					s->color = 1;
					rightRotate(s);
					s = x->parent->right;
				}
				s->color = x->parent->color;
				x->parent->color = 0;
				s->right->color = 0;
				leftRotate(x->parent);
				x = root;
			}
		}
		else {
			s = x->parent->left;
			if (s->color == 1) {
				s->color = 0;
				x->parent->color = 1;
				rightRotate(x->parent);
				s = x->parent->left;
			}

			if (s->left->color == 0 && s->right->color == 0) {
				s->color = 1;
				x = x->parent;
			}
			else {
				if (s->left->color == 0) {
					s->right->color = 0;
					s->color = 1;
					leftRotate(s);
					s = x->parent->left;
				}
				s->color = x->parent->color;
				x->parent->color = 0;
				s->left->color = 0;
				rightRotate(x->parent);
				x = root;
			}
		}
	}
	x->color = 0;
}

void RBTree::rbTransplant(NodePtrRB u, NodePtrRB v) {
	if (u->parent == nullptr) {
		root = v;
	}
	else if (u == u->parent->left) {
		u->parent->left = v;
	}
	else {
		u->parent->right = v;
	}
	v->parent = u->parent;
}

void RBTree::deleteNodeHelper(NodePtrRB node, int key) {
	NodePtrRB z = TNULL;
	NodePtrRB x, y;
	while (node != TNULL) {
		if (node->key == key) {
			z = node;
		}

		if (node->key <= key) {
			node = node->right;
		}
		else {
			node = node->left;
		}
	}

	if (z == TNULL) {
		//cout << "Couldn't find key in the tree" << endl;
		return;
	}

	y = z;
	int y_original_color = y->color;
	if (z->left == TNULL) {
		x = z->right;
		rbTransplant(z, z->right);
	}
	else if (z->right == TNULL) {
		x = z->left;
		rbTransplant(z, z->left);
	}
	else {
		y = minimum(z->right);
		y_original_color = y->color;
		x = y->right;
		if (y->parent == z) {
			x->parent = y;
		}
		else {
			rbTransplant(y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}

		rbTransplant(z, y);
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
	}
	delete z;
	if (y_original_color == 0) {
		fixDelete(x);
	}
}

void RBTree::fixInsert(NodePtrRB k) {
	NodePtrRB u;
	while (k->parent->color == 1) {
		if (k->parent == k->parent->parent->right) {
			u = k->parent->parent->left; // uncle
			if (u->color == 1) {
				// case 3.1
				u->color = 0;
				k->parent->color = 0;
				k->parent->parent->color = 1;
				k = k->parent->parent;
			}
			else {
				if (k == k->parent->left) {
					// case 3.2.2
					k = k->parent;
					rightRotate(k);
				}
				// case 3.2.1
				k->parent->color = 0;
				k->parent->parent->color = 1;
				leftRotate(k->parent->parent);
			}
		}
		else {
			u = k->parent->parent->right; // uncle

			if (u->color == 1) {
				// mirror case 3.1
				u->color = 0;
				k->parent->color = 0;
				k->parent->parent->color = 1;
				k = k->parent->parent;
			}
			else {
				if (k == k->parent->right) {
					// mirror case 3.2.2
					k = k->parent;
					leftRotate(k);
				}
				// mirror case 3.2.1
				k->parent->color = 0;
				k->parent->parent->color = 1;
				rightRotate(k->parent->parent);
			}
		}
		if (k == root) {
			break;
		}
	}
	root->color = 0;
}

NodePtrRB RBTree::minimum(NodePtrRB node) {
	while (node->left != TNULL) {
		node = node->left;
	}
	return node;
}

NodePtrRB RBTree::maximum(NodePtrRB node) {
	while (node->right != TNULL) {
		node = node->right;
	}
	return node;
}

NodePtrRB RBTree::successor(NodePtrRB x) {
	if (x->right != TNULL) {
		return minimum(x->right);
	}

	NodePtrRB y = x->parent;
	while (y != TNULL && x == y->right) {
		x = y;
		y = y->parent;
	}
	return y;
}

NodePtrRB RBTree::predecessor(NodePtrRB x) {
	if (x->left != TNULL) {
		return maximum(x->left);
	}
	NodePtrRB y = x->parent;
	while (y != TNULL && x == y->left) {
		x = y;
		y = y->parent;
	}
	return y;
}

void RBTree::leftRotate(NodePtrRB x) {
	NodePtrRB y = x->right;
	x->right = y->left;
	if (y->left != TNULL) {
		y->left->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == nullptr) {
		this->root = y;
	}
	else if (x == x->parent->left) {
		x->parent->left = y;
	}
	else {
		x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
}

void RBTree::rightRotate(NodePtrRB x) {
	NodePtrRB y = x->left;
	x->left = y->right;
	if (y->right != TNULL) {
		y->right->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == nullptr) {
		this->root = y;
	}
	else if (x == x->parent->right) {
		x->parent->right = y;
	}
	else {
		x->parent->left = y;
	}
	y->right = x;
	x->parent = y;
}

void RBTree::clearTree__(NodePtrRB* p) {
	if ((*p)->left != nullptr && (*p)->right != nullptr && (*p)->key != 0)           //  если дерево не пусто
	{
		clearTree__(&(*p)->left);   //  удаляем левое поддерево     
		clearTree__(&(*p)->right);  //  удаляем правое поддерево    
		delete* p; //Удаляем указатель на текущий узел
		*p = nullptr;//Присваиваем ему пустой указатель
	}
}

void RBTree::insert__(int key) {
	NodePtrRB node = new Node_RB;
	node->parent = nullptr;
	node->key = key;
	node->left = TNULL;
	node->right = TNULL;
	node->color = 1; // new node must be red

	NodePtrRB y = nullptr;
	NodePtrRB x = this->root;

	while (x != TNULL) {
		y = x;
		if (node->key < x->key) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}

	// y is parent of x
	node->parent = y;
	if (y == nullptr) {
		root = node;
	}
	else if (node->key < y->key) {
		y->left = node;
	}
	else {
		y->right = node;
	}

	if (node->parent == nullptr) {
		node->color = 0;
		return;
	}
	if (node->parent->parent == nullptr) {
		return;
	}

	fixInsert(node);
}