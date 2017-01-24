#ifndef DEQUE_H
#define DEQUE_H

#include "Phone.h"

//Класс "Структура" реализует очередь с правилами работы FIFO
class Structure {
public:
	Structure();
	~Structure();
	//Класс "Элемент структуры" отвечает за отдельный элемент очереди
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