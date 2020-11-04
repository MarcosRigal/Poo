/**
 * @file contador.h
 * @author Marcos Rivera Gavilán (i92rigam@uco.es)
 * @brief La clase ruleta representa un contador.
 * @version 1.0
 * @date 2020-11-02
 */

#ifndef CONTADOR_H
#define CONTADOR_H

#include <list>

class Contador //Definición de la clase contador
{

private:

  int valor_;//Valor actual del contador
  int min_;//Valor minimo que puede tomar el contador
  int max_;
  std::list<Contador> history_;//Historial de cambios del contador
  
  /**
   * @brief Función encargada de controlar que valor no supere los limites superior e inferior del intervalo
   */

  void controlValor();

public:

  /**
   * @brief Construye un nuevo objeto de la clase contador
   * 
   * @param valor al que inicializamos el contador. (Por defecto es 0)
   * @param min valor que puede tomar la variable valor. (Por defecto es 0)
   * @param max valor que puede tomar la variable valor. (Por defecto es 0)
   */

  Contador(int valor = 0, int min = 0, int max = 1000);

  /**
   * @brief Iguala el valor del contador que la llama al entero n
   * 
   * @param n Valor al que queremos igualar
   * @return Contador con el nuevo valor
   */

  Contador operator=(const int &n);

  /**
   * @brief Iguala el valor del contador que la llama al de otro contador
   * 
   * @param contador al que queremos igualar
   * @return Contador con los nuevos valores
   */

  Contador operator=(const Contador &contador);

  /**
   * @brief Incrementa el valor del contador y lo devuelve incrementado
   * 
   * @return Contador con el valor incrementado
   */

  Contador operator++(void);

  /**
   * @brief Incrementa el valor pero lo devuelve sin incrementar
   * 
   * @return Contador con el valor sin incrementar 
   */

  Contador operator++(int);

  /**
   * @brief Decrementa el valor del contador y lo devuelve decrementado
   * 
   * @return Contador con el valor decrementado
   */

  Contador operator--(void);

  /**
   * @brief Decrementa el valor pero lo devuelve sin decrementar
   * 
   * @return Contador con el valor sin decrementar 
   */

  Contador operator--(int);

  /**
   * @brief Suma al valor del contador el entero pasado como argumento
   * 
   * @param n valor que queremos sumar al contador
   * @return Contador con el valor sumado
   */

  Contador operator+(const int &n);
  
  /**
   * @brief Suma al valor del contador el entero pasado como argumento
   * 
   * @param n valor que queremos sumar al contador
   * @return Contador con el valor sumado
   */
  
  friend Contador operator+(const int &n, const Contador &contador);
 
  /**
   * @brief Resta al valor del contador el entero pasado como argumento
   * 
   * @param n valor que queremos restar al contador
   * @return Contador con el valor restado
   */

  Contador operator-(const int &n);
  
  /**
   * @brief Resta al valor del contador el entero pasado como argumento
   * 
   * @param n valor que queremos restar al contador
   * @return Contador con el valor restado
   */
  
  friend Contador operator-(const int &n, const Contador &contador);
  
  /**
   * @brief Deshace tantos cambios como se le indique en el valor n pasado como parámetro. (Por defecto n = 1)
   * 
   * @param n de acciones que queremos deshacer
   * @return true si se ha podido volver a un estado anterior
   * @return false si no se ha podido volver a un estado anterior
   */
  
  bool undo(int const &n = 1);
  
  /**
   * @brief Devuelve el valor actual de la variable valor
   * 
   * @return int con el valor actual de la variable
   */
  
  inline int get() const {return valor_;}
};


#endif