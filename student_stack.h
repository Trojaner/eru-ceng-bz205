#pragma once
#include "student.h"
#include "sorted_stack.h"

class student_stack : public sorted_stack<student>
{
public:
	int compare(student left, student right) override;
};

#include "student_stack.ipp"