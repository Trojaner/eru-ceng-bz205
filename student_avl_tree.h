#pragma once
#include "student.h"
#include "avl_tree.h"

class student_avl_tree : public avl_tree<student>
{
public:
	int compare(student a, student b) override;
};

#include "student_avl_tree.ipp"