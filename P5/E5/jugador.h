/**
 * @file jugador.h
 * @author Marcos Rivera Gavilán (i92rigam@uco.es)
 * @brief La clase jugador representa a los jugadores del casino.
 * @version 1.0
 * @date 2020-10-07
 */

#ifndef JUGADOR_H
#define JUGADOR_H

#include "persona.h"
#include <list>

struct Apuesta //Definición de la estructura apuesta en base a la cual se hará la lista de apuestas.
{
  int tipo;
  std::string valor;
  int cantidad;
};

class Jugador : public Persona //Deninición de la clase jugador que hereda sus atributos de la clase persona
{

private:
  
  std::string codigo_; //Códico del jugador
  int dinero_; //Dinero del jugador
  std::list<Apuesta> apuestas_; //Lista que contiene las apuestas del jugador

public:

  /**
   * @brief Crea un nuevo objeto jugador
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
  
  inline Jugador(std::string dni, std::string codigo, std::string nombre = "", std::string apellidos = "", int edad = 0, std::string direccion = "", std::string localidad = "", std::string provincia = "", std::string pais = "") : Persona(dni, nombre, apellidos, edad, direccion, localidad, provincia, pais) {codigo_ = codigo; dinero_ = 1000;}

  /**
   * @brief Asigna un código de jugador al jugador
   * 
   * @param std::string codigo que se desea asignar al jugador 
   */

  inline void setCodigo(std::string const codigo) {codigo_=codigo;}
 
  /**
   * @brief Devuelve el código de jugador del jugador
   * 
   * @return std::string 
   */ 

  inline std::string getCodigo() const {return codigo_;}

  /**
   * @brief Asigna una cantidad de dinero al jugador
   * 
   * @param int const &dinero dinero que se desea asignar al jugador 
   */

  inline void setDinero(int const &dinero) {dinero_=dinero;}
  
  /**
   * @brief Devuelve el dinero del jugador
   * 
   * @return int 
   */ 
  
  inline int getDinero() const {return dinero_;}
  
  /**
   * @brief Devuelve la lista con las apuestas del jugador
   * 
   * @return std::list<Apuesta> 
   */
  
  inline std::list<Apuesta> getApuestas() const {return apuestas_;}

  /**
   * @brief Permite asignar una lista de apuestas al jugador a partir de un fichero de texto.
   * 
   */

  void setApuestas();

};

#endif