#include "FindTree.h"

FindTree::FindTree() {
    Top_of_Tree = NULL;
}

void FindTree::insert(int value) {
    insert__(&Top_of_Tree, value);
}

void FindTree::del(int val) {
    TreeNode* target = getNodeByValue(Top_of_Tree, val);
    removeNodeByPtr(target);
}

TreeNode* FindTree::getFreeNode(int value, TreeNode* parent) {
    TreeNode* tmp = new TreeNode(NULL, NULL, parent, value);
    return tmp;
}

void FindTree::insert__(TreeNode** head, int value) {
    TreeNode* tmp = NULL;
    TreeNode* ins = NULL;
    if (*head == NULL) {
        *head = getFreeNode(value, NULL);
        return;
    }

    tmp = *head;
    while (tmp) {
        if (CMP_GT(value, tmp->data)) {
            if (tmp->right != NULL) {
                tmp = tmp->right;
                continue;
            }
            else {
                tmp->right = getFreeNode(value, tmp);
                return;
            }
        }
        else if (CMP_LT(value, tmp->data)) {
            if (tmp->left != NULL) {
                tmp = tmp->left;
                continue;
            }
            else {
                tmp->left = getFreeNode(value, tmp);
                return;
            }
        }
        else {
            return; // ожинаковые
        }
    }
}

TreeNode* FindTree::getMinNode(TreeNode* root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}

TreeNode* FindTree::getMaxNode(TreeNode* root) {
    while (root->right) {
        root = root->right;
    }
    return root;
}

int FindTree::HeightOfTree(TreeNode* node) {
    if (node == NULL)
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

TreeNode* FindTree::getNodeByValue(TreeNode* root, int value) {
    while (root) {
        if (CMP_GT(root->data, value)) {
            root = root->left;
            continue;
        }
        else if (CMP_LT(root->data, value)) {
            root = root->right;
            continue;
        }
        else {
            return root;
        }
    }
    return NULL;
}


void FindTree::removeNodeByPtr(TreeNode* target) {
    if (target != NULL) {
        if (target->left != NULL && target->right != NULL) {
            TreeNode* localMax = getMaxNode(target->left);
            target->data = localMax->data;
            removeNodeByPtr(localMax);
            return;
        }
        else if (target->left != NULL) {
            if (target->parent != NULL) {
                if (target == target->parent->left) {
                    target->parent->left = target->left;
                }
                else {
                    target->parent->right = target->left;
                }
            }
        }
        else if (target->right != NULL) {
            if (target->parent != NULL) {
                if (target == target->parent->right) {
                    target->parent->right = target->right;
                }
                else {
                    target->parent->left = target->right;
                }
            }
        }
        else {
            if (target->parent != NULL) {
                if (target == target->parent->left) {
                    target->parent->left = NULL;
                }
                else {
                    target->parent->right = NULL;
                }
            }
        }
        free(target);
    }
}