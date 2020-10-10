/**
 * @file persona.h
 * @author Marcos Rivera Gavilán (i92rigam@uco.es)
 * @brief La clase persona representa la entidad persona.
 * @version 1.0
 * @date 2020-10-07
 */

#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona //Definición de la clase persona
{
private:

  std::string dni_; //DNI de la persona
  std::string nombre_; //Nombre de la persona
  std::string apellidos_; //Apellidos de la persona
  int edad_; //Edad de la persona
  std::string direccion_; //Dirección de la persona
  std::string localidad_; //Localidad de la persona
  std::string provincia_; //Provincia de la persona
  std::string pais_; //País de la persona

public:

  /**
   * @brief Crea un nuevo objeto persona
   */

  Persona(std::string dni, std::string nombre = "", std::string apellidos = "", int edad = 0, std::string direccion = "", std::string localidad = "", std::string provincia = "", std::string pais = "");

  /**
   * @brief Asigna un DNI a la persona
   * 
   * @param std::string dni que se desea asignar a la persona 
   */

  inline void setDNI(std::string const dni) {dni_=dni;}

  /**
   * @brief Devuelve el DNI de la persona
   * 
   * @return std::string 
   */

  inline std::string getDNI() const {return dni_;}

  /**
   * @brief Asigna un nombre a la persona
   * 
   * @param std::string nombre que se desea asignar a la persona 
   */

  inline void setNombre(std::string const nombre) {nombre_=nombre;}  

  /**
   * @brief Devuelve el nombre de la persona
   * 
   * @return std::string 
   */

  inline std::string getNombre() const {return nombre_;}

  /**
   * @brief Asigna unos apellidos a la persona
   * 
   * @param std::string apellidos que se desea asignar a la persona 
   */

  inline void setApellidos(std::string const apellidos) {apellidos_=apellidos;}  

  /**
   * @brief Devuelve los apellidos de la persona
   * 
   * @return std::string 
   */

  inline std::string getApellidos() const {return apellidos_;}

  /**
   * @brief Asigna una edad a la persona
   * 
   * @param int const &edad 
   * @return true si se ha podido asignar la edad
   * @return false se no se ha podido asignar la edad
   */

  bool setEdad(int const &edad);

  /**
   * @brief Devuelve la edad de la persona
   * 
   * @return int
   */

  inline int getEdad() const {return edad_;}

  /**
   * @brief Asigna una direccion a la persona
   * 
   * @param std::string direccion que se desea asignar a la persona 
   */

  inline void setDireccion(std::string const direccion) {direccion_=direccion;}  

  /**
   * @brief Devuelve la direccion de la persona
   * 
   * @return std::string 
   */

  inline std::string getDireccion() const {return direccion_;}

  /**
   * @brief Asigna una localidad a la persona
   * 
   * @param std::string direccion que se desea asignar a la persona 
   */

  inline void setLocalidad(std::string const localidad) {localidad_=localidad;} 
  /**
   * @brief Devuelve la localidad de la persona
   * 
   * @return std::string 
   */
  inline std::string getLocalidad() const {return localidad_;}

  /**
   * @brief Asigna una provincia a la persona
   * 
   * @param std::string provincia que se desea asignar a la persona 
   */

  inline void setProvincia(std::string const provincia) {provincia_=provincia;}  

  /**
   * @brief Devuelve la provincia de la persona
   * 
   * @return std::string 
   */

  inline std::string getProvincia() const {return provincia_;}

  /**
   * @brief Asigna un pais a la persona
   * 
   * @param std::string pais que se desea asignar a la persona 
   */

  inline void setPais(std::string const pais) {pais_=pais;}

  /**
   * @brief Devuelve el pais de la persona
   * 
   * @return std::string 
   */

  inline std::string getPais() const {return pais_;}
  
  /**
   * @brief Devuelve una cadena con el siguiente formato: apellidos, nombre
   * 
   * @return std::string 
   */


  inline std::string getApellidosyNombre() const {return (apellidos_ + ", " + nombre_);}
  
  /**
   * @brief Permite comprobar si una persona es mayor de edad
   * 
   * @return true si la persona es mayor de edad
   * @return false si la persona es menor de edad
   */

  bool mayor();

};

#endif