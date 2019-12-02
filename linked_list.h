#pragma once

template<typename T>
class node
{
public:
	node()
	{
		next = nullptr;
	}

	T data;
	node<T>* next;
};

template<typename T>
class linked_list
{
public:
	typedef void (*for_each_callback)(T& item);

	linked_list() noexcept;
	~linked_list() noexcept;

	bool is_empty() noexcept;
	node<T>* insert(int index, T& value) noexcept;
	int find(T& value) noexcept;
	int remove(T& value) noexcept;
	int size() const noexcept;
	void print() noexcept;
	void for_each(for_each_callback callback);
protected:
	template<typename K>
	friend class stack;
	node<T>* head_;
	int size_;
};

#include "linked_list.ipp"
