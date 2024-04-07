#pragma once

#include <iostream>

using namespace std;

template <class T>
class DynamicArray {
private:
	unsigned int size;
	unsigned int capacity;
	T* arr;

public:
	DynamicArray();
	DynamicArray(unsigned int cap);
	~DynamicArray() { delete[] arr; }

	T& operator[](unsigned int index);

	void push(T data);
	T pop();
	void insert(T data, unsigned int index);
	void print();
	int find(T data);

	unsigned int getSize() { return size; }
	unsigned int getCapacity() { return capacity; }
};

template <class T>
DynamicArray<T>::DynamicArray() {
	size = 0;
	capacity = 1;
	arr = new T[capacity];
}

template <class T>
DynamicArray<T>::DynamicArray(unsigned int cap) {
	size = 0;
	capacity = cap;
	arr = new T[capacity];
}

template <class T>
T& DynamicArray<T>::operator[](unsigned int index) {
	if (index < size) {
		return arr[index];
	}
	else {
		throw out_of_range("Index out of range");
	}
}

template <class T>
void DynamicArray<T>::push(T data) {
	if (size == capacity) {
		T* temp = new T[capacity * 2];
		for (unsigned int i = 0; i < capacity; i++) {
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
		capacity *= 2;
	}
	arr[size] = data;
	size++;
}

template <class T>
T DynamicArray<T>::pop() {
	if (size > 0) {
		T temp = arr[size - 1];
		arr[size - 1] = NULL;
		size--;
		return temp;
	}
	else {
		throw out_of_range("Array is empty");
	}
}

template <class T>
void DynamicArray<T>::insert(T data, unsigned int index) {
	if (index < size) {
		if (size == capacity) {
			T* temp = new T[capacity * 2];
			for (unsigned int i = 0; i < capacity; i++) {
				temp[i] = arr[i];
			}
			delete[] arr;
			arr = temp;
			capacity *= 2;
		}
		for (unsigned int i = size; i > index; i--) {
			arr[i] = arr[i - 1];
		}
		arr[index] = data;
		size++;
	}
	else {
		throw out_of_range("Index out of range");
	}
}

template <class T>
void DynamicArray<T>::print() {
	for (unsigned int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

template <class T>
int DynamicArray<T>::find(T data) {
	for (unsigned int i = 0; i < size; i++) {
		if (arr[i] == data) {
			return i;
		}
	}
	return -1;
}