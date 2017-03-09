/*----------------------------*/
/*-- Лабораторная работа №9 --*/
/*----------------------------*/
#include <tchar.h>
#include <iostream>
#include <conio.h>
#include <clocale>
#include <cstdlib>
#include <cctype>
#include <wchar.h>
#include "Phone.h"
#include "Deque.h"
#include "Compare.h"

using namespace std;

void wait();
template <typename TYPE>
void outputDeque(Structure<TYPE>* structure);
void compare();

int main()
{
	locale::global(std::locale("Russian"));
	setlocale(LC_ALL, "Russian");
	std::wcin.imbue(std::locale("rus_rus.866"));

	Structure<int>* intStructure = new Structure<int>();
	Structure<Phone>* phoneStructure = new Structure<Phone>();
	Structure<Interface*>* interfaceStructure = new Structure<Interface*>();

	for (int i = 0; i < 3; i++) {
		intStructure->push(i);
	}
	//Вывод
	for (int i = 0; i < 3; i++) {
		outputDeque(intStructure);
		_getch();
	}

	//Через итератор:
	for (Structure<int>::Iterator* it = intStructure->begin(); it != intStructure->end(); ) {
		//int output = *it;
		++it;
	}

	for (int i = 0; i < 3; i++) {
		intStructure->pop();
	}

	for (int i = 0; i < 3; i++) {
		phoneStructure->push(Phone(i,i,i));
	}
	//Вывод
	for (int i = 0; i < 3; i++) {
		outputDeque(phoneStructure);
		_getch();
	}
	for (int i = 0; i < 3; i++) {
		phoneStructure->pop();
	}

	for (int i = 0; i < 3; i++) {
		Phone* element = new Phone(i,i,i);
		interfaceStructure->push(element);
		element = NULL;
	}
	//Вывод
	for (int i = 0; i < 3; i++) {
		outputDeque(interfaceStructure);
		_getch();
	}
	for (int i = 0; i < 3; i++) {
		interfaceStructure->pop();
	}

	delete intStructure;
	delete phoneStructure;
	delete interfaceStructure;
}

void wait() {
	cout << endl << "Нажмите любую клавишу для продолжения..." << endl;
	_getch();
}

template<typename TYPE>
void outputDeque(Structure<TYPE>* structure) {
	Structure<TYPE>::StructureElement* temp = structure->getFirst();
	if (temp == NULL) {
		cout << endl << "Очередь пуста";
		delete temp;
	}
	else {
		for (int i = 1; temp->getElement() != NULL; i++) {
			cout << endl << "Элемент очереди №" << i << ":" << endl;
			temp->output();
			if (temp->getNext()) {
				temp = temp->getNext();
			}
			else {
				break;
			}
		}
	}
	temp = NULL;
}

void compare() {
	//Функция для теста по сравнению объектов по заданию в лабораторной работе
	Phone* firstObj = new Phone();
	Phone* secondObj = new Phone();
	bool result = false; //Результат теста

	system("cls");
	cout << "Сравнение двух объектов типа Phone" << endl;
	cout << endl << "Создание первого объекта: " << endl;
	firstObj->input();
	cout << endl << "Создание второго объекта: " << endl;
	secondObj->input();
	wait();
	system("cls");
	cout << endl << "Тест:" << endl << endl
		<< "Параметр price первого объекта: " << firstObj->getPrice() << endl
		<< "Параметр price первого объекта: " << secondObj->getPrice() << endl << endl
		<< "Вызов функции 'isBigger(...)':" << endl;
	result = isBigger(firstObj, secondObj);
	if (result) {
		cout << "Первый объект имеет больший параметр price, чем второй" << endl;
	}
	else {
		cout << "Первый объект имеет меньший параметр price, чем второй" << endl;
	}

	cout << "Вызов функции 'isSmallOrEqual(...)':" << endl;
	result = isSmallerOrEqual(firstObj, secondObj);
	if (result) {
		cout << "Первый объект имеет меньший или равный параметр price, чем второй" << endl;
	}
	else {
		cout << "Первый объект имеет больший параметр price, чем второй" << endl;
	}
	wait();
	delete firstObj;
	delete secondObj;
}