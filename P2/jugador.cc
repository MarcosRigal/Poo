/**
 * @file jugador.cc
 * @author Marcos Rivera Gavilán (i92rigam@uco.es)
 * @brief Cuerpo de los métodos de la clase jugador.
 * @version 1.0
 * @date 2020-10-07
 */

#include "jugador.h"
#include <fstream>
#include <iostream>

void Jugador::setApuestas()
{
  apuestas_.clear(); //Vaciamos la lista de apuestas del jugador
  std::string fichero = (getDNI() + ".txt"); //fichero almacena el nombre del fichero que queremos abrir para ello concatenamos el DNI del jugador con la extensión.txt
  std::ifstream f(fichero); //Creamos el puntero para abrir el fichero en modo lectura y lo abrimos introduciendo el nombre del fichero que queremos abrir en el parentesis
  if (!f) //comprobamos que el fichero se haya abierto correctamente
  {
    std::cout<<"Error al abrir el archivo\n"; //Como no se ha abierto correctamente informamos al usuario de que ha habido un error
    EXIT_FAILURE; //Salimos y devolviendo una señal de error
  }
  Apuesta ap; //Creamos la estructura apuesta para almacenar temporalmente la información
  std::string cadena; //Creamos una cadena para almacenar la información leida del fichero
  getline(f, cadena, ',');//Leemos del archivo hasta la primera coma
  while (!f.eof()) //Este bucle se repetirá hasta que hallamos llegado al final del fichero y no hay nada mas que leer
  { //Cunado leemos con getline poniendo una condición del tipo ',' el puntero de lectura se queda justo después
    ap.tipo = std::stoi(cadena);//Guardamos en el campo tipo de nuestra estructura auxiliar el valor de la lectura convertido a entero
    getline(f, cadena, ',');//Leemos del archivo hasta la siguiente coma
    ap.valor = cadena; //Guardamos la cadena en el campo valor de nuestra estructura auxiliar
    getline(f, cadena, '\n'); //Como esta lectura siempre se va a realizar al final de la linea en vez de leer hasta la coma leemos hasta \n que indica el salto de linea
    ap.cantidad = std::stoi(cadena); //Guardamos en el campo cantidad de nuestra estructura auxiliar el valor de la lectura convertido a entero
    apuestas_.push_back(ap); //Añadimos nuestra estructura auxiliar a la lista de apuestas
    getline(f, cadena, ','); //Leemos del archivo hasta la siguiente coma
  }
  f.close(); //Como ya no hay nada mas que leer cerramos el fichero
}