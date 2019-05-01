//
// Created by Tobi on 29.04.2019.
//

#ifndef LIST_NODE_H
#define LIST_NODE_H


#include <string>
#include <vector>
using namespace std;

class node {

private:
    string name;
    vector<node *> children;

public:
    node(string name);
    virtual ~node();


    void set_Name(std::string new_name);

    string get_Name();

    int get_nr_children();

    void add_child(node *child);

    node* get_child(int i);

};
#endif //LIST_NODE_H
