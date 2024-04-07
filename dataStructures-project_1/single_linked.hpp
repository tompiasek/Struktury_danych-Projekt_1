#pragma once

#include <iostream>

using namespace std;


// Klasa Node - pojedynczy element listy jednokierunkowej
template <typename T>
class Node {
public:
	T data;
	Node* next;

	Node() : data(NULL), next(nullptr) {};
	Node(T dta) : data(dta), next(nullptr) {};
	Node(T dta, Node* nxt = nullptr) : data(dta), next(nxt) {};
};

template <typename T>
class SingleLinkedList {
private:
	Node<T>* head = nullptr;
		 
public:
	SingleLinkedList(int n);
	~SingleLinkedList();

	void append(T data);
	void prepend(T data);
	bool insert(T data, int index);
	void remove(int index);
	void display();
	int length();
	int find(T data);

	// Przeciazenie operatora [] - dostep do elementu listy
	T& operator[](unsigned int index) {
		Node<T>* temp = head;
		for (int i = 0; i < index; i++) {
			if (temp->next == nullptr) {
				cout << "Index out of range" << endl;
				return temp->data;
			}
			temp = temp->next;
		}
		return temp->data;
	}
};

template <typename T>
SingleLinkedList<T>::SingleLinkedList(int n) {
	head = new Node<T>();
	head->data = NULL;
	Node<T>* temp = head;
	for (int i = 0; i < n - 1; i++) {
		Node<T>* newNode = new Node<T>();
		temp->next = newNode;
		temp = newNode;
	}
}

template <typename T>
SingleLinkedList<T>::~SingleLinkedList() {
	Node<T>* temp = head;
	while (temp != nullptr) {
		Node<T>* next = temp->next;
		delete temp;
		temp = next;
	}
}

template <typename T>
void SingleLinkedList<T>::append(T data) {
	/* Wstawianie elementu na koncu listy */
	/* Mozna to tez zrobic dodajac atrybut "length" w klasie, 
	ktora bedzie zapisywac dlugosc listy i wtedy operacja wstawiania 
	elementu bedzie znacznie szybsza (O(1) zamiast O(^2) */

	Node<T>* temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	Node<T>* newNode = new Node<T>;
	newNode->data = data;
	newNode->next = nullptr;
	temp->next = newNode;
}

template <typename T>
void SingleLinkedList<T>::prepend(T data) {
	/* Wstawianie elementu na poczatku listy */

	Node<T>* newNode = new Node<T>(data, nullptr);
	newNode->next = head;
	head = newNode;
}

template <typename T>
bool SingleLinkedList<T>::insert(T data, int index) {
	/* Wstawienie elementu do listy jednokierunkowej
		index <int> - indeks, na ktorym ma byc wstawiony element
		data <T> - wartosc elementu
		return <bool> - czy operacja sie powiodla
	*/

	if (index < 0) {
		cout << "Index out of range" << endl;
		return false;
	}

	if (index == 0) {
		// Umieszczenie elementu na poczatku listy
		prepend(data);
		return true;
	}
	else {
		Node<T>* newNode = new Node<T>(data, nullptr);
		Node<T>* temp = head;

		for (int i = 0; i < index - 1; i++) {
			if (!temp) {
				cout << "Index out of range!" << endl;
				delete newNode;
				return false;
			}
			temp = temp->next;
		}
		newNode->next = temp->next;
		temp->next = newNode;
		return true;
	}
}

template <typename T>
void SingleLinkedList<T>::remove(int index) {
	/* Usuniecie elementu z listy jednokierunkowej
		index <int> - indeks elementu do usuniecia
	*/

	if (index < 0) {
		cout << "Index out of range" << endl;
		return;
	}

	Node<T>* temp = head;
	if (index == 0) {
		head = head->next;
		delete temp;
		return;
	}
	for (int i = 0; i < index - 1; i++) {
		if (!temp) {
			cout << "Index out of range" << endl;
			return;
		}
		temp = temp->next;
	}
	Node<T>* toDelete = temp->next;
	temp->next = toDelete->next;
	delete toDelete;
}

template <typename T>
void SingleLinkedList<T>::display() {
	/* Wyswietlenie zawartosci listy jednokierunkowej */

	Node<T>* temp = head;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

template <typename T>
int SingleLinkedList<T>::length() {
	/* Sprawdzenie dlugosci listy jednokierunkowej
		return <int> - dlugosc listy
	*/

	Node<T>* temp = head;
	int count = 0;
	while (temp != nullptr) {
		count++;
		temp = temp->next;
	}
	return count;
}

template <typename T>
int SingleLinkedList<T>::find(T data) {
	/* Szukanie elementu w liscie jednokierunkowej
		data <T> - szukana wartosc
		return <int> - indeks, na ktorym znajduje sie szukana wartosc
	*/

	Node<T>* temp = head;	// Ustawiamy wskaznik na poczatek listy
	int index = 0;
	while (temp != nullptr) {	// Przechodimy przez liste (poki nie trafimy na pusty wskaznik - koniec)
		if (temp->data == data) {	// Jesli znalezlismy szukana wartosc to zwracamy indeks, na ktorym sie znajduje
			return index;
		}
		temp = temp->next;	// Przechodzimy do nastepnego elementu
		index++;
	}
	return -1;	// Jesli nie znalezlismy wartosci to zwracamy -1
}
