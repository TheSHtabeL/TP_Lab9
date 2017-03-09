#include <iostream>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <clocale>
#include <cstdlib>
#include <cctype>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "Phone.h"

#define dollarCourse 63;
using namespace std;

//����������� ����� "���������"
Interface::Interface()
{

}
void Interface::input()
{

}
void Interface::output()
{

}

Phone::Phone(wstring model, wstring firm) {
	price = -1;
	this->model = new wstring(model);
	this->firm = new wstring(firm);
	screenSize[0] = -1;
	screenSize[1] = -1;
}
Phone::Phone(int price, int screenLength, int screenHeight) {
	model = new wstring(L"none");
	firm = new wstring(L"none");
	this->price = price;
	screenSize[0] = screenLength;
	screenSize[1] = screenHeight;
}
Phone::Phone(wstring model, wstring firm, int price, int screenLength, int screenHeight) {
	this->model = new wstring(model);
	this->firm = new wstring(firm);
	this->price = price;
	screenSize[0] = screenLength;
	screenSize[1] = screenHeight;
}
Phone::Phone() {
	price = -1;
	this->model = new wstring(L"none");
	screenSize[0] = -1;
	screenSize[1] = -1;
	this->firm = new wstring(L"none");
}
Phone::Phone(Phone* original) {
	this->model = new wstring(original->model->data());
	this->firm = new wstring(original->firm->data());
	this->price = original->price;
	this->screenSize[0] = original->screenSize[0];
	this->screenSize[1] = original->screenSize[1];
}
Phone::Phone(Phone const& original) {
	this->model = new wstring(original.model->data());
	this->firm = new wstring(original.firm->data());
	this->price = original.price;
	this->screenSize[0] = original.screenSize[0];
	this->screenSize[1] = original.screenSize[1];
}

Phone::~Phone() {
	delete firm;
	delete model;
}
bool Phone::checkFirm(wstring firm) {
	//����� ��������, ��� �� ������� ������� ��������� ��������������
	return this->firm->compare(firm) == 0 ? true : false;
}
int Phone::getPrice() {
	return price;
}
Phone& Phone::operator=(Phone const& original) {
	if (this == &original) {
		return *this;
	}
	else {
		delete model;
		delete firm;
		this->model = new wstring(original.model->data());
		this->firm = new wstring(original.firm->data());
		this->price = original.price;
		this->screenSize[0] = original.screenSize[0];
		this->screenSize[1] = original.screenSize[1];
		return *this;
	}
}
void Phone::input() {
	//����� ��� ������� ����� �������� ��� ���������� ������
	wchar_t* integerTest = new wchar_t[100];
	wstring readFromStream;

	cout << "������� �����-������������� ��������: ";
	getline(wcin, readFromStream);
	firm->assign(readFromStream);
	cout << "������� ������ ��������: ";
	getline(wcin, readFromStream);
	model->assign(readFromStream);
	_flushall();
	while (true) {
		cout << "������� ���� ��������: ";
		wcin >> integerTest;
		//������ ����� �����
		while (wcin.peek() != '\n') {
			wcin.ignore();
		}
		wcin.ignore();
		if (iswdigit(integerTest[0])) { //���������, ���������� �� ������ � ����������� �����
			price = _wtoi(integerTest); //��������� ����� �� ������ � int
			if (price < 0) {
				cout << "���� �������� ������ ���� ������������� ��������� ��� ����. ���������� ��� ���: " << endl;
			}
			else {
				break;
			}
		}
	}
	while (true) {
		cout << "������� ������ ������ �������� � �����������: ";
		wcin >> integerTest;
		while (wcin.peek() != '\n') {
			wcin.ignore();
		}
		wcin.ignore();
		if (iswdigit(integerTest[0])) {
			screenSize[0] = _wtoi(integerTest);
			if (screenSize[0] <= 0) {
				cout << "�������� ������������ ��������. ���������� ��� ���: " << endl;
			}
			else {
				break;
			}
		}
	}
	while (true) {
		cout << "������� ����� ������ �������� � �����������: ";
		wcin >> integerTest;
		while (wcin.peek() != '\n') {
			wcin.ignore();
		}
		wcin.ignore();
		if (iswdigit(integerTest[0])) {
			screenSize[1] = _wtoi(integerTest);
			if (screenSize[1] <= 0) {
				cout << "���� �������� ������������ ��������. ���������� ��� ���: " << endl;
			}
			else {
				break;
			}
		}
	}
	delete integerTest;
}
void Phone::output() {
	cout << "�����: ";
	wcout << firm->data() << endl;
	cout << "������ ��������: ";
	wcout << model->data() << endl;
	cout << "����: " << endl;
	cout << price << " � ������" << endl;
	cout << getDollarPrice() << " � ��������" << endl;
	cout << "���������� ������: " << screenSize[0] << "�� x " << screenSize[1] << "��" << endl;
	cout << "���������: " << getDiagonal() << " ����." << endl;
}
double Phone::getDiagonal() {
	//����� ���������� ��������� ������ �������� � ������
	if ((screenSize[0] > 0) && (screenSize[1] > 0)) {
		return sqrt((screenSize[0] / 2.54)*(screenSize[0] / 2.54) + (screenSize[1] / 2.54)*(screenSize[1] / 2.54));
	}
	else {
		return -1;
	}
}
int Phone::getDollarPrice() {
	//����� ���������� ���� ��������, ���������������� � �������
	return (int)price / dollarCourse;
}
wstring* Phone::getFirm() {
	return firm;
}
void Phone::setFirm(wstring firm) {
	this->firm->assign(firm);
}

ButtonPhone::ButtonPhone() : Phone() {
	buttonsNum = -1;
}
ButtonPhone::ButtonPhone(ButtonPhone* original) : Phone(original) {
	this->buttonsNum = original->buttonsNum;
}
ButtonPhone::ButtonPhone(ButtonPhone const& original) : Phone(original) {
	this->buttonsNum = original.buttonsNum;
}
ButtonPhone::~ButtonPhone() {
}
int ButtonPhone::getButtonsNum() {
	//����� ���������� ���������� ������ ��������
	return (buttonsNum == NULL) ? -1 : buttonsNum;
}
void ButtonPhone::input() {
	//����� ��� ������� ����� �������� ��� ���������� ������
	Phone::input();
	wchar_t* integerTest = new wchar_t[100];

	while (true) {
		cout << "������� ���������� ������ � ��������: ";
		wcin >> integerTest;
		//������ ����� �����
		while (wcin.peek() != '\n') {
			wcin.ignore();
		}
		wcin.ignore();
		if (iswdigit(integerTest[0])) { //���������, ���������� �� ������ � ����������� �����
			buttonsNum = _wtoi(integerTest); //��������� ����� �� ������ � int
			if (buttonsNum < 0) {
				cout << "���������� ������ ������ ���� ������������� ��������� ��� ����. ���������� ��� ���: " << endl;
			}
			else {
				break;
			}
		}
	}
	delete integerTest;
}
void ButtonPhone::output() {
	//����� ������ ������
	Phone::output();
	cout << "���������� ������ � ��������: " << buttonsNum << endl;
}
ButtonPhone& ButtonPhone::operator=(ButtonPhone const& original) {
	if (this == &original) {
		return *this;
	}
	else {
		delete model;
		this->model = new wstring(original.model->data());
		this->price = original.price;
		this->screenSize[0] = original.screenSize[0];
		this->screenSize[1] = original.screenSize[1];
		return *this;
	}
}

SensorPhone::SensorPhone() : Phone() {
	OS = new wstring(L"default");
}
SensorPhone::SensorPhone(SensorPhone* original) : Phone(original) {
	this->OS = new wstring(original->OS->data());
}
SensorPhone::SensorPhone(SensorPhone const& original) : Phone(original) {
	this->OS = new wstring(original.OS->data());
}
SensorPhone::~SensorPhone() {
	delete OS;
}

bool SensorPhone::checkSystem(wstring testOS) {
	//����� ��������� �� ���� �������� ������������ ������� � ���������� ����� �� ������
	//"����� �� ������� ������ ������������ �������?"
	return OS->compare(testOS) == 0 ? true : false;
}
void SensorPhone::input() {
	//����� ��� ������� ����� �������� ��� ���������� ������
	wstring readFromStream;

	Phone::input();
	cout << "������� �������� ������������ ������� ��������: ";
	getline(wcin, readFromStream);
	OS->assign(readFromStream);
}
void SensorPhone::output() {
	//����� ������ ������
	Phone::output();
	cout << "������������ �������: ";
	wcout << OS->data() << endl;
}

SensorPhone& SensorPhone::operator=(SensorPhone const& original) {
	if (this == &original) {
		return *this;
	}
	else {
		delete model;
		delete OS;
		this->model = new wstring(original.model->data());
		this->price = original.price;
		this->screenSize[0] = original.screenSize[0];
		this->screenSize[1] = original.screenSize[1];
		this->OS = new wstring(original.OS->data());
		return *this;
	}
}
AndroidPhone::AndroidPhone() : SensorPhone() {
	version = new wstring(L"none");
}
AndroidPhone::AndroidPhone(AndroidPhone* original) : SensorPhone(original) {
	this->version = new wstring(original->version->data());
}
AndroidPhone::AndroidPhone(AndroidPhone const& original) : SensorPhone(original) {
	this->version = new wstring(original.version->data());
}
AndroidPhone::AndroidPhone(wstring version = L"default") : SensorPhone() {
	this->version = new wstring(version);

}
AndroidPhone::~AndroidPhone() {
	delete version;
}
void AndroidPhone::input() {
	//����� ��� ������� ����� �������� ��� ���������� ������
	SensorPhone::input();
	wstring readFromStream;

	cout << "������� ������ Android: ";
	getline(wcin, readFromStream);
	version->assign(readFromStream);
}
void AndroidPhone::output() {
	//����� ������ ������
	cout << "������ ������������ �������: ";
	wcout << version->data() << endl;
	SensorPhone::output();
}
AndroidPhone& AndroidPhone::operator=(AndroidPhone const& original) {
	if (this == &original) {
		return *this;
	}
	else {
		delete model;
		delete OS;
		delete version;
		this->model = new wstring(original.model->data());
		this->price = original.price;
		this->screenSize[0] = original.screenSize[0];
		this->screenSize[1] = original.screenSize[1];
		this->OS = new wstring(original.OS->data());
		this->version = new wstring(original.version->data());
		return *this;
	}
}