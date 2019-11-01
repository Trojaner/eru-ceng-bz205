#pragma once
#include "linked_list.h"

template<typename T>
class stack : public linked_list<T>
{
public:
	virtual T peek();
	virtual void push(T& value) noexcept;
	virtual T pop();
};

#include "stack.ipp"
