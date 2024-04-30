// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef	_EXPRESSION_PARSER_H_
#define _EXPRESSION_PARSER_H_

/**
* @class Expression Parser
*
* Creates math expressions from infix expressions
*/
class Expression_Parser
{
public:
	/// Default Constructor
	Expression_Parser(void);

	/// Destructor
	~Expression_Parser(void);

	/**
	* parses the equation
	* 
	* @retval	bool	true if equation can be parsed, false if not
	*/
	virtual bool parse(const std::string & infix) = 0;
};

#include "Expression_Parser.cpp"

#endif   // !defined _EXPRESSION_PARSER_H_