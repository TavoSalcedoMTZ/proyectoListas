#pragma once
#include "List.h"


class Interfaz
{
public:

	Interfaz();
	~Interfaz();


	void init();
	void MainMenu();

	void SetList(ListType _type);
	ListType GetList();

	void MenuList();


private:
	List* lista;

	void GetValueN();
	void PushVal();
	void ReadListN();
	void ClearListN();


};

