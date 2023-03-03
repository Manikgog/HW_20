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

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // установка кодовой страницы на ввод текста
	srand(time(NULL));

	const int length = 100;
	int arr[length];
	fill_arr(arr, length, -100, 100);
	show_arr(arr, length);
	int val;
	std::cin >> val;
	search_index(arr, length, val);


	return 0;
}

template <typename T>
int search_index(T* arr, const int length, int value, int begin) {
	if (begin >= 0 && begin <= length) {
		for (int i = begin; i < length; i++) {
			if (arr[i] == value)
				return i;
		}
	}else
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
