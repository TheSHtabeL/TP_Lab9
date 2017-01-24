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
	//��������� ������ �������� � �������
	if (head != NULL) {
		//� ������� ��� ���� �������
		StructureElement* temp = new StructureElement();
		temp->element = source;
		temp->next = head;
		head = temp;
		temp = NULL;
		delete temp;
	}
	else {
		//� ������� ��� �������
		head = new StructureElement();
		head->element = source;
		head->next = NULL;
	}
}
void Structure::pop() {
	//����� ����������� �� ������� ������� �� ������� FIFO
	/*StructureElement* temp = new StructureElement();
	temp = this->getFirst();*/
	StructureElement* temp = this->getFirst();
	if (temp == NULL) {
		//������ ������� ����
		//temp = NULL;
		delete temp;
		return;
	}
	else if (temp->getNext() == NULL) {
		//� ������� ������� ���� �������
		//head = NULL;
		delete head;
		head = NULL;
		//delete temp;
	}
	else {
		//�������� �������� ��� ������� n, ��� n>1
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
	//�������� ��������� �� ������� ������ �������
	return head;
}
Structure::StructureElement* Structure::StructureElement::getNext() {
	//��������� � ���������� ��������
	return this->next;
}
void Structure::serialize() {
	//������������ ������������ ���������
	ofstream file("Saved Structure.txt");
	Structure::StructureElement* temp = this->getFirst();
	file.close();
	if (temp == NULL) {
		cout << endl << "������� �����. ��� ��������� ��� ������������";
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
	//������� ������������ ����� � ����. ��� ��� �� ���������� �������,
	//��� ���������� ���������� � � ���� � �������� �������, �����
	//��� ���������� �������� �������� ������ ���������
	if ((temp->element != NULL) && temp->getNext() ) {
		recursion(temp->getNext());
	}
	temp->element->serialize();
}
void Structure::deserialize() {
	//�������������� ��������� �� �����
		wifstream* read = new wifstream("Saved Structure.txt");
		if (!read->is_open()) {
			cout << endl << "������ ��� �������� �����." << endl;
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