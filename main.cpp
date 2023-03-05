#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>

template <typename T>
void show_arr(T* arr, const int size);

template <typename T>
void fill_arr(T* arr, const int size, int low, int hi);

template <typename T>
int search_index(T* arr, const int length, int value, int begin = 0);

template <typename T>
int search_last_index(T* arr, const int length, int value);

template <typename T>
int search_last_index(T* arr, const int length, int value, int begin);

template <typename T>
T arr_min(T* arr, const int length);

template <typename T>
T arr_max(T* arr, const int length);

template <typename T>
double mean_value(T* arr, const int length);

template <typename T>
void range(T* arr, const int length, T left, T right);

template <typename T>
int counter(T* arr, const int length, T value);

template <typename T>
void Testing_search_index(T* arr, const int length);

template <typename T>
void Testing_search_last_index(T* arr, const int length);

template <typename T>
void Testing_search_last_index_(T* arr, const int length);

template <typename T>
int check_same_number(T* arr, const int length);


int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	srand(time(NULL));

	const int length = 100;
	int arr[length];
	do{
		fill_arr(arr, length, -100, 100);
	} while (check_same_number(arr, length) == 0);
	std::cout << "Array:\n";
	show_arr(arr, length);
	std::cout << "\n\n\n";
	char c = 'y';
	
	///////////////////////////////////////////////////////////////////////////////////////////////
	std::cout << "Testing the function search_index(T* arr, const int length, value, begin).\n";
	do {
		Testing_search_index(arr, length);
		std::cout << "Again (y/n) ? ";
		std::cin >> c;
	} while (c == 'y');
	std::cout << "\n\n\n";
	///////////////////////////////////////////////////////////////////////////////////////////////
	std::cout << "Testing the function search_last_index(T* arr, const int length, int value).\n";
	do {
		Testing_search_last_index(arr, length);
		std::cout << "Again (y/n) ? ";
		std::cin >> c;
	} while (c == 'y');
	std::cout << "\n\n\n";
	///////////////////////////////////////////////////////////////////////////////////////////////
	std::cout << "Testing the function search_last_index(T* arr, const int length, int value, int begin).\n";
	do {
		Testing_search_last_index_(arr, length);
		std::cout << "Again (y/n) ? ";
		std::cin >> c;
	} while (c == 'y');
	std::cout << "\n\n\n";
	system("cls");
	///////////////////////////////////////////////////////////////////////////////////////////////
	std::cout << "Testing the function arr_min(arr, length).\n";
	do {
		fill_arr(arr, length, -100, 100);
		show_arr(arr, length);
		std::cout << "Minimum element is -> " << arr_min(arr, length) << std::endl;
		std::cout << "Again (y/n) ? ";
		std::cin >> c;
	} while (c == 'y');
	std::cout << "\n\n\n";
	
	///////////////////////////////////////////////////////////////////////////////////////////////
	std::cout << "Testing the function arr_max(arr, length).\n";
	do {
		fill_arr(arr, length, -100, 100);
		show_arr(arr, length);
		std::cout << "Maximum element is -> " << arr_max(arr, length) << std::endl;
		std::cout << "Again (y/n) ? ";
		std::cin >> c;
	} while (c == 'y');
	std::cout << "\n\n\n";
	

	///////////////////////////////////////////////////////////////////////////////////////////////

	std::cout << "Testing the function mean_value(arr, length).\n";
	do {
		fill_arr(arr, length, -100, 100);
		show_arr(arr, length);
		std::cout << "The arithmetic mean of the array is equal " << mean_value(arr, length) << std::endl;
		std::cout << "Again (y/n) ? ";
		std::cin >> c;
	} while (c == 'y');
	std::cout << "\n\n\n";
	
	///////////////////////////////////////////////////////////////////////////////////////////////

	std::cout << "Testing the function range(arr, length, left, right).\n";
	do {
		fill_arr(arr, length, -100, 100);
		show_arr(arr, length);
		int left, right;
		std::cout << "Enter the range boundaries: ";
		std::cin >> left >> right;
		std::cout << "The range from " << left << " to " << right << " includes the following numbers -> "; range(arr, length, left, right);
		std::cout << "Again (y/n) ? ";
		std::cin >> c;
	} while (c == 'y');
	std::cout << "\n\n\n";

	///////////////////////////////////////////////////////////////////////////////////////////////
	
	std::cout << "Testing the function counter(arr, length, value).\n";
	do {
		fill_arr(arr, length, -100, 100);
		show_arr(arr, length);
		int value;
		std::cout << "Enter a number to search for the number of occurrences of this number in the array -> ";
		std::cin >> value;
		std::cout << "The number of occurrences of the number " << value << " is equal to " << counter(arr, length, value) << std::endl;
		std::cout << "Again (y/n) ? ";
		std::cin >> c;
	} while (c == 'y');
	std::cout << "\n\n\n";

	

	return 0;
}

template <typename T>
void Testing_search_index(T* arr, const int length) {
	int val, begin = 0;
	std::cout << "Enter a number to search for index of this number in the array -> ";
	std::cin >> val;
	std::cout << search_index(arr, length, val) << std::endl;
	std::cout << "Enter a number to search for index of this number in the array -> ";
	std::cin >> val;
	std::cout << "Enter the index to start the search -> ";
	std::cin >> begin;
	std::cout << search_index(arr, length, val, begin) << std::endl;
}

template <typename T>
void Testing_search_last_index(T* arr, const int length) {
	int val;
	std::cout << "Enter a number to search for index of this number in the array -> ";
	std::cin >> val;
	std::cout << search_last_index(arr, length, val) << std::endl;
}

template <typename T>
void Testing_search_last_index_(T* arr, const int length) {
	int val;
	std::cout << "Enter a number to search for index of this number in the array -> ";
	std::cin >> val;
	int begin;
	std::cout << "Enter the index to start the search -> ";
	std::cin >> begin;
	std::cout << search_last_index(arr, length, val, begin) << std::endl;
}

template <typename T>
int counter(T* arr, const int length, T value) {
	int counter = 0;
	for (size_t i = 0; i < length; i++) {
		value == arr[i] ? counter++ : counter;
	}
	return counter;
}

template <typename T>
void range(T* arr, const int length, T left, T right) {
	if (left > right)
		std::swap(left, right);
	int count = 0;
	for (size_t i = 0; i < length; i++){
		if (arr[i] >= left && arr[i] <= right) {
			std::cout << arr[i] << ' ';
			count++;
		}
	}
	if (!count)
		std::cout << "There are no array values in the specified range.";
	std::cout << std::endl;
}

template <typename T>
double mean_value(T* arr, const int length) {
	T summ = 0;
	for (size_t i = 0; i < length; i++)
	{
		summ += arr[i];
	}
	return (double)summ / length;
}


template <typename T>
T arr_min(T* arr, const int length) {
	int min = arr[0];
	for (size_t i = 1; i < length; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	return min;
}

template <typename T>
T arr_max(T* arr, const int length) {
	int max = arr[0];
	for (size_t i = 1; i < length; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

template <typename T>
int search_index(T* arr, const int length, int value, int begin) {
	if (begin >= 0 && begin <= length) {
		for (int i = begin; i < length; i++) {
			if (arr[i] == value)
				return i;
		}
		return -1;
	}
	else
		std::cout << "The entered index of the beginning of the search is missing in the array!\n";
	
	return -2;
}

template <typename T>
int search_last_index(T* arr, const int length, int value, int begin) {
	if (begin >= 0 && begin <= length) {
		for (int i = begin; i >= 0; i--) {
			if (arr[i] == value)
				return i;
		}
		return -1;
	}
	else
		std::cout << "The entered index of the beginning of the search is missing in the array!\n";

	return -2;
}

template <typename T>
int search_last_index(T* arr, const int length, int value) {
	for (int i = length - 1; i >= 0; i--) {
		if (arr[i] == value)
			return i;
	}
	return -1;
}


template <typename T>
void fill_arr(T* arr, const int size, int low, int hi) {
	for (int i = 0; i < size; ++i) {
		arr[i] = rand() % (hi + 1 - low) + low;
	}
}


template <typename T>
void show_arr(T* arr, const int size) {
	
	std::cout << "[ ";
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << ", ";
	}
	std::cout << "\b\b ]\n";
}

template <typename T>
int check_same_number(T* arr, const int length) {
	int count = 0;
	for (size_t i = 0; i < length-1; i++)
	{
		for (size_t j = i+1; j < length; j++) {
			if(arr[i] == arr[j])
				count++;
		}
	}
	if(count)
		return 1;
	else
		return 0;
}
