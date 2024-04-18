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
{ 
	delete this->result_;
}

//
// append
//
void Postfix_Expr::append(Command& com)
{
	expr_.resize(expr_.size() + 1);
	expr_.set(expr_.size() - 1, com)
}

//
// eval
//
int Postfix_Expr::eval(void)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		arr.get(i)->execute();
	}
	return result_->pop();
}