#pragma once
#include <iostream>
#include "linked_list.h"

using namespace std;

template <typename T>
linked_list<T>::linked_list() noexcept
{
	head_ = nullptr;
	size_ = 0;
}

template <typename T>
linked_list<T>::~linked_list() noexcept
{
	node<T>* currnode = head_;

	while (currnode != nullptr)
	{
		node<T>* nextnode = currnode->next;
		delete currnode;
		currnode = nextnode;
	}
}

template <typename T>
bool linked_list<T>::is_empty() noexcept
{
	return head_ == nullptr;
}

template <typename T>
int linked_list<T>::find(const T& value) noexcept
{
	node<T>* currnode = head_;
	int currIndex = 1;

	while (currnode && currnode->data != value)
	{
		currnode = currnode->next;
		currIndex++;
	}

	if (currnode)
	{
		return currIndex;
	}

	return 0;
}

template <typename T>
node<T>* linked_list<T>::insert(int index, const T& value) noexcept
{
	if (index < 0)
	{
		return nullptr;
	}

	if(index > size_)
	{
		index = size_;
	}

	int currIndex = 1;
	node<T>* currnode = head_;

	while (currnode && index > currIndex)
	{
		currnode = currnode->next;
		currIndex++;
	}

	if (index > 0 && currnode == nullptr)
	{
		return nullptr;
	}

	auto newnode = new node<T>();
	newnode->data = *&value;

	if (index == 0)
	{
		newnode->next = head_;
		head_ = newnode;
	}
	else
	{
		newnode->next = currnode->next;
		currnode->next = newnode;
	}
	
	size_++;
	return newnode;
}

template <typename T>
int linked_list<T>::remove(const T& value) noexcept
{
	node<T>* prevnode = nullptr;
	node<T>* currnode = head_;

	int currIndex = 1;
	while (currnode && currnode->data != value)
	{
		prevnode = currnode;
		currnode = currnode->next;
		currIndex++;
	}

	if (currnode)
	{
		if (prevnode)
		{
			prevnode->next = currnode->next;
			delete currnode;
		}
		else
		{
			head_ = currnode->next;
			delete currnode;
		}

		size_--;
		return currIndex;
	}

	return 0;
}

template <typename T>
void linked_list<T>::remove_at(int idx) noexcept
{
	node<T>* prevnode = nullptr;
	node<T>* currnode = head_;

	int currIndex = 0;
	while (currnode && currIndex < idx)
	{
		prevnode = currnode;
		currnode = currnode->next;
		currIndex++;
	}

	if (currnode)
	{
		if (prevnode)
		{
			prevnode->next = currnode->next;
			delete currnode;
		}
		else
		{
			head_ = currnode->next;
			delete currnode;
		}

		size_--;
	}
}


template <typename T>
void linked_list<T>::print() noexcept
{
	for_each([](T& currnode)
	{
		cout << currnode << endl;
	});
}

template <typename T>
void linked_list<T>::for_each(std::function<void(T)> callback) noexcept
{
	node<T>* currnode = head_;
	while (currnode != nullptr)
	{
		callback(currnode->data);
		currnode = currnode->next;
	}
}

template <typename T>
int linked_list<T>::size() const noexcept
{
	return size_;
}

template <typename T>
void linked_list<T>::clear() noexcept
{
	node<T>* currnode = head_;
	while (currnode != nullptr)
	{
		auto next = currnode->next;
		delete currnode;
		currnode = next;
	}

	head_ = nullptr;
	size_ = 0;
}

template <typename T>
T* linked_list<T>::get(const int idx) noexcept
{
	int i = 0;
	node<T>* currnode = head_;
	while (currnode != nullptr)
	{
		if(i == idx)
		{
			return &currnode->data;
		}

		currnode = currnode->next;
		i++;
	}

	return nullptr;
}

template <typename T>
void linked_list<T>::shuffle() noexcept
{
	const auto list_size = size();
	if(list_size < 2)
	{
		return;
	}

	auto tmp = new T*[list_size];
	for(int i = 0; i < list_size; i++)
	{
		tmp[i] = nullptr;
	}

	for (int i = 0; i < list_size; i++)
	{
		get_random_index:
		int idx = rand() % list_size;
		if(tmp[idx] != nullptr)
		{
			goto get_random_index;
		}

		tmp[idx] = get(i);
	}

	head_ = nullptr;
	size_ = 0;

	for(int i = 0; i < list_size; i++)
	{
		insert(i, *tmp[i]);
	}

	delete[] tmp;
}
