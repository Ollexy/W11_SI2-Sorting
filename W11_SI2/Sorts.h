#pragma once
class Sorts
{


public:
	void swap(int* a, int* b);
	void selectionSort();
	void bubbleSort();
	void insertionSort();
	void mergeSort(int array[], int const left, int const mid, int const right);
	void quickSort(int arr[], int l, int r);
	void heapSort(int arr[], int n, int i);
	void allSorts();
};

