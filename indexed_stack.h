#pragma once
#include "stack.h"

template<typename T>
class indexed_stack : public stack<T>
{
public:
	virtual int compare(const T& left, const T& right) = 0;
	void push(const T& value) override;
protected:
	void sort();
};

#include "indexed_stack.ipp"