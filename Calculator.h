// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef	_CALCULATOR_H_
#define _CALCULATOR_H_

/**
* @class Calculator
*
* Solves mathematical equations
*/
class Calculator 
{
public:
	/// Default Constructor
	Calculator(void);

	/**
	* Constructor
	* 
	* @param[in]	builder		reference to the builder that the Calculator will use
	*/
	Calculator(Expression_Builder & builder);
	
	/// Destructor
	~Calculator(void);

	/**
	* Evaluates the infix expression
	* 
	* @param[in]	infix		string representing an infix equation. Must have a space between each token
	* @retval		int			returns the solution to the infix equation.
	*/
	int evaluate(const std::string & infix);

	/**
	* Turns an infix equation into a managable form of equation
	* 
	* @param[in]	infix		string representing an infix equation. Must have a space between each token
	* @retval		bool		true if infix equation was able to be parsed and false if not.
	*/
	bool parse_expr(const std::string & infix);

private:
	/// Reference to the builder used to parse
	Expression_Builder builder_;

};

#include "Calculator.cpp"

#endif   // !defined _CALCULATOR_H_