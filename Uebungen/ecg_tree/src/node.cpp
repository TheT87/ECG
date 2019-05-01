
#include "node.h"
#include <string>
#include <vector>
#include <iostream>



    node::node(string name) {
        this->name = name;
        cout<<"enter ~node() of" <<'"'<<name<<'"'<<"\n";
}

    node::~node() {

        for( int i=0; i < get_nr_children(); i++ ) {
            delete children.at(i);
    }
        cout<<"leave ~node() of" <<'"'<<name<<'"'<<"\n";
}



    void node::set_Name(string new_name){
        this->name = new_name;
}
    string node::get_Name() {
        return name;
}
    int node::get_nr_children(){
        return children.size();
}


    void node::add_child(node *child) {
    //child->set_Parent(this);
    children.push_back(child);
}
    node* node::get_child(int i) {
        {
            if(children.size() < i)
                return nullptr;
            else
                return children[i];
        }
}




