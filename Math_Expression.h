// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef	_MATH_EXPRESSION_H_
#define _MATH_EXPRESSION_H_

/**
* @class Math Expression
*
* Abstract class for math expressions
*/
class Math_Expression
{
public:

	Math_Expression(void);

	~Math_Expression(void);

	// Returns the expressions value
	virtual int eval(void) = 0;

	virtual void reset(void) = 0;

	virtual void append(Command* com) = 0;

	virtual void print(void) = 0;
};

#include "Math_Expression.cpp"

#endif   // !defined _MATH_EXPRESSION_H_