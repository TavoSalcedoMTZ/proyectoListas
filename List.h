#pragma once
#include "nodo.h"
#include <cstdlib>
#include <ctime>
#include <chrono>
enum ListType {
    LISTA_LINEAL_LIGADA = 0,
    LISTA_CIRCULAR_LIGADA = 0b01,
    LISTA_LINEAL_DLIGADA = 0b10,
    LISTA_CIRCULAR_DLIGADA
};

class List {
public:
    List();
    List(ListType type, nodo* root);

    int GetValue(int pos);
    void Push(int newValue);
    void ReadList();
    void ClearList();
    void PushFirstList(int newValue);
    ListType type;
    void SearchOnList();
    void FillList();
    void BubbleSort();
    void SelectionSort();
    void InsertionSort();
    void MergeSort();

    nodo* mergeSort(nodo* principal);

    nodo* findMiddle(nodo* principal);

    nodo* merge(nodo* izquierda, nodo* derecha);

    void QuickSort();

    nodo* quickSort(nodo* inicio, nodo* fin);

    nodo* particionar(nodo* inicio, nodo* fin);

    nodo* obtenerUltimoNodo(nodo* nodo);

private:
    nodo* root;
    void setRoot(nodo*);
    void setRoot(int _root);
};
