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
	std::cout << "pre parse" << std::endl;
	this->parse_expr(infix);
	std::cout << "post parse" << std::endl;
	//if (!this->parse_expr(infix))
	//	throw std::runtime_exception(“Bad expresssion”);
	return this->builder_->get_expression()->eval();
	std::cout << "pre get expression" << std::endl;
	//Math_Expression expr();
	std::cout << "post get expression" << std::endl;
	//if (nullptr == expr.get())
	//	throw std::runtime_exception(“No expression!!”);
	// evaluate the expression
	//expr->print();
	std::cout << std::endl << "pre eval" << std::endl;
	return expr->eval();
}

//
// parse_expr (const std::string &)
// 
bool Calculator::parse_expr(const std::string & infix)
{
	Expression_Parser * p = this->builder_->parser();
	return p->parse(infix);
}