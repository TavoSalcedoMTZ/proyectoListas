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

void List::FillList() {
    int cantidad, LimiteInf, LimiteSup;
    std::cout << "Ingresa Cantidad de Valores" << std::endl;
    std::cin >> cantidad;

    std::cout << "Ingresa Limite Inferior" << std::endl;
    std::cin >> LimiteInf;

    std::cout << "Ingresa Limite Superior" << std::endl;
    std::cin >> LimiteSup;
    std::cout << std::endl;

    std::srand(std::time(0));

    for (int i = 0; i < cantidad; ++i) {
        int valores = LimiteInf + std::rand() % (LimiteSup - LimiteInf + 1);
        Push(valores);
    }
}

void List::BubbleSort() {
    if (root == nullptr) return;


    auto inicio = std::chrono::high_resolution_clock::now();

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
    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = fin - inicio;
    std::cout << std::endl << std::endl << duracion.count() << std::endl;
}


void List::SelectionSort() {
    if (root == nullptr) return;
    auto inicio = std::chrono::high_resolution_clock::now();
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


    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = fin - inicio;
    std::cout << std::endl << std::endl << duracion.count() << std::endl;
}

void List::InsertionSort() {
    if (root == nullptr || root->GetNext() == nullptr) return;
    auto inicio = std::chrono::high_resolution_clock::now();

    nodo* sorted = nullptr;
    nodo* current = root;

    while (current != nullptr) {
        nodo* next = current->GetNext();
        current->SetNextNodo(nullptr);

        if (sorted == nullptr || current->GetValue() < sorted->GetValue()) {
            current->SetNextNodo(sorted);
            sorted = current;
        }
        else {
            nodo* temp = sorted;
            while (temp->GetNext() != nullptr && temp->GetNext()->GetValue() < current->GetValue()) {
                temp = temp->GetNext();
            }
            current->SetNextNodo(temp->GetNext());
            temp->SetNextNodo(current);
        }

        current = next;
    }

    root = sorted;

    if (type == LISTA_CIRCULAR_LIGADA || type == LISTA_CIRCULAR_DLIGADA) {
        nodo* last = sorted;
        while (last->GetNext() != nullptr) {
            last = last->GetNext();
        }
        last->SetNextNodo(sorted);
        if (type == LISTA_CIRCULAR_DLIGADA) {
            sorted->SetPrevNodo(last);
            last->SetNextNodo(sorted);
        }
    }

    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = fin - inicio;
    std::cout << std::endl << std::endl << duracion.count() << std::endl;
}

void List::MergeSort() {
    if (root == nullptr) return;
    auto inicio = std::chrono::high_resolution_clock::now();

    if (type == LISTA_CIRCULAR_LIGADA || type == LISTA_CIRCULAR_DLIGADA) {
        nodo* lastNode = root;

        while (lastNode->GetNext() != root) {
            lastNode = lastNode->GetNext();
        }


        if (type == LISTA_CIRCULAR_DLIGADA) {
            lastNode->SetNextNodoNull();
            root->SetPrevNodo(nullptr);
        }
        else {
            lastNode->SetNextNodoNull();
        }


        if (type == LISTA_CIRCULAR_LIGADA) {
            type = LISTA_LINEAL_LIGADA;
        }
        else if (type == LISTA_CIRCULAR_DLIGADA) {
            type = LISTA_LINEAL_DLIGADA;
        }
    }


    root = mergeSort(root);


    if (type == LISTA_CIRCULAR_LIGADA || type == LISTA_CIRCULAR_DLIGADA) {
        nodo* lastNode = root;
        while (lastNode->GetNext() != nullptr) {
            lastNode = lastNode->GetNext();
        }


        if (type == LISTA_CIRCULAR_LIGADA) {
            lastNode->SetNextNodoCircular(root);
        }
        else if (type == LISTA_CIRCULAR_DLIGADA) {
            lastNode->SetNextNodoCircular(root);
            root->SetPrevNodo(lastNode);
        }
    }


    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = fin - inicio;
    std::cout << std::endl << std::endl << duracion.count() << std::endl;
}

nodo* List::mergeSort(nodo* principal) {
    if (principal == nullptr || principal->GetNext() == nullptr) {
        return principal;
    }

    nodo* mid = findMiddle(principal);
    nodo* nextOfMid = mid->GetNext();

    if (type == LISTA_CIRCULAR_LIGADA || type == LISTA_CIRCULAR_DLIGADA) {
        mid->SetNextNodoNull();
    }
    else {
        mid->SetNextNodoNull();
    }

    if (type == LISTA_CIRCULAR_DLIGADA) {
        nodo* last = principal;

        do {
            last = last->GetNext();

        } while (last->GetNext() == principal);
        last->SetNextNodoNull();

        nextOfMid->SetPrevNodo(nullptr);
    }

    nodo* izquierda = mergeSort(principal);
    nodo* derecha = mergeSort(nextOfMid);

    return merge(izquierda, derecha);
}

nodo* List::findMiddle(nodo* principal) {
    if (!principal) return nullptr;

    nodo* primer = principal;
    nodo* segundo = principal->GetNext();

    while (segundo != nullptr && segundo->GetNext() != nullptr && segundo != primer && segundo->GetNext() != primer) {
        primer = primer->GetNext();
        segundo = segundo->GetNext()->GetNext();
    }



    return primer;
}

nodo* List::merge(nodo* izquierda, nodo* derecha) {
    if (!izquierda) return derecha;
    if (!derecha) return izquierda;

    nodo* result = nullptr;

    if (izquierda->GetValue() <= derecha->GetValue()) {
        result = izquierda;
        izquierda = izquierda->GetNext();
    }
    else {
        result = derecha;
        derecha = derecha->GetNext();
    }

    nodo* current = result;

    while (izquierda && derecha) {
        if (izquierda->GetValue() <= derecha->GetValue()) {
            current->SetNextNodoCircular(izquierda);
            if (type == LISTA_LINEAL_DLIGADA || type == LISTA_CIRCULAR_DLIGADA) {
                izquierda->SetPrevNodo(current);
            }
            izquierda = izquierda->GetNext();
        }
        else {
            current->SetNextNodoCircular(derecha);
            if (type == LISTA_LINEAL_DLIGADA || type == LISTA_CIRCULAR_DLIGADA) {
                derecha->SetPrevNodo(current);
            }
            derecha = derecha->GetNext();
        }
        current = current->GetNext();
    }

    while (izquierda) {
        current->SetNextNodoCircular(izquierda);
        if (type == LISTA_LINEAL_DLIGADA || type == LISTA_CIRCULAR_DLIGADA) {
            izquierda->SetPrevNodo(current);
        }
        izquierda = izquierda->GetNext();
        current = current->GetNext();
    }

    while (derecha) {
        current->SetNextNodoCircular(derecha);
        if (type == LISTA_LINEAL_DLIGADA || type == LISTA_CIRCULAR_DLIGADA) {
            derecha->SetPrevNodo(current);
        }
        derecha = derecha->GetNext();
        current = current->GetNext();
    }

    if (type == LISTA_CIRCULAR_DLIGADA) {
        nodo* lastNode = current;
        while (lastNode->GetNext() != nullptr && lastNode->GetNext() != result) {
            lastNode = lastNode->GetNext();
        }
        lastNode->SetNextNodoCircular(result);
        result->SetPrevNodo(lastNode);
    }

    if (type == LISTA_CIRCULAR_LIGADA) {
        nodo* lastNode = current;
        while (lastNode->GetNext() != nullptr && lastNode->GetNext() != result) {
            lastNode = lastNode->GetNext();
        }
        lastNode->SetNextNodoCircular(result);
    }

    return result;
}



void List::QuickSort() {

    //Si la lista esta vacia no hace nada
    if (root == nullptr) return;
    auto inicio = std::chrono::high_resolution_clock::now();

   
    //Si la lista es circular se desconecta la lista, para que no explote this shit, si la lista es doblemente ligada se desconecta el puntero anterior
    if (type == LISTA_CIRCULAR_LIGADA || type == LISTA_CIRCULAR_DLIGADA) {
        nodo* ultimoNodo = root;
        while (ultimoNodo->GetNext() != root) {
            ultimoNodo = ultimoNodo->GetNext();
        }
        if (type == LISTA_CIRCULAR_DLIGADA) {
            ultimoNodo->SetNextNodoNull();
            root->SetPrevNodo(nullptr);
        }
        else {
            ultimoNodo->SetNextNodoNull();
        }
    }

    //Llamamos a la funcion auxiliar QuickSort, que funciona de manera recursiva para ordenar los nodos de la lista  le estamos dando el principio y el final de la lista
    root = quickSort(root, nullptr); 


    //Reconectamos la lista si era circular, despues de que ya se ordenaron todos los nodos, se recorre la lista para encontrar el ultimo nodo y se enlaza con el primero para volverla circular denuevo
    if (type == LISTA_CIRCULAR_LIGADA || type == LISTA_CIRCULAR_DLIGADA) {
        nodo* ultimoNodo = root;
        while (ultimoNodo->GetNext() != nullptr) {
            ultimoNodo = ultimoNodo->GetNext();
        }
        if (type == LISTA_CIRCULAR_LIGADA) {
            ultimoNodo->SetNextNodoCircular(root);
        }
        else if (type == LISTA_CIRCULAR_DLIGADA) {
            ultimoNodo->SetNextNodoCircular(root);
            root->SetPrevNodo(ultimoNodo);
        }
    }


    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = fin - inicio;
    std::cout << std::endl << std::endl << duracion.count() << std::endl;
}

nodo* List::quickSort(nodo* inicio, nodo* fin) {
    //Si el nodo de inicio es igual al nodo final o el primer nodo es nulo devuelve el nodo inicial
    if (inicio == fin || inicio == nullptr) return inicio;


    //Particionamos la lista y asignamos a la funcion un pivotm que reorganiza los nodos de la lista para que los valores menores al pivote esten antes del el y los mayores despues
    nodo* pivote = particionar(inicio, fin);



    //Hacemos recursion sobre las dos mitades, se hace la llamda para ordenar la parte de la lista antes del pivote, primero se recorrer hasta el notodo anterior al pivote se corta la lista y se llama nuevamente al quicksort, para una sublista
    if (pivote != inicio) {
        nodo* temp = inicio;
        while (temp->GetNext() != pivote) {
            temp = temp->GetNext();
        }
        temp->SetNextNodoNull();
        inicio = quickSort(inicio, temp);
        temp = obtenerUltimoNodo(inicio);
        temp->SetNextNodoCircular(pivote);
    }


    //finalmente se llama recurisvamente la parte posterior al pivote
    pivote->SetNextNodoCircular(quickSort(pivote->GetNext(), fin));
    return inicio;
}

nodo* List::particionar(nodo* inicio, nodo* fin) {

    //este metodo toma el nodo de inicio, y un nodo de fin, ademas que los organiza en funcion al pivote
    int valorPivote = inicio->GetValue();
    nodo* menor = inicio;
    nodo* current = inicio->GetNext();



    //Hacemos un reordamiento de nodos a travez de un un ciclo, que recorre desde inicio hasta el fin comparando cada valor con el pivote, si el valor es menor que el pivote se intecambia con el valor menor
    while (current != fin) {
        if (current->GetValue() < valorPivote) {
            menor = (menor == nullptr) ? inicio : menor->GetNext();

            int temp = menor->GetValue();
            menor->SetValue(current->GetValue());
            current->SetValue(temp);
        }
        current = current->GetNext();
    }

    //Al final se intercambia el valor del nodo inicio con el valor del nodo que esta apuntado como menor y el  y el menor termina apuntando igual que el nodo temporal que creamos con la ubicacion de inicio, asi cambiando valores
    int temp = inicio->GetValue();
    inicio->SetValue(menor->GetValue());
    menor->SetValue(temp);
    return menor;
    //el nodo menor lo retornamos como el nuevo pivote porque encontramos que esta en la posicion correcta
}

nodo* List::obtenerUltimoNodo(nodo* nodo) {
    //con este recorremos toda la lista hata que lleguemos al ultimo noto que tendria el valor nullptr
    while (nodo && nodo->GetNext() != nullptr) {
        nodo = nodo->GetNext();
    }
    return nodo;
}
