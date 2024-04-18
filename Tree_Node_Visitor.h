// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef	_TREE_NODE_VISITOR_H_
#define _TREE_NODE_VISITOR_H_

/**
* @class Tree Node Visitor
*
* Visitor class for objects of type tree node
*/
class Tree_Node_Visitor
{
public:
	// Destructor
	~Tree_Node_Visitor(void);

		//Methods for visiting Nodes
	
	// Visit Number Node
	void Visit_Number_Node(const Number_Node & node) = 0;
	
	// Visit Add Node
	void Visit_Add_Node(const Add_Node & node) = 0;
	
	// Visit Subtract Node
	void Visit_Subtract_Node(const Subtract_Node & node) = 0;
	
	// Visit Multiply Node
	void Visit_Multiply_Node(const Multiply_Node & node) = 0;

	// Visit Divide Node
	void Visit_Divide_Node(const Divide_Node & node) = 0;

	// Visit Modulo Node
	void Visit_Modulo_Node(const Modulo_Node & node) = 0;
};

#endif   // !defined _TREE_NODE_VISITOR_H_