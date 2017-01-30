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
		void output();
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

template <>
class Structure<Interface> {
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
		void setNext(typename StructureElement*);
		void setElement(Interface*);
		void output();
	private:
		Interface* element;
		StructureElement* next;
	};
public:
	//void serialize();
	//void deserialize();
	void push(Interface*);
	Interface* pop();
	StructureElement* getFirst();
private:
	//void recursion(StructureElement*);
	StructureElement* head;
};

#endif