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
		StructureElement* getNext();
		Interface* getElement();
		void setNext(StructureElement*);
		void setElement(Interface*);
	private:
		Interface* element;
		StructureElement* next;
	};
public:
	void serialize();
	void deserialize();
	void push(Interface*);
	Interface* pop();
	StructureElement* getFirst();
private:
	void recursion(StructureElement*);
	StructureElement* head;
};

#endif