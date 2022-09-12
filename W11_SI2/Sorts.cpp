#include "Sorts.h"
#include <ctime>
#include <stdlib.h>
#include <iostream>

void Sorts::selectionSort()
{
	clock_t start{}, stop{}, duration{};
	int arr[500]{};

	for (size_t i{ 0 }; i < 499; i++) {
		arr[i] = rand() % 500;
	}

	std::cout << "\t\t --- SELECTION SORT ---\n\n";
	std::cout << "\tUnsorted arr:\n";
	for (auto a : arr)
		std::cout << arr[a] << " ";
	std::cout << std::endl << std::endl;

	start = clock();
	for (int step = 0; step < 500 - 1; step++) {
		int min_idx = step;
		for (int i = step + 1; i < 500; i++) {

			if (arr[i] < arr[min_idx])
				min_idx = i;
		}
		swap(&arr[min_idx], &arr[step]);
	}
	stop = clock();
	duration = stop - start;

	std::cout << "\tSorted arr:\n";
	for (auto a : arr)
		std::cout << arr[a] << " ";
	std::cout << std::endl << std::endl;

	std::cout << "Duration of sorting: " << duration << " seconds" << std::endl << std::endl;
}

void Sorts::swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Sorts::bubbleSort()
{
	clock_t start{}, stop{}, duration{};
	int arr[500]{};

	for (size_t i{ 0 }; i < 499; i++) {
		arr[i] = rand() % 500;
	}
	std::cout << "\t\t --- BUBBLE SORT ---\n\n";
	std::cout << "\tUnsorted arr:\n";
	for (auto a : arr)
		std::cout << arr[a] << " ";
	std::cout << std::endl << std::endl;

	start = clock();

	for (size_t i{0}; i < 500 - 1; i++)
		for (size_t j{0}; j < 499 - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);

	stop = clock();
	duration = stop - start;

	std::cout << "\tSorted arr:\n";
	for (auto a : arr)
		std::cout << arr[a] << " ";
	std::cout << std::endl << std::endl;
	
	std::cout << "Duration of sorting: " << duration << " seconds" << std::endl << std::endl;
}

void Sorts::insertionSort()
{
	clock_t start{}, stop{}, duration{};
	int arr[500]{};

	for (size_t i{ 0 }; i < 499; i++) {
		arr[i] = rand() % 500;
	}
	std::cout << "\t\t --- INSERTION SORT ---\n\n";
	std::cout << "\tUnsorted arr:\n";
	for (auto a : arr)
		std::cout << arr[a] << " ";
	std::cout << std::endl << std::endl;

	start = clock();

	int key, j;
	for (int i{0}; i < 500; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
	stop = clock();
	duration = stop - start;

	std::cout << "\tUnsorted arr:\n";
	for (auto a : arr)
		std::cout << arr[a] << " ";
	std::cout << std::endl << std::endl;

	std::cout << "Duration of sorting: " << duration << " seconds" << std::endl << std::endl;
}

void Sorts::mergeSort(int array[], int const left, int const mid, int const right)
{
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	// Create temp arrays
	auto* leftArray = new int[subArrayOne],
		* rightArray = new int[subArrayTwo];

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	auto indexOfSubArrayOne = 0, // Initial index of first sub-array
		indexOfSubArrayTwo = 0; // Initial index of second sub-array
	int indexOfMergedArray = left; // Initial index of merged array

	// Merge the temp arrays back into array[left..right]
	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
			array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// left[], if there are any
	while (indexOfSubArrayOne < subArrayOne) {
		array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo) {
		array[indexOfMergedArray]
			= rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
	delete[] leftArray;
	delete[] rightArray;
}

void Sorts::quickSort(int arr[], int l, int r)
{
	if (l < r) {
		int pivot = l;
		int i = l;
		int j = r;
		while (i < j) {
			while (arr[i] <= arr[pivot] && i < r)
				i++;
			while (arr[j] > arr[pivot])
				j--;
			if (i < j) {
				std::swap(arr[i], arr[j]);
			}
		}
		std::swap(arr[pivot], arr[j]);
		quickSort(arr, l, j - 1);
		quickSort(arr, j + 1, r);
	}
}

void Sorts::heapSort(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		std::swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapSort(arr, n, largest);
	}
}

void Sorts::allSorts()
{
	selectionSort();
	bubbleSort();
	insertionSort();
}
