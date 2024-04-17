// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Stack.h"

//
// Stack
//
template <typename T>
Stack<T>::Stack(void)
	: parent_array_(Array<T>())
{ }

//
// Stack
//
template <typename T>
Stack <T>::Stack(const Stack& stack)
	: parent_array_(Array<T>(stack.parent_array_))
{ }

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack(void)
{ }

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
	if (*this == rhs)
		return *this;

	this->parent_array_ = rhs.parent_array_;
	return *this;
}

//
// push 
//
template <typename T>
void Stack <T>::push (T element)
{
	this->parent_array_.resize(this->parent_array_.size() + 1);
	this->parent_array_.set(this->parent_array_.size() - 1, element);
}

//
// pop 
//
template <typename T>
T Stack <T>::pop (void)
{
	if (this->parent_array_.size() == 0) 
		throw Stack<T>::empty_exception("Stack is empty");
	
	T ret_val = this->top();
	this->parent_array_.resize(this->parent_array_.size() - 1);
	return ret_val;
}

//
// top
//
template <typename T>
inline
T Stack <T>::top(void) const
{
	if (this->parent_array_.size() == 0) {
		throw Stack<T>::empty_exception("Stack is empty");
	}
	return this->parent_array_.get(this->parent_array_.size() - 1);
}

//
// is_empty
//
template <typename T>
bool Stack <T>::is_empty(void) const
{
	if (this->parent_array_.size() == 0) 
		return true;

	return false;
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
	this->parent_array_.resize(0);
}

///
/// print
/// 
template <typename T>
void Stack <T>::print(void) {
	this->parent_array_.print();
}