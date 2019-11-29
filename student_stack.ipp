#pragma once
#include "student.h"
#include "student_stack.h"

inline int student_stack::compare(student left, student right)
{
	if(left.id > right.id)
	{
		return 1;
	}

	if(left.id < right.id)
	{
		return -1;
	}

	return 0;
}
