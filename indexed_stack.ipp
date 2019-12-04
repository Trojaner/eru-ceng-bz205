#pragma once

template <typename T>
void indexed_stack<T>::push(const T& value)
{
	stack<T>::push(value);
	sort();
}

template <typename T>
void indexed_stack<T>::sort()
{
	// O(n^2)
	// Stack based insertion sort

	const int size = stack<T>::internal_list_->size();

	// no sort needed
	if(size <= 1)
	{
		return;
	}

	stack<T> tmp_stack;
	for(int i = 0; i < size; i++)
	{
		T tmp = indexed_stack<T>::pop();
		while (!tmp_stack.is_empty() && compare(tmp_stack.peek(), tmp) < 0) {
			stack<T>::push(tmp_stack.pop());
		}

		tmp_stack.push(tmp);
	}

	auto tmp_size = tmp_stack.size();
	for(int i = 0; i < tmp_size; i++)
	{
		stack<T>::push(tmp_stack.pop());
	}
}
