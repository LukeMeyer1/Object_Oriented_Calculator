#include <iostream>
#include <sstream>
#include <string>
#include "Number_Command.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Modulo_Command.h"
#include "Stack.h"
#include "Stack_Command_Factory.h"
#include "Number_Node.h"
#include "Add_Node.h"
#include "Subtract_Node.h"
#include "Multiply_Node.h"
#include "Divide_Node.h"
#include "Modulo_Node.h"
#include "Postfix_Expr.h"

/**
* Pushes a command onto stack and pushes all in front of lesser priority onto postfix equation
* 
* @param	cmd					command that is being added to stack
* @param	postfix				array to store commands in postfix order
* @param	stk					stack that the commands are being temporarily stored on
*/
void operator_onto_stack(Operator_Command* & cmd,
						Postfix_Expr& postfix,
						Stack<Operator_Command*>& stk)
{
	// push command at top of stk onto postfix until reach command of lesser or equal priority as cmd
	while ((stk.size() > 0) and (cmd->priority() <= stk.top()->priority())) {
		postfix.append(stk.pop());
	}
	// push add command onto the stack
	stk.push(cmd);
}

/**
* Creates a postfix statement from an infix statement
* 
* @param	input				istringstream of infix expression
* @param	factory				factory used to create commands
* @param	postfix				array to store commands in postfix order
* @param	opened_parenthesis	boolean value showing if an open parenthesis must be closed
* @return	if valid infix equation was given 	
*/
bool infix_to_postfix(std::istringstream & input,
					  Command_Factory & factory,
					  Postfix_Expr & postfix,
					  bool opened_parenthesis = false)
{
	std::string token;
	Operator_Command* cmd = 0;
	Stack <Operator_Command*> temp;
	while (!input.eof()) {

		input >> token;

		// Plus operator
		if (token == "+") {
			cmd = factory.create_add_command();
			operator_onto_stack(cmd, postfix, temp);
		}
		// Minus operator
		else if (token == "-") {
			cmd = factory.create_subtract_command();
			operator_onto_stack(cmd, postfix, temp);
		}
		// Multiply operator
		else if (token == "*") {
			cmd = factory.create_multiply_command();
			operator_onto_stack(cmd, postfix, temp);
		}
		// Divide operator
		else if (token == "/") {
			cmd = factory.create_divide_command();
			operator_onto_stack(cmd, postfix, temp);
		}
		// Modulo operator
		else if (token == "%") {
			cmd = factory.create_modulo_command();
			operator_onto_stack(cmd, postfix, temp);
		}

		// Open parenthesis operator
		else if (token == "(") {
			// recursive call, will put all new postfix onto the same postfix equation until reaching a close parenthesis
			// or the end of the statement
			bool did_run = infix_to_postfix(input, factory, postfix, true);
			if (!did_run)
				return false;
		}
		// Close parenthesis operator
		else if (token == ")") {
			// if called with opened parenthesis then push all commands onto the postfix and return 'true' because it is 
			// closed, else return false because there is a closed parenthesis without an open.
			if (opened_parenthesis) {
				// empty temp stack onto end of postfix array
				while (!(temp.is_empty())) {
					postfix.append(temp.pop());
				}

				return true;
			}
			return false;
		}
		// Number operator
		else {
			// add number command directly to end of postfix array
			postfix.append(factory.create_number_command(std::stoi(token)));
        }
	}
	// reached end of input
	
	// check if opened parenthesis 
	if (!opened_parenthesis){
		// empty temp stack onto end of postfix array
		while (!(temp.is_empty())) {
			postfix.append(temp.pop());
		}

		return true;
	}
	// open parenthesis never closed
	return false;
}

///
///	Main
/// 
int main(int argc, char* argv[])
{
	
	// COMMENT The program is to loop until QUIT is entered.
	// RESPONSE: added loop with and check for QUIT to end.

	std::string infix;
	Stack<int> result = Stack<int>();
	Stack_Command_Factory factory(result);
	Postfix_Expr postfix(result);
	while (true) {
		// get user input into 'infix'
		infix = "";
		std::cout << "Type your equation" << std::endl;
		std::getline(std::cin, infix);
		
		// check if user is exiting program
		if (infix == "QUIT")
			return 0;

		// reset postfix 
		postfix = Postfix_Expr(result);

		// translate infix equation to postfix and solve if infix was valid
		std::istringstream input(infix);
		if (infix_to_postfix(input, factory, postfix)) {
			// output result
			std::cout << postfix.eval() << std::endl;
		}
		// if invalid infix expression, output error statement
		else
			std::cout << "Invalid equation" << std::endl;

		std::cout << std::endl;
	}






	Number_Node * n1 = new Number_Node(4);
	Tree_Node * n2 = new Number_Node(2);
	Add_Node * n3 = new Add_Node(n1, n2);
	Tree_Node * n4 = new Subtract_Node(new Number_Node(4), new Number_Node(2));
	Tree_Node * n5 = new Multiply_Node(new Number_Node(4), new Number_Node(2));
	Tree_Node * n6 = new Divide_Node(new Number_Node(4), new Number_Node(2));
	Tree_Node * n7 = new Modulo_Node(new Number_Node(4), new Number_Node(3));

	delete n3;
	delete n4;
	delete n5;
	delete n6;
	delete n7;
}