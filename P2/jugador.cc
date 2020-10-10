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
  std::ifstream f; //Creamos el puntero para abrir el fichero
  f.open(fichero); //Abrimos el fichero
  if (!f) //comprobamos que el fichero se haya abierto correctamente
  {
    std::cout<<"Error al abrir el archivo\n"; //Como no se ha abierto correctamente informamos al usuario de que ha habido un error
    EXIT_FAILURE; //Salimos y devolviendo una señal de error
  }
  Apuesta ap; //Creamos la estructura apuesta para almacenar temporalmente la información
  std::string cadena; //Creamos una cadena para almacenar la información leida del fichero
  int coma,n; //Estas variables las usaremos posteriormente para trocear la cadena
  getline(f, cadena); //Leemos la primera linea del fichero
  while (!f.eof()) //Este bucle se repetirá hasta que se cumpla la condición pues eso significará que hemos llegado al final del fichero y no hay nada mas que leer
  {
    coma = cadena.find_first_of(","); //Buscamos la posición de la primera coma ya que los elementos estan separados por comas
    n = (cadena.size()-1); //Calculamos el numero correspondiente a la ultima posicion de la cadena
    ap.tipo = std::stoi(cadena.substr(0,coma)); //Almacenamos en el campo tipo de la estructura apuesta la subcadena que contiene el dato correspondiente y lo convertimos a entero 
    cadena = cadena.substr(coma+1,n); //Creamos una nueva cadena con los elementos que quedan por almacenar aún en los campos de la estructura
    coma = cadena.find_first_of(","); //Buscamos la posición de la primera coma en la nueva cadena
    n = (cadena.size()-1); //Y volvemos a calcular el numero correspondiente a la ultima posicion de la cadena
    ap.valor = cadena.substr(0,coma); //Almacenamos en el campo valor de la estructura apuesta la subcadena que contiene el dato correspondiente
    ap.cantidad = std::stoi(cadena.substr(coma+1,n)); //Almacenamos en el campo cantidad de la estructura apuesta la subcadena que contiene el dato correspondiente y lo convertimos a entero
    apuestas_.push_back(ap); //Añadimos a la lista de apuestas esta estructura apuesta con la información correspondiente
    getline(f, cadena); //Leemos una linea del fichero
  }
  f.close(); //Como ya no hay nada mas que leer cerramos el fichero
}