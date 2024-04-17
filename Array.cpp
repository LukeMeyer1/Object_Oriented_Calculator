// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception


//
// ~Array
//
template <typename T>
Array <T>::~Array(void)
{ }

//
// operator = 
//
template <typename T>
const Array<T> & Array<T>::operator= (const Array<T>& rhs)
{
    // Check that rhs isn't the same location in memory as the array
    if (this == &rhs) 
        return *this;

    // Insure that the size of rhs is equal to the array
    if (this->cur_size_ != rhs.cur_size_)
        this->resize(rhs.cur_size_);

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
// operator []
//  
template <typename T>
T& Array<T>::operator [] (size_t index)
{
    return Base_Array<T>::operator[](index);
}

//
// operator []
//  
template <typename T>
const T& Array<T>::operator [] (size_t index) const
{
    return Base_Array<T>::operator[](index);
}

//
// resize 
//
template <typename T>
void Array <T>::resize(size_t new_size)
{
    // Lengthen Array if needed
    if (new_size > this->max_size_) {
        T* new_data = new T[new_size * 2];
        for (T* iter = this->data_, *iter_end = this->data_ + this->cur_size_, *new_iter = new_data;
            iter < iter_end;
            ++iter, ++new_iter)
        {
            *new_iter = *iter;
        }

        this->max_size_ = new_size * 2;
        delete[] this->data_;
        this->data_ = new_data;
    }

    // Resize array to 'new_size'
    this->cur_size_ = new_size;
}

//
// shrink
//
template <typename T>
void Array <T>::shrink()
{
    // Check that the array needs to be shrunk
    if (this->cur_size_ == this->max_size_) 
        return;

    // Create a copy of data_ with correct max_size
    T* shrunk_arr = new T[this->cur_size_];
    for (T* iter = shrunk_arr, *iter_end = shrunk_arr + this->cur_size_, *old_iter = this->data_;
        iter != iter_end;
        ++iter, ++old_iter)
    {
        *iter = *old_iter;
    }

    // Delete old data and replace it with new data
    delete[] this->data_;
    this->data_ = shrunk_arr;
    this->max_size_ = this->cur_size_;
}

//
// operator ==
//
template <typename T>
bool Array<T>::operator== (const Array<T>& rhs) const
{
    return Base_Array<T>::operator==(rhs);
}

//
// operator !=
//
template <typename T>
bool Array<T>::operator!= (const Array<T>& rhs) const
{
    return !(*this == rhs);
}

//
//	slice (size_t)
//
template <typename T>
Array<T> Array<T>::slice(size_t begin) const
{
    return this->slice(begin, this->cur_size_);
}

//
//	slice (size_t, size_t)
//
template <typename T>
Array<T> Array<T>::slice(size_t begin, size_t end) const
{
    // Check that both parameters are in bounds
    if (begin >= this->cur_size_)
        throw std::out_of_range("index out of range");
    if (end > this->cur_size_)
        throw std::out_of_range("index out of range");

    // Check that 'begin' is not greater than 'end'
    if (begin > end)
        throw std::invalid_argument("end index must be greater than begin index");

    // Set each element from begin(inclusive) to end(not inclusive) to respective index in slice
    Array<T>* slice = new Array<T>(end - begin);
    for (T* iter = this->data_ + begin, *iter_end = this->data_ + end, *slice_iter = slice->data_;
        iter < iter_end;
        ++iter, ++slice_iter)
    {
        *slice_iter = *iter;
    }

    return *slice;
}
