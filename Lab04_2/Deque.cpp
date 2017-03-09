#include <iostream>
#include <fstream>
#include <conio.h>
#include <clocale>
#include <cstdlib>
#include <cctype>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"
#include "Types.h"

using namespace std;

//Структура данных "Очередь"

template <typename TYPE>
Structure<TYPE>::Structure() {

}

template<typename TYPE>
Structure<TYPE>::~Structure() {
	while (head != NULL) {
		if (head->getElement() != NULL) {
			pop();
		}
	}
	delete head;
}

template<typename TYPE>
void Structure<TYPE>::push(TYPE* source) {
	//Помещение нового элемента в очередь
	if (head != NULL) {
		//В очереди уже есть вершина
		StructureElement* temp = new StructureElement();
		temp->setElement(source);
		temp->setNext(head);
		head = temp;
		temp = NULL;
		delete temp;
	}
	else {
		//В очереди нет вершины
		head = new StructureElement();
		head->setElement(source);
		head->setNext(NULL);
	}
}

template<typename TYPE>
void Structure<TYPE>::push(TYPE in) {
	TYPE* source = new TYPE(in);
	//Помещение нового элемента в очередь
	if (head != NULL) {
		//В очереди уже есть вершина
		StructureElement* temp = new StructureElement();
		temp->setElement(source);
		temp->setNext(head);
		head = temp;
		temp = NULL;
		delete temp;
	}
	else {
		//В очереди нет вершины
		head = new StructureElement();
		head->setElement(source);
		head->setNext(NULL);
	}
}

template <typename TYPE>
TYPE* Structure<TYPE>::pop() {
	//Метод выбрасывает из очереди элемент по правилу FIFO
	StructureElement* temp = this->getFirst();
	TYPE* poppedElement;
	if (temp == NULL) {
		//Первый элемент пуст
		//temp = NULL;
		delete temp;
		return NULL;
	}
	else if (temp->getNext() == NULL) {
		//В очереди остался один элемент
		poppedElement = head->getElement();
		delete head;
		head = NULL;
		//delete temp;
	}
	else {
		//Удаление элемента под номером n, где n>1
		while (temp->getNext()->getNext() != NULL) {
			temp = temp->getNext();
		}
		poppedElement = temp->getNext()->getElement();
		delete temp->getNext();
		temp->setNext(NULL);
	}
	temp = NULL;
	delete temp;
	return poppedElement;
}

//Элементы очереди
template <typename TYPE>
Structure<TYPE>::StructureElement::StructureElement() {
	element = NULL;
	next = NULL;
}

template<typename TYPE>
Structure<TYPE>::StructureElement::~StructureElement() {
	//delete element;
	element = NULL;
	delete next;
}

template <typename TYPE>
void Structure<TYPE>::StructureElement::setElement(TYPE* source) {
	element = source;
}

template <typename TYPE>
void Structure<TYPE>::StructureElement::setNext(typename Structure<TYPE>::StructureElement* source) {
	next = source;
}

template <typename TYPE>
TYPE* Structure<TYPE>::StructureElement::getElement() {
	return this->element;
}

template <typename TYPE>
typename Structure<TYPE>::StructureElement* Structure<TYPE>::getFirst() {
	//Получить указатель на текущее начало очереди
	return head;
}

template <typename TYPE>
typename Structure<TYPE>::StructureElement* Structure<TYPE>::StructureElement::getNext() {
	//Обращение к следующему элементу
	return this->next;
}

template <typename TYPE>
void Structure<TYPE>::StructureElement::output() {
	//cout << *element;
}

//Итератор
template <typename TYPE>
Structure<TYPE>::Iterator::Iterator() {
	element = NULL;
}

template <typename TYPE>
Structure<TYPE>::Iterator::Iterator(Iterator* original) {
	element = original->element;
}

template <typename TYPE>
Structure<TYPE>::Iterator::Iterator(const Iterator& original) {
	element = original.element;
}

template <typename TYPE>
Structure<TYPE>::Iterator::~Iterator() {
	element = NULL;
}

template <typename TYPE>
typename Structure<TYPE>::Iterator* Structure<TYPE>::begin() {
	Iterator* it = new Iterator();
	it->setIterator(getFirst());

	return it;
}

template <typename TYPE>
typename Structure<TYPE>::Iterator* Structure<TYPE>::end() {
	return NULL;
}

template <typename TYPE>
void Structure<TYPE>::Iterator::setIterator(StructureElement* source) {
	element = source;
}

template <typename TYPE>
bool Structure<TYPE>::Iterator::operator==(const Iterator& original) {
	return (element == original.element) ? true : false;
}

template <typename TYPE>
typename Structure<TYPE>::Iterator& Structure<TYPE>::Iterator::operator=(const Iterator& original) {
	if (&original == this) {
		return *this;
	}
	else {
		element = original.element;
		return *this;
	}
}

template <typename TYPE>
typename Structure<TYPE>::Iterator& Structure<TYPE>::Iterator::operator++() {
	this->element = this->element->getNext();
	if (element == NULL) {
		//return NULL;
	}
	else {
		return *this;
	}
}