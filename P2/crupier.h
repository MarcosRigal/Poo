/**
 * @file crupier.h
 * @author Marcos Rivera Gavilán (i92rigam@uco.es)
 * @brief La clase crupier representa a los trabajadores del casino.
 * @version 1.0
 * @date 2020-10-07
 */

#ifndef CRUPIER_H
#define CRUPIER_H

#include "persona.h"

class Crupier: public Persona
{
private:

  std::string codigo_;

public:

  inline Crupier(std::string dni, std::string codigo,std::string nombre = "", std::string apellidos = "", int edad = 0, std::string direccion = "", std::string localidad = "", std::string provincia = "", std::string pais = "") : Persona(dni, nombre, apellidos, edad, direccion, localidad, provincia, pais) {codigo_=codigo;} 
  inline void setCodigo(std::string const codigo) {codigo_=codigo;}
  inline std::string getCodigo() const {return codigo_;}
};


#endif