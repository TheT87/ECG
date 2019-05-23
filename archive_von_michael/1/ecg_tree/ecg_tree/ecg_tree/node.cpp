#include "node.h"
// Aufgabe 1.2.1
int node::node_id = 0;
// Aufgabe 1.1.1
node::node(const std::string& name)
{
	// Inkrementieren der globalen Variable
	node::node_id++;
	if (name.compare("") == 0) {
		std::stringstream str_sm;
		str_sm << node::node_id;
		std::string node_id_str = str_sm.str();
		this->name = "node_" + node_id_str;
	}
	else {
		this->name = name;
	}
}

// Aufgabe 1.1.3
node::~node()
{
	std::cout << "enter ~node() of \"" <<  this->name << "\"" << std::endl;
	for (unsigned int i = 0; i < get_nr_children(); i++) {
		delete get_child(i);
	}
	std::cout << "leave ~node() of \"" << this->name << "\"" << std::endl;
}

std::string node::get_name() const
{
	return name;
}

void node::set_name(std::string new_name)
{
	this->name = new_name;
}

int node::get_nr_children() const
{
	return children.size();
}

node* node::get_child(unsigned int i) const
{
	if (!children.empty()) {
		return children.at(i);
	}
	return NULL;
}

void node::add_child(node* child)
{
	children.push_back(child);
}

// Aufgabe 1.2.2
node* create_complete_tree(int nr_child_nodes, int tree_depth)
{
	if (tree_depth > 0)
	{
		node* newNode = new node();
		if (tree_depth > 1)
		{
			for (int i = 0; i < nr_child_nodes; i++)
			{
				newNode->add_child(create_complete_tree(nr_child_nodes, tree_depth - 1));
			}
		}
		return newNode;
	}
	return NULL;
}

// Aufgabe 1.2.3
void node::print(std::ostream &str, int depth)
{
	if (depth > 1)
	{
		for (int i = 0; i < depth; i++)
		{
			str << "  ";
		}
	}
	str << name << std::endl;
	for (unsigned int i = 0; i < get_nr_children(); i++)
	{
		children.at(i)->print(str, depth + 1);
	}
}

void operator<<(std::ostream &os, node* n)
{
	n->print(os);
}