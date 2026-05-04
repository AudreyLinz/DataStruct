#ifndef BST_HPP
#define BST_HPP
#include "BTNode.hpp"
#include <string>


template <typename T>
class BST {
public:
    BST();
    
    bool empty() const;
    void insert(const T& val);
    void insert_recursive(const T& val);

    // Traversals of the tree
    void inorder() const;
    void preorder() const;
    void postorder() const;

    bool isFullTree() const;
    BTNode<T>* search(const T& val) const;

    BTNode<T>* getMinNode(BTNode<T>* node) const;
    BTNode<T>* searchParent(const T& val) const;
    void deleteLeaf(BTNode<T>* child, BTNode<T>* parent);
    void deleteNodeWithOneChild(BTNode<T>* nodeToDelete, BTNode<T>* parent);
    void deleteAll();

    void deleteNode(const T& val);

    void print() const;

    int getHeight(BTNode<T>* node) const;

    int getBalance(BTNode<T>* node) const;

    void rotateRight(BTNode<T>* & node);
    void rotateValRight(const T& val);

    void rotateLeft(BTNode<T>* & node);
    void rotateValLeft(const T& val);
    void rotateLeftDoubleRef(BTNode<T>*& node);
    void rotateRightDoubleRef(BTNode<T>*& node); // TODO
    void balance();
    //final practice functions:
    T extractMax();

private:
    BTNode<T>* root;
    void inorder(BTNode<T>* node) const;
    void preorder(BTNode<T>* node) const;
    void postorder(BTNode<T>* node) const;
    bool isFullTree(BTNode<T>* node) const;
    BTNode<T>* insert_recursive(BTNode<T>* node, const T& val);
    void deleteAll(BTNode<T>* node);
    void print(const std::string& prefix, BTNode<T>* node, bool isRight) const;
    void deleteNodeWithTwoChild(BTNode<T>* node);
    void balance(BTNode<T>*& node);
};

#endif