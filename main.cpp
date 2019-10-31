#include "main.h"
#include "student.h"

student get_student()
{
	long id;
	string name;
	string surname;
	string department;
	int dbms_count;
	int dsa_count;

	cout << "Student ID: ";
	cin >> id;

	cout << "Student Name: ";
	cin >> name;

	cout << "Student Surname: ";
	cin >> surname;

	cout << "Student Department: ";
	cin >> department;

	get_dbms_count:
	cout << "How often did this student take Database Management Systems?";
	cin >> dbms_count;
	if(dbms_count < 0)
	{
		goto get_dbms_count;
	}

	get_dsa_count:
	cout << "How often did this student take Data Structures and Algorithms?";
	cin >> dsa_count;
	if (dsa_count < 0)
	{
		goto get_dsa_count;
	}

	return student(id, name, surname, department, dbms_count, dsa_count);
}

bool ask_add_another()
{
	cout << "Add another? [Y/N] ";
	char a;
	cin >> a;

	if (a == 'Y' || a == 'y')
	{
		return true;;
	}

	if (a == 'N' || a == 'n')
	{
		return false;;
	}

	return ask_add_another();
}

void get_students(student_stack* stack)
{
	while (true)
	{
		student student = get_student();
		if(stack->find_by_id(student.id))
		{
			cout << "A student with this ID has been already added!" << endl;
			continue;
		}

		stack->push(student);

		if(!ask_add_another())
		{
			break;
		}
	}
}

void process_option()
{
	cout << "Select an operation:" << endl;
	cout << "\t[a]: Students taking both courses more than one time" << endl;
	cout << "\t[b]: Students only taking Database Management Systems" << endl;
	cout << "\t[c]: Split both courses to A and B groups" << endl;
	cout << "\t[d]: Students taking both courses from a different department" << endl;

	char option;
	cin >> option;

	switch (option)
	{
	case 'A':
	case 'a':
		break;
	case 'B':
	case 'b':
		break;
	case 'C':
	case 'c':
		break;
	case 'D':
	case 'd':
		break;
	default:
		cout << "Invalid option: '" << option << "'!" << endl << endl;
		process_option();
		return;
	}
}

int main()
{
	student_stack stack;
	get_students(&stack);

	process_option();

	stack.print();
	return 0;
}
