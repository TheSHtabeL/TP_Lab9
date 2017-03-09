#ifndef PHONE_H
#define PHONE_H

#include "iostream"
#include <string.h>

using namespace std;

class Interface {
public:
	Interface();
	virtual void input();
	virtual void output();
};

class Phone : public Interface {
	//Класс "Телефон"
public:
	int price;
	wstring* model;
	//Стандартные конструкторы 
	Phone(wstring, wstring);
	Phone(int, int, int);
	Phone(wstring, wstring, int, int, int);
	//Конструктор со значениями по умолчанию
	Phone();
	//Копирующий конструктор
	Phone(Phone*);
	Phone(Phone const&);
	//Дескриптор
	~Phone();

	Phone& operator=(Phone const&);
	bool checkFirm(wstring);
	void input();
	void output();
	void setFirm(wstring);
	wstring* getFirm();
	int getPrice();
protected:
	int screenSize[2];
	double getDiagonal();
private:
	wstring* firm;
	int getDollarPrice();
};

class ButtonPhone : public Phone {
public:
	ButtonPhone();
	ButtonPhone(ButtonPhone*);
	ButtonPhone(ButtonPhone const&);
	~ButtonPhone();
	int getButtonsNum();

	ButtonPhone& operator=(ButtonPhone const&);
	void input();
	void output();
private:
	//Количество кнопок у кнопочного телефона
	int buttonsNum;
};

class SensorPhone : public Phone {
public:
	SensorPhone();
	~SensorPhone();
	SensorPhone(SensorPhone*);
	SensorPhone(SensorPhone const&);

	SensorPhone& operator=(SensorPhone const&);
	bool checkSystem(wstring);
	void input();
	void output();
protected:
	//Операционная система телефона
	wstring* OS;
};

class AndroidPhone : public SensorPhone {
public:
	//Версия операционной системы телефона
	wstring* version;
	AndroidPhone();
	AndroidPhone(wstring);
	AndroidPhone(AndroidPhone*);
	AndroidPhone(AndroidPhone const&);
	~AndroidPhone();

	AndroidPhone& operator=(AndroidPhone const&);
	void input();
	void output();
};
#endif