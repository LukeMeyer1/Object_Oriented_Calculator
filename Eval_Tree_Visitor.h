// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef	_EVAL_TREE_VISITOR_H_
#define _EVAL_TREE_VISITOR_H_

#include "Tree_Node_Visitor.h"

/**
* @class Binary Operator Node
*
* Defines a tree node that is composite and has 2 chidren
* of type tree_node
*/
class Eval_Tree_Visitor : public Tree_Node_Visitor
{
public:
	// Default constructor
	Eval_Tree_Visitor();

	// Destructor
	~Eval_Tree_Visitor(void);

	// Methods for visiting concrete nodes
	void Visit_Number_Node(const Number_Node & node);
};

#include "Eval_Tree_Visitor.cpp"

#endif   // !defined _EVAL_TREE_VISITOR_H_
