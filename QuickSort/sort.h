#pragma once

template<typename T>
T GetPivotElement(T*, int, int, int);

template<typename T>
void Swap(T&, T&);

template<typename T, typename Compare>
int Partition(T*, int, int, Compare);

template<typename T, typename Compare>
void InsertionSort(T*, int, int, Compare);

template<typename T, typename Compare>
void QuickSort(T*, int, int, Compare); 

int compare(const void*, const void*);  
