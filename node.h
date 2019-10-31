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
