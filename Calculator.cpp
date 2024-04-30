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
Calculator::Calculator(Postfix_Builder& builder)
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
	this->parse_expr(infix);
	//if (!this->parse_expr(infix))
	//	throw std::runtime_exception(“Bad expresssion”);
	std::unique_ptr <Math_Expression> expr(this->builder_.get_expression());
	//if (nullptr == expr.get())
	//	throw std::runtime_exception(“No expression!!”);
	// evaluate the expression
	return expr->eval();
}

//
// parse_expr (const std::string &)
// 
bool Calculator::parse_expr(const std::string & infix)
{
	Postfix_Parser * p = this->builder_.parser();
	p->parse();
}