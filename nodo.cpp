#include "nodo.h"

int nodo::GetValue()
{

    return valor;
}

nodo* nodo::GetNext()
{
    return nextNodo;
}

void nodo::SetValue(int _value)
{
    valor = _value;
}

void nodo::SetPrevNodo(nodo* _prev)
{
    this->prevnodo = _prev;
}

void nodo::SetNextNodo(nodo* _next)
{
    if (nextNodo != NULL) {

        nextNodo->SetNextNodo(_next);
    }
    else
    {
        this->nextNodo = _next;
    }
}
nodo::~nodo()
{
    std::cout << "Clase destruida" << std::endl;
}




nodo::nodo(int valor, nodo* nextNodo, nodo* prevnodo)
{
}

nodo::nodo()
{
    valor = 0;
    nextNodo = nullptr;
    prevnodo = nullptr;
}
