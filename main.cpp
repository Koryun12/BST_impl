//Usage EXample
#include "BST.h"
#include <string>

int main() {
    BST<int> tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    tree.inorder(); 

    tree.remove(50);
    tree.inorder(); 

    std::cout << std::boolalpha << tree.search(60) << '\n'; // true
    std::cout << tree.search(100) << '\n'; // false 

    tree.clear();
    tree.inorder(); 

    return 0;
}
