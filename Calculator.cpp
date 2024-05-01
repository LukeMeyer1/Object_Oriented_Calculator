// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Calculator.h"

//
// Calculator
//
Calculator::Calculator(Expression_Builder * builder)
	: builder_(builder) 
{ }

//
// ~Calculator
//
Calculator::~Calculator(void)
{ }

//
// evaluate (const std::string &)
//
int Calculator::evaluate(const std::string& infix)
{
	if (!this->parse_expr(infix))
		throw std::runtime_error("Bad Expression");
	this->builder_->get_expression()->print();
	if (nullptr == this->builder_->get_expression())
		throw std::runtime_error("No Expression");
	std::cout << "parsed" << std::endl;
	return this->builder_->get_expression()->eval();
}

//
// parse_expr (const std::string &)
// 
bool Calculator::parse_expr(const std::string & infix)
{
	Expression_Parser * p = this->builder_->parser();
	bool finished = p->parse(infix);
	this->builder_->get_expression()->print();
	return finished;
}