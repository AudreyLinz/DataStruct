
#ifndef AVLNODE_HPP
#define AVLNODE_HPP
template <typename T>
class AVLNode {
public:
    AVLNode(const T& val = T(), AVLNode<T>* l = nullptr, AVLNode<T>* r = nullptr, int h = 0) :
    data(val), left(l), right(r), height(h) { }
    bool isLeaf() const {
        return !left && !right;
    }
    bool hasOneChild() const {
        return !isLeaf() && !hasTwoChildren();
    }
    bool hasTwoChildren() const {
        return left && right;
    }
    T data;
    AVLNode<T>* left;
    AVLNode<T>* right;
    int height;
    };
#endif
