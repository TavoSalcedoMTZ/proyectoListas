	#pragma once
	#include <iostream>
	class nodo
	{
	public:
		nodo(int valor, nodo* nextNodo);
		nodo();
		~nodo();


		int GetValue();
		nodo* GetNext();
		
		void SetValue(int _value);
		void SetNextNodo(nodo * _next);
		void SetPrevNodo(nodo* _prev);
	private:
		int valor;
		nodo* nextNodo;
		nodo* prevnodo;
	};

