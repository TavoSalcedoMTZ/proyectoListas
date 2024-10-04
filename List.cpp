#include "List.h"

List::List() : root(nullptr), type(LISTA_LINEAL_LIGADA) {}

List::List(ListType type, nodo* root) : type(type), root(root) {}


int List::GetValue(int pos) {
    nodo* TempNode = root;
    int contador = 1; 

    if (type == LISTA_LINEAL_LIGADA || type == LISTA_LINEAL_DLIGADA) {
        for (int i = 1; i < pos && TempNode; i++) {
            TempNode = TempNode->GetNext();
        }
        return (TempNode) ? TempNode->GetValue() : 0;
    }

    else if (type == LISTA_CIRCULAR_LIGADA || type == LISTA_CIRCULAR_DLIGADA) {
        if (root) {
            for (int i = 1; i < pos; i++) {
                TempNode = TempNode->GetNext();
                if (TempNode == root) break; 
            }
            return (TempNode != root) ? TempNode->GetValue() : 0;
        }
    }

    return 0; 
}
void List::Push(int newValue) {
    nodo* Node = new nodo(newValue);

    switch (type) {
    case LISTA_LINEAL_LIGADA:
        if (root) {
            nodo* TempNode = root;
            while (TempNode->GetNext() != nullptr) {
                TempNode = TempNode->GetNext();
            }
            TempNode->SetNextNodo(Node); 
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
            TempNode->SetNextNodoCircular(Node);
            Node->SetNextNodoCircular(root);
        }
        else {
            root = Node;
            Node->SetNextNodoCircular(root);
        }
        break;

    case LISTA_LINEAL_DLIGADA:
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
        break;

    case LISTA_CIRCULAR_DLIGADA:
        if (root) {
            nodo* TempNode = root;
            while (TempNode->GetNext() != nullptr && TempNode->GetNext() != root) {
                TempNode = TempNode->GetNext();
            }
            TempNode->SetNextNodoCircular(Node);
            Node->SetPrevNodo(TempNode);
            Node->SetNextNodoCircular(root);
            root->SetPrevNodo(Node);
        }
        else {
            root = Node;
            Node->SetNextNodoCircular(root);
            Node->SetPrevNodo(root);
        }
        break;
    }
}


void List::ReadList() {
    nodo* NodeTemp = root;
    int contador = 1;

    if (type == LISTA_LINEAL_LIGADA || type == LISTA_LINEAL_DLIGADA) {
        while (NodeTemp) {
            std::cout << "Nodo " << contador++ << ": " << NodeTemp->GetValue() << std::endl;
            NodeTemp = NodeTemp->GetNext();
        }
    }
    else if (type == LISTA_CIRCULAR_LIGADA || type == LISTA_CIRCULAR_DLIGADA) {
        if (root) {
            do {
                std::cout << "Nodo " << contador++ << ": " << NodeTemp->GetValue() << std::endl;
                NodeTemp = NodeTemp->GetNext();
            } while (NodeTemp != root); 
        }
    }

    std::cout << std::endl;
}

void List::ClearList() {
    nodo* NodeTemp;

    if (type == LISTA_LINEAL_LIGADA || type == LISTA_LINEAL_DLIGADA) {
        while (root != nullptr) {
            NodeTemp = root;
            root = root->GetNext();
            delete NodeTemp;
        }
    }
    else if (type == LISTA_CIRCULAR_LIGADA || type == LISTA_CIRCULAR_DLIGADA) {
        if (root) {
            nodo* startNode = root;
            do {
                NodeTemp = root;
                root = root->GetNext();
                delete NodeTemp;
            } while (root != startNode); 
            root = nullptr;
        }
    }
}