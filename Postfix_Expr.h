// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef	_POSTFIX_EXPR_H_
#define _POSTFIX_EXPR_H_

/**
* @class Postfix Expr
*
* Array of Commands that represents a postfix expression
*/
class Postfix_Expr
{
public:
	// Default constructor
	Postfix_Expr(Stack<int> & res);

	// Destructor
	~Postfix_Expr(void);

	// Increases size by one and adds command to end of expr
	void append(Command* com);

	// empties the array
	void reset(void);

	// Returns the expressions value
	virtual int eval(void);

	// Prints postfix expression
	void print(void);

private:
	// Array that stores the expression
	Array<Command*> expr_;
	// Pointer to stack that commands are operating on
	Stack<int>* result_;
};

#include "Postfix_Expr.cpp"

#endif   // !defined _POSTFIX_EXPR_H_