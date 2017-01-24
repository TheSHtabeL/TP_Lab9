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

//Абстрактный класс "Интерфейс"
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
	//Метод сообщает, был ли выпущен телефон указанным производителем
	return wcscmp(firm, this->firm) == 0 ? true : false;
}
void Phone::input() {
	//Метод для ручного ввода значений для переменных класса
	wchar_t* integerTest = new wchar_t[100];

	cout << "Введите фирму-производителя телефона: ";
	wcin.getline(firm, (_msize(firm) / sizeof(wchar_t)));
	cout << "Введите модель телефона: ";
	wcin.getline(model, (_msize(model) / sizeof(wchar_t)));
	_flushall();
	while (true) {
		cout << "Введите цену телефона: ";
		wcin >> integerTest;
		//Чистим поток ввода
		while (wcin.peek() != '\n') {
			wcin.ignore();
		}
		wcin.ignore();
		if (iswdigit(integerTest[0])) { //Проверяем, начинается ли строка с корректного числа
			price = _wtoi(integerTest); //Переводим число из строки в int
			if (price < 0) {
				cout << "Цена телефона должна быль положительным значением или нулём. Попробуйте ещё раз: " << endl;
			}
			else {
				break;
			}
		}
	}
	while (true) {
		cout << "Введите ширину экрана телефона в сантиметрах: ";
		wcin >> integerTest;
		while (wcin.peek() != '\n') {
			wcin.ignore();
		}
		wcin.ignore();
		if (iswdigit(integerTest[0])) {
			screenSize[0] = _wtoi(integerTest);
			if (screenSize[0] <= 0) {
				cout << "Получено некорректное значение. Попробуйте ещё раз: " << endl;
			}
			else {
				break;
			}
		}
	}
	while (true) {
		cout << "Введите длину экрана телефона в сантиметрах: ";
		wcin >> integerTest;
		while (wcin.peek() != '\n') {
			wcin.ignore();
		}
		wcin.ignore();
		if (iswdigit(integerTest[0])) {
			screenSize[1] = _wtoi(integerTest);
			if (screenSize[1] <= 0) {
				cout << "Было получено некорректное значение. Попробуйте ещё раз: " << endl;
			}
			else {
				break;
			}
		}
	}
	delete integerTest;
}
void Phone::output() {
	cout << "Фирма: ";
	wcout << firm << endl;
	cout << "Модель телефона: ";
	wcout << model << endl;
	cout << "Цена: " << endl;
	cout << price << " в рублях" << endl;
	cout << getDollarPrice() << " в долларах" << endl;
	cout << "Разрешение экрана: " << screenSize[0] << "см x " << screenSize[1] << "см" << endl;
	cout << "Диагональ: " << getDiagonal() << " дюйм." << endl;
}
double Phone::getDiagonal() {
	//Метод возвращает диагональ экрана телефона в дюймах
	if ((screenSize[0] > 0) && (screenSize[1] > 0)) {
		return sqrt((screenSize[0] / 2.54)*(screenSize[0] / 2.54) + (screenSize[1] / 2.54)*(screenSize[1] / 2.54));
	}
	else {
		return -1;
	}
}
int Phone::getDollarPrice() {
	//Метод возвращает цену телефона, конвертированную в доллары
	return (int)price / dollarCourse;
}
void Phone::serialize() {
	//Метод отвечает за сериализацию элемента структуры
	//В файл записываются все данные элемента, а его тип обозначается идентификатором
	wofstream file("Saved Structure.txt", ios_base::app);
	file << "#Phone" << endl; //Идентификатор для упрощения считывания данных из файла
	file << model << endl;
	file << firm << endl;
	file << price << endl;
	file << screenSize[0] << endl;
	file << screenSize[1] << endl;
	file.close();
}
void Phone::deserialize(wifstream* file) {
	//Метод, отвечающий за десериализацию элемента структуры
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
	//Метод возвращает количество кнопок телефона
	return (buttonsNum == NULL) ? -1 : buttonsNum;
}
void ButtonPhone::input() {
	//Метод для ручного ввода значений для переменных класса
	Phone::input();
	wchar_t* integerTest = new wchar_t[100];

	while (true) {
		cout << "Введите количество кнопок у телефона: ";
		wcin >> integerTest;
		//Чистим поток ввода
		while (wcin.peek() != '\n') {
			wcin.ignore();
		}
		wcin.ignore();
		if (iswdigit(integerTest[0])) { //Проверяем, начинается ли строка с корректного числа
			buttonsNum = _wtoi(integerTest); //Переводим число из строки в int
			if (buttonsNum < 0) {
				cout << "Количество кнопок должно быть положительным значением или нулём. Попробуйте ещё раз: " << endl;
			}
			else {
				break;
			}
		}
	}
	delete integerTest;
}
void ButtonPhone::output() {
	//Метод вывода данных
	Phone::output();
	cout << "Количество кнопок у телефона: " << buttonsNum << endl;
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
	//Метод, отвечающий за десериализацию элемента структуры
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
	//Метод принимает на вход название операционной системы и возвращает ответ на вопрос
	//"Имеет ли телефон данную операционную систему?"
	return wcscmp(OS, testOS) ? true : false;
}
void SensorPhone::input() {
	//Метод для ручного ввода значений для переменных класса
	Phone::input();
	cout << "Введите название операционной системы телефона: ";
	wcin.getline(OS, (_msize(OS) / sizeof(wchar_t)));
}
void SensorPhone::output() {
	//Метод вывода данных
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
	//Метод, отвечающий за десериализацию элемента структуры
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
	//Метод для ручного ввода значений для переменных класса
	SensorPhone::input();

	cout << "Введите версию Android: ";
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
	//Метод, отвечающий за десериализацию элемента структуры
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
	//Перегрузка оператора позволяет сравнить пять первых символов входной строки
	//и пять последних символов переменной 'version' по весу в алфавите
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
		//Метод может работать только в случае, если обе строки имеют 5 или более символов
		return -1;
	}
}
bool AndroidPhone::operator >= (AndroidPhone* b) {
	//Перегрузка оператора сравнивает две строки из двух объектов одного класса по длине
	return wcscmp(version, b->version) ? false : true;
}
void AndroidPhone::operator |= (wchar_t* a) {
	//Перегрузка оператора ищет пришедшую на вход подстроку в строке
	//и удаляет её. В качестве исходной строки используется переменная
	//класса 'AndroidPhone' - 'version'
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
		//Строка закончилась, но последние её символы были теми же, что и у подстроки.
		//Без этого условия часть строки будет потеряна
		for (; equalCount > 0; equalCount--) {
			str[j] = version[i - equalCount];
		}
	}
	for (int equalCount = 0; equalCount < i; equalCount++) {
		version[equalCount] = str[equalCount];
	}
}
void AndroidPhone::operator |= (AndroidPhone* a) {
	//Перегрузка оператора ищет пришедшую на вход подстроку в строке
	//и удаляет её. В качестве исходной строки используется переменная
	//класса 'AndroidPhone' - 'version'
	//В качестве строки-параметра используется переменная 'version'
	//другого объекта класса 'AnroidPhone'
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
		//Строка закончилась, но последние её символы были теми же, что и у подстроки.
		//Без этого условия часть строки будет потеряна
		for (; equalCount > 0; equalCount--) {
			str[j] = version[i - equalCount];
		}
	}
	for (int equalCount = 0; equalCount < i; equalCount++) {
		version[equalCount] = str[equalCount];
	}
}
void AndroidPhone::output() {
	//Метод вывода данных
	cout << "Версия операционной системы: ";
	wcout << version << endl;
	SensorPhone::output();
}