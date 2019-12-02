#pragma once
#include "stack.h"
using namespace std;

template <typename T>
stack<T>::stack() noexcept
{
	internal_list_ = new linked_list<T>();
}

template <typename T>
stack<T>::~stack() noexcept
{
	delete internal_list_;
}

template <typename T>
int stack<T>::size() noexcept
{
	return internal_list_->size();
}

template <typename T>
void stack<T>::print() noexcept
{
	internal_list_->print();
}

template <typename T>
T stack<T>::peek()
{
	if (internal_list_->is_empty())
	{
		throw std::exception("The stack is empty.");
	}

	return internal_list_->head_->data;
}

template <typename T>
void stack<T>::push(T& value)
{
	internal_list_->insert(0, value);
}

template <typename T>
bool stack<T>::is_empty() noexcept
{
	return internal_list_->is_empty();
}

template <typename T>
T stack<T>::pop()
{
	if (internal_list_->is_empty())
	{
		throw std::exception("The stack is empty.");
	}

	T val = internal_list_->head_->data;
	internal_list_->remove(val);
	return val;
}

template <typename T>
void stack<T>::for_each(typename linked_list<T>::for_each_callback callback)
{
	stack<T> tmp;

	for (int i = 0; i < internal_list_->size(); i++)
	{
		T current = pop();
		tmp.push(current);
		callback(current);
	}

	for (int i = 0; i < internal_list_->size(); i++)
	{
		T current = tmp.pop();
		push(current);
	}
}