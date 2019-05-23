#include "node.h"

int main(int argc, char* argv[])
{
	// Aufgabe 1.1.2
	node* root = new node("root");
	node* leftChild = new node("left child");
	node* rightChild = new node("right child");
	root->add_child(leftChild);
	root->add_child(rightChild);
	delete root;
	std::cout << "\n";
	// Aufgabe 1.2.2
	node::node_id = 0;
	node* completeTree = create_complete_tree(2, 4);
	// Aufgabe 1.2.3
	std::cout << completeTree;
	std::cout << "\n";
	return 0;
}