// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef	_MODULO_NODE_H_
#define _MODULO_NODE_H_

#include "Binary_Operator_Node.h"

/**
* @class Modulo Node
*
* Finds the remainder after deviding 2 nodes
*/
class Modulo_Node : public Binary_Operator_Node
{
public:
	// Default constructor
	Modulo_Node();

	/**
	* Initializing constructor.
	*
	* @param[in]	left_branch		left branch of the node
	*/
	Modulo_Node(Tree_Node* left_branch);

	/**
	* Initializing constructor.
	*
	* @param[in]	left_branch		left branch of the node
	* @param[in]	right_branch	right branch of the node
	*/
	Modulo_Node(Tree_Node* left_branch, Tree_Node* right_branch);

	// Destructor
	~Modulo_Node(void);

	/// Returns the number node's value
	int eval(void);
};

#include "Modulo_Node.cpp"

#endif   // !defined _MODULO_NODE_H_