#include <iostream>
#include <string.h>
#include <list>
#include "jugador.h"

int main()
{
  system("clear");
  std::cout<<" ___________________________________________________\n";
  std::cout<<"|                                                   |\n";
  std::cout<<"|---------------  Datos del jugador: ---------------|\n";
  std::cout<<"|___________________________________________________|\n";
  Jugador jugador("a","a");//Creamos un jugador auxiliar para ir añadiendo los datos y hacer el push
  std::string cadena;//Creamos una cadena para almacenar las lecturas de getline
  std::cout<<"\nIntroduzca el DNI del juagador: ";
  getline(std::cin, cadena,'\n');//Leemos el dni del jugador
  jugador.setDNI(cadena);//Guardamos el dni en la estructura auxiliar
  std::cout<<"\nIntroduzca el codigo del juagador: ";
  getline(std::cin, cadena,'\n');//Leemos el código
  jugador.setCodigo(cadena);//Guardamos el código en la estructura auxiliar
  std::cout<<"\nIntroduzca el nombre del juagador: ";
  getline(std::cin, cadena,'\n');//Leemos el nombre
  jugador.setNombre(cadena);//Guardamos el nombre en la estructura auxiliar
  std::cout<<"\nIntroduzca los apellidos del juagador: ";
  getline(std::cin, cadena,'\n');//Leemos los apellidos
  jugador.setApellidos(cadena);//Guardamos los apellidos en la estructura auxiliar
  std::cout<<"\nIntroduzca la edad del juagador: ";
  getline(std::cin, cadena,'\n');//Leemos la edad
  jugador.setEdad(std::stoi(cadena));//Guardamos la edad en la estructura auxiliar
  std::cout<<"\nIntroduzca la dirección del juagador: ";
  getline(std::cin, cadena,'\n');//Leemos la dirección
  jugador.setDireccion(cadena);//Guardamos la dirección en la estructura auxiliar
  std::cout<<"\nIntroduzca la localidad del juagador: ";
  getline(std::cin, cadena,'\n');//Leemos la localidad
  jugador.setLocalidad(cadena);//Guardamos la localidad en la estructura auxiliar
  std::cout<<"\nIntroduzca la provincia del juagador: ";
  getline(std::cin, cadena,'\n');//Leemos la provincia
  jugador.setProvincia(cadena);//Guardamos la provincia en la estructura auxiliar
  std::cout<<"\nIntroduzca el pais del juagador: ";
  getline(std::cin, cadena,'\n');//Leemos el pais
  jugador.setPais(cadena);//Guardamos el pais en la estructura auxiliar
  std::list<Apuesta> aux; 
  system("clear");
  jugador.setApuestas();
  aux = jugador.getApuestas();
  std::list<Apuesta>::iterator a = aux.begin();
  std::cout<<" _____________________________________\n";
  std::cout<<"|   Tipo   |   Valor   |   Cantidad   |\n";
  std::cout<<"|__________|___________|______________|\n";
  for (int j =0; j < aux.size(); j++)
  {
    std::cout<<"    "<<(*a).tipo<<"          "<<(*a).valor<<"           "<<(*a).cantidad<<"\n";
    a++;
  }
  return 0;
}

  
  
  
  
  
  
  
  
  