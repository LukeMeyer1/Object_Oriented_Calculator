// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Base_Array.h"
#include <stdexcept>         // for std::out_of_bounds exception
#include <iostream>

size_t DEFAULT_SIZE = 7;

//
//	Base_Array
//
template <typename T>
Base_Array <T>::Base_Array(void)
    : Base_Array<T>(0)

{ }

//
//	Base_Array
//
template <typename T>
Base_Array <T>::Base_Array(size_t length)
    : data_(nullptr),
    cur_size_(0),
    max_size_(0)
{
    //insure max_size_ is not less than 'DEFAULT_SIZE'
    size_t max_size_ = (length <= DEFAULT_SIZE ? DEFAULT_SIZE : length);

    //set member variables
    this->data_ = new T[max_size_];
    this->cur_size_ = length;
    this->max_size_ = max_size_;
}

//
//	Base_Array
//
template <typename T>
Base_Array <T>::Base_Array(size_t length, T fill)
    : Base_Array<T>(length)
{
    this->fill(fill);
}

//
//	Base_Array
//
template <typename T>
Base_Array <T>::Base_Array(const Base_Array<T>& arr)
    : Base_Array<T>(arr.cur_size_)
{
    *this = arr;
}

//
//	~Base_Array
//
template <typename T>
Base_Array <T>::~Base_Array(void)
{
    delete[] this->data_;
}

//
//	operator =
//
template <typename T>
const Base_Array<T>& Base_Array <T>::operator = (const Base_Array<T>& rhs)
{
    // Check that rhs isn't the same location in memory as the array
    if (this == &rhs)
        return *this;

    // Insure that the size of rhs is equal to the array
    if (this->cur_size_ != rhs.cur_size_)
        throw std::invalid_argument("base_array must be set equal to a base_array of same length");

    // Set array values equal to respective rhs array values
    for (T* iter = this->data_, *iter_end = this->data_ + this->cur_size_, *rhs_iter = rhs.data_;
        iter != iter_end;
        ++iter, ++rhs_iter)
    {
        *iter = *rhs_iter;
    }

    return *this;
}

//
//	operator []
//
template <typename T>
T& Base_Array <T>::operator [] (size_t index)
{
    if (index >= this->cur_size_) 
        throw std::out_of_range("index out of range");
    
    return *(this->data_ + index);
}

//
//	operator []
//
template <typename T>
const T& Base_Array <T>::operator [] (size_t index) const
{
    if (index >= this->cur_size_) 
        throw std::out_of_range("index out of range");
   
    return *(this->data_ + index);
}

//
//	get
//
template <typename T>
T Base_Array <T>::get(size_t index) const
{
    if (index >= this->cur_size_) 
        throw std::out_of_range("index out of range");

    return *(this->data_ + index);
}

//
//	set
//
template <typename T>
void Base_Array <T>::set(size_t index, T value)
{
    if (index >= this->cur_size_) 
        throw std::out_of_range("index out of range");

    *(this->data_ + index) = value;
}

//
//	find (T)
//
template <typename T>
int Base_Array <T>::find(T element) const
{
    return this->find(element, 0);
}

//
//	find (T, size_t)
//
template <typename T>
int Base_Array <T>::find(T element, size_t start) const
{
    // Check that start index is in range
    if (start >= this->cur_size_) 
        throw std::out_of_range("index out of range");

    // Find the element in the array
    for (int index = start; index < this->cur_size_; index++) 
    {
        if (*(this->data_ + index) == element)
            return index;
    }
    return -1;
}

//
//	operator ==
//
template <typename T>
bool Base_Array <T>::operator == (const Base_Array<T>& rhs) const
{
    // Check if rhs is the same location in memory as the array
    if (&rhs == this)
        return true;

    // Check if rhs has the same size as the array
    if (rhs.cur_size_ != this->cur_size_)
        return false;

    // Check that the array is not size 0
    if (this->cur_size_ == 0)
        return true;

    // Check if each element in rhs equals the respective element in the array
    for (const T* iter = this->data_, *iter_end = this->data_ + this->cur_size_, *rhs_iter = rhs.data_;
        iter != iter_end;
        ++iter, ++rhs_iter)
    {
        if (*iter != *rhs_iter)
            return false;
    }

    return true;
}

//
//	operator !=
//
template <typename T>
bool Base_Array <T>::operator != (const Base_Array<T>& rhs) const
{
    return !(*this == rhs);
}

//
//	fill (T)
//
template <typename T>
void Base_Array <T>::fill(T element)
{
    for (int i = 0; i < this->cur_size_; i++)
        *(this->data_ + i) = element;
    return;
}

//
//	reverse
//
template <typename T>
void Base_Array <T>::reverse(void)
{
    T placeholder;
    for (T* iter = this->data_, *rev_iter = this->data_ + this->cur_size_;
        iter < rev_iter;
        ++iter, --rev_iter)
    {
        placeholder = *iter;
        *iter = *rev_iter;
        *rev_iter = placeholder;
    }
}

//
// print
//
template <typename T>
void Base_Array<T>::print()
{
    if (this->cur_size_ != 0) {
        for (T* iter = this->data_, *iter_end = this->data_ + (this->cur_size_ - 1);
            iter != iter_end;
            ++iter)
        {
            (*iter)->print();
            std::cout << ", ";
        }
        (*(this->data_ + (this->cur_size_ - 1)))->print();
        std::cout << std::endl;
    }
}
