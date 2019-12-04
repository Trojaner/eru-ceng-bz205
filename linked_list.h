#pragma once
#include <functional>

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
	linked_list() noexcept;
	~linked_list() noexcept;

	bool is_empty() noexcept;
	node<T>* insert(int index, const T& value) noexcept;
	int find(const T& value) noexcept;
	int remove(const T& value) noexcept;
	void remove_at(int idx) noexcept;
	int size() const noexcept;
	void print() noexcept;
	void for_each(function<void(T)> callback) noexcept;
	void clear() noexcept;
	void shuffle() noexcept;
	T* get(int idx) noexcept;

protected:
	template<typename K>
	friend class stack;
	node<T>* head_;
	int size_;
};

#include "linked_list.ipp"
