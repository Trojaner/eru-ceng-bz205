#include <fstream>
#include "main.h"
#include "student.h"
#include "student_stack.h"
#include "avl_tree.h"
#include "student_avl_tree.h"
#include "sorting.h"

student_avl_tree* dbms_tree = new student_avl_tree();
student_stack* dsa_stack = new student_stack();

student get_student(ifstream& stream) noexcept
{
	long id = 0;
	string name;
	string surname;
	string department;
	int dbms_count = 0;
	int dsa_count = 0;

	string unused;

	stream >> id;
	std::getline(stream, unused); // remove new line
	std::getline(stream, name);
	std::getline(stream, surname);
	std::getline(stream, department);

	stream >> dbms_count;
	std::getline(stream, unused); // remove new line
	stream >> dsa_count;

	if (!stream.eof())
	{
		std::getline(stream, unused); // remove new line
	}

	return student(id, name, surname, department, dbms_count, dsa_count);
}

void get_students(ifstream& stream) noexcept
{
	while (!stream.eof())
	{
		student student = get_student(stream);

		if (student.dbms_count > 0)
		{
			dbms_tree->insert(student);
		}

		if (student.dsa_count > 0)
		{
			dsa_stack->push(student);
		}

		cout << "Added student from file: " << student << endl;
	}

	cout << endl;
}

void print_taking_both_courses_multiple_times() noexcept
{
	std::cout << "Students taking DBMS and DSA multiple times:" << std::endl;
	int i = 0;
	dbms_tree->inorder_traverse([&i](student& dbms_student) mutable
		{
			if (dbms_student.dbms_count > 1) {

				bool student_takes_dsa = false;

				dsa_stack->for_each([&student_takes_dsa, dbms_student](student& dsa_student) mutable
					{
						if (dsa_student == dbms_student && dsa_student.dsa_count > 1) {
							student_takes_dsa = true;
						}
					});

				if (student_takes_dsa)
				{
					cout << dbms_student << endl;
					i++;
				}
			}
		});

	cout << "Total: " << i << " students." << endl;
}

void print_students_only_taking_dbms() noexcept
{
	std::cout << "Students only taking DBMS:" << std::endl;
	int i = 0;
	dbms_tree->inorder_traverse([&i](student& dbms_student) mutable
		{
			bool student_takes_dsa = false;

			dsa_stack->for_each([&student_takes_dsa, dbms_student](student& dsa_student) mutable
				{
					if (dsa_student == dbms_student)
					{
						student_takes_dsa = true;
					}
				});

			if (!student_takes_dsa)
			{
				cout << dbms_student << endl;
				i++;
			}
		});

	cout << "Total: " << i << " students." << endl;
}

void print_split_a_and_b_groups() noexcept
{
	linked_list<student> a_group;
	linked_list<student> b_group;

	std::cout << "Students split into A and B groups by odd or even number for DBMS:" << std::endl;
	dbms_tree->inorder_traverse([&a_group, &b_group](student& dbms_student) mutable
		{
			if (dbms_student.id % 2 == 1)
			{
				a_group.insert(a_group.size(), dbms_student);
			}
			else
			{
				b_group.insert(b_group.size(), dbms_student);
			}
		});

	std::cout << "A group:" << std::endl;
	a_group.print();

	std::cout << "B group:" << std::endl;
	b_group.print();

	std::cout << "Students split into A and B groups by lastname for DSA:" << std::endl;

	a_group.clear();
	b_group.clear();

	dsa_stack->for_each([&a_group, &b_group](student& dsa_student) mutable
		{
			const char normalized = toupper(dsa_student.surname[0]);

			if (normalized <= 'K')
			{
				a_group.insert(a_group.size(), dsa_student);
			}
			else
			{
				b_group.insert(b_group.size(), dsa_student);
			}
		});

	std::cout << "A group:" << std::endl;
	a_group.print();

	std::cout << "B group:" << std::endl;
	b_group.print();

}

void print_taking_both_courses_different_department() noexcept
{
	std::cout << "Students taking DBMS and DSA from a different department:" << std::endl;
	int i = 0;

	dbms_tree->inorder_traverse([&i](student& dbms_student) mutable
		{
			if (dbms_student.department != "Computer Engineering" && dbms_student.dbms_count > 0) {

				bool student_takes_dsa = false;

				dsa_stack->for_each([&student_takes_dsa, dbms_student](student& dsa_student) mutable
					{
						if (dbms_student == dsa_student && dsa_student.dsa_count > 0) {
							student_takes_dsa = true;
						}
					});

				if (student_takes_dsa)
				{
					cout << dbms_student << endl;
					i++;
				}
			}
		});

	cout << "Total: " << i << " students." << endl;
}

bool has_student(linked_list<student>& list, const student& to_check) noexcept
{
	bool result = false;
	list.for_each([&result, to_check](student& item) mutable
		{
			if (item.id == to_check.id)
			{
				result = true;
			}
		});

	return result;
}

void print_radix_sort_both_courses_by_surname() noexcept
{
	linked_list<student> student_list;
	dbms_tree->inorder_traverse([&student_list](student& student) mutable
		{
			if (!has_student(student_list, student))
			{
				student_list.insert(student_list.size(), student);
			}
		});

	dsa_stack->for_each([&student_list](student& student) mutable
		{
			if (!has_student(student_list, student))
			{
				student_list.insert(student_list.size(), student);
			}
		});

	student_list.shuffle();
	cout << "Shuffled student list: " << endl;
	student_list.print();

	cout << endl;

	sorting::radix_sort(student_list);
	cout << "Radix sorted student list (by surname): " << endl;
	student_list.print();
}

void print_selection_sort_dbms_by_name() noexcept
{
	linked_list<student> student_list;
	dbms_tree->inorder_traverse([&student_list](student& student) mutable
		{
			student_list.insert(student_list.size(), student);
		});

	student_list.shuffle();
	cout << "Shuffled student list: " << endl;
	student_list.print();

	cout << endl;

	sorting::selection_sort(student_list);
	cout << "Selection sorted student list (by name): " << endl;
	student_list.print();
}

void print_quick_sort_dsa_by_student_id() noexcept
{
	linked_list<student> student_list;
	dsa_stack->for_each([&student_list](student& student) mutable
		{
			student_list.insert(student_list.size(), student);
		});

	student_list.shuffle();
	cout << "Shuffled student list: " << endl;
	student_list.print();

	cout << endl;

	sorting::quick_sort(student_list);
	cout << "Quick sorted student list (by id): " << endl;
	student_list.print();
}

void process_option() noexcept
{
	cout << "Select an operation:" << endl;
	cout << "\t[a]: Students taking both courses more than one time" << endl;
	cout << "\t[b]: Students only taking Database Management Systems" << endl;
	cout << "\t[c]: Split both courses to A and B groups" << endl;
	cout << "\t[d]: Students taking both courses from a different department" << endl;
	cout << "\t[e]: Sort students taking both courses by last name with radix sort" << endl;
	cout << "\t[f]: Sort students taking only DBMS by names with selection sort" << endl;
	cout << "\t[g]: Sort students taking DSA by student id with quick sort" << endl;

	char option;
	cin >> option;

	switch (toupper(option))
	{
	case 'A':
		print_taking_both_courses_multiple_times();
		break;
	case 'B':
		print_students_only_taking_dbms();
		break;
	case 'C':
		print_split_a_and_b_groups();
		break;
	case 'D':
		print_taking_both_courses_different_department();
		break;
	case 'E':
		print_radix_sort_both_courses_by_surname();
		break;
	case 'F':
		print_selection_sort_dbms_by_name();
		break;
	case 'G':
		print_quick_sort_dsa_by_student_id();
		break;
	default:
		cout << "Invalid option: '" << option << "'!" << endl << endl;
	}

	cout << endl;
	process_option();
}

int main(int argc, char* argv[]) noexcept
{
	ifstream in("data.txt");
	get_students(in);

	cout << "Data Structures and Algorithms stack students (sorted by id): " << endl;
	dsa_stack->print();
	cout << "Number of nodes in the students stack: " << dsa_stack->size() << endl << endl;

	cout << "Database Management Systems AVL tree students (sorted by surname): " << endl;
	dbms_tree->print();
	cout << "Number of nodes in the students avl tree: " << dbms_tree->size() << endl << endl;

	process_option();
	return 0;
}
