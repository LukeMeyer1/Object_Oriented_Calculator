// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef	_POSTFIX_PARSER_H_
#define _POSTFIX_PARSER_H_

#include "Expression_Parser.h"

/**
* @class Postfix Parser
*
* Creates postfix expressions from infix expressions
*/
class Postfix_Parser : public Expression_Parser
{
public:
	/**
	* Default Constructor
	*
	* @param[in]	Postfix_Builder		builder that the parser is working with
	*/
	Postfix_Parser(Postfix_Builder& builder);

	/// Destructor
	~Postfix_Parser(void);

	/**
	* parses the equation
	*
	* @retval	bool	true if equation can be parsed, false if not
	*/
	bool parse(void);
};

#include "Postfix_Parser.cpp"

#endif   // !defined _POSTFIX_PARSER_H_