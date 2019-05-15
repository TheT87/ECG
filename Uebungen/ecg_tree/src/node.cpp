
#include "node.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <sstream>

static int Node_id{0};
int indent=0;
int tree_depth;
string Node_id_str;



Node::Node(const string &name): name(""){
    if (name.empty()) {
        Node_id++;
        stringstream str_sm;
        for (int j=1; j<indent;j++) {
            str_sm<<"    ";
        }
        str_sm<<"Node_"<<endl;
        str_sm << Node_id;
        //cout<<Node_id_str;
        Node_id_str = str_sm.str();

        this->name = Node_id_str;
    }else {
        this->name = name;
    }
}

Node::~Node() {
    for(Node* n : children){
        delete n;
    }
}
ostream &operator<<(ostream &os, Node &node){
    cout<<"test2";
    os<<"node_"<<(node.print(os,node))<<endl;
    return os;
}


void Node::create_complete_tree(int nr_child_Node, int tree_depth) {
    stringstream str_sm;
    if (tree_depth == 1){
        return;
    }
    indent++;
    for (int i = 0; i < nr_child_Node; i++){
        // Wird für richtige Indentation des zweiten Teilbaums benötigt
        if (tree_depth==4){
            indent++;
        }

        add_child(new Node(("")));
        //cout<<" "<<"indent: "<<indent<<" td: "<<tree_depth<<endl;
        get_child(i)->create_complete_tree(nr_child_Node, tree_depth-1);
        indent=indent-((tree_depth)-(nr_child_Node));
    }
}


string Node::print(ostream &str,Node &node){
    create_complete_tree(2, 4);
    return Node_id_str;


}


void Node::set_Name(string new_name){
    this->name = new_name;
}

string Node::get_Name() {
    return name;
}

int Node::get_nr_children(){
    return children.size();
}


void Node::add_child(Node *child) {
    //child->set_Parent(this);
    children.push_back(child);
}

Node* Node::get_child(int i) {
    {
        if(children.size() < i)
            return nullptr;
        else
            return children.at(i);
    }
}



