// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef	_MULTIPLY_NODE_H_
#define _MULTIPLY_NODE_H_

#include "Binary_Operator_Node.h"

/**
* @class Multiply Node
*
* Multiplies 2 branch nodes
*/
class Multiply_Node : public Binary_Operator_Node
{
public:
	// Default constructor
	Multiply_Node();

	/**
	* Initializing constructor.
	*
	* @param[in]	left_branch		left branch of the node
	*/
	Multiply_Node(Tree_Node* left_branch);

	/**
	* Initializing constructor.
	*
	* @param[in]	left_branch		left branch of the node
	* @param[in]	right_branch	right branch of the node
	*/
	Multiply_Node(Tree_Node* left_branch, Tree_Node* right_branch);

	// Destructor
	~Multiply_Node(void);

	/// Returns the number node's value
	int eval(void);
};

#include "Multiply_Node.cpp"

#endif   // !defined _MULTIPLY_NODE_H_