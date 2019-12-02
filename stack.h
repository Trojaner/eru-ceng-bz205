#pragma once
#include "linked_list.h"

template<typename T>
class stack
{
public:
	stack() noexcept;
	virtual ~stack() noexcept;

	bool is_empty() noexcept;
	T peek();
	T pop();
	virtual void push(T& value);
	int size() noexcept;
	virtual void print() noexcept;

	void for_each(typename linked_list<T>::for_each_callback callback);
protected:
	linked_list<T>* internal_list_;
};

#include "stack.ipp"
