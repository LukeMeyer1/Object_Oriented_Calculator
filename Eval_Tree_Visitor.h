// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef	_EVAL_TREE_VISITOR_H_
#define _EVAL_TREE_VISITOR_H_

#include "Tree_Node_Visitor.h"

/**
* @class Eval Tree Visitor
*
* Visitor class for objects of type tree node that evaluates the tree
*/
class Eval_Tree_Visitor : public Tree_Node_Visitor
{
public:
	// Default Constructor
	Eval_Tree_Visitor(void);
	
	// Destructor
	~Eval_Tree_Visitor(void);

		//Methods for visiting Nodes
	// Visit Number Node
	void Visit_Number_Node(const Number_Node& node);

	// Visit Add Node
	void Visit_Add_Node(const Add_Node& node);

	// Visit Subtract Node
	void Visit_Subtract_Node(const Subtract_Node& node);

	// Visit Multiply Node
	void Visit_Multiply_Node(const Multiply_Node& node);

	// Visit Divide Node
	void Visit_Divide_Node(const Divide_Node& node);

	// Visit Modulo Node
	void Visit_Modulo_Node(const Modulo_Node& node);
};

#include "Eval_Tree_Visitor.cpp"

#endif   // !defined _EVAL_TREE_VISITOR_H_