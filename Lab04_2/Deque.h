#ifndef DEQUE_H
#define DEQUE_H

#include "Phone.h"

//����� "���������" ��������� ������� � ��������� ������ FIFO
class Structure {
public:
	Structure();
	~Structure();
	//����� "������� ���������" �������� �� ��������� ������� �������
	class StructureElement {
	public:
		StructureElement();
		~StructureElement();
		Interface* element;
		StructureElement* next;
		StructureElement* getNext();
	};
public:
	void serialize();
	void deserialize();
	void push(Interface*);
	void pop();
	StructureElement* getFirst();
private:
	void recursion(StructureElement*);
	StructureElement* head;
};

#endif