// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef	_EXPRESSION_BUILDER_H_
#define _EXPRESSION_BUILDER_H_

#include "Expression_Parser.h"

/**
* @class Expression Builder
*
* Abstract class defining an expression builder
*/
class Expression_Builder
{
public:
	// Build methods
	virtual void build_number(int num) = 0;
	virtual void build_add_operator(void) = 0;
	virtual void build_subtract_operator(void) = 0;
	virtual void build_multiply_operator(void) = 0;
	virtual void build_divide_operator(void) = 0;
	virtual void build_modulo_operator(void) = 0;

	// starts a new expression
	virtual void start_expression(void) = 0;

	// empties stack into postfix
	virtual void end_expression(void) = 0;

	// returns postfix expression
	virtual Math_Expression * get_expression(void) = 0;

	/**
	* Creates a parser for the builder to work with
	* 
	* @retval	Expression_Parser&		parser object that will work with the builder
	*/
	virtual Expression_Parser& parser(void) = 0;
};

#endif   // !defined _EXPRESSION_BUILDER_H_