#ifndef DEQUE_H
#define DEQUE_H

#include "Phone.h"

//Класс "Структура" реализует очередь с правилами работы FIFO
template <typename TYPE>
class Structure {
public:
	Structure();
	~Structure();
	//Класс "Элемент структуры" отвечает за отдельный элемент очереди
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
	class Iterator {
	public:
		Iterator();
		Iterator(Iterator*);
		Iterator(Iterator const&);
		~Iterator();

		bool operator==(Iterator const&);
		Iterator& operator=(Iterator const&);
		Iterator& operator++();
		//Iterator* operator++();
		void setIterator(StructureElement*);
	private:
		StructureElement* element;
	};
public:
	void push(TYPE*);
	void push(TYPE);
	TYPE* pop();

	Iterator* begin();
	Iterator* end();
	StructureElement* getFirst();
private:
	StructureElement* head;
};

#endif