
#include "Node.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>

static int Node_id{1};
int indent=0;
int tree_depth;
stringstream str_sm;




Node::Node(const string &name,int indent): name(""){
    if (name.empty()) {
        string string1;


        for (int j=1; j<indent;j++) {
            string1.insert(0,"    ");

        }

        cout<<string1<< "Node_" << Node_id<<endl;

        Node_id++;


        this->name = str_sm.str();

    } else {
        Node_id++;
        this->name = name;
    }

}

Node::~Node() {


    for(Node* n : children)
    {
        delete n;
    }

    //cout<<"leave ~Node() of" <<'"'<<get_Name()<<'"'<<"\n";
}

string Node::print(Node *Node1, int indent) {
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




void Node::create_complete_tree(int nr_child_Node, int tree_depth) {


    if (tree_depth == 1){
        return;
    }


    indent++;
    for (int i = 0; i < nr_child_Node; i++){

        // Wird für richtige Indentation des zweiten Teilbaums benötigt
        if (tree_depth==4){
            indent++;

        }
        add_child(new Node("",indent));
        cout<<"\t\t\t\t\t"<<"indent: "<<indent<<" tree_d: "<<tree_depth<<" otd: "<<org_tree_depth<<endl;
        get_child(i)->create_complete_tree(nr_child_Node, tree_depth-1);

        indent=indent-((tree_depth)-(nr_child_Node));

    }





    // todo: set Node to new Node.

    //create_complete_tree(nr_child_Node, tree_depth-1);
}




