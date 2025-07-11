#include "BST.h"

template<typename T>
void BST<T>::insert(const T& value) {
    insert(root, value);
}

template<typename T>
void BST<T>::insert(std::unique_ptr<Node>& node, const T& value) {
    if (!node) {
        node = std::make_unique<Node>(value);
    } else if (value < node->data) {
        insert(node->left, value);
    } else if (value > node->data) {
        insert(node->right, value);
    }
}

template<typename T>
bool BST<T>::search(const T& value) const {
    return search(root, value);
}

template<typename T>
bool BST<T>::search(const std::unique_ptr<Node>& node, const T& value) const {
    if (!node) return false;
    if (value == node->data) return true;
    return value < node->data ? search(node->left, value) : search(node->right, value);
}

template<typename T>
void BST<T>::inorder() const {
    inorder(root);
    std::cout << '\n';
}

template<typename T>
void BST<T>::inorder(const std::unique_ptr<Node>& node) const {
    if (node) {
        inorder(node->left);
        std::cout << node->data << ' ';
        inorder(node->right);
    }
}

template<typename T>
void BST<T>::remove(const T& value) {
    root = remove(root, value);
}

template<typename T>
std::unique_ptr<typename BST<T>::Node> BST<T>::remove(std::unique_ptr<Node>& node, const T& value) {
    if (!node) return nullptr;

    if (value < node->data) {
        node->left = remove(node->left, value);
    } else if (value > node->data) {
        node->right = remove(node->right, value);
    } else {
      
        if (!node->left && !node->right) {
            return nullptr;
        }
    
        if (!node->left) return std::move(node->right);
        if (!node->right) return std::move(node->left);

        Node* minRight = findMin(node->right.get());
        node->data = minRight->data;
        node->right = remove(node->right, minRight->data);
    }

    return std::move(node);
}

template<typename T>
typename BST<T>::Node* BST<T>::findMin(Node* node) const {
    while (node && node->left) {
        node = node->left.get();
    }
    return node;
}

template<typename T>
void BST<T>::clear() {
    root.reset(); 
}


template class BST<int>;
template class BST<std::string>;
