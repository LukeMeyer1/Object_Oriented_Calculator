// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef	_TREE_BUILDER_H_
#define _TREE_BUILDER_H_

#include "Expression_Builder.h"
/**
* @class Tree Builder
*
* Builder class that creates binary tree that represents an expression
*/
class Tree_Builder : public Expression_Builder
{
public:
	// Default constructor
	Tree_Builder();

	// Destructor
	~Tree_Builder(void);

	// Build methods
	void build_number(int num);
	void build_add_operator(void);
	void build_subtract_operator(void);
	void build_multiply_operator(void);
	void build_divide_operator(void);
	void build_modulo_operator(void);

	// starts a new expression
	void start_expression(void);

	// ends expression building
	void end_expression(void);

	// returns tree root node
	Tree_Node * get_expression(void);

private:
	// builds a node
	void build(Tree_Node* node);

	// traverses the tree in preorder traversal and sets the first open node 
	// to 'add'. Returns true if completed or false if no open nodes found
	bool set_first_empty_node(Binary_Operator_Node& node);

	// Array that stores the expression
	Tree_Node* tree_;
};

#include "Tree_Builder.cpp"

#endif   // !defined _TREE_BUILDER_H_