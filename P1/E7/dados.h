/**
 * @file dados.h
 * @author Marcos Rivera Gavilán (i92rigam@uco.es)
 * @brief La clase dados representa el lanzamiento de 2 dados.
 * @version 1.0
 * @date 2020-09-26
 */

#ifndef DADOS_H
#define DADOS_H

class Dados //
{
private:

  int d1_; //Valor del Dado 1
  int d2_; //Valor del Dado 2
//Ponerlos como int y hacer casting en la función
  float lanz1_; //Número de lanzamientos del Dado 1
  float lanz2_; //Número de lanzamientos del Dado 2

  float sum1_; //Suma de los valores obtenidos al lanzar el Dado 1
  float sum2_; //Suma de los valores obtenidos al lanzar el Dado 2

  int v1[5]; //Vector que almacena los 5 últimos valores del Dado 1
  int v2[5]; //Vector que almacena los 5 últimos valores del Dado 2

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

  int getDado1();
  
  /**
   * @brief Devuelve el valor del Dado 2
   * 
   * @return int 
   */

  int getDado2();

  /**
   * @brief Asigna un valor al Dado 1
   * 
   * @param int Valor que se desea asignar al Dado 1 
   * @return True si se ha podido asignar el valor
   * @return False si no se ha podido asignar el valor
   */

  bool setDado1(int v);

  /**
   * @brief Asigna un valor al Dado 2
   * 
   * @param int Valor que se desea asignar al Dado 2 
   * @return True si se ha podido asignar el valor
   * @return False si no se ha podido asignar el valor
   */

  bool setDado2(int v);

  /**
   * @brief Devuelve el resultado de sumar el valor del Dado 1 y del Dado 2
   * 
   * @return int 
   */

  int getSuma();

  /**
   * @brief Devuelve el resultado de restar el valor del Dado 1 y del Dado 2
   * 
   * @return int 
   */

  int getDiferencia();

  /**
   * @brief Devuelve el número de lanzamientos del Dado 1
   * 
   * @return int 
   */

  int getLanzamientos1();

  /**
   * @brief Devuelve el número de lanzamientos del Dado 2
   * 
   * @return int 
   */

  int getLanzamientos2();

  /**
   * @brief Devuelve la media de los valores del Dado 1
   * 
   * @return float 
   */

  float getMedia1();

  /**
   * @brief Devuelve la media de los valores del Dado 2
   * 
   * @return float 
   */

  float getMedia2();

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

  /**
   * @brief Copia al vector pasado como parámetro los últimos 5 valores del Dado 1
   * 
   * @param Vectro de enteros
   * @return void 
   */

  void getUltimos1(int ultimos[]);

  /**
   * @brief Copia al vector pasado como parámetro los últimos 5 valores del Dado 2
   * 
   * @param Vector de enteros
   * @return void 
   */

  void getUltimos2(int ultimos[]);
};

#endif