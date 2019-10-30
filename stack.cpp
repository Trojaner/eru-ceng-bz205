#include "stack.h"
#include <iostream>

using namespace std;

template <typename T>
T stack<T>::peek()
{
	if (linked_list<T>::IsEmpty())
	{
		throw "The stack is empty.";
	}

	return linked_list<T>::head->data;
}

template <typename T>
void stack<T>::push(T& value)
{
	linked_list<T>::insert(0, value);
}

template <typename T>
T stack<T>::pop()
{
	if (linked_list<T>::IsEmpty())
	{
		throw "The stack is empty.";
	}

	T val = linked_list<T>::head->data;
	linked_list<T>::remove(val);
	return val;
}
