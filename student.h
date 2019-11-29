#pragma once
#include <string>
#include <ostream>

using namespace std;

class student
{
public:
	student(
		const long student_id,
		const string& student_name,
		const string& student_surname,
		const string& student_department,
		const int student_dbms_count,
		const int student_dsa_count)
	{
		id = student_id;
		name = student_name;
		surname = student_surname;
		department = student_department;
		dbms_count = student_dbms_count;
		dsa_count = student_dsa_count;
	}

	student()
	{
		id = 0;
		name = "";
		surname = "";
		department = "";
		dbms_count = 0;
		dsa_count = 0;
	}

	long id;
	string name;
	string surname;
	string department;
	int dbms_count;
	int dsa_count;

	friend bool operator!=(student const& lhs, student const& rhs) { return lhs.id != rhs.id; }
	friend bool operator==(student const& lhs, student const& rhs) { return lhs.id == rhs.id; }
};

inline std::ostream& operator << (std::ostream& stream, const student& student) {
	return stream << "[" << student.id << "] " << student.name << " " << student.surname << " (" << student.department << ")";
}