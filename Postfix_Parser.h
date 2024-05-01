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
	Postfix_Parser(Postfix_Builder & builder);

	/// Destructor
	~Postfix_Parser(void);

	/**
	* parses the equation
	*
	* @retval	bool	true if equation can be parsed, false if not
	*/
	bool parse(const std::string & infix);

private:
	/**
	* recursive helper function for the parse function
	* 
	* @param[in]	input				reference to an istringstream object that contains the infix expression
	* @param[in]	b					builder that is being used
	* @param[in]	opened_parenthesis	true if function call is being made by an open parenthesis in the expression, 
	*									false if there aren't any opened parenthesis found in the expression 
	* @retval		bool				true if parsed correctly false if couldn't parse
	*/
	bool parse_equation(std::istringstream& input, Postfix_Builder& b, bool opened_parenthesis);

	/// Reference to the builder used to parse
	Postfix_Builder builder_;
	
	/// infix expression being parsed
	std::string infix;
};

#include "Postfix_Parser.cpp"

#endif   // !defined _POSTFIX_PARSER_H_