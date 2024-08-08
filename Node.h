#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <map>
#include <chrono>
#include <vector>
#include <queue>


using namespace std;

template <class T>
class Node
{
private:
	T element;
	Node<T>* next;
	Node<T>* prev;
public:
	Node(T element, Node<T>* next, Node<T>* prev);
	~Node();

	T getElement();
	Node<T>* getNext();
	Node<T>* getPrev();

	void setElement(T element);
	void setNext(Node<T>* next);
	void setPrev(Node<T>* prev);

	void CreateNext(T element);
};

template<class T>
inline Node<T>::Node(T element, Node<T>* next, Node<T>* prev)
{
	this->element = element;
	this->next = next;
	this->prev = prev;
}

template<class T>
inline Node<T>::~Node()
{
}

template<class T>
inline T Node<T>::getElement()
{
	return element;
}

template<class T>
inline Node<T>* Node<T>::getNext()
{
	return next;
}

template<class T>
inline Node<T>* Node<T>::getPrev()
{
	return prev;
}

template<class T>
inline void Node<T>::setElement(T element)
{
	this->element = element;
}

template<class T>
inline void Node<T>::setNext(Node<T>* next)
{
	this->next = next;
}

template<class T>
inline void Node<T>::setPrev(Node<T>* prev)
{
	this->prev = prev;
}

template<class T>
inline void Node<T>::CreateNext(T element)
{
	next = new Node<T>(element, NULL, this);
}