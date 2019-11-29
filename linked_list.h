#pragma once
#include "node.h"

template<typename T>
class linked_list
{
public:
	typedef void (*for_each_callback)(T& item);

	linked_list() noexcept;
	virtual ~linked_list() noexcept;

	bool is_empty() noexcept;
	node<T>* insert(int index, T& value) noexcept;
	int find(T& value) noexcept;
	int remove(T& value) noexcept;
	int size() const noexcept;
	virtual void print() noexcept;

	virtual void for_each(for_each_callback callback);
protected:
	node<T>* head_;
	int size_;
};

#include "linked_list.ipp"
