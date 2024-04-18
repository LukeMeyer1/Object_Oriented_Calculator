// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef	_SUBTRACT_NODE_H_
#define _SUBTRACT_NODE_H_

#include "Binary_Operator_Node.h"

/**
* @class Subtract Node
*
* Subtracts 2 branch nodes 
*/
class Subtract_Node : public Binary_Operator_Node
{
public:
	// Default constructor
	Subtract_Node();

	/**
	* Initializing constructor.
	*
	* @param[in]	left_branch		left branch of the node
	*/
	Subtract_Node(Tree_Node* left_branch);

	/**
	* Initializing constructor.
	*
	* @param[in]	left_branch		left branch of the node
	* @param[in]	right_branch	right branch of the node
	*/
	Subtract_Node(Tree_Node* left_branch, Tree_Node* right_branch);

	// Destructor
	~Subtract_Node(void);

	/// Traverses the tree
	virtual void accept(Tree_Node_Visitor& v);
};

#include "Subtract_Node.cpp"

#endif   // !defined _SUBTRACT_NODE_H_