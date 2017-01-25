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
void outputDeque(Structure* structure);

int main()
{
	locale::global(std::locale("Russian"));
	setlocale(LC_ALL, "Russian");
	std::wcin.imbue(std::locale("rus_rus.866"));
	Structure* structure = new Structure();
	Interface* element;
	int command;

	while (true) {
		wchar_t* integerTest = new wchar_t[100];
		while (true) {
			system("cls");
			cout << "Лабораторная работа №9" << endl << endl;
			cout << "Очередь:" << endl
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
		case 1:
			outputDeque(structure); //Output case
			wait();
			break;
		case 2: //Push
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
					element = new Phone();
					element->input();
					structure->push(element);
					element = NULL;
					break;
				case 2:
					cout << endl << "Объект ButtonPhone: " << endl;
					element = new ButtonPhone();
					element->input();
					structure->push(element);
					element = NULL;
					break;
				case 3:
					cout << endl << "Объект SensorPhone: " << endl;
					element = new SensorPhone();
					element->input();
					structure->push(element);
					element = NULL;
					break;
				case 4:
					cout << endl << "Объект AndroidPhone: " << endl;
					element = new AndroidPhone();
					element->input();
					structure->push(element);
					element = NULL;
					break;
				}
			break;
		case 3: //Pop
			if (structure->getFirst()) {
				element = structure->pop();
				cout << endl << "Элемент был удалён из очереди" << endl;
				element->output();
				delete element;
			}
			else {
				cout << endl << "Очередь пуста, невозможно удалить элемент";
			}
			wait();
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
			delete structure;
			delete integerTest;
			return 0;
		default:
			cout << "Неверная команда. Попробуйте ещё раз." << endl;
			wait();
		}
		delete integerTest;
	}
}
void wait() {
	cout << endl << "Нажмите любую клавишу для продолжения..." << endl;
	_getch();
}
void outputDeque(Structure* structure) {
	Structure::StructureElement* temp = structure->getFirst();
	if (temp == NULL) {
		cout << endl << "Очередь пуста";
		delete temp;
	}
	else {
		for (int i = 1; temp->getElement() != NULL; i++) {
			cout << endl << "Элемент очереди №" << i << ":" << endl;
			temp->getElement()->output();
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