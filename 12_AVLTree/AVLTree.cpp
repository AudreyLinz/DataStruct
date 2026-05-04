#include "AVLTree.hpp"
#include <iostream>
#include <algorithm>

template <typename T>
AVLTree<T>::AVLTree() {
    root = nullptr;
}

template <typename T>
bool AVLTree<T>::empty() const {
    return root == nullptr;
}

// --- Traversals and Helpers ---

template <typename T>
void AVLTree<T>::inorder() const {
    std::cout << "Inorder: [ ";
    inorder(root);
    std::cout << "]\n";
}

template <typename T>
void AVLTree<T>::inorder(AVLNode<T>* node) const {
    if (!node) return;
    inorder(node->left);
    std::cout << node->data << ' ';
    inorder(node->right);
}

template <typename T>
int AVLTree<T>::getHeight(const AVLNode<T>* node) const {
    // Convention: null nodes have height -1, leaves have height 0
    return (node == nullptr) ? -1 : node->height;
}

template <typename T>
int AVLTree<T>::getBalance(const AVLNode<T>* node) const {
    if (!node) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// --- Rotations ---

template <typename T>
void AVLTree<T>::rotateRightRef(AVLNode<T>*& node) {
    if (!node || !node->left) return;

    AVLNode<T>* left_kid = node->left;
    node->left = left_kid->right;
    left_kid->right = node;

    // Update heights: start with the one that moved down
    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
    left_kid->height = 1 + std::max(getHeight(left_kid->left), getHeight(left_kid->right));

    node = left_kid;
}

template <typename T>
void AVLTree<T>::rotateLeftRef(AVLNode<T>*& node) {
    if (!node || !node->right) return;

    AVLNode<T>* right_kid = node->right;
    node->right = right_kid->left;
    right_kid->left = node;

    // Update heights
    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
    right_kid->height = 1 + std::max(getHeight(right_kid->left), getHeight(right_kid->right));

    node = right_kid;
}

template <typename T>
void AVLTree<T>::rotateLeftDoubleRef(AVLNode<T>*& node) {
    if (!node || !node->right) return;
    rotateRightRef(node->right);
    rotateLeftRef(node);
}

template <typename T>
void AVLTree<T>::rotateRightDoubleRef(AVLNode<T>*& node) {
    if (!node || !node->left) return;
    rotateLeftRef(node->left);
    rotateRightRef(node);
}

// --- Balancing ---

template <typename T>
void AVLTree<T>::balance(AVLNode<T>*& node) {
    if (!node) return;

    int bf = getBalance(node);

    // Left Heavy
    if (bf > 1) {
        if (getBalance(node->left) >= 0) {
            rotateRightRef(node); // LL Case
        } else {
            rotateRightDoubleRef(node); // LR Case
        }
    }
    // Right Heavy
    else if (bf < -1) {
        if (getBalance(node->right) <= 0) {
            rotateLeftRef(node); // RR Case
        } else {
            rotateLeftDoubleRef(node); // RL Case
        }
    }
}

// --- Insert ---

template <typename T>
void AVLTree<T>::insert(const T& val) {
    insert(val, root);
}

template <typename T>
void AVLTree<T>::insert(const T& val, AVLNode<T>*& node) {
    if (!node) {
        node = new AVLNode<T>(val);
    } else if (val < node->data) {
        insert(val, node->left);
    } else if (val > node->data) {
        insert(val, node->right);
    } else {
        return; // Duplicate
    }

    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
    balance(node);
}

// --- Remove ---

template <typename T>
void AVLTree<T>::remove(const T& val) {
    remove(val, root);
}

template <typename T>
void AVLTree<T>::remove(const T& val, AVLNode<T>*& node) {
    if (!node) return;

    if (val < node->data) {
        remove(val, node->left);
    } else if (val > node->data) {
        remove(val, node->right);
    } else {
        // Node found
        if (!node->left || !node->right) {
            AVLNode<T>* temp = node->left ? node->left : node->right;
            if (!temp) {
                temp = node;
                node = nullptr;
            } else {
                *node = *temp; // Copy child to current
            }
            delete temp;
        } else {
            // Two children
            AVLNode<T>* temp = getMinNode(node->right);
            node->data = temp->data;
            remove(temp->data, node->right);
        }
    }

    if (!node) return;

    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
    balance(node);
}

template <typename T>
AVLNode<T>* AVLTree<T>::getMinNode(AVLNode<T>* node) const {
    if (!node) return nullptr;
    while (node->left) node = node->left;
    return node;
}

// --- Visualization ---

template <typename T>
void AVLTree<T>::print() const {
    std::cout << "===============================\n";
    print("", root, false);    
    std::cout << "===============================\n";
}

template <typename T>
void AVLTree<T>::print(const std::string& prefix, AVLNode<T>* node, bool isRight) const {
    if (!node) return;

    std::cout << prefix;
    if (node != root) {
        std::cout << (isRight ? "R----" : "L----");
    } else {
        std::cout << "---";
    }

    std::cout << '[' << node->data <<  ", H:" << node->height << ", B:" << getBalance(node) << ']' << std::endl;

    print(prefix + "      ", node->right, true);
    print(prefix + "      ", node->left, false);
}