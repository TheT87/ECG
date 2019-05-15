//
// Created by Tobi on 29.04.2019.
//

#ifndef LIST_NODE_H
#define LIST_NODE_H


#include <string>
#include <vector>


using namespace std;

class Node {

private:
    string name;
    vector<Node*> children;

public:

    Node(const string &name);
    virtual ~Node();

    string print(ostream &str,Node &node);
    friend ostream &operator<<(ostream &os, Node &node);

    void set_Name(string new_name);
    string get_Name();
    int get_nr_children();
    void add_child(Node *child);
    Node* get_child(int i);
    void create_complete_tree(int nr_child_Node, int tree_depth);



};
#endif //LIST_NODE_H
