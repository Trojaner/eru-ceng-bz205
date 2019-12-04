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
	void for_each(std::function<void(T)> callback) noexcept;

	virtual void push(const T& value);
	virtual ~stack() noexcept;
protected:
	linked_list<T>* internal_list_;
};

#include "stack.ipp"
