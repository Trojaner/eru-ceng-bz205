#pragma once
#include "linked_list.h"

template<typename T>
class stack
{
public:
	stack() noexcept;

	bool is_empty() noexcept;
	T peek();
	T pop();
	int size() noexcept;
	void print() noexcept;
	void for_each(typename linked_list<T>::for_each_callback callback);

	virtual void push(T& value);
	virtual ~stack() noexcept;
protected:
	linked_list<T>* internal_list_;
};

#include "stack.ipp"
