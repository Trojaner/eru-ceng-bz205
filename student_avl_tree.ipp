#pragma once
#include "student.h"
#include "student_avl_tree.h"

inline int student_avl_tree::compare(student left, student right)
{
	if (left.id > right.id)
	{
		return 1;
	}

	if (left.id < right.id)
	{
		return -1;
	}

	return 0;
}