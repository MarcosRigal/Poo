#include <iostream>
#include <fstream>
#include <vector>
#include "jugador.h"
#include <algorithm>

std::vector<Jugador> leeJugadores()
{
  std::ifstream f("jugadores.txt"); //Creamos el puntero para abrir el fichero en modo lectura y lo abrimos introduciendo el nombre del fichero que queremos abrir
  if (!f) //comprobamos que el fichero se haya abierto correctamente
  {
    std::cout<<"Error al abrir el archivo\n"; //Como no se ha abierto correctamente informamos al usuario de que ha habido un error
    EXIT_FAILURE; //Salimos y devolviendo una señal de error
  }
  std::vector<Jugador> jugadores;//Creamos el vector de jugadores
  jugadores.clear(); //Vaciamos la lista de apuestas del jugador
  Jugador jugador("a","a");//Creamos un jugador auxiliar para ir añadiendo los datos y hacer el push
  std::string cadena;//Creamos una cadena para almacenar las lecturas de getline
  getline(f, cadena,',');//Leemos el dni del jugador
  while (!f.eof()) //Este bucle se repetirá hasta que hallamos llegado al final del fichero y no hay nada mas que leer
  { //Cunado leemos con getline poniendo una condición del tipo ',' el puntero de lectura se queda justo después
    jugador.setDNI(cadena);//Guardamos el dni en la estructura auxiliar
    getline(f, cadena,',');//Leemos el código
    jugador.setCodigo(cadena);//Guardamos el código en la estructura auxiliar
    getline(f, cadena,',');//Leemos el nombre
    jugador.setNombre(cadena);//Guardamos el nombre en la estructura auxiliar
    getline(f, cadena,',');//Leemos los apellidos
    jugador.setApellidos(cadena);//Guardamos los apellidos en la estructura auxiliar
    getline(f, cadena,',');//Leemos la dirección
    jugador.setDireccion(cadena);//Guardamos la dirección en la estructura auxiliar
    getline(f, cadena,',');//Leemos la localidad
    jugador.setLocalidad(cadena);//Guardamos la localidad en la estructura auxiliar
    getline(f, cadena,',');//Leemos la provincia
    jugador.setProvincia(cadena);//Guardamos la provincia en la estructura auxiliar
    getline(f, cadena,',');//Leemos el pais
    jugador.setPais(cadena);//Guardamos el pais en la estructura auxiliar
    getline(f, cadena,'\n');//Leemos el dinero
    jugador.setDinero(std::stoi(cadena));//Guardamos el dinero en la estructura auxiliar
    jugadores.push_back(jugador);//Añadimos el jugador a la lista
    getline(f, cadena,',');//Leemos el dni
  }
  f.close(); //Como ya no hay nada mas que leer cerramos el fichero
  return jugadores;
}

bool ascendente(Jugador j1, Jugador j2){return j1.getDNI()<j2.getDNI();}

int main(int argc, char const *argv[])
{
   std::vector<Jugador> jugadores;
   jugadores = leeJugadores();
   std::cout<<"DNIS del vector de jugadores : ";
   for (int i = 0; i < (int) jugadores.size(); i++)//Este bucle se repetirá mientras haya jugadores
   {
     std::cout<<jugadores[i].getDNI()<<" ";
   }
   std::cout<<"\n";

   std::sort(jugadores.begin(), jugadores.end(), ascendente);

   std::cout<<"DNIS del vector de jugadores ordenados : ";
   for (int i = 0; i < (int) jugadores.size(); i++)//Este bucle se repetirá mientras haya jugadores
   {
     std::cout<<jugadores[i].getDNI()<<" ";
   }
   std::cout<<"\n";
   return 0;
}
