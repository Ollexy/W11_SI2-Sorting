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

void Sorts::mergeSort()
{
	clock_t start{}, stop{}, duration{};
	int arr[500]{};

	for (size_t i{ 0 }; i < 499; i++) {
		arr[i] = rand() % 500;
	}
	start = clock();
}

void Sorts::quickSort()
{
	clock_t start{}, stop{}, duration{};
	int arr[500]{};

	for (size_t i{ 0 }; i < 499; i++) {
		arr[i] = rand() % 500;
	}
	start = clock();
}

void Sorts::heapSort()
{
	clock_t start{}, stop{}, duration{};
	int arr[500]{};

	for (size_t i{ 0 }; i < 499; i++) {
		arr[i] = rand() % 500;
	}
	start = clock();
}

void Sorts::allSorts()
{
	selectionSort();
	bubbleSort();
	insertionSort();
	//mergeSort();
	//quickSort();
	//heapSort();
}
