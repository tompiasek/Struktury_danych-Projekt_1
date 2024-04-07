#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include <conio.h>
#include "single_linked.hpp"
#include "dynamicArray.hpp"

using namespace std;

int main()
{
	/* SETUP */
	srand(time(NULL));
	fstream data;
	data.open("data.txt", ios::out | ios::app);

	/* TEST BLOCK */
	DynamicArray<int> arr(100000);
	SingleLinkedList<int> list(100000);

	for (int i = 1; i < 100000; i++)
	{
		arr.push(rand() % 1000);
		list.append(rand() % 1000);
	}
	arr.push(1001);
	list.append(1001);

	auto arr_start = chrono::high_resolution_clock::now();
	arr.find(1001);
	auto arr_stop = chrono::high_resolution_clock::now();
	auto arr_duration = chrono::duration_cast<chrono::microseconds>(arr_stop - arr_start);

	auto list_start = chrono::high_resolution_clock::now();
	list.find(1001);
	auto list_stop = chrono::high_resolution_clock::now();
	auto list_duration = chrono::duration_cast<chrono::microseconds>(list_stop - list_start);

	string res = "Array find duration (10k int; 1st pos): " + to_string(arr_duration.count()) + " microseconds\n" +
		"List find duration (10k int; 1st pos): " + to_string(list_duration.count()) + " microseconds";

	cout << res << endl;

	cout << endl << "Do you want to save the data to a file? (y/n): ";
	char choice;
	choice = _getch();
	if (choice == 'y')
	{
		data << endl << res;
	}


	data.close();
	return 0;
}