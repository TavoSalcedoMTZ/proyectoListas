#include "List.h"

List::List()
{
}

List::List(nodo* root)
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
	nodo* Node = new nodo(newValue, nullptr);
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

		}
	}

	


}


void List::ReadList()
{

	nodo* NodeTemo = root;

	while (NodeTemo != nullptr)
	{
		std::cout << NodeTemo->GetValue() << std::endl;
		NodeTemo = NodeTemo->GetNext();
	}
	std::cout << std::endl;
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
