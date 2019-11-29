#pragma once
#include "stack.h"
using namespace std;

template <typename T>
T stack<T>::peek()
{
	if (stack<T>::is_empty())
	{
		throw std::exception("The stack is empty.");
	}

	return stack<T>::head_->data;
}

template <typename T>
void stack<T>::push(T& value) noexcept
{
	stack<T>::insert(0, value);
}

template <typename T>
T stack<T>::pop()
{
	if (stack<T>::is_empty())
	{
		throw std::exception("The stack is empty.");
	}

	T val = stack<T>::head_->data;
	stack<T>::remove(val);
	return val;
}

template <typename T>
void stack<T>::for_each(typename linked_list<T>::for_each_callback callback)
{
	stack<T> tmp;

	for (int i = 0; i < stack<T>::size(); i++)
	{
		T current = pop();
		tmp.push(current);
		callback(current);
	}

	for (int i = 0; i < stack<T>::size(); i++)
	{
		T current = tmp.pop();
		push(current);
	}
}