#include "List.h"

List::List() : root(nullptr), type(LISTA_LINEAL_LIGADA) {}

List::List(ListType type, nodo* root) : type(type), root(root) {}

int List::GetValue(int pos) {
    nodo* TempNode = root;

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
void List::PushFirstList(int newValue) {
    nodo* Node = new nodo(newValue);

    switch (type) {
    case LISTA_LINEAL_LIGADA:
        if (root) {
            Node->SetNextNodo(root);
        }
        root = Node;
        break;

    case LISTA_CIRCULAR_LIGADA:
        if (root) {
            Node->SetNextNodoCircular(root);
            nodo* TempNode = root;
            while (TempNode->GetNext() != root) {
                TempNode = TempNode->GetNext();
            }
            TempNode->SetNextNodoCircular(Node); 
            Node->SetNextNodoCircular(root); 
        }
        else {
            root = Node;
            Node->SetNextNodo(root); 
        }
        break;

    case LISTA_LINEAL_DLIGADA:
        if (root) {
            Node->SetNextNodo(root);
            root->SetPrevNodo(Node);
        }
        root = Node;
        break;

    case LISTA_CIRCULAR_DLIGADA:
        if (root) {
            Node->SetNextNodoCircular(root);
            nodo* TempNode = root->GetPrev();
            TempNode->SetNextNodoCircular(Node);
            Node->SetPrevNodo(TempNode);
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

void List::SearchOnList() {
    char c = 0;
    nodo* Current = root;
        Current->ImprimirValor();
 
    do {
        std::cout << std::endl << "Para avanzar presiona la letra 'D', para retroceder presiona la letra 'A'." << std::endl << "Para salir presiona 'x'." << std::endl;
        std::cin >> c;

        if (c == 'd' || c == 'D') {
                Current = Current->GetNext();
                Current->ImprimirValor();
            
        }
        else if (c == 'a' || c == 'A') {
                Current = Current->GetPrev();
                Current->ImprimirValor();
            
   
        }

    } while (c != 'x' && c != 'X');
}

void List::FillList()
{

        int cantidad, LimiteInf, LimiteSup;
        std::cout << "Ingresa Cantidad de Valores" << std::endl;
        std::cin >> cantidad;
        
        std::cout << "Ingresa Limite Inferior" << std::endl;
        std::cin >> LimiteInf;

        std::cout << "Ingresa Limite Superior" << std::endl;
        std::cin >> LimiteSup;
        std::cout << std:: endl;

        std::srand(std::time(0));

        for (int i = 0; i < cantidad; ++i) {

            int valores=LimiteInf+std::rand()%(LimiteSup-LimiteInf+1);

            Push(valores);
        }
    
}

void List::BubbleSort()
{
    if (root == nullptr) return;

    bool cambio;
    nodo* current;
    nodo* ultimobuscado = nullptr;

    do {
        cambio = false;
        current = root;

        if (type == LISTA_LINEAL_LIGADA || type == LISTA_LINEAL_DLIGADA) {

            while (current->GetNext() != ultimobuscado) {
                nodo* nextNode = current->GetNext();

                if (current->GetValue() > nextNode->GetValue()) {

                    int temp = current->GetValue();
                    current->SetValue(nextNode->GetValue());
                    nextNode->SetValue(temp);

                    cambio = true;
                }
                current = current->GetNext();
            }
        }
        else if (type == LISTA_CIRCULAR_LIGADA || type == LISTA_CIRCULAR_DLIGADA) {

            do {
                nodo* nextNode = current->GetNext();

                if (current->GetValue() > nextNode->GetValue()) {

                    int temp = current->GetValue();
                    current->SetValue(nextNode->GetValue());
                    nextNode->SetValue(temp);

                    cambio = true;
                }
                current = current->GetNext();
            } while (current != root && current->GetNext() != ultimobuscado);

        }

        ultimobuscado = current;
    } while (cambio);
}

void List::SelectionSort() {
    if (root == nullptr) return;

    nodo* start = root;


    if (type == LISTA_LINEAL_LIGADA || type == LISTA_LINEAL_DLIGADA) {
        while (start && start->GetNext() != nullptr) {
            nodo* menor = start;
            nodo* current = start->GetNext();

            while (current) {
                if (current->GetValue() < menor->GetValue()) {
                    menor = current;
                }
                current = current->GetNext();
            }


            if (menor != start) {
                int temp = start->GetValue();
                start->SetValue(menor->GetValue());
                menor->SetValue(temp);
            }

            start = start->GetNext();
        }
    }
   
    else if (type == LISTA_CIRCULAR_LIGADA || type == LISTA_CIRCULAR_DLIGADA) {
       

        do {
            nodo* menor = start;
            nodo* current = start->GetNext();

       
            do {
                if (current->GetValue() < menor->GetValue()) {
                    menor = current;
                }
                current = current->GetNext();
            } while (current != root);

            if (menor != start) {
                int temp = start->GetValue();
                start->SetValue(menor->GetValue());
                menor->SetValue(temp);
            }

            start = start->GetNext();
        } while (start != root); 
    }
}

void List::MergeSort()
{
    if (root == nullptr) return;
        
    nodo* current = root;
    nodo* NodeTemp = root;
    int contador = 1;

        while (NodeTemp) {
            contador++;
            NodeTemp = NodeTemp->GetNext();
        }

        nodo* Temp = root;
        int index=1;
        while (current!=nullptr) {
            index ++;
            current = current->GetNext();

            if (index == (contador * 0.5)) {

                Temp = current->GetNext();
                Temp->GetNext() = nullptr;
            }
           
           

        }



   


}



