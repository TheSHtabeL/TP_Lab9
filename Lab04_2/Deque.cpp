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

//Структура данных "Очередь"
Structure::StructureElement::StructureElement() {
	element = NULL;
	next = NULL;
}
Structure::StructureElement::~StructureElement() {
	//this->element = NULL;
	//this->next = NULL;
	delete element;
	delete next;
}
Structure::Structure() {

}
Structure::~Structure() {
	while (head != NULL) {
		if (head->element != NULL) {
			pop();
		}
	}
	delete head;
}
void Structure::push(Interface* source) {
	//Помещение нового элемента в очередь
	if (head != NULL) {
		//В очереди уже есть вершина
		StructureElement* temp = new StructureElement();
		temp->element = source;
		temp->next = head;
		head = temp;
		temp = NULL;
		delete temp;
	}
	else {
		//В очереди нет вершины
		head = new StructureElement();
		head->element = source;
		head->next = NULL;
	}
}
void Structure::pop() {
	//Метод выбрасывает из очереди элемент по правилу FIFO
	/*StructureElement* temp = new StructureElement();
	temp = this->getFirst();*/
	StructureElement* temp = this->getFirst();
	if (temp == NULL) {
		//Первый элемент пуст
		//temp = NULL;
		delete temp;
		return;
	}
	else if (temp->getNext() == NULL) {
		//В очереди остался один элемент
		//head = NULL;
		delete head;
		head = NULL;
		//delete temp;
	}
	else {
		//Удаление элемента под номером n, где n>1
		while (temp->getNext()->getNext() !=NULL) {
			temp = temp->getNext();
		}
		delete temp->getNext();
		temp->next = NULL;
	}
	temp = NULL;
	delete temp;
}
Structure::StructureElement* Structure::getFirst() {
	//Получить указатель на текущее начало очереди
	return head;
}
Structure::StructureElement* Structure::StructureElement::getNext() {
	//Обращение к следующему элементу
	return this->next;
}
void Structure::serialize() {
	//Сериализация существующей структуры
	ofstream file("Saved Structure.txt");
	Structure::StructureElement* temp = this->getFirst();
	file.close();
	if (temp == NULL) {
		cout << endl << "Очередь пуста. Нет элементов для сериализации";
		//delete temp;
	}
	else {
		recursion(temp);
	}
	file.open("Saved Structure.txt", ios_base::app);
	file << "#end";
	file.close();
	temp = NULL;
	//delete temp;
}
void Structure::recursion(StructureElement* temp) {
	//Функция реверсивного ввода в файл. Так как мы используем очередь,
	//нам необходимо записывать её в файл в обратном порядке, чтобы
	//при считывании получить исходную версию структуры
	if ((temp->element != NULL) && temp->getNext() ) {
		recursion(temp->getNext());
	}
	temp->element->serialize();
}
void Structure::deserialize() {
	//Десериализация структуры из файла
		wifstream* read = new wifstream("Saved Structure.txt");
		if (!read->is_open()) {
			cout << endl << "Ошибка при открытии файла." << endl;
			return;
		}
		wchar_t* command = new wchar_t[100];
		while (!read->eof()) {
			read->getline(command, 100);
			if (!wcscmp(command,L"#Phone")) {
				Phone* element = new Phone();
				element->deserialize(read);
				push(element);
				element = NULL;
				//delete element;
			}
			else if (!wcscmp(command, L"#ButtonPhone")) {
				ButtonPhone* element = new ButtonPhone();
				element->deserialize(read);
				push(element);
				element = NULL;
				//delete element;
			}
			else if (!wcscmp(command, L"#AndroidPhone")) {
				AndroidPhone* element = new AndroidPhone();
				element->deserialize(read);
				push(element);
				element = NULL;
				//delete element;
			}
			else if (!wcscmp(command, L"#SensorPhone")) {
				SensorPhone* element = new SensorPhone();
				element->deserialize(read);
				push(element);
				element = NULL;
				//delete element;
			}
			else if (!wcscmp(command,L"#end")) {
				delete command;
				delete read;
				return;
			}
		}
		delete command;
		delete read;
}