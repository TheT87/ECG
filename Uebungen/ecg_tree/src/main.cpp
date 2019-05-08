#include <iostream>
#include <vector>

#include "node.h"
#include "node.cpp"


int main() {


    Node *root = new Node("",0);
    root->create_complete_tree(2, 4);
    delete root;


}