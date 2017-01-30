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

template Structure<int>;
template Structure<short>;
template Structure<char>;
template Structure<void*>;

//Структура данных "Очередь"
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
	cout << *element;
}

//*-- Специализация для типа Interface --*//

Structure<Interface>::StructureElement::StructureElement() {
	element = NULL;
	next = NULL;
}

Structure<Interface>::StructureElement::~StructureElement() {
	//delete element;
	element = NULL;
	delete next;
}

Structure<Interface>::Structure() {

}


Structure<Interface>::~Structure() {
	while (head != NULL) {
		if (head->getElement() != NULL) {
			pop();
		}
	}
	delete head;
}

void Structure<Interface>::push(Interface* source) {
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

Interface* Structure<Interface>::pop() {
	//Метод выбрасывает из очереди элемент по правилу FIFO
	StructureElement* temp = this->getFirst();
	Interface* poppedElement;
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

void Structure<Interface>::StructureElement::setElement(Interface* source) {
	element = source;
}

void Structure<Interface>::StructureElement::setNext(typename Structure<Interface>::StructureElement* source) {
	next = source;
}

Interface* Structure<Interface>::StructureElement::getElement() {
	return this->element;
}

Structure<Interface>::StructureElement* Structure<Interface>::getFirst() {
	//Получить указатель на текущее начало очереди
	return head;
}

Structure<Interface>::StructureElement* Structure<Interface>::StructureElement::getNext() {
	//Обращение к следующему элементу
	return this->next;
}

void Structure<Interface>::StructureElement::output() {
	this->element->output();
}

//void Structure::serialize() {
//	//Сериализация существующей структуры
//	ofstream file("Saved Structure.txt");
//	Structure::StructureElement* temp = this->getFirst();
//	file.close();
//	if (temp == NULL) {
//		cout << endl << "Очередь пуста. Нет элементов для сериализации";
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
//	//Функция реверсивного ввода в файл. Так как мы используем очередь,
//	//нам необходимо записывать её в файл в обратном порядке, чтобы
//	//при считывании получить исходную версию структуры
//	if ((temp->getElement() != NULL) && temp->getNext() ) {
//		recursion(temp->getNext());
//	}
//	temp->getElement()->serialize();
//}
//void Structure::deserialize() {
//	//Десериализация структуры из файла
//		wifstream* read = new wifstream("Saved Structure.txt");
//		if (!read->is_open()) {
//			cout << endl << "Ошибка при открытии файла." << endl;
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