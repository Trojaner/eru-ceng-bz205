#pragma once
#include "node.h"

template<typename T>
class linked_list
{
public:
	linked_list() noexcept;
	virtual ~linked_list() noexcept;

	virtual bool is_empty() noexcept;
	virtual node<T>* insert(int index, T& value) noexcept;
	virtual int find(T& value) noexcept;
	virtual int remove(T& value) noexcept;
	virtual void print() noexcept;

protected:
	node<T>* head_;
};

#include "linked_list.ipp"
