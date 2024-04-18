// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef	_TREE_NODE_VISITOR_H_
#define _TREE_NODE_VISITOR_H_

#include "Tree_Node.h"

/**
* @class Binary Operator Node
*
* Defines a tree node that is composite and has 2 chidren
* of type tree_node
*/
class Tree_Node_Visitor
{
public:
	// Destructor
	~Tree_Node_Visitor(void);

	// Methods for visiting concrete nodes
	virtual void Visit_Number_Node(const Tree_Node & node) = 0;
};

#endif   // !defined _TREE_NODE_VISITOR_H_