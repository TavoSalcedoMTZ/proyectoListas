#pragma once
#include "nodo.h"


enum ListType {
	LISTA_LINEAL_LIGADA = 0,
	LISTA_CIRCULAR_LIGADA = 0b01,
	LISTA_LINEAL_DLIGADA = 0b10,
	LISTA_CIRCULAR_DLIGADA
};
class List
{
public:
	List();
	List(nodo* root);

	int GetValue(int pos);
	void Push(int newValue);

	void ReadList();
	void ClearList();







	


private:
	ListType type;
	nodo* root;
	void setRoot(nodo*);
	void setRoot(int _root);
};

