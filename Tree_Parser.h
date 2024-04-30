// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef	_TREE_PARSER_H_
#define _TREE_PARSER_H_

#include "Expression_Parser.h"

/**
* @class Tree Parser
*
* Creates tree expressions from infix expressions
*/
class Tree_Parser : public Expression_Parser
{
public:
	/**
	* Default Constructor
	*
	* @param[in]	Tree_Builder		builder that the parser is working with
	*/
	Tree_Parser(Tree_Builder& builder);

	/// Destructor
	~Tree_Parser(void);

	/**
	* parses the equation
	*
	* @retval	bool	true if equation can be parsed, false if not
	*/
	bool parse(void);

private:
	/// Reference to the builder used to parse
	Tree_Builder builder_;
};

#include "Tree_Parser.cpp"

#endif   // !defined _TREE_PARSER_H_