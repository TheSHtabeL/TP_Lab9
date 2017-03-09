/*----------------------------*/
/*-- ������������ ������ �9 --*/
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
	//�����
	for (int i = 0; i < 3; i++) {
		outputDeque(intStructure);
		_getch();
	}

	//����� ��������:
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
	//�����
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
	//�����
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
	cout << endl << "������� ����� ������� ��� �����������..." << endl;
	_getch();
}

template<typename TYPE>
void outputDeque(Structure<TYPE>* structure) {
	Structure<TYPE>::StructureElement* temp = structure->getFirst();
	if (temp == NULL) {
		cout << endl << "������� �����";
		delete temp;
	}
	else {
		for (int i = 1; temp->getElement() != NULL; i++) {
			cout << endl << "������� ������� �" << i << ":" << endl;
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
	//������� ��� ����� �� ��������� �������� �� ������� � ������������ ������
	Phone* firstObj = new Phone();
	Phone* secondObj = new Phone();
	bool result = false; //��������� �����

	system("cls");
	cout << "��������� ���� �������� ���� Phone" << endl;
	cout << endl << "�������� ������� �������: " << endl;
	firstObj->input();
	cout << endl << "�������� ������� �������: " << endl;
	secondObj->input();
	wait();
	system("cls");
	cout << endl << "����:" << endl << endl
		<< "�������� price ������� �������: " << firstObj->getPrice() << endl
		<< "�������� price ������� �������: " << secondObj->getPrice() << endl << endl
		<< "����� ������� 'isBigger(...)':" << endl;
	result = isBigger(firstObj, secondObj);
	if (result) {
		cout << "������ ������ ����� ������� �������� price, ��� ������" << endl;
	}
	else {
		cout << "������ ������ ����� ������� �������� price, ��� ������" << endl;
	}

	cout << "����� ������� 'isSmallOrEqual(...)':" << endl;
	result = isSmallerOrEqual(firstObj, secondObj);
	if (result) {
		cout << "������ ������ ����� ������� ��� ������ �������� price, ��� ������" << endl;
	}
	else {
		cout << "������ ������ ����� ������� �������� price, ��� ������" << endl;
	}
	wait();
	delete firstObj;
	delete secondObj;
}