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
	//����� "�������"
public:
	int price;
	wstring* model;
	//����������� ������������ 
	Phone(wstring, wstring);
	Phone(int, int, int);
	Phone(wstring, wstring, int, int, int);
	//����������� �� ���������� �� ���������
	Phone();
	//���������� �����������
	Phone(Phone*);
	Phone(Phone const&);
	//����������
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
	//���������� ������ � ���������� ��������
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
	//������������ ������� ��������
	wstring* OS;
};

class AndroidPhone : public SensorPhone {
public:
	//������ ������������ ������� ��������
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