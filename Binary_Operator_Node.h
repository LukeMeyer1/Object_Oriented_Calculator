// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef	_Binary_Operator_NODE_H_
#define _Binary_Operator_NODE_H_

#include "Tree_Node.h"

/**
* @class Binary Operator Node
*
* Defines a tree node that is composite and has 2 chidren 
* of type tree_node
*/
class Binary_Operator_Node : public Tree_Node
{
public:
	// Default constructor
	Binary_Operator_Node();

	/**
	* Initializing constructor.
	*
	* @param[in]	left_branch		left branch of the node
	*/
	Binary_Operator_Node(Tree_Node* left_branch);

	/**
	* Initializing constructor.
	*
	* @param[in]	left_branch		left branch of the node
	* @param[in]	right_branch	right branch of the node
	*/
	//Binary_Operator_Node(Tree_Node*& left_branch, Tree_Node*& right_branch);

	// Destructor
	~Binary_Operator_Node(void);

	/// Returns the product of the operation on the left and right branches
	int eval();

protected:
	Tree_Node * left_branch_;
	Tree_Node * right_branch_;
};

#include "Binary_Operator_Node.cpp"

#endif   // !defined _Binary_Operator_NODE_H_