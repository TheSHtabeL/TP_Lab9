#ifndef PHONE_H
#define PHONE_H

class Interface {
public:
	Interface();
	virtual void input();
	virtual void output();
	virtual void serialize() = NULL;
	virtual void deserialize(std::wifstream*) = NULL;
};

class Phone : public Interface{
	//Класс "Телефон"
public:
	int price;
	wchar_t* model;
	//Стандартные конструкторы 
	Phone(wchar_t[], wchar_t[]);
	Phone(int, int, int);
	Phone(wchar_t[], wchar_t[], int, int, int);
	//Конструктор со значениями по умолчанию
	Phone();
	//Копирующий конструктор
	Phone(Phone*);
	//Дескриптор
	~Phone();

	bool checkFirm(wchar_t[]);
	void input();
	void output();
	void serialize();
	void deserialize(std::wifstream*);
	void setFirm(wchar_t[]);
	wchar_t* getFirm();
protected:
	int screenSize[2];

	double getDiagonal();
private:
	wchar_t* firm;

	int getDollarPrice();
};

class ButtonPhone : public Phone {
public:
	ButtonPhone();
	~ButtonPhone();
	int getButtonsNum();

	void input();
	void output();
	void serialize();
	void deserialize(std::wifstream*);
private:
	//Количество кнопок у кнопочного телефона
	int buttonsNum;
};

class SensorPhone : public Phone {
public:
	SensorPhone();
	~SensorPhone();
	bool checkSystem(wchar_t[]);
	void input();
	void output();
	void serialize();
	void deserialize(std::wifstream*);
protected:
	//Операционная система телефона
	wchar_t* OS;
};

class AndroidPhone : public SensorPhone {
public:
	//Версия операционной системы телефона
	wchar_t* version;
	AndroidPhone();
	AndroidPhone(wchar_t[]);
	~AndroidPhone();
	void input();
	int operator >= (wchar_t[]);
	bool operator >= (AndroidPhone*);
	void operator |= (wchar_t*);
	void operator |= (AndroidPhone*);
	void output();
	void serialize();
	void deserialize(std::wifstream*);
};
#endif