#ifndef BST_H
#define BST_H

#include <memory>
#include <iostream>

template<typename T>
class BST {
private:
    struct Node {
        T data;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;

        Node(const T& val) : data(val) {}
    };

    std::unique_ptr<Node> root;

    void insert(std::unique_ptr<Node>& node, const T& value);
    bool search(const std::unique_ptr<Node>& node, const T& value) const;
    void inorder(const std::unique_ptr<Node>& node) const;
    std::unique_ptr<Node> remove(std::unique_ptr<Node>& node, const T& value);
    Node* findMin(Node* node) const;

public:
    BST() = default;
    void insert(const T& value);
    bool search(const T& value) const;
    void remove(const T& value);
    void inorder() const;
    void clear();
};

#endif 
