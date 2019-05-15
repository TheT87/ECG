#include <iostream>
#include <vector>

#include "node.h"
#include "node.cpp"


int main() {
    Node node("");

    Node *root = new Node((""));
    root->create_complete_tree(2,4);
    cout<<root;
    delete root;


}