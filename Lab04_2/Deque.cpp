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

//��������� ������ "�������"

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
	//��������� ������ �������� � �������
	if (head != NULL) {
		//� ������� ��� ���� �������
		StructureElement* temp = new StructureElement();
		temp->setElement(source);
		temp->setNext(head);
		head = temp;
		temp = NULL;
		delete temp;
	}
	else {
		//� ������� ��� �������
		head = new StructureElement();
		head->setElement(source);
		head->setNext(NULL);
	}
}

template<typename TYPE>
void Structure<TYPE>::push(TYPE in) {
	TYPE* source = new TYPE(in);
	//��������� ������ �������� � �������
	if (head != NULL) {
		//� ������� ��� ���� �������
		StructureElement* temp = new StructureElement();
		temp->setElement(source);
		temp->setNext(head);
		head = temp;
		temp = NULL;
		delete temp;
	}
	else {
		//� ������� ��� �������
		head = new StructureElement();
		head->setElement(source);
		head->setNext(NULL);
	}
}

template <typename TYPE>
TYPE* Structure<TYPE>::pop() {
	//����� ����������� �� ������� ������� �� ������� FIFO
	StructureElement* temp = this->getFirst();
	TYPE* poppedElement;
	if (temp == NULL) {
		//������ ������� ����
		//temp = NULL;
		delete temp;
		return NULL;
	}
	else if (temp->getNext() == NULL) {
		//� ������� ������� ���� �������
		poppedElement = head->getElement();
		delete head;
		head = NULL;
		//delete temp;
	}
	else {
		//�������� �������� ��� ������� n, ��� n>1
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

//�������� �������
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
	//�������� ��������� �� ������� ������ �������
	return head;
}

template <typename TYPE>
typename Structure<TYPE>::StructureElement* Structure<TYPE>::StructureElement::getNext() {
	//��������� � ���������� ��������
	return this->next;
}

template <typename TYPE>
void Structure<TYPE>::StructureElement::output() {
	//cout << *element;
}

//��������
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