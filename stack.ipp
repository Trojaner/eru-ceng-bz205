#pragma once
#include "stack.h"
using namespace std;

template <typename T>
T stack<T>::peek()
{
	if (linked_list<T>::is_empty())
	{
		throw std::exception("The stack is empty.");
	}

	return linked_list<T>::head_->data;
}

template <typename T>
void stack<T>::push(T& value) noexcept
{
	linked_list<T>::insert(0, value);
}

template <typename T>
T stack<T>::pop()
{
	if (linked_list<T>::is_empty())
	{
		throw std::exception("The stack is empty.");
	}

	T val = linked_list<T>::head_->data;
	linked_list<T>::remove(val);
	return val;
}
