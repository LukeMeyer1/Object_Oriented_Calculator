// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Postfix_Expr.h"


// 
// Postfix_Expr 
//
Postfix_Expr::Postfix_Expr(Stack<int> & res)
	: result_(&res)
{ }

//
// ~Postfix_Expr
//
Postfix_Expr::~Postfix_Expr(void)
{ }

//
// reset
//
void Postfix_Expr::reset(void)
{
	this->expr_.resize(0);
	this->result_.clear();
}

//
// append
//
void Postfix_Expr::append(Command* com)
{
	expr_.resize(expr_.size() + 1);
	expr_.set(expr_.size() - 1, com);
}

//
// eval
//
int Postfix_Expr::eval(void)
{
	for (int i = 0; i < expr_.size(); ++i)
	{
		expr_.get(i)->execute();
	}
	return result_->pop();
}