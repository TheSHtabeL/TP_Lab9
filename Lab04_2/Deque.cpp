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

using namespace std;

//��������� ������ "�������"
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
		while (temp->getNext()->getNext() !=NULL) {
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

//void Structure::serialize() {
//	//������������ ������������ ���������
//	ofstream file("Saved Structure.txt");
//	Structure::StructureElement* temp = this->getFirst();
//	file.close();
//	if (temp == NULL) {
//		cout << endl << "������� �����. ��� ��������� ��� ������������";
//		//delete temp;
//	}
//	else {
//		recursion(temp);
//	}
//	file.open("Saved Structure.txt", ios_base::app);
//	file << "#end";
//	file.close();
//	temp = NULL;
//	//delete temp;
//}
//void Structure::recursion(StructureElement* temp) {
//	//������� ������������ ����� � ����. ��� ��� �� ���������� �������,
//	//��� ���������� ���������� � � ���� � �������� �������, �����
//	//��� ���������� �������� �������� ������ ���������
//	if ((temp->getElement() != NULL) && temp->getNext() ) {
//		recursion(temp->getNext());
//	}
//	temp->getElement()->serialize();
//}
//void Structure::deserialize() {
//	//�������������� ��������� �� �����
//		wifstream* read = new wifstream("Saved Structure.txt");
//		if (!read->is_open()) {
//			cout << endl << "������ ��� �������� �����." << endl;
//			return;
//		}
//		wchar_t* command = new wchar_t[100];
//		while (!read->eof()) {
//			read->getline(command, 100);
//			if (!wcscmp(command,L"#Phone")) {
//				Phone* element = new Phone();
//				element->deserialize(read);
//				push(element);
//				element = NULL;
//			}
//			else if (!wcscmp(command, L"#ButtonPhone")) {
//				ButtonPhone* element = new ButtonPhone();
//				element->deserialize(read);
//				push(element);
//				element = NULL;
//			}
//			else if (!wcscmp(command, L"#AndroidPhone")) {
//				AndroidPhone* element = new AndroidPhone();
//				element->deserialize(read);
//				push(element);
//				element = NULL;
//			}
//			else if (!wcscmp(command, L"#SensorPhone")) {
//				SensorPhone* element = new SensorPhone();
//				element->deserialize(read);
//				push(element);
//				element = NULL;
//			}
//			else if (!wcscmp(command,L"#end")) {
//				delete command;
//				delete read;
//				return;
//			}
//		}
//		delete command;
//		delete read;
//}