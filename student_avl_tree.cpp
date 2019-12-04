#include "student.h"
#include "student_avl_tree.h"

int student_avl_tree::compare(const student& left, const student& right) noexcept
{
	if (left.surname > right.surname)
	{
		return 1;
	}

	if (left.surname < right.surname)
	{
		return -1;
	}

	return 0;
}