#include "List.h"

List::List()
{
	root = nullptr;
}

List::List(ListType type, nodo* root)
{
}

int List::GetValue(int pos)
{
	nodo* TempNode = root;
	if (root)
	{
		for (int i = 0; i < pos && TempNode; i++)
		{
			TempNode = TempNode->GetNext();
		}

		if (TempNode) {
			return TempNode->GetValue();
		}
	}
	return 0; 
}

void List::Push(int newValue)
{
	nodo* Node = new nodo(newValue, nullptr,nullptr);
	switch (type) {

	case LISTA_LINEAL_LIGADA:
		if (root) {


			root->SetNextNodo(Node);
		}
		else {
			root = Node;
		}
		break;

	case LISTA_CIRCULAR_LIGADA:
		if (root) {

			nodo* TempNode = root;
			while (TempNode->GetNext() != nullptr && TempNode->GetNext() != root) {
				TempNode = TempNode->GetNext();
			}
			TempNode->SetNextNodo(Node);
			Node->SetNextNodo(root);
		}
		else {
			root = Node;
			Node->SetNextNodo(root);
		}
		break;

	case LISTA_LINEAL_DLIGADA: {
		if (root) {
			nodo* TempNode = root;
			while (TempNode->GetNext() != nullptr) {
				TempNode = TempNode->GetNext();
			}
			TempNode->SetNextNodo(Node);
			Node->SetPrevNodo(TempNode);
		}
		else {
			root = Node;
		}
		


	}
	case LISTA_CIRCULAR_DLIGADA: {
		if (root) {
			nodo* TempNode = root;
			while (TempNode->GetNext() != nullptr && TempNode->GetNext() != root) {
				TempNode = TempNode->GetNext();
			}
			TempNode->SetNextNodo(Node);
			Node->SetPrevNodo(TempNode); 
			Node->SetNextNodo(root);
			root->SetPrevNodo(Node);
		}
		else {
			root = Node;
			Node->SetNextNodo(root); 
			Node->SetPrevNodo(root); 
		}

	}
	
	}//LAVE DE CIERRE SWITCH
}//LLAVE DE CIERRE DE PUSH(NO BORRES PENDEJO)



void List::ReadList()
{
	switch (type) {


	case LISTA_LINEAL_LIGADA: {

		nodo* NodeTemo = root;

		while (NodeTemo != nullptr)
		{
			std::cout << NodeTemo->GetValue() << std::endl;
			NodeTemo = NodeTemo->GetNext();
		}
		std::cout << std::endl;
	}
	}
}

void List::ClearList()
{
	nodo* NodeTemp;
	while (root != nullptr)
	{
		NodeTemp = root;
		root = root->GetNext();
		delete NodeTemp;
	}

}
