#include <iostream>
#include <string.h>
#include <list>
#include "jugador.h"

int main()
{
  std::string dni, codigo, nombre, apellidos, direccion, localidad, provincia, pais;
  int edad;
  std::cout<<" ___________________________________________________\n";
  std::cout<<"|                                                   |\n";
  std::cout<<"|---------------  Datos del jugador: ---------------|\n";
  std::cout<<"|___________________________________________________|\n";
  std::cout<<"\nIntroduzca el DNI del juagador: ";
  std::cin >> dni;
  std::cout<<"\nIntroduzca el codigo del juagador: ";
  std::cin >> codigo;
  std::cout<<"\nIntroduzca el nombre del juagador: ";
  std::cin >> nombre;
  getchar();
  std::cout<<"\nIntroduzca los apellidos del juagador: ";
  getline(std::cin, apellidos);
  std::cout<<"\nIntroduzca el edad del juagador: ";
  std::cin >> edad;
  std::cout<<"\nIntroduzca la dirección del juagador: ";
  std::cin >> direccion;
  std::cout<<"\nIntroduzca la localidad del juagador: ";
  std::cin >> localidad;
  std::cout<<"\nIntroduzca la provincia del juagador: ";
  std::cin >> provincia;
  std::cout<<"\nIntroduzca el pais del juagador: ";
  std::cin >> pais;
  Jugador j(dni, codigo, nombre, apellidos, edad, direccion, localidad, provincia, pais);
  std::list<Apuesta> aux; 
  system("clear");
  j.setApuestas();
  aux = j.getApuestas();
  std::list<Apuesta>::iterator i = aux.begin();
  std::cout<<" _____________________________________\n";
  std::cout<<"|   Tipo   |   Valor   |   Cantidad   |\n";
  std::cout<<"|__________|___________|______________|\n";
  for (int j =0; j < aux.size(); j++)
  {
    std::cout<<"    "<<(*i).tipo<<"          "<<(*i).valor<<"           "<<(*i).cantidad<<"\n";
    i++;
  }
  return 0;
}
