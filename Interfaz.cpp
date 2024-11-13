#include "Interfaz.h"

Interfaz::Interfaz() : lista(new List()) {}

Interfaz::~Interfaz() {
    delete lista;
}

void Interfaz::init() {
    MenuList();
}

void Interfaz::MainMenu() {
    int opcion;



    std::cout << "Ingresa una opcion para continuar" << std::endl
        << "1- Realiza un Push" << std::endl
        << "2- Obtener el Valor" << std::endl
        << "3- Leer la lista" << std::endl
        << "4- Limpiar la lista" << std::endl
        << "5- Agregar valor al principio a la lista" << std::endl
        << "6- Avanzar el valor" << std::endl
        << "7- Llena la Lista de manera Aleatoria" << std::endl
        << "8- Ordena La Lista" << std::endl
        << "10- Salir" << std::endl;

    opcion = ManejoError();

    switch (opcion) {
    case 1: PushVal(); break;
    case 2: GetValueN(); break;
    case 3: ReadListN(); break;
    case 4: ClearListN(); break;
    case 5: PushFirstListVal(); break;
    case 6:SearchOnListVal(); break;
    case 7:FillListValue(); break;
    case 8:MenuAlgoritmo(); break;
    case 10: std::cout << "Saliendo" << std::endl; return;

    default: std::cout << "Opcion erronea." << std::endl; break;
    }

    MainMenu();
}

void Interfaz::MenuAlgoritmo()
{
    int opcion;

    std::cout << "Ingresa una opcion para continuar" << std::endl
        << "1- Realiza Ordenamiento por Algoritmo BubbleSort" << std::endl
        << "2- Realiza Ordenamiento por Algoritmo SelectionSort" << std::endl
        << "3- Realiza Ordenamiento por Algoritmo InsertionSort" << std::endl
        << "4- Realiza Ordenamiento por Algoritmo MergeSort" << std::endl
        << "5- Realiza Ordenamiento por Algoritmo QuickSort" << std::endl
        << "10- Salir" << std::endl;
        opcion = ManejoError();

        switch (opcion) {
        case 1: ActiveBubbleSort(); break;
        case 2: ActiveSelectionSort(); break;
        case 3: ActiveInsertionSort(); break;
        case 4: ActiveMergeSort(); break;
        case 5: ActiveQuickSort(); break;
        case 10: std::cout << "Saliendo" << std::endl; MainMenu();
        default: std::cout << "Opcion erronea." << std::endl; break;
        }


}




void Interfaz::SetList(ListType type) {
    lista->type = type;
}

ListType Interfaz::GetList() {
    return lista->type;
}

void Interfaz::MenuList() {
    int tipo_de_Lista;
    std::cout << "1- LISTA LINEAL LIGADA" << std::endl
        << "2- LISTA CIRCULAR LIGADA" << std::endl
        << "3- LISTA LINEAL DOBLEMENTE LIGADA" << std::endl
        << "4- LISTA CIRCULAR DOBLEMENTE LIGADA" << std::endl;
    std::cout << "Ingresa una opcion" << std::endl;

    tipo_de_Lista = ManejoError();

    switch (tipo_de_Lista) {
    case 1: SetList(LISTA_LINEAL_LIGADA); MainMenu(); break;
    case 2: SetList(LISTA_CIRCULAR_LIGADA); MainMenu(); break;
    case 3: SetList(LISTA_LINEAL_DLIGADA); MainMenu(); break;
    case 4: SetList(LISTA_CIRCULAR_DLIGADA); MainMenu(); break; 
    default: std::cout << "Opcion no valida." << std::endl; MenuList(); break;
    }
}

void Interfaz::PushVal() {
    int newValue;
    std::cout << "Ingresa un valor para realizar el push" << std::endl;
    std::cin >> newValue;
    lista->Push(newValue);
}

void Interfaz::GetValueN() {
    int pos;
    std::cout << "Ingresa la posición a obtener" << std::endl; 
    std::cin >> pos;

    int value = lista->GetValue(pos);
    std::cout << "El valor en la posición " << pos << " es: " << value << std::endl;
}

void Interfaz::ReadListN() {
    std::cout << "Leyendo todos los elementos de la lista:" << std::endl;
    lista->ReadList();
}

void Interfaz::ClearListN() {
    lista->ClearList();
    std::cout << "Lista limpiada." << std::endl;
}


void Interfaz::PushFirstListVal()
{
    int newValue;
    std::cout << "Ingresa un valor para realizar el push al final de la lista" << std::endl;
    std::cin >> newValue;
    lista->PushFirstList(newValue);
}

void Interfaz::SearchOnListVal()
{
    lista-> SearchOnList();
}

int Interfaz::ManejoError()
{
    
    int numero;
    std::cin >> numero;
    while (true) {
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error al ingresar" << std::endl;
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return numero;
        }
    }
}

void Interfaz::FillListValue()
{
    lista->FillList();
}

void Interfaz::ActiveBubbleSort()
{
    lista->BubbleSort();
}

void Interfaz::ActiveSelectionSort()
{
    lista->SelectionSort();
}

void Interfaz::ActiveInsertionSort()
{
    lista->InsertionSort();
}

void Interfaz::ActiveMergeSort()
{

    lista->MergeSort();
}

void Interfaz::ActiveQuickSort()
{
    lista->QuickSort();
}
