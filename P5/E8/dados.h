/**
 * @file dados.h
 * @author Marcos Rivera Gavilán (i92rigam@uco.es)
 * @brief La clase dados representa el lanzamiento de 2 dados.
 * @version 1.0
 * @date 2020-09-26
 */

#ifndef DADOS_H
#define DADOS_H
#include <vector>
#include <iostream>

class Dados //Definición de la clase dados
{
private:

  int d1_; //Valor del Dado 1
  int d2_; //Valor del Dado 2

  int lanz1_; //Número de lanzamientos del Dado 1
  int lanz2_; //Número de lanzamientos del Dado 2

  int sum1_; //Suma de los valores obtenidos al lanzar el Dado 1
  int sum2_; //Suma de los valores obtenidos al lanzar el Dado 2

  std::vector <int> v1; //Vector que almacena los 5 últimos valores del Dado 1
  std::vector <int> v2; //Vector que almacena los 5 últimos valores del Dado 2
  
  /**
   * @brief Añade el último valor del Dado 1
   * 
   * @return void
   */

  void ordena1();

  /**
   * @brief Añade el último valor del Dado 2
   * 
   * @return void
   */

  void ordena2();

public:
  
  /**
   * @brief Crea un nuevo obejto dados
   */
  
  Dados();
  
  /**
   * @brief Lanza los dados
   * 
   * @return void
   */
  
  void lanzamiento();
  
  /**
   * @brief Devuelve el valor del Dado 1
   * 
   * @return int 
   */

  inline int getDado1() const {return d1_;};
  
  /**
   * @brief Devuelve el valor del Dado 2
   * 
   * @return int 
   */

  inline int getDado2() const {return d2_;}

  /**
   * @brief Asigna un valor al Dado 1
   * 
   * @param int Valor que se desea asignar al Dado 1 
   * @return True si se ha podido asignar el valor
   * @return False si no se ha podido asignar el valor
   */

  bool setDado1(const int &v);

  /**
   * @brief Asigna un valor al Dado 2
   * 
   * @param int Valor que se desea asignar al Dado 2 
   * @return True si se ha podido asignar el valor
   * @return False si no se ha podido asignar el valor
   */

  bool setDado2(const int &v);

  /**
   * @brief Devuelve el resultado de sumar el valor del Dado 1 y del Dado 2
   * 
   * @return int 
   */

  inline int getSuma() const {return (d1_+d2_);}

  /**
   * @brief Devuelve el resultado de restar el valor del Dado 1 y del Dado 2
   * 
   * @return int 
   */

  int getDiferencia() const;  
  /**
   * @brief Devuelve el número de lanzamientos del Dado 1
   * 
   * @return int 
   */

  inline int getLanzamientos1() const {return lanz1_;}

  /**
   * @brief Devuelve el número de lanzamientos del Dado 2
   * 
   * @return int 
   */

  inline int getLanzamientos2() const {return lanz2_;}

  /**
   * @brief Devuelve la media de los valores del Dado 1
   * 
   * @return float 
   */

  float getMedia1() const;

  /**
   * @brief Devuelve la media de los valores del Dado 2
   * 
   * @return float 
   */

  float getMedia2() const;

  /**
   * @brief Copia al vector pasado como parámetro los últimos 5 valores del Dado 1
   * 
   * @param Vector de enteros
   * @return void 
   */

  void getUltimos1(int ultimos[]) const;

  /**
   * @brief Copia al vector pasado como parámetro los últimos 5 valores del Dado 2
   * 
   * @param Vector de enteros
   * @return void 
   */

  void getUltimos2(int ultimos[]) const;

  /**
   * @brief Insertador para la clase dados
   * 
   * @param stream 
   * @param d 
   * @return std::ostream& 
   */

  friend std::ostream &operator<<(std::ostream &stream, const Dados &d);

  /**
   * @brief Extractor para la clase dados
   * 
   * @param stream 
   * @param d 
   * @return std::istream& 
   */
      
  friend std::istream &operator>>(std::istream &stream, Dados &d);
};

#endif