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

class Crupier: public Persona //Definición de la clase crupier que hereda sus atributos de la clase persona
{
private:

  std::string codigo_; //Código de empleado del crupier

public:

  /**
   * @brief Crea un nuevo objeto crupier
   * 
   * @param dni de la persona (obligatorio)
   * @param codigo de empleado (obligatorio)
   * @param nombre de la persona (opcional)
   * @param apellidos de la persona (opcional)
   * @param edad de la persona (opcional)
   * @param direccion de la persona (opcional)
   * @param localidad de la persona (opcional)
   * @param provincia de la persona (opcional)
   * @param pais de la persona (opcional)
   */

  inline Crupier(std::string dni, std::string codigo, std::string nombre = "", std::string apellidos = "", int edad = 0, std::string direccion = "", std::string localidad = "", std::string provincia = "", std::string pais = "") : Persona(dni, nombre, apellidos, edad, direccion, localidad, provincia, pais) {codigo_=codigo;} 
  
  /**
   * @brief Asigna un código de empleado al crupier
   * 
   * @param std::string codigo que se desea asignar al crupier 
   */
  
  inline void setCodigo(std::string const codigo) {codigo_=codigo;}
  
  /**
   * @brief Devuelve el código de empleado del crupier
   * 
   * @return std::string 
   */
  
  inline std::string getCodigo() const {return codigo_;}
};

#endif