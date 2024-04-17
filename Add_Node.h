// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef	_ADD_NODE_H_
#define _ADD_NODE_H_

#include "Binary_Operator_Node.h"

/**
* @class Add Node
*
* Base node class by which all other operation and number nodes derive from
*/
class Add_Node : public Binary_Operator_Node
{
public:
	// Default constructor
	Add_Node();

	/**
	* Initializing constructor.
	*
	* @param[in]	left_branch		left branch of the node
	*/
	Add_Node(Tree_Node* left_branch);

	/**
	* Initializing constructor.
	*
	* @param[in]	left_branch		left branch of the node
	* @param[in]	right_branch	right branch of the node
	*/
	Add_Node(Tree_Node* left_branch, Tree_Node* right_branch);

	// Destructor
	~Add_Node(void);

	/// Returns the number node's value
	int eval(void);
};

#include "Add_Node.cpp"

#endif   // !defined _ADD_NODE_H_