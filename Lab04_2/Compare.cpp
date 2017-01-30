#include "Compare.h"
#include "Phone.h"

template <typename TYPE>
bool isBigger(TYPE* first, TYPE* second) {
	return (*first > *second) ? true : false;
}
template <typename TYPE>
bool isSmallerOrEqual(TYPE* first, TYPE* second) {
	return (*first <= *second) ? true : false;
}

template <>
bool isBigger(Phone* first, Phone* second) {
	return ((first->price) > (second->price)) ? true : false;
}

template <>
bool isSmallerOrEqual(Phone* first, Phone* second) {
	return ((first->price) <= (second->price)) ? true : false;
}