// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef	_POSTFIX_BUILDER_H_
#define _POSTFIX_BUILDER_H_

/**
* @class Postfix Builder
*
* Array of Commands that represents a postfix expression
*/
class Postfix_Builder
{
public:
	// Default constructor
	Postfix_Builder(Stack<int>& result);

	// Creates a builder that builds on the same postfix expression
	// but has an empty temp command stack
	Postfix_Builder(Postfix_Builder& builder);

	// Destructor
	~Postfix_Builder(void);

	// Build methods
	void build_number(int num);
	void build_add_operator(void);
	void build_subtract_operator(void);
	void build_multiply_operator(void);
	void build_divide_operator(void);
	void build_modulo_operator(void);

	// starts a new expression
	void start_expression(void);

	// empties stack into postfix
	void end_expression(void);

	// returns postfix expression
	Postfix_Expr * postfix(void);

private:
	// helper function to add operator onto temp stack
	void operator_onto_stack(Operator_Command * cmd);

	// Array that stores the expression
	Postfix_Expr * postfix_;
	// Factory that builds command
	Stack_Command_Factory * factory_;
	// Temporary operator stack
	Stack <Operator_Command*> temp_;
};

#include "Postfix_Builder.cpp"

#endif   // !defined _POSTFIX_BUILDER_H_