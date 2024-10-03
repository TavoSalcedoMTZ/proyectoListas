#include "nodo.h"

nodo::nodo(int valor, nodo* nextNodo, nodo* prevnodo)
    : valor(valor), nextNodo(nextNodo), prevnodo(prevnodo) {}

nodo::nodo()
    : valor(0), nextNodo(nullptr), prevnodo(nullptr) {}

nodo::~nodo() {
    std::cout << "Clase destruida" << std::endl;
}

int nodo::GetValue() {
    return valor;
}

nodo* nodo::GetNext() {
    return nextNodo;
}

nodo* nodo::GetPrev() {
    return prevnodo; 
}

void nodo::SetValue(int _value) {
    valor = _value;
}

void nodo::SetNextNodo(nodo* _next) {
    if (nextNodo != nullptr) { 
        nextNodo->SetNextNodo(_next);
    }
    else {
        this->nextNodo = _next; 
    }
}

void nodo::SetNextNodoCircular(nodo* _next)
{
    this->nextNodo = _next;

}



void nodo::SetPrevNodo(nodo* _prev) {
    prevnodo = _prev; 
}
