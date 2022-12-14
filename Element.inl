#pragma once
#include "Element.h"

template<class T>
T& Element<T>::getVal() {
	return val;
}

template<class T>
Element<T>* Element<T>::getAdr() {
	return adr;
}

template<class T>
void Element<T>::setVal(T val) {
	this->val = val;
}
template<class T>
void Element<T>::setAdr(Element<T>* adr) {
	this->adr = adr;
}