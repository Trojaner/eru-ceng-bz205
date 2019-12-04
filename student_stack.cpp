#include "student.h"
#include "student_stack.h"

int student_stack::compare(const student& left, const student& right)
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
