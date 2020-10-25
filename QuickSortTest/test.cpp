#include "pch.h"
#include <ctime>
#include <algorithm>
#include "../QuickSort/quickSort.cpp"

TEST(TestCaseName, TestName) 
{
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(Median_test, ten_elements)
{
	int arr[] = { 5, 9, 1, 2, 4, 3, 8, 6, 7, 10 };
	EXPECT_EQ(5, GetPivotElement(arr, 0, (9 / 2), 9));
}

TEST(Median_test, ten_elements_withComparator)
{
	int arr[] = { 5, 9, 1, 2, 4, 3, 8, 6, 7, 10 };
	EXPECT_EQ(5, GetPivotElement(arr, 0, (9 / 2), 9), [](auto a, auto b) -> bool {return a > b; });
}

TEST(Median_test, three_elements)
{
	int arr[] = { 3, 9, 0 };
	EXPECT_EQ(3, GetPivotElement(arr, 0, (2 / 2), 2));
}

TEST(Median_test, who_elements)
{
	int arr[] = { 7, 9 };
	EXPECT_EQ(7, GetPivotElement(arr, 0, (1 / 2), 1));
}

TEST(Median_test, with_same_elements)
{
	int arr[] = { 3, 9, 3 };
	EXPECT_EQ(3, GetPivotElement(arr, 0, (2 / 2), 2));
	int arr2[] = { 3, 9, 9 };
	EXPECT_EQ(9, GetPivotElement(arr2, 0, (2 / 2), 2));
}

TEST(Partition_test, ten_elements)
{
	int arr[] = { 5, 9, 1, 2, 4, 3, 8, 6, 7, 10 };
	EXPECT_EQ(3, Partition(arr, 0, 9, [](auto a, auto b) {return a < b; }));
}

TEST(QS_test, int_empty)
{
	int arr[3] = {};
	QuickSort(arr, 0, 2, [](auto a, auto b) -> bool {return a < b; });	
	EXPECT_EQ(3, sizeof(arr) / sizeof(arr[0]));
	EXPECT_EQ(0, arr[0]);
	EXPECT_EQ(0, arr[1]);
	EXPECT_EQ(0, arr[2]);
}

TEST(QS_test, int_two)
{
	int arr[] = {2, 1};
	QuickSort(arr, 0, 1, [](auto a, auto b) -> bool {return a < b; });
	EXPECT_EQ(1, arr[0]);
	EXPECT_EQ(2, arr[1]);
}

TEST(QS_test, int_five)
{
	int sortedArray[] = { 1, 2, 3, 4, 5 };
	int arr[] = { 2, 4, 1, 5, 3};
	QuickSort(arr, 0, 4, [](auto a, auto b) -> bool {return a < b; });
	for (int i = 0; i < 5; i++)
		EXPECT_EQ(sortedArray[i], arr[i]);
}

TEST(QS_test, int_five_same)
{
	int arr[] = { 1, 1, 1, 1, 1 };
	QuickSort(arr, 0, 4, [](auto a, auto b) -> bool {return a < b; });
	for (int i = 0; i < 5; i++)
		EXPECT_EQ(1, arr[i]);
	EXPECT_EQ(5, sizeof(arr) / sizeof(arr[0]));
}

TEST(QS_test, char_five)
{
	char arr[] = { 'c', 'b', 'd', 'a', 'e' };
	char sortedArray[] = { 'a', 'b', 'c', 'd', 'e' };
	QuickSort(arr, 0, 5 - 1, [](auto a, auto b) {return a < b; });
	for (int i = 0; i < 5; i++)
		EXPECT_EQ(sortedArray[i], arr[i]);
}

TEST(QS_test, int_oneHundred)
{
	const int count = 100;
	int arr[count];
	int sortedArray[count];
	srand(time(0));
	for (int i = 0; i < count; i++)	
		arr[i] = 1 + rand() % count;	
	for (int i = 0; i < count; i++)
		sortedArray[i] = arr[i];	
	qsort(sortedArray, count, sizeof(int), compare);
	QuickSort(arr, 0, count - 1, [](int a, int b) {return a < b; });
	for (int i = 0; i < count; i++)
		EXPECT_EQ(sortedArray[i], arr[i]);
}

TEST(QS_test, int_oneThousand)
{
	const int count = 1000;
	int arr[count];
	int sortedArray[count];
	srand(time(0));
	for (int i = 0; i < count; i++)
		arr[i] = 1 + rand() % count;
	for (int i = 0; i < count; i++)
		sortedArray[i] = arr[i];
	qsort(sortedArray, count, sizeof(int), compare);
	QuickSort(arr, 0, count - 1, [](auto a, auto b) {return a < b; });
	for (int i = 0; i < count; i++)
		EXPECT_EQ(sortedArray[i], arr[i]);
}

TEST(QS_test, int_oneHundredThousand)
{
	const int count = 100000;
	int arr[count];
	int sortedArray[count];
	srand(time(0));
	for (int i = 0; i < count; i++)
		arr[i] = 1 + rand() % count;
	for (int i = 0; i < count; i++)
		sortedArray[i] = arr[i];
	qsort(sortedArray, count, sizeof(int), compare);
	QuickSort(arr, 0, count - 1, [](auto a, auto b) {return a < b; });
	for (int i = 0; i < count; i++)
		EXPECT_EQ(sortedArray[i], arr[i]);
}

TEST(QS_test, float_ten)
{
	float arr[] = { 0.1, 2.2222, 0.01, 0.02, 4.5, 4.45, 5, 9.01, 9.009, 0.0 };
	float sortedArray[] = { 0.0, 0.01, 0.02, 0.1, 2.2222, 4.45, 4.5, 5, 9.009, 9.01 };
	QuickSort(arr, 0, 9, [](auto a, auto b) {return a < b; });
	for (int i = 0; i < 10; i++)
		EXPECT_TRUE((sortedArray[i] - arr[i]) < 0.0000001);
}

struct testStruct
{
	std::string name;
	int id;
	float number;
};

TEST(QS_test, struct_elements)
{
	testStruct testElement1 = { "test1", 4, 0.2 };
	testStruct testElement2 = { "test2", 7, 3.567 };
	testStruct testElement3 = { "test3", 2, 3.5 };

	testStruct arr[] = { testElement1, testElement2, testElement3 };
	testStruct sortedArrayById[] = { testElement3, testElement1, testElement2 };
	testStruct sortedArrayByNumber[] = { testElement2, testElement3, testElement1 };

	QuickSort(arr, 0, 2, [](auto a, auto b) {return a.id < b.id; }); // сортировака по id по возростанию
	for (int i = 0; i < 3; i++)
		EXPECT_EQ(sortedArrayById[i].id, arr[i].id);

	QuickSort(arr, 0, 2, [](auto a, auto b) {return a.number > b.number; }); // сортировака по number по убыванию
	for (int i = 0; i < 3; i++)
		EXPECT_TRUE((sortedArrayByNumber[i].number - arr[i].number) < 0.000001);
}

TEST(IS_test, int_ten)
{
	int arr[] = { 5, 9, 1, 2, 4, 3, 8, 6, 7, 10 };
	int sortedArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	InsertionSort(arr, 0, 9, [](auto a, auto b) {return a < b; });
	for (int i = 0; i < 10; i++)
		EXPECT_EQ(sortedArray[i], arr[i]);
}

TEST(IS_test, int_ten_same)
{
	int arr[] = { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 };
	InsertionSort(arr, 0, 9, [](auto a, auto b) {return a < b; });
	for (int i = 0; i < 10; i++)
		EXPECT_EQ(3, arr[i]);
	EXPECT_EQ(10, sizeof(arr) / sizeof(arr[0]));
}

TEST(IS_test, double_ten)
{
	double arr[] = { 5.3, 1.1, 1.01, 5.3, 4.5, 3, 1.0, 6.9, 7.0, 0.0 };
	double sortedArray[] = { 0.0, 1.0, 1.01, 1.1, 3, 4.5, 5.3, 5.3, 6.9, 7 };
	InsertionSort(arr, 0, 9, [](auto a, auto b) {return a < b; });
	for (int i = 0; i < 10; i++)
		EXPECT_TRUE((sortedArray[i] - arr[i]) < 0.00000001);
}

TEST(Comp_test, ascending) //по возростанию
{
	int arr[] = { 5, 9, 1, 2, 4, 3, 8, 6, 7, 10 };
	int sortedArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	QuickSort(arr, 0, 9, [](auto a, auto b) {return a < b; });
	for (int i = 0; i < 10; i++)
		EXPECT_EQ(sortedArray[i], arr[i]);
}

TEST(Comp_test, descending) //по убыванию
{
	int arr[] = { 5, 9, 1, 2, 4, 3, 8, 6, 7, 10 };
	int sortedArray[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	QuickSort(arr, 0, 9, [](auto a, auto b) {return a > b; });
	for (int i = 0; i < 10; i++)
		EXPECT_EQ(sortedArray[i], arr[i]);
}

int compare(const void * x1, const void * x2)   
{
	return (*(int*)x1 - *(int*)x2);              
}