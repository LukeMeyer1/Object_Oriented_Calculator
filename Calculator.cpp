// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Calculator.h"
#include <memory>


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
	std::cout << "pre get expression" << std::endl;
	std::unique_ptr <Math_Expression> expr(this->builder_->get_expression());
	std::cout << "post get expression" << std::endl;
	//if (nullptr == expr.get())
	//	throw std::runtime_exception(“No expression!!”);
	// evaluate the expression
	std::cout << "pre eval" << std::endl;
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