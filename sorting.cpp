#include "sorting.h"

void sorting::selection_sort(linked_list<student>& students) noexcept
{
	int n = students.size();

	for (int i = 0; i < n - 1; i++)
	{
		// Find the minimum element in unsorted array  
		int min_idx = i;
		for (int j = i + 1; j < n; j++)
			if (students.get(j)->name < students.get(min_idx)->name)
				min_idx = j;

		// Swap the found minimum element with the first element  
		swap(students.get(min_idx), students.get(i));
	}
}

void sorting::quick_sort(linked_list<student>& list) noexcept
{
	quick_sort(list, 0, list.size() - 1);
}

void sorting::quick_sort(linked_list<student>& list, int low, int high) noexcept
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		   at right place */
		const int pivot = quick_sort_partition(list, low, high);

		// Separately sort elements before 
		// partition and after partition 
		quick_sort(list, low, pivot - 1);
		quick_sort(list, pivot + 1, high);
	}
}

int sorting::quick_sort_partition(linked_list<student>& list, int low, int high) noexcept
{
	student* pivot = list.get(high);
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (list.get(j)->id <= pivot->id)
		{
			i++;
			swap(list.get(i), list.get(j));
		}

	}
	swap(list.get(i + 1), list.get(high));
	return (i + 1);
}

void sorting::radix_sort(linked_list<student>& students) noexcept
{
	radix_sort(students, 20);
}

void sorting::radix_sort(linked_list<student>& students, int max_length) noexcept
{
	linked_list<linked_list<student>> wordsByLength;
	linked_list<linked_list<student>> buckets;

	students.for_each([&wordsByLength](student& s) mutable
		{
			auto list = wordsByLength.get(s.name.length());
			if (list == nullptr)
			{
				list = new linked_list<student>;
			}
			list->insert(list->size(), std::move(s));
		});

	int idx = 0;


	wordsByLength.for_each([&students, &idx](linked_list<student>& list) mutable
		{
			list.for_each([&students, &idx](student& s) mutable
				{
					students.remove_at(idx);
					students.insert(idx, std::move(s));
					idx++;
				});
		});


	int startingIndex = students.size();
	for (int pos = max_length - 1; pos >= 0; --pos)
	{
		startingIndex -= wordsByLength.get(pos + 1)->size();

		for (int i = startingIndex; i < students.size(); ++i)
		{
			auto list = buckets.get(students.get(i)->name[pos]);
			list->insert(list->size(), *students.get(i));
		}

		idx = startingIndex;
		buckets.for_each([&students, &idx](linked_list<student>& list) mutable
			{
				list.for_each([&students, &idx](student& s) mutable
					{
						students.remove_at(idx);
						students.insert(idx, std::move(s));
						idx++;
					});

				list.clear();
			});
	}
}