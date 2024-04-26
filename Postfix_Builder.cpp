// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Postfix_Builder.h"


// 
// Postfix_Builder 
//
Postfix_Builder::Postfix_Builder(Stack<int>& result)
	: postfix_(new Postfix_Expr(result)),
	factory_(new Stack_Command_Factory(result)),
	temp_(Stack <Operator_Command*>())
{ }

// 
// Postfix_Builder 
//
Postfix_Builder::Postfix_Builder(Postfix_Builder& builder)
	:postfix_(builder.postfix_),
	factory_(builder.factory_),
	temp_(Stack <Operator_Command*>())
{ }

//
// ~Postfix_Builder
//
Postfix_Builder::~Postfix_Builder(void)
{ }

//
// build number
//
void Postfix_Builder::build_number(int num)
{
	postfix_.append(factory_.create_number_command(num));
}

//
// build add
//
void Postfix_Builder::build_add_operator(void)
{
	
	operator_onto_stack(factory_.create_add_command());
}

//
// build subtract
//
void Postfix_Builder::build_subtract_operator(void)
{
	operator_onto_stack(factory_.create_subtract_command());
}

//
// build multiply
//
void Postfix_Builder::build_multiply_operator(void) 
{
	operator_onto_stack(factory_.create_multiply_command());
}

//
// build divide
//
void Postfix_Builder::build_divide_operator(void)
{
	operator_onto_stack(factory_.create_divide_command());
}

//
// build modulo
//
void Postfix_Builder::build_modulo_operator(void)
{
	operator_onto_stack(factory_.create_modulo_command());
}

//
//	start expression
//
void Postfix_Builder::start_expression(void)
{
	this->postfix_.reset();
	this->temp_.clear();
}

//
//	end expression
//
void Postfix_Builder::end_expression(void)
{
	while (!(this->temp_.is_empty())) {
		this->postfix_.append(this->temp_.pop());
	}
	postfix_.print();
}

//
//	postfix
//
Postfix_Expr Postfix_Builder::postfix(void)
{
	return this->postfix_;
}

//
// operator onto stack
//
void Postfix_Builder::operator_onto_stack(Operator_Command * cmd)
{
	// push command at top of stk onto postfix until reach command of lesser or equal priority as cmd
	while ((this->temp_.size() > 0) and (cmd->priority() <= this->temp_.top()->priority())) {
		this->postfix_.append(this->temp_.pop());
	}
	// push add command onto the stack
	this->temp_.push(cmd);
}
