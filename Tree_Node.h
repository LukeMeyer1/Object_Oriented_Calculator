// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef	_TREE_NODE_H_
#define _TREE_NODE_H_

/**
* @class Tree Node
*
* Base node class by which all other operation and number nodes derive from
*/
class Tree_Node
{
public:
	//Default Constructor
	Tree_Node(void);
	//Destructor
	~Tree_Node(void);

	/// Operation that is executed on the stack
	virtual int eval(void) = 0;
};

#endif   // !defined _TREE_NODE_H_