// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef	_DIVIDE_NODE_H_
#define _DIVIDE_NODE_H_

#include "Binary_Operator_Node.h"

/**
* @class Divide Node
*
* Divides 2 branch nodes
*/
class Divide_Node : public Binary_Operator_Node
{
public:
	// Default constructor
	Divide_Node();

	/**
	* Initializing constructor.
	*
	* @param[in]	left_branch		left branch of the node
	*/
	Divide_Node(Tree_Node* left_branch);

	/**
	* Initializing constructor.
	*
	* @param[in]	left_branch		left branch of the node
	* @param[in]	right_branch	right branch of the node
	*/
	Divide_Node(Tree_Node* left_branch, Tree_Node* right_branch);

	// Destructor
	~Divide_Node(void);

	/// Traverses the tree
	virtual void accept(Tree_Node_Visitor& v);
};

#include "Divide_Node.cpp"

#endif   // !defined _DIVIDE_NODE_H_