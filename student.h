#pragma once
#include <string>
#include <ostream>
#include "stack.h"

using namespace std;

struct student
{
	student(long student_id, string student_name, string student_surname, string student_course)
	{
		id = student_id;
		name = std::move(student_name);
		surname = std::move(student_surname);
		course = std::move(student_course);
	}

	student()
	{
		id = 0;
		name = nullptr;
		surname = nullptr;
		course = nullptr;
	}

	long id;
	string name;
	string surname;
	string course;
};

inline std::ostream& operator << (std::ostream& stream, const student& student) {
	return stream << "[" << student.id << "] " << student.name << " " << student.surname << " (" << student.course << ")";
}

class student_stack : public stack<student>
{
public:
	virtual student find_by_id(long student_id);
	virtual int remove_by_id(long student_id);
};
