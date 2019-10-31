#pragma once
#include "node.h"

template<typename T>
class linked_list
{
public:
	linked_list();
	virtual ~linked_list();

	virtual bool is_empty();
	virtual node<T>* insert(int index, T& value);
	virtual int find(T& value);
	virtual int remove(T& value);
	virtual void print();

protected:
	node<T>* head_;
};

#include "linked_list.ipp"
