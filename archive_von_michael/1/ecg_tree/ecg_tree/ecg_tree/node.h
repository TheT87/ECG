#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <stack>

class node
{
public:
	node(const std::string& name = "");
	virtual ~node();
	std::string get_name() const;
	void set_name(std::string new_name);
	int get_nr_children() const;
	node* get_child(unsigned int i) const;
	void add_child(node* child);
	static int node_id;
	// 1.2.3
	void print(std::ostream &str, int depth = 1);
	void print_it();
private:
	std::string name;
	std::vector<node*> children;
};

node* create_complete_tree(int nr_child_nodes, int tree_depth);
extern void operator<<(std::ostream &os, node* n);