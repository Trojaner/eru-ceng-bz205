#pragma once
#include "stack.h"

template<typename T>
class sorted_stack : public stack<T>
{
public:
	virtual int compare(T a, T b) = 0;
	void push(T& value) noexcept override;
private:
	void sort();
};

#include "sorted_stack.ipp"