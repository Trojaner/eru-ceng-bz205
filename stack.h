#pragma once
#include "linked_list.h"

template<typename T>
class stack : public linked_list<T>
{
public:
	T peek();
	virtual void push(T& value) noexcept;
	T pop();

	void for_each(typename linked_list<T>::for_each_callback callback) override;
};

#include "stack.ipp"
