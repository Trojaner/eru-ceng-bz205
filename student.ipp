#pragma once
#include "student.h"
#include <xlocmon>

inline student* student_stack::find_by_id(const long student_id) noexcept
{
	node<student>* currnode = head_;
	int currIndex = 1;

	while (currnode && currnode->data.id != student_id)
	{
		currnode = currnode->next;
		currIndex++;
	}

	if (currnode)
	{
		return &currnode->data;
	}

	return nullptr;
}

inline int student_stack::remove_by_id(long student_id) noexcept
{
	return 0;
}
