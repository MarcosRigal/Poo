/**
 * @file persona.cc
 * @author Marcos Rivera Gavilán (i92rigam@uco.es)
 * @brief Cuerpo de los métodos de la clase persona.
 * @version 1.0
 * @date 2020-10-07
 */

#include "persona.h"

Persona::Persona(std::string dni, std::string nombre , std::string apellidos , int edad, std::string direccion , std::string localidad , std::string provincia , std::string pais)
{
    dni_ = dni; //Asignamos el valor pasado como parametro correspondiente al DNI de la persona
    nombre_ = nombre; //Asignamos el valor pasado como parametro correspondiente al Nombre de la persona
    apellidos_ = apellidos; //Asignamos el valor pasado como parametro correspondiente a los Apellidos de la persona
    edad_ = edad; //Asignamos el valor pasado como parametro correspondiente a la Edad de la persona
    direccion_ = direccion; //Asignamos el valor pasado como parametro correspondiente a la Dirección de la persona
    localidad_ = localidad; //Asignamos el valor pasado como parametro correspondiente a la Localidad de la persona
    provincia_ = provincia; //Asignamos el valor pasado como parametro correspondiente a la Provincia de la persona
    pais_ = pais; //Asignamos el valor pasado como parametro correspondiente al País de la persona
}

bool Persona::setEdad(int const &edad)
{
  if (edad>=0) //Comprobamos que la edad que se va a introducir sea una edad válida
  {
    edad_=edad; //Como es válida, asignamos el valor pasado como parametro a la edad de la persona
    return true; //Como la operación se ha completado con exito devolvemos true
  }
  return false;  //Como la operación no se ha completado con exito devolvemos false
}

bool Persona::mayor()
{
  if (getEdad()>=18) //Comprobamos que la edad de la persona sea 18 o más
  {
    return true; //Como tiene más de 18 años es mayor de edad por lo tanto devolvemos true
  }
  return false; //Como tiene menos de 18 años es menor de edad por lo tanto devolvemos false
}