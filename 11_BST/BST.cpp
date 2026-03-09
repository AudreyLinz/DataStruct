#include "BST.hpp"
#include <iostream>

template <typename T>
BST<T>::BST() {
    root = nullptr;
}

template <typename T>
bool BST<T>::empty() const {
    return root == nullptr;
}

template <typename T>
void BST<T>::insert(const T& val) {
    if (empty()) {
        root = new BTNode<T>(val);
        return;
    }
    
    // Iterative approach
    BTNode<T>* cur = root;
    BTNode<T>* prev = root;
    while (cur) {
        prev = cur;
        if (cur->data > val) {
            cur = cur->left;
        }
        else {
            cur = cur->right;
        }
    }
    if (prev->data > val) {
        prev->left = new BTNode<T>(val);   
    }
    else {
        prev->right = new BTNode<T>(val);   
    }
}

template <typename T>
void BST<T>::insert_recursive(const T& val) {
    root = insert_recursive(root, val);
}

template <typename T>
BTNode<T>* BST<T>::insert_recursive(BTNode<T>* node, const T& val) {
    if (!node) {
        return new BTNode<T>(val);
    }
    if (val > node->data) {
        node->right = insert_recursive(node->right, val);
        return node;
    } 
    else {
        node->left = insert_recursive(node->left, val);
        return node;
    }
}


template <typename T>
void BST<T>::inorder() const {
    std::cout << "Inorder: [ ";
    inorder(root);
    std::cout << "]\n";
}

template <typename T>
void BST<T>::inorder(BTNode<T>* node) const {
    if (!node) {
        return;
    }
    inorder(node->left);
    std::cout << node->data << ' ';
    inorder(node->right);
}


template <typename T>
bool BST<T>::isFullTree() const {
    return isFullTree(root);
}

template <typename T>
bool BST<T>::isFullTree(BTNode<T>* node) const {
    if (!node) {
        return true;
    }
    if (node->hasOneChild()) {
        return false;
    }
    return isFullTree(node->left) && isFullTree(node->right);
}

template <typename T>
BTNode<T>* BST<T>::search(const T& val) const {
    BTNode<T>* cur = root;

    while (cur) {
        if (cur->data == val) { // Found the value
            return cur;
        }
        else if (cur->data > val) { // Value is less than current
            cur = cur->left;
        }
        else {
            cur = cur->right;
        }
    }

    return nullptr;
}

template <typename T>
BTNode<T>* BST<T>::getMinNode(BTNode<T>* node) const {
    if (node == nullptr) { 
        return nullptr;
    }
    BTNode<T>* cur = node;
    while (cur->left != nullptr) {
        cur = cur->left;
    }
    return cur;
}

template <typename T>
BTNode<T>* BST<T>::searchParent(const T& val) const{
    if (root == nullptr || root->data == val) {
        return nullptr;
    }

    BTNode<T>* cur = root;
    while (cur != nullptr) {
        if (cur->left != nullptr && cur->left->data == val) {
            return cur;
        }
        if (cur->right != nullptr && cur->right->data == val) {
            return cur;
        }
        if (val < cur->data) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    return nullptr;
}

template <typename T>
void BST<T>::deleteLeaf(BTNode<T>* child, BTNode<T>* parent) {
    if (child == nullptr) return;

    if (parent == nullptr) {
        root = nullptr;
    } else if (parent->left == child) {
        parent->left = nullptr;
    } else if (parent->right == child) {
        parent->right = nullptr;
    }

    delete child;
}

template <typename T>
void BST<T>::deleteNodeWithOneChild(BTNode<T>* nodeToDelete, BTNode<T>* parent){
    BTNode<T>* child = nullptr;
    if (nodeToDelete->left != nullptr) {
        child = nodeToDelete->left;
    } else {
        child = nodeToDelete->right;
    }

    if (parent == nullptr) {
        root = child;
    } else if (parent->left == nodeToDelete) {
        parent->left = child;
    } else {
        parent->right = child;
    }

    delete nodeToDelete;
}

template <typename T>
void BST<T>::deleteAll() {
    deleteAll(root);
    root = nullptr;
}

template <typename T>
void BST<T>::deleteAll(BTNode<T>* node) {
    if (node == nullptr) {
        return;
    }

    deleteAll(node->left);
    deleteAll(node->right);

    delete node;
}

template <typename T>
void BST<T>::print() const{
    std::cout << "=======================\n";
    print("", root, false);
}

template <typename T>
void BST<T>::print(const std::string& prefix, BTNode<T>* node, bool isRight) const{
    if(root==nullptr){ std::cout << "empty tree" << std::endl; }
    if(!node){
        return;
    }
    std::cout << prefix;
    if(node!=root){
        std::cout << (isRight ? "R--" : "L--");
    } else {
        std::cout << "---";
    }

    //print the value of the node
    std::cout << '[' << node->data << ", " << getHeight(node)<< ", " << getBalance(node) << ']' << std::endl;

    //go to the next level of the tree
    print(prefix + "   ", node->right, true);
    print(prefix + "   ", node->left, false);
}

template<typename T>
void BST<T>::deleteNode(const T& val){
    BTNode<T>* node = search(val);
    if(!node){
        std::cout << "Delete: no value in the BST\n";
        return;
    } else if (node==root){
        std::cout << "Can't delete root\n";
        return;
    }
    BTNode<T>* parent = searchParent(val);
    if(node->isLeaf()){
        deleteLeaf(node, parent);
    } else if(node->hasOneChild()){
        deleteNodeWithOneChild(node, parent);
    } else { //node has 2 childs
        deleteNodeWithTwoChild(node);
    }
}

template<typename T>
void BST<T>::deleteNodeWithTwoChild(BTNode<T>* node){
    BTNode<T>* min_right_node = getMinNode(node->right);
    T min_val = min_right_node->data;

    if(min_right_node->isLeaf()){
        deleteLeaf(min_right_node, searchParent(min_val));
    } else if(min_right_node->hasOneChild()) {
        deleteNodeWithOneChild(min_right_node, searchParent(min_val));
    }
    node->data = min_val;
}

template<typename T>
int BST<T>::getHeight(BTNode<T>* node) const{
    if(!node){
        return 0;
    }
    int left_height = getHeight(node->left);
    int right_height = getHeight(node->right);
    return (left_height>right_height) ? left_height + 1 : right_height + 1;
}

template<typename T>
int BST<T>::getBalance(BTNode<T>* node) const{
    if(!node){
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

template<typename T>
void BST<T>::rotateRight(BTNode<T>* & node){
    if(!node || !node->left){
        return;
    }
    BTNode<T>* left_kid = node->left;
    node->left = left_kid->right;
    left_kid->right = node;
    node = left_kid;
}

template<typename T>
void BST<T>::rotateValRight(const T& val) {
    if (root != nullptr && root->data == val) {
        rotateRight(root);
        return;
    }

    BTNode<T>* parent = searchParent(val);
    if (!parent) return;

    if (parent->left != nullptr && parent->left->data == val) {
        rotateRight(parent->left);
    } else if (parent->right != nullptr && parent->right->data == val) {
        rotateRight(parent->right);
    }
}

template<typename T>
void BST<T>::rotateLeft(BTNode<T>* & node){
    if(!node || !node->right){
        return;
    }
    BTNode<T>* right_kid = node->right;
    node->right = right_kid->left;
    right_kid->left = node;
    node = right_kid;
}

template<typename T>
void BST<T>::rotateValLeft(const T& val) {
    if (root != nullptr && root->data == val) {
        rotateLeft(root);
        return;
    }
    

    BTNode<T>* parent = searchParent(val);
    if (!parent) return;

    if (parent->left != nullptr && parent->left->data == val) {
        rotateLeft(parent->left); // Corrected
    } else if (parent->right != nullptr && parent->right->data == val) {
        rotateLeft(parent->right); // Corrected
    }
}

template <typename T>
void BST<T>::balance() {
    balance(root);
}

template <typename T>
void BST<T>::balance(BTNode<T>*& node) {
    if (!node) return;

    // 1. Recursively balance subtrees first (Bottom-up approach)
    balance(node->left);
    balance(node->right);

    // 2. Calculate balance factor
    int bf = getBalance(node);

    // 3. Left-Heavy Cases
    if (bf > 1) { 
        if (getBalance(node->left) >= 0) {
            rotateRight(node);
        } else {
            rotateLeft(node->left); 
            rotateRight(node);    
        }
    }
    // 4. Right-Heavy Cases
    else if (bf < -1) { 
        if (getBalance(node->right) <= 0) {
            // Case 3: Right-Right (RR) -> Single Left Rotation
            rotateLeft(node);
        } else {
            // Case 4: Right-Left (RL) -> Double Rotation
            rotateRight(node->right); // Rotate child right
            rotateLeft(node);         // Rotate node left
        }
    }
}

template <typename T>
void BST<T>::rotateLeftDoubleRef(BTNode<T>*& node) {
    if (!node || !node->right) {
        return;
    }
    rotateRightRef(node->right);
    rotateLeftRef(node);
}

template <typename T>
void BST<T>::rotateRightDoubleRef(BTNode<T>*& node) {
    if (!node || !node->left) {
        return;
    }
    rotateRightRef(node->left);
    rotateLeftRef(node);
}