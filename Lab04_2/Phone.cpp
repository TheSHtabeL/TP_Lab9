#include <iostream>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <clocale>
#include <cstdlib>
#include <cctype>
#include <string.h>
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
void Interface::serialize() {

}
void Interface::deserialize(wifstream* file) {

}

Phone::Phone(wchar_t model[], wchar_t firm[]) {
	price = -1;
	this->model = new wchar_t[100];
	wcscpy_s(this->model, (_msize(this->model) / sizeof(wchar_t)), model);
	this->firm = new wchar_t[100];
	wcscpy_s(this->firm, (_msize(this->firm) / sizeof(wchar_t)), firm);
	screenSize[0] = -1;
	screenSize[1] = -1;
}
Phone::Phone(int price, int screenLength, int screenHeight) {
	model = new wchar_t[100];
	wcscpy_s(model, (_msize(this->model) / sizeof(wchar_t)), L"none");
	firm = new wchar_t[100];
	wcscpy_s(firm, (_msize(this->firm) / sizeof(wchar_t)), L"none");
	this->price = price;
	screenSize[0] = screenLength;
	screenSize[1] = screenHeight;
}
Phone::Phone(wchar_t model[], wchar_t firm[], int price, int screenLength, int screenHeight) {
	this->model = new wchar_t[100];
	wcscpy_s(this->model, (_msize(this->model) / sizeof(wchar_t)), model);
	this->firm = new wchar_t[100];
	wcscpy_s(this->firm, (_msize(this->firm) / sizeof(wchar_t)), firm);
	this->price = price;
	screenSize[0] = screenLength;
	screenSize[1] = screenHeight;
}
Phone::Phone(){
	price = -1;
	this->model = new wchar_t[100];
	wcscpy_s(this->model, (_msize(this->model) / sizeof(wchar_t)), L"default");
	screenSize[0] = -1;
	screenSize[1] = -1;
	this->firm = new wchar_t[100];
	wcscpy_s(this->firm, (_msize(this->firm) / sizeof(wchar_t)), L"default");
}
Phone::Phone(Phone* original) {
	this->price = original->price;
	this->model = new wchar_t[100];
	wcscpy_s(this->model, (_msize(this->model) / sizeof(wchar_t)), original->model);
	this->screenSize[0] = original->screenSize[0];
	this->screenSize[1] = original->screenSize[1];
	this->firm = new wchar_t[100];
	wcscpy_s(this->firm, (_msize(this->firm) / sizeof(wchar_t)), original->firm);
}
Phone::~Phone() {
	delete firm;
	delete model;
}
bool Phone::checkFirm(wchar_t firm[]) {
	//����� ��������, ��� �� ������� ������� ��������� ��������������
	return wcscmp(firm, this->firm) == 0 ? true : false;
}
int Phone::getPrice() {
	return price;
}
void Phone::input() {
	//����� ��� ������� ����� �������� ��� ���������� ������
	wchar_t* integerTest = new wchar_t[100];

	cout << "������� �����-������������� ��������: ";
	wcin.getline(firm, (_msize(firm) / sizeof(wchar_t)));
	cout << "������� ������ ��������: ";
	wcin.getline(model, (_msize(model) / sizeof(wchar_t)));
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
	wcout << firm << endl;
	cout << "������ ��������: ";
	wcout << model << endl;
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
void Phone::serialize() {
	//����� �������� �� ������������ �������� ���������
	//� ���� ������������ ��� ������ ��������, � ��� ��� ������������ ���������������
	wofstream file("Saved Structure.txt", ios_base::app);
	file << "#Phone" << endl; //������������� ��� ��������� ���������� ������ �� �����
	file << model << endl;
	file << firm << endl;
	file << price << endl;
	file << screenSize[0] << endl;
	file << screenSize[1] << endl;
	file.close();
}
void Phone::deserialize(wifstream* file) {
	//�����, ���������� �� �������������� �������� ���������
	wchar_t* integerTest = new wchar_t[100];

	file->getline(model, (_msize(model)/sizeof(wchar_t)) );
	file->getline(firm, (_msize(firm) / sizeof(wchar_t)) );
	file->getline(integerTest, (_msize(integerTest) / sizeof(wchar_t)));
	price = _wtoi(integerTest);
	file->getline(integerTest, (_msize(integerTest) / sizeof(wchar_t)));
	screenSize[0] = _wtoi(integerTest);
	file->getline(integerTest, (_msize(integerTest) / sizeof(wchar_t)));
	screenSize[1] = _wtoi(integerTest);
	delete integerTest;
}
wchar_t* Phone::getFirm() {
	return firm;
}
void Phone::setFirm(wchar_t firm[100]) {
	wcscpy_s(this->firm, (_msize(this->firm) / sizeof(wchar_t)), firm);
}

ButtonPhone::ButtonPhone() : Phone() {
	buttonsNum = -1;
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
void ButtonPhone::serialize() {
	wofstream file("Saved Structure.txt", ios_base::app);
	file << "#ButtonPhone" << endl;
	file << model << endl;
	file << Phone::getFirm() << endl;
	file << price << endl;
	file << screenSize[0] << endl;
	file << screenSize[1] << endl;
	file << buttonsNum << endl;
	file.close();
}
void ButtonPhone::deserialize(wifstream* file) {
	//�����, ���������� �� �������������� �������� ���������
	wchar_t* integerTest = new wchar_t[100];
	
	file->getline(model, (_msize(model) / sizeof(wchar_t)));
	file->getline(integerTest, (_msize(integerTest) / sizeof(wchar_t)));
	setFirm(integerTest);
	file->getline(integerTest, (_msize(integerTest) / sizeof(wchar_t)));
	price = _wtoi(integerTest);
	file->getline(integerTest, (_msize(integerTest) / sizeof(wchar_t)));
	screenSize[0] = _wtoi(integerTest);
	file->getline(integerTest, (_msize(integerTest) / sizeof(wchar_t)));
	screenSize[1] = _wtoi(integerTest);
	file->getline(integerTest, (_msize(integerTest) / sizeof(wchar_t)));
	buttonsNum = _wtoi(integerTest);
	
	delete integerTest;
}

SensorPhone::SensorPhone() : Phone() {
	this->OS = new wchar_t[100];
	wcscpy_s(this->OS, (_msize(this->OS)) / sizeof(wchar_t), L"default");
}
SensorPhone::~SensorPhone() {
	delete OS;
}
bool SensorPhone::checkSystem(wchar_t testOS[]) {
	//����� ��������� �� ���� �������� ������������ ������� � ���������� ����� �� ������
	//"����� �� ������� ������ ������������ �������?"
	return wcscmp(OS, testOS) ? true : false;
}
void SensorPhone::input() {
	//����� ��� ������� ����� �������� ��� ���������� ������
	Phone::input();
	cout << "������� �������� ������������ ������� ��������: ";
	wcin.getline(OS, (_msize(OS) / sizeof(wchar_t)));
}
void SensorPhone::output() {
	//����� ������ ������
	Phone::output();
}
void SensorPhone::serialize() {
	wofstream file("Saved Structure.txt", ios_base::app);
	file << "#SensorPhone" << endl;
	file << model << endl;
	file << Phone::getFirm() << endl;
	file << price << endl;
	file << screenSize[0] << endl;
	file << screenSize[1] << endl;
	file << OS << endl;
	file.close();
}
void SensorPhone::deserialize(wifstream* file) {
	//�����, ���������� �� �������������� �������� ���������
	wchar_t* integerTest = new wchar_t[100];

	file->getline(model, (_msize(model) / sizeof(wchar_t)));
	file->getline(integerTest, (_msize(integerTest) / sizeof(wchar_t)));
	setFirm(integerTest);
	file->getline(OS, (_msize(OS) / sizeof(wchar_t)));
	file->getline(integerTest, (_msize(integerTest) / sizeof(wchar_t)));
	price = _wtoi(integerTest);
	file->getline(integerTest, (_msize(integerTest) / sizeof(wchar_t)));
	screenSize[0] = _wtoi(integerTest);
	file->getline(integerTest, (_msize(integerTest) / sizeof(wchar_t)));
	screenSize[1] = _wtoi(integerTest);
	
	delete integerTest;
}

AndroidPhone::AndroidPhone() : SensorPhone(){
	this->version = new wchar_t[100];
	wcscpy_s(this->version, _msize(this->version) / sizeof(wchar_t), L"none");
}
AndroidPhone::AndroidPhone(wchar_t version[] = L"default") : SensorPhone() {
	this->version = new wchar_t[100];
	wcscpy_s(this->version, _msize(this->version) / sizeof(wchar_t), version);
}
AndroidPhone::~AndroidPhone() {
	delete version;
}
void AndroidPhone::input() {
	//����� ��� ������� ����� �������� ��� ���������� ������
	SensorPhone::input();

	cout << "������� ������ Android: ";
	wcin.getline(version, _msize(version) / sizeof(wchar_t));
}
void AndroidPhone::serialize() {
	wofstream file("Saved Structure.txt", ios_base::app);
	file << "#AndroidPhone" << endl;
	file << model << endl;
	file << Phone::getFirm() << endl;
	file << price << endl;
	file << screenSize[0] << endl;
	file << screenSize[1] << endl;
	file << OS << endl;
	file << version << endl;
	file.close();
}
void AndroidPhone::deserialize(wifstream* file) {
	//�����, ���������� �� �������������� �������� ���������
	wchar_t* integerTest = new wchar_t[100];

	file->getline(model, (_msize(model) / sizeof(wchar_t)));
	file->getline(integerTest, (_msize(integerTest) / sizeof(wchar_t)));
	setFirm(integerTest);
	file->getline(OS, (_msize(OS) / sizeof(wchar_t)));
	file->getline(version, (_msize(version) / sizeof(wchar_t)));
	file->getline(integerTest, (_msize(integerTest) / sizeof(wchar_t)));
	price = _wtoi(integerTest);
	file->getline(integerTest, (_msize(integerTest) / sizeof(wchar_t)));
	screenSize[0] = _wtoi(integerTest);
	file->getline(integerTest, (_msize(integerTest) / sizeof(wchar_t)));
	screenSize[1] = _wtoi(integerTest);

	delete integerTest;
}
int AndroidPhone::operator >= (wchar_t ptr[]) {
	//���������� ��������� ��������� �������� ���� ������ �������� ������� ������
	//� ���� ��������� �������� ���������� 'version' �� ���� � ��������
	wchar_t* a = new wchar_t[5];
	wchar_t* b = new wchar_t[5];
	if (wcslen(version) >= 5 && wcslen(ptr) >= 5) {
		for (int i = 0; i < 5; i++) {
			a[i] = version[wcslen(version) - (4 - i)];
			b[i] = ptr[i];
		}
		return (wcscmp(a, b) > 0) ? 0 : 1;
	}
	else {
		//����� ����� �������� ������ � ������, ���� ��� ������ ����� 5 ��� ����� ��������
		return -1;
	}
}
bool AndroidPhone::operator >= (AndroidPhone* b) {
	//���������� ��������� ���������� ��� ������ �� ���� �������� ������ ������ �� �����
	return wcscmp(version, b->version) ? false : true;
}
void AndroidPhone::operator |= (wchar_t* a) {
	//���������� ��������� ���� ��������� �� ���� ��������� � ������
	//� ������� �. � �������� �������� ������ ������������ ����������
	//������ 'AndroidPhone' - 'version'
	wchar_t* str = new wchar_t[100];
	int equalCount = 0;
	int j = 0;
	int i = 0;

	for (; version[i] != '\0'; i++) {
		if (version[i] == a[equalCount]) {
			equalCount++;
		}
		else {
			for (int count = 0; count <= equalCount; count++) {
				str[j] = version[i - (equalCount - count)];
				j++;
			}
			equalCount = 0;
		}
		if (a[equalCount] == '\0') {
			equalCount = 0;
		}
	}
	if (equalCount) {
		//������ �����������, �� ��������� � ������� ���� ���� ��, ��� � � ���������.
		//��� ����� ������� ����� ������ ����� ��������
		for (; equalCount > 0; equalCount--) {
			str[j] = version[i - equalCount];
		}
	}
	for (int equalCount = 0; equalCount < i; equalCount++) {
		version[equalCount] = str[equalCount];
	}
}
void AndroidPhone::operator |= (AndroidPhone* a) {
	//���������� ��������� ���� ��������� �� ���� ��������� � ������
	//� ������� �. � �������� �������� ������ ������������ ����������
	//������ 'AndroidPhone' - 'version'
	//� �������� ������-��������� ������������ ���������� 'version'
	//������� ������� ������ 'AnroidPhone'
	wchar_t* str = new wchar_t[100];
	int equalCount = 0;
	int j = 0;
	int i = 0;

	for (; version[i] != '\0'; i++) {
		if (version[i] == a->version[equalCount]) {
			equalCount++;
		}
		else {
			for (int count = 0; count <= equalCount; count++) {
				str[j] = version[i - (equalCount - count)];
				j++;
			}
			equalCount = 0;
		}
		if (a->version[equalCount] == '\0') {
			equalCount = 0;
		}
	}
	if (equalCount) {
		//������ �����������, �� ��������� � ������� ���� ���� ��, ��� � � ���������.
		//��� ����� ������� ����� ������ ����� ��������
		for (; equalCount > 0; equalCount--) {
			str[j] = version[i - equalCount];
		}
	}
	for (int equalCount = 0; equalCount < i; equalCount++) {
		version[equalCount] = str[equalCount];
	}
}
void AndroidPhone::output() {
	//����� ������ ������
	cout << "������ ������������ �������: ";
	wcout << version << endl;
	SensorPhone::output();
}