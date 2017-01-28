#ifndef DEQUE_H
#define DEQUE_H

#include "Phone.h"

//����� "���������" ��������� ������� � ��������� ������ FIFO
template <typename TYPE>
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
		TYPE* getElement();
		void setNext(typename StructureElement*);
		void setElement(TYPE*);
	private:
		TYPE* element;
		StructureElement* next;
	};
public:
	//void serialize();
	//void deserialize();
	void push(TYPE*);
	TYPE* pop();
	StructureElement* getFirst();
private:
	//void recursion(StructureElement*);
	StructureElement* head;
};

#endif