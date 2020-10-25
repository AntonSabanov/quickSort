#include "sort.h"

const int n = 20;

template<typename T, typename Compare>
void QuickSort(T *arr, int low, int high, Compare comp) // без рекурсии
{
	int _low = low;
	int _high = high;
	int border;

	while (true)
	{
		if (_low < _high)
		{
			if ((_high - _low) < n)
			{
				InsertionSort(arr, _low, _high, comp);
				return;
			}

			border = Partition(arr, _low, _high, comp); // для левого интервала

			if ((border - _low) + 1 <= _high - border) // слева меньше
			{
				QuickSort(arr, _low, border, comp);
				_low = border + 1;
			}
			else if ((border - _low) + 1 > _high - border) //справа меньше
			{
				QuickSort(arr, border + 1, _high, comp);
				_high = border;
			}
		}
		else return;
	}
}

template<typename T, typename Compare>
void InsertionSort(T* arr, int low, int high, Compare comp)
{
	T currentElement;
	int lastIndex;
	for (int i = low + 1; i < high + 1; i++)
	{
		currentElement = arr[i];
		lastIndex = i;
		while ((lastIndex >= 1) && (comp(currentElement, arr[lastIndex - 1])))
		{
			Swap(arr[lastIndex - 1], arr[lastIndex]);
			lastIndex--;
		}
	}
	return;
}

template<typename T, typename Compare>
int Partition(T *arr, int first, int last, Compare comp)
{
	//T pivot = GetPivotElement(arr, first, (first + last) / 2, last);
	T pivot = GetPivotElement(arr, first, (first + last) / 2, last, comp);
	int left = first;
	int right = last;

	while (true)
	{
		while (comp(arr[left], pivot))
		{
			left++;
		}

		while (comp(pivot, arr[right]))
		{
			right--;
		}

		if (left >= right)
			return right;

		Swap(arr[left], arr[right]);

		left++;
		right--;
	}
}

template<typename T>
T GetPivotElement(T *arr, int first, int mid, int last)
{
	T pivot;
	if ((arr[first] <= arr[mid] && arr[mid] <= arr[last]) || (arr[first] >= arr[mid] && arr[mid] >= arr[last]))
		pivot = arr[mid];
	if ((arr[first] <= arr[last] && arr[last] <= arr[mid]) || (arr[first] >= arr[last] && arr[last] >= arr[mid]))
		pivot = arr[last];
	if ((arr[mid] <= arr[first] && arr[first] <= arr[last]) || (arr[mid] >= arr[first] && arr[first] >= arr[last]))
		pivot = arr[first];
	return pivot;
}

template<typename T, typename Compare>
T GetPivotElement(T *arr, int first, int mid, int last, Compare comp)
{
	T pivot;
	if ((comp(arr[first], arr[mid]) && comp(arr[mid], arr[last])) || (comp(arr[mid], arr[first]) && comp(arr[last], arr[mid])))
		pivot = arr[mid];
	else if ((comp(arr[first], arr[last]) && comp(arr[last], arr[mid])) || (comp(arr[last], arr[first]) && comp(arr[mid], arr[last])))
		pivot = arr[last];
	else if ((comp(arr[mid], arr[first]) && comp(arr[first], arr[last])) || (comp(arr[first], arr[mid]) && comp(arr[last], arr[first])))
		pivot = arr[first];
	else
		pivot = arr[mid];
	return pivot;
}

template<typename T>
void Swap(T &value1, T &value2)
{
	auto temp = value1;
	value1 = value2;
	value2 = temp;
	return;
}