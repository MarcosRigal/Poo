//Programa principal prueba el funcionamiento de la clase Dados

#include "dados.h"
#include "dados.cc"
#include <iostream>

int main()
{
  Dados d;
  int select =1, v;
  while (select !=0 )
  {
    std::cout<<" ___________________________________________________\n";
    std::cout<<"|                                                   |\n";
    std::cout<<"|---------------  Menu de selección: ---------------|\n";
    std::cout<<"|___________________________________________________|\n";
    std::cout<<"|                                                   |\n";
    std::cout<<"|Pulsa 1 para lanzar los dados                      |\n";
    std::cout<<"|Pulsa 2 para obtener el valor del dado 1           |\n";
    std::cout<<"|Pulsa 3 para obtener el valor del dado 2           |\n";
    std::cout<<"|Pulsa 4 para asignar un valor al dado 1            |\n";
    std::cout<<"|Pulsa 5 para asignar un valor al dado 2            |\n";
    std::cout<<"|Pulsa 6 para sumar el valor del dado 1 y del dado 2|\n";
    std::cout<<"|___________________________________________________|\n";
    std::cout<<"\nSu elección: ";
    std::cin >> select;
    switch (select)
    {
    case 0:
        std::cout<<"Hasta la próxima.\n";
      break;
    case 1:
        d.lanzamiento();
      break;
    case 2:
        std::cout<<"El valor del dado 1 es: "<<d.getDado1()<<"\n";
      break;
    case 3:
        std::cout<<"El valor del dado 2 es: "<<d.getDado2()<<"\n";
      break;
    case 4:
        std::cout<<"¿Qué valor desea asignar al dado 1?\n";
        std::cin>>v;
        if (d.setDado1(v))
        {
          std::cout<<"La asignación se realizó correctamente\n";
        }
        else
        {
          std::cout<<"Se produjo un error durante la asignación\n";
        }
      break;
    case 5:
        std::cout<<"¿Qué valor desea asignar al dado 2?\n";
        std::cin>>v;
        if (d.setDado2(v))
        {
          std::cout<<"La asignación se realizó correctamente\n";
        }
        else
        {
          std::cout<<"Se produjo un error durante la asignación\n";
        }
      break;
    case 6:
        std::cout<<"La suma de D1 y D2 es: "<<d.getSuma()<<"\n";
      break;
    default:
        std::cout<<"Error seleccione una opción valida.";
      break;
    }
  }

  return 0;
}
