#pragma once
#include "indexed_stack.h"
#include "student.h"

class student_stack : public indexed_stack<student>
{
public: 
	int compare(const student& left, const student& right) override final;
};
