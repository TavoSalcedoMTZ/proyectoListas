#pragma once
#include <iostream>

class nodo
{
public:
    nodo(int valor, nodo* nextNodo = nullptr, nodo* prevnodo = nullptr);
    nodo();
    ~nodo();

    int GetValue();
    nodo* GetNext();
    nodo* GetPrev(); 

    void SetValue(int _value);
    void SetNextNodo(nodo* _next);
    void SetNextNodoCircular(nodo* _next);
    void SetPrevNodo(nodo* _prev);
    void ImprimirValor();
    void SetNextNodoNull();
private:
    int valor;
    nodo* nextNodo;
    nodo* prevnodo;
};
