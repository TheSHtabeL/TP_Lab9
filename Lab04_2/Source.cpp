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

using namespace std;

void wait();
template <typename TYPE>
void outputDeque(Structure<TYPE>* structure);

int main()
{
	locale::global(std::locale("Russian"));
	setlocale(LC_ALL, "Russian");
	std::wcin.imbue(std::locale("rus_rus.866"));
	Structure<typename Interface>* interfaceStructure = new Structure<typename Interface>();
	Structure<int>* intStructure = new Structure<int>();
	Interface* interfaceElement;
	int* intElement;
	bool dequeType = true; //true: Object; false: standard
	int command;
	int value;

	while (true) {
		wchar_t* integerTest = new wchar_t[100];
		while (true) {
			system("cls");
			cout << "Лабораторная работа №9" << endl << endl;
			if (dequeType) {
				cout << "В данный момент выбрана очередь типа Interface" << endl;
			}
			else {
				cout << "В данный момент выбрана очередь стандартного типа" << endl;
			}
			cout << "Команды:" << endl
				<< "0. Сменить очередь" << endl
				<< "1. Вывод всей очереди на экран" << endl
				<< "2. Добавить элемент в очередь" << endl
				<< "3. Удалить элемент из очереди" << endl
				<< "4. Сериализация структуры" << endl
				<< "5. Десериализация структуры" << endl
				<< "6. Выйти" << endl << endl
				<< "Введите команду: ";
			wcin.getline(integerTest, _msize(integerTest) / sizeof(wchar_t));
			if (iswdigit(integerTest[0])) { //Проверяем, начинается ли строка с корректного числа
				command = _wtoi(integerTest); //Переводим число из строки в int
				break;
			}
			else {
				cout << endl << "Неверная команда";
				wait();
			}
		}
		delete integerTest;
		integerTest = new wchar_t[100];
		switch (command) {
		case 0:
			dequeType = !dequeType;
			break;
		case 1:
			if (dequeType) {
				outputDeque(interfaceStructure); //Output case
			}
			else {
				outputDeque(intStructure);
			}
			wait();
			break;
		case 2: //Push
			if (dequeType) {
				while (true) {
					system("cls");
					cout << "Выберите тип элемента, который вы добавите в очередь:" << endl
						<< "1. Phone" << endl
						<< "2. ButtonPhone" << endl
						<< "3. SensorPhone" << endl
						<< "4. AndroidPhone" << endl << endl
						<< "Введите команду: ";
					wcin.getline(integerTest, _msize(integerTest) / sizeof(wchar_t));

					if (iswdigit(integerTest[0])) { //Проверяем, начинается ли строка с корректного числа
						command = _wtoi(integerTest); //Переводим число из строки в int
						if ((command > 0) && (command < 5)) {
							break;
						}
						else {
							cout << endl << "Неверная команда";
							wait();
						}
					}
					else {
						cout << endl << "Неверная команда";
						wait();
					}
				}
				switch (command) {
				case 1:
					cout << endl << "Объект Phone: " << endl;
					interfaceElement = new Phone();
					interfaceElement->input();
					interfaceStructure->push(interfaceElement);
					interfaceElement = NULL;
					break;
				case 2:
					cout << endl << "Объект ButtonPhone: " << endl;
					interfaceElement = new ButtonPhone();
					interfaceElement->input();
					interfaceStructure->push(interfaceElement);
					interfaceElement = NULL;
					break;
				case 3:
					cout << endl << "Объект SensorPhone: " << endl;
					interfaceElement = new SensorPhone();
					interfaceElement->input();
					interfaceStructure->push(interfaceElement);
					interfaceElement = NULL;
					break;
				case 4:
					cout << endl << "Объект AndroidPhone: " << endl;
					interfaceElement = new AndroidPhone();
					interfaceElement->input();
					interfaceStructure->push(interfaceElement);
					interfaceElement = NULL;
					break;
				}
			}
			else {
				while (true) {
					system("cls");
					cout << "Введите значение нового элемента структуры типа int: ";
					wcin.getline(integerTest, _msize(integerTest) / sizeof(wchar_t));

					if (iswdigit(integerTest[0])) { //Проверяем, начинается ли строка с корректного числа
						value = _wtoi(integerTest); //Переводим число из строки в int
						break;
					}
					else {
						cout << endl << "Некорректное значение, попробуйте ещё раз." << endl;
						wait();
					}
				}
				intElement = new int(value);
				intStructure->push(intElement);
				intElement = NULL;
			}
			break;
		case 3: //Pop
			if (dequeType) {
				if (interfaceStructure->getFirst()) {
					interfaceElement = interfaceStructure->pop();
					cout << endl << "Элемент был удалён из очереди" << endl;
					interfaceElement->output();
					delete interfaceElement;
				}
				else {
					cout << endl << "Очередь пуста, невозможно удалить элемент";
				}
				wait();
			}
			else {
				if (intStructure->getFirst()) {
					intElement = intStructure->pop();
					cout << endl << "Элемент был удалён из очереди" << endl;
					cout << intElement;
					delete intElement;
				}
				else {
					cout << endl << "Очередь пуста, невозможно удалить элемент";
				}
				wait();
			}
			break;
		case 4:
			cout << endl << "Сериализация структуры" << endl;
			//structure->serialize();
			cout << endl << "В данной лабораторной работе функция отключена" << endl;
			wait();
			break;
		case 5:
			cout << endl << "Десериализация структуры" << endl;
			//delete structure; //Перезаписывание старой структуры
			//structure = new Structure();
			//structure->deserialize();
			cout << endl << "В данной лабораторной работе функция отключена" << endl;
			wait();
			break;
		case 6: //Quit
			delete interfaceStructure;
			delete intStructure;
			delete integerTest;
			return 0;
		default:
			cout << "Неверная команда. Попробуйте ещё раз." << endl;
			wait();
			delete integerTest;
		}
	}
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
			//temp->getElement()->output();
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