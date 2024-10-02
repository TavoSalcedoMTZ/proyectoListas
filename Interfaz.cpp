#include "Interfaz.h"

Interfaz::Interfaz() : lista(new List())
{
}

Interfaz::~Interfaz()
{
    delete lista;
}

void Interfaz::init()
{
    MenuList();
}

void Interfaz::MainMenu()
{
    int opcion;

    std::cout << "Ingresa una opcion para continuar" << std::endl
        << "1- Realiza un Push" << std::endl
        << "2- Obtener el Valor" << std::endl
        << "3- Leer la lista" << std::endl
        << "4- Limpiar la lista" << std::endl
        << "5- Salir" << std::endl;
    std::cin >> opcion;

    switch (opcion)
    {
    case 1:
        PushVal();
        break;
    case 2:
        GetValueN();
        break;
    case 3:
        ReadListN();
        break;
    case 4:
        ClearListN();
        break;
    case 5:
        std::cout << "Saliendo" << std::endl;
        return;
    default:
        std::cout << "Opción erronea." << std::endl;
        break;
    }

 
    MainMenu();
}

void Interfaz::SetList(ListType type)
{
}

ListType Interfaz::GetList()
{
    return ListType();
}   

void Interfaz::MenuList()
{
    int tipo_de_Lista;
    std::cout << "1- LISTA LINEAL LIGADA" << std::endl << "2- LISTA CIRCULAR LIGADA" << std::endl << "3- LISTA LINEAL DOBLEMENTE LIGADA" << std::endl << "4- LISTA CIRCULAR DOBLEMENTE LIGADA" << std::endl;
    std::cout << "Ingresa una opcion" << std::endl;
    std::cin >> tipo_de_Lista;


    switch (tipo_de_Lista) {
    case 1:
    {
        SetList(LISTA_LINEAL_LIGADA);
        MainMenu();
        break;
    }

    case 2:
    {
        SetList(LISTA_CIRCULAR_LIGADA);
        MainMenu();
        break;
    }
    case 3:
    {
        SetList(LISTA_LINEAL_DLIGADA);
        MainMenu();
        break;
    }
    case 4:
    {
        SetList(LISTA_CIRCULAR_DLIGADA);
        MainMenu();
        break;
    }
    }
}

void Interfaz::PushVal()
{
    int newValue;
    std::cout << "Ingresa un valor para realizar el push" << std::endl;
    std::cin >> newValue;

    lista->Push(newValue);
}

void Interfaz::GetValueN()
{
    int valor;
    std::cout << "Ingresa el valor a obtener" << std::endl;
    std::cin >> valor;

    int value = lista->GetValue(valor);
    std::cout << "El valor que buscaste" << valor << " es: " << value << std::endl;
}

void Interfaz::ReadListN()
{
    std::cout << "Leyendo todos los elementos de la lista:" << std::endl;
    lista->ReadList(); 
}

void Interfaz::ClearListN()
{
    lista->ClearList(); 
    std::cout << "Lista limpiada." << std::endl;
}

