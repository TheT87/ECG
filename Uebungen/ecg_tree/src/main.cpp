#include <iostream>
#include <vector>

#include "node.h"
#include "node.cpp"


int main() {


    node *root = new node("root");
    root->add_child(new node("left child"));
    root->add_child(new node("right child"));



    delete root;

}