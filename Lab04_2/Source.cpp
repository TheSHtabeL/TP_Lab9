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
			cout << "������������ ������ �9" << endl << endl;
			if (dequeType) {
				cout << "� ������ ������ ������� ������� ���� Interface" << endl;
			}
			else {
				cout << "� ������ ������ ������� ������� ������������ ����" << endl;
			}
			cout << "�������:" << endl
				<< "0. ������� �������" << endl
				<< "1. ����� ���� ������� �� �����" << endl
				<< "2. �������� ������� � �������" << endl
				<< "3. ������� ������� �� �������" << endl
				<< "4. ������������ ���������" << endl
				<< "5. �������������� ���������" << endl
				<< "6. �����" << endl << endl
				<< "������� �������: ";
			wcin.getline(integerTest, _msize(integerTest) / sizeof(wchar_t));
			if (iswdigit(integerTest[0])) { //���������, ���������� �� ������ � ����������� �����
				command = _wtoi(integerTest); //��������� ����� �� ������ � int
				break;
			}
			else {
				cout << endl << "�������� �������";
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
					cout << "�������� ��� ��������, ������� �� �������� � �������:" << endl
						<< "1. Phone" << endl
						<< "2. ButtonPhone" << endl
						<< "3. SensorPhone" << endl
						<< "4. AndroidPhone" << endl << endl
						<< "������� �������: ";
					wcin.getline(integerTest, _msize(integerTest) / sizeof(wchar_t));

					if (iswdigit(integerTest[0])) { //���������, ���������� �� ������ � ����������� �����
						command = _wtoi(integerTest); //��������� ����� �� ������ � int
						if ((command > 0) && (command < 5)) {
							break;
						}
						else {
							cout << endl << "�������� �������";
							wait();
						}
					}
					else {
						cout << endl << "�������� �������";
						wait();
					}
				}
				switch (command) {
				case 1:
					cout << endl << "������ Phone: " << endl;
					interfaceElement = new Phone();
					interfaceElement->input();
					interfaceStructure->push(interfaceElement);
					interfaceElement = NULL;
					break;
				case 2:
					cout << endl << "������ ButtonPhone: " << endl;
					interfaceElement = new ButtonPhone();
					interfaceElement->input();
					interfaceStructure->push(interfaceElement);
					interfaceElement = NULL;
					break;
				case 3:
					cout << endl << "������ SensorPhone: " << endl;
					interfaceElement = new SensorPhone();
					interfaceElement->input();
					interfaceStructure->push(interfaceElement);
					interfaceElement = NULL;
					break;
				case 4:
					cout << endl << "������ AndroidPhone: " << endl;
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
					cout << "������� �������� ������ �������� ��������� ���� int: ";
					wcin.getline(integerTest, _msize(integerTest) / sizeof(wchar_t));

					if (iswdigit(integerTest[0])) { //���������, ���������� �� ������ � ����������� �����
						value = _wtoi(integerTest); //��������� ����� �� ������ � int
						break;
					}
					else {
						cout << endl << "������������ ��������, ���������� ��� ���." << endl;
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
					cout << endl << "������� ��� ����� �� �������" << endl;
					interfaceElement->output();
					delete interfaceElement;
				}
				else {
					cout << endl << "������� �����, ���������� ������� �������";
				}
				wait();
			}
			else {
				if (intStructure->getFirst()) {
					intElement = intStructure->pop();
					cout << endl << "������� ��� ����� �� �������" << endl;
					cout << intElement;
					delete intElement;
				}
				else {
					cout << endl << "������� �����, ���������� ������� �������";
				}
				wait();
			}
			break;
		case 4:
			cout << endl << "������������ ���������" << endl;
			//structure->serialize();
			cout << endl << "� ������ ������������ ������ ������� ���������" << endl;
			wait();
			break;
		case 5:
			cout << endl << "�������������� ���������" << endl;
			//delete structure; //��������������� ������ ���������
			//structure = new Structure();
			//structure->deserialize();
			cout << endl << "� ������ ������������ ������ ������� ���������" << endl;
			wait();
			break;
		case 6: //Quit
			delete interfaceStructure;
			delete intStructure;
			delete integerTest;
			return 0;
		default:
			cout << "�������� �������. ���������� ��� ���." << endl;
			wait();
			delete integerTest;
		}
	}
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