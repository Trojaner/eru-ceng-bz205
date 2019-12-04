#pragma once
#include "student.h"
#include "avl_tree.h"

class student_avl_tree : public avl_tree<student>
{
public:
	int compare(const student& left, const student& right) noexcept override final;
};
