#include "avl_tree.h"

avl_tree::avl_tree() { Top_of_Tree = NULL; }

void avl_tree::insert(int elem) { Top_of_Tree = insert__(Top_of_Tree, elem); }

unsigned char avl_tree::height(nodeptr p)
{
	return p ? p->height : 0;
}

void avl_tree::del(int num)
{
	Top_of_Tree = remove(Top_of_Tree, num);
}

nodeptr avl_tree::findmax_in_tree()
{
	if (Top_of_Tree == NULL) {
		return Top_of_Tree;
	}
	else {
		nodeptr p = Top_of_Tree;
		while (p->right != NULL) {
			p = p->right;
		}
		return p;
	}
}

nodeptr avl_tree::findmin_in_tree() {
	if (Top_of_Tree == NULL) {
		return Top_of_Tree;
	}
	else {
		nodeptr p = Top_of_Tree;
		while (p->left != NULL) {
			p = p->left;
		}
		return p;
	}
}

void avl_tree::clearTree__(nodeptr* p) {
	if ((*p) != NULL)           //  если дерево не пусто
	{
		clearTree__(&(*p)->left);   //  удаляем левое поддерево     
		clearTree__(&(*p)->right);  //  удаляем правое поддерево    
		delete* p; //Удаляем указатель на текущий узел
		*p = NULL;//Присваиваем ему пустой указатель
	}
}

int avl_tree::bfactor(nodeptr p)
{
	return height(p->right) - height(p->left);
}

void avl_tree::fixheight(nodeptr p)
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl > hr ? hl : hr) + 1;
}

nodeptr avl_tree::rotateright(nodeptr p) // правый поворот вокруг p
{
	nodeptr q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

nodeptr avl_tree::rotateleft(nodeptr q) // левый поворот вокруг q
{
	nodeptr p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

nodeptr avl_tree::balance(nodeptr p) // балансировка узла p
{
	fixheight(p);
	if (bfactor(p) == 2) {
		if (bfactor(p->right) < 0)
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	if (bfactor(p) == -2) {
		if (bfactor(p->left) > 0)
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p; // балансировка не нужна
}

nodeptr avl_tree::insert__(nodeptr p, int k) // вставка ключа k в дерево с корнем p
{
	if (!p) return new node(k);
	if (k < p->element)
		p->left = insert__(p->left, k);
	else
		p->right = insert__(p->right, k);
	return balance(p);
}

nodeptr avl_tree::findmin(nodeptr p) // поиск узла с минимальным ключом в дереве p 
{
	return p->left ? findmin(p->left) : p;
}

nodeptr avl_tree::removemin(nodeptr p) // удаление узла с минимальным ключом из дерева p
{
	if (p->left == 0)
		return p->right;
	p->left = removemin(p->left);
	return balance(p);
}

nodeptr avl_tree::remove(nodeptr p, int k) // удаление ключа k из дерева p
{
	if (!p) return 0;
	if (k < p->element)
		p->left = remove(p->left, k);
	else if (k > p->element)
		p->right = remove(p->right, k);
	else //  k == p->key 
	{
		nodeptr q = p->left;
		nodeptr r = p->right;
		delete p;
		if (!r) return q;
		nodeptr min = findmin(r);
		min->right = removemin(r);
		min->left = q;
		return balance(min);
	}
	return balance(p);
}