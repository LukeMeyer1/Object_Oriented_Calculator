#ifndef _CS507_Queue_H_
#define _CS507_Queue_H_

#include <exception>
#include "Array.h"

/**
 * @class Stack
 *
 * Basic stack for abitrary elements.
 */
template <typename T>
class Queue
{
public:
    /// Type definition of the type.
    typedef T type;

    /**
     * @class empty_exception
     *
     * Exception thrown to indicate the stack is empty.
     */
    class empty_exception : public std::runtime_error
    {
    public:
        /// Default constructor.
        empty_exception(void)
            : std::runtime_error() { }

        /**
         * Initializing constructor.
         *
         * @param[in]      msg         Error message.
         */
        empty_exception(const char* msg)
            : std::runtime_error(msg) { }
    };

    /// Default constructor.
    Queue(void);

    /// Copy constructor.
    Queue(const Queue& q);

    /// Destructor.
    ~Queue(void);

    /**
    * Assignment operator
    *
    * @param[in]      rhs           Right-hand side of operator
    * @return         Reference to self
    */
    const Queue& operator = (const Queue& rhs);

    /**
    * Append a new \a element onto the queue. The element is inserted
    * after all the other elements in the queue.
    *
    * @param[in]      element       Element to add to the queue
    */
    void enqueue (T element);

    /**
    * Remove the top-most element from the stack.
    *
    * @exception      empty_exception    The stack is empty.
    */
    void dequeue (void);

    /**
    * Element at the top of the queue, if there are no elements 
    * on queue, then queue empty_exception is thrown
    * 
    * @return           Element at the top of queue
    * @excpetion        empty_exception     The queue is empty
    */
    T top (void) const;

    /**
    * Test if the Queue is empty
    * 
    * @retval           true            The stack is empty
    * @retval           false           The stack is not empty
    */
    bool is_empty (void) const;

    /**
    * Number of elements in Queue
    * 
    * @return           Size of the stack.
    */
    size_t size (void) const;

    /// Remove all the elements in the queue.
    void clear (void);

private:
    Array<T> parent_array_;
    size_t front_index_;
};

// include the inline files
#include "Queue.inl"

// include the source file since template class
#include "Queue.cpp"

#endif  // !defined _CS507_Queue_H_

