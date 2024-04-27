// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef	_NUMBER_NODE_H_
#define _NUMBER_NODE_H_

#include "Tree_Node.h"

/**
* @class Number Node
*
* Tree Node that defines a number.
* Is a leaf node of the tree
*/
class Number_Node : public Tree_Node
{
public:
	// Default constructor
	Number_Node (int num);

	// Destructor
	~Number_Node (void);

	// Returns the number node's value
	virtual int eval(void);

	// prints the value of num_
	virtual void print(void);

private:
	// Value of the number node
	int num_;
};

#include "Number_Node.cpp"

#endif   // !defined _Number_NODE_H_