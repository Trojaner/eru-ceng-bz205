#pragma once
#include "student.h"
#include "linked_list.h"

class sorting {
public:
	static void radix_sort(linked_list<student>& students) noexcept;
	static void selection_sort(linked_list<student>& students) noexcept;
	static void quick_sort(linked_list<student>& list) noexcept;
private:
	static void quick_sort(linked_list<student>& list, int low, int high) noexcept;
	static int quick_sort_partition(linked_list<student>& list, int low, int high) noexcept;

	static void radix_sort(linked_list<student>& students, int max_length)  noexcept;

	template<typename T>
	static void swap(T* xp, T* yp) noexcept
	{
		const T temp = *xp;
		*xp = *yp;
		*yp = temp;
	}
};