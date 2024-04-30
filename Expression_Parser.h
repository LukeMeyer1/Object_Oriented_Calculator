// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef	_EXPRESSION_PARSER_H_
#define _EXPRESSION_PARSER_H_

#include "Expression_Builder.h"

/**
* @class Expression Parser
*
* Creates math expressions from infix expressions
*/
class Expression_Parser
{
public:
	/**
	* Default Constructor
	* 
	* @param[in]	Expression_Builder	builder that the parser is working with
	*/
	Expression_Parser(Expression_Builder& builder);

	/// Destructor
	~Expression_Parser(void);

	/**
	* parses the equation
	* 
	* @retval	bool	true if equation can be parsed, false if not
	*/
	virtual bool parse(void) = 0;

private:
	/// Reference to the builder used to parse
	Expression_Builder builder_;

};

#include "Expression_Parser.cpp"

#endif   // !defined _EXPRESSION_PARSER_H_