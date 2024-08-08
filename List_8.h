#pragma once
#include <utility>
#include <iostream>
#include "Node.h"
#include <random>
template <class T>
class List_8
{
private:
	Node<T>* first;
	Node<T>* last;
	int cantidad;
public:
	List_8();
	List_8(const List_8<T>& other); 
	List_8& operator=(const List_8<T>& other);
	~List_8();

	Node<T>* getFirst();
	Node<T>* getLast();
	int getCantidad();

	bool InsertFirst(T element);
	bool InsertLast(T element);
	bool DeleteFirst();
	bool DeleteLast();
	void Show();
	int Search(T element);
	void Sort();
	void DeleteAll();
	T operator[](int indice);
	void Merge(List_8<T>& vector1, List_8<T>& vector2);
	T getRandom();
	bool Delete(T element); 
};

inline std::ostream& operator<<(std::ostream& os, const std::pair<int, int>& p) {
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}
template<class T>
inline List_8<T>::List_8()
{
	this->first = NULL;
	this->last = NULL;
	this->cantidad = 0;
}
template <class T>  
inline List_8<T>::List_8(const List_8<T>& other) { 
	first = last = nullptr;
	cantidad = 0;
	Node<T>* current = other.first;
	while (current != nullptr) {
		InsertLast(current->getElement());
		current = current->getNext();
	}
}

template <class T>
List_8<T>& List_8<T>::operator=(const List_8<T>& other) {
	if (this == &other) {
		return *this;
	}

	DeleteAll();
	Node<T>* current = other.first;
	while (current != nullptr) {
		InsertLast(current->getElement());
		current = current->getNext();
	}

	return *this;
}
template<class T>
inline List_8<T>::~List_8()
{
	while (first!= nullptr) 
	{
		DeleteFirst();
	}
}

template<class T>
inline Node<T>* List_8<T>::getFirst()
{
	return first;
}

template<class T>
inline Node<T>* List_8<T>::getLast()
{
	return last;
}

template<class T>
inline int List_8<T>::getCantidad()
{
	return cantidad;
}

template<class T>
inline bool List_8<T>::InsertFirst(T element)
{
	bool resultado = false;
	if (first == NULL)
	{
		cantidad++;
		first = new Node<T>(element, NULL, NULL);
		last = first;
		resultado = true;
	}
	else
	{
		cantidad++;
		Node<T>* Aux = new Node<T>(element, first, NULL);
		first->setPrev(Aux);
		first = Aux;
		resultado = true;
	}
	return resultado;
}

template<class T>
inline bool List_8<T>::InsertLast(T element)
{
	bool resultado = false;
	if (first == NULL)
	{
		cantidad++;
		first = new Node<T>(element, NULL, NULL);
		last = first;
		resultado = true;
	}
	else
	{
		cantidad++;
		Node<T>* Aux = new Node<T>(element, NULL, last);
		last->setNext(Aux);
		last = Aux;
		resultado = true;
	}
	return resultado;
}

template<class T>
inline bool List_8<T>::DeleteFirst()
{
	bool resultado = true;
	if (first == NULL)
	{
		resultado = false;
	}
	else
	{
		cantidad--;
		Node<T>* Aux = first;
		first = first->getNext();
		delete Aux;
		if (first == NULL)
		{
			last = NULL;
		}
		else
		{
			first->setPrev(NULL);
		}
	}
	return resultado;
}

template<class T>
inline bool List_8<T>::DeleteLast()
{
	bool resultado = true;
	if (first == NULL)
	{
		resultado = false;
	}
	else
	{
		cantidad--;
		Node<T>* Aux = last;
		last = last->getPrev();
		delete Aux;
		if (last == NULL)
		{
			first = NULL;
		}
		else
		{
			last->setNext(NULL);
		}
	}
	return resultado;
}
template<class T>
inline void List_8<T>::Show() {
	cout << "{";
	if (first == NULL) {
		cout << "";
	}
	else {
		Node<T>* Aux = first;
		while (Aux != NULL) {
			cout << Aux->getElement();
			if (Aux->getNext() != NULL) {
				cout << ", ";
			}
			Aux = Aux->getNext();
		}
	}
	cout << "}" << endl;
}

template<class T>
inline int List_8<T>::Search(T element)
{
	Node<T>* Aux = first;
	int pos = 0;
	while (Aux != NULL)
	{
		if (Aux->getElement() == element)
		{
			return pos;
		}
		else
		{
			pos++;
			Aux = Aux->getNext();
		}
	}
	return -1;
}

template<class T>
inline void List_8<T>::Sort()
{
	Node<T>* Aux = first;
	Node<T>* Temp = Aux;
	while (Aux != NULL)
	{
		Temp = Aux->getNext();
		while (Temp != NULL)
		{
			if (Aux->getElement() > Temp->getElement())
			{
				T Cambio = Aux->getElement();
				Aux->setElement(Temp->getElement());
				Temp->setElement(Cambio);
			}
			Temp = Temp->getNext();
		}
		Aux = Aux->getNext();
	}
}

template<class T>
inline void List_8<T>::DeleteAll()
{
	if (first == NULL)
	{
		cout << "No hay Datos" << endl;
	}
	else
	{
		while (first != NULL)
		{
			DeleteFirst();
		}
	}
}

template<class T>
inline T List_8<T>::operator[](int indice)
{
	int i = 0;
	Node<T>* Aux = first;
	T encontrado;
	while (Aux != NULL)
	{
		if (i == indice)
		{
			encontrado = Aux->getElement();
		}
		i++;
		Aux = Aux->getNext();
	}
	return encontrado;
}

template<class T>
inline void List_8<T>::Merge(List_8<T>& vector1, List_8<T>& vector2)
{
	Node<T>* Aux1 = vector1.first;
	Node<T>* Aux2 = vector2.first;
	int i = 0;
	int j = 0;
	while (Aux1 != NULL || Aux2 != NULL)
	{
		if (Aux1 != NULL)
		{
			this->InsertLast(vector1[i]);
			Aux1 = Aux1->getNext();
			i++;
		}
		if (Aux2 != NULL)
		{
			this->InsertLast(vector2[j]);
			Aux2 = Aux2->getNext();
			j++;
		}
	}
}

template<class T>
inline T List_8<T>::getRandom()
{
	if (cantidad == 0) { 
		throw std::out_of_range("La lista está vacía."); 
	}
	std::random_device rd; 
	std::mt19937 gen(rd()); 
	std::uniform_int_distribution<> dis(0, cantidad - 1); 

	int randomIndex = dis(gen); 
	Node<T>* current = first; 
	for (int i = 0; i < randomIndex; ++i) { 
		current = current->getNext(); 
	}
	return current->getElement(); 
}

template<class T>
inline bool List_8<T>::Delete(T element) {
	Node<T>* current = first; 

	while (current != nullptr) {
		if (current->getElement() == element) {
			if (current->getPrev() != nullptr) {
				current->getPrev()->setNext(current->getNext());
			}
			else {
				first = current->getNext();
			}

			if (current->getNext() != nullptr) {
				current->getNext()->setPrev(current->getPrev());
			}
			else {
				last = current->getPrev();
			}

			delete current;
			--cantidad;
			return true;
		}
		current = current->getNext();
	}
	return false; // Element not found
}
