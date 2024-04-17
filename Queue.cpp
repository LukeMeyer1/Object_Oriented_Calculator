//
// Queue
//
template<typename T>
Queue <T>::Queue(void)
	:parent_array_(Array<T>()),
	front_index_(parent_array_.size()-1)
{ }

//
// Queue
//
template<typename T>
Queue <T>::Queue(const Queue& q)
	:parent_array_(Array<T>(q.parent_array_)),
	front_index_(parent_array_.size() - 1)
{ }

//
// ~Queue
//
template<typename T>
Queue <T>::~Queue(void)
{ }

//
// operator =
//
template <typename T>
const Queue <T>& Queue <T>::operator = (const Queue& rhs)
{
	if (*this == rhs)
		return *this;

	this->parent_array_ = rhs.parent_array_;
	this->front_index_ = rhs.front_index_;
	return *this;
}

//
// enqueue
//
template<typename T>
void Queue <T>::enqueue(T element)
{
	if (this->front_index_ == 0)
	{
		//Set the amount of memory added to the queue 
		size_t change_size = int(this->parent_array_.size() / 2);

		this->parent_array_.resize(this->parent_array_.size() + change_size);
		this->front_index_ += change_size;

		//Move all elements in the queue back 
		for (int i = this->parent_array_.size() - 2; i >= 0; i--) {
			this->parent_array_.set(i + change_size, this->parent_array_.get(i));
		}
	}

	//Add new element to the front of the queue
	-- this->front_index_;
	this->parent_array_.set(this->front_index_, element);
}

//
// dequeue
//
template<typename T>
void Queue <T>::dequeue(void)
{
	if (this->parent_array_.size() == 0) {
		throw Queue<T>::empty_exception("Queue is empty");
	}
	else {
		this->parent_array_.resize(this->parent_array_.size() - 1);
	}
}

// 
// top
//
template<typename T>
T Queue <T>::top(void) const
{
	if (this->parent_array_.size() == 0) {
		throw Queue<T>::empty_exception("Queue is empty");
	}
	else {
		return this->parent_array_.get(this->parent_array_.size() - 1);
	}
}

//
// is_empty
//
template<typename T>
bool Queue <T>::is_empty(void) const
{
	if (this->parent_array_.size() == 0) {
		return true;
	}
	return false;
}

//
// clear
//
template<typename T>
void Queue <T>::clear(void)
{
	this->parent_array_.resize(0);
}

