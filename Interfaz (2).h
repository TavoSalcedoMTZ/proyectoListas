#pragma once
#include "List.h"
class Interfaz
{
public:

	Interfaz();
	~Interfaz();


	void init();
	void MainMenu();


private:
	List* lista;

	void GetValueN();
	void PushVal();
	void ReadListN();
	void ClearListN();


};

