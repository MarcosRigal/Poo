/**
 * @file contador.cc
 * @author Marcos Rivera Gavilán (i92rigam@uco.es)
 * @brief Cuerpo de los métodos de la clase contador.
 * @version 1.0
 * @date 2020-10-07
 */

#include "contador.h"
#include <iostream>

Contador::Contador(int valor, int min, int max)
{
  if (valor<min || valor>max || min>max)//Comprobamos que no se de ninguno de los casos prohibidos en el enunciado
  {//Como se ha dado uno de los tres o mas le asignamos sus valores por defecto a las variables
    valor = 0;
    min = 0;
    max = 1000;
  }
  valor_ = valor;//Le asignamos el valor pasado como parámetro 
  min_ = min;//Le asignamos el valor pasado como parámetro 
  max_ = max;//Le asignamos el valor pasado como parámetro 
  history_.push_back(*this);//Lo añadimos a la lista de cambios
}

void Contador::controlValor()
{
  if (valor_>max_)//Comprobamos que el valor no exceda el limite superior
  {
    valor_=max_;//Como lo excede lo igualamos a este tal y como indica el enunciado
  }
  else if (valor_<min_)//Comprobamos que el valor no exceda el limite inferior
  {
    valor_=min_;//Como lo excede lo igualamos al limite inferior tal y como indica el enunciado
  }
  history_.push_back(*this);  //Añadimos el cabio a la lista de cambios
}

Contador Contador::operator=(const int &n)
{
  this->valor_= n;//Asignamos el nuevo valor
  controlValor();//Comprobamos que no se hayan excedido los limites del intervalo y guardamos el cambio en el historial
  return *this;//Devolvemos el contador con el nuevo valor
}

Contador Contador::operator=(const Contador &contador)
{
  this->valor_ = contador.valor_;//Asignamos el nuevo valor
  this->min_ = contador.min_;//Asignamos el nuevo valor
  this->max_ = contador.max_;//Asignamos el nuevo valor
  this->history_ = contador.history_;//Copiamos el historial de cambios del contador pasado como parametro
  history_.push_back(*this);//Comprobamos que no se hayan excedido los limites del intervalo y guardamos el cambio en el historial
  return *this;//Devolvemos el contador con el nuevo valor
}

Contador Contador::operator++(void)
{
  ++this->valor_;//Incrementamos el valor
  controlValor();//Comprobamos que no se hayan excedido los limites del intervalo y guardamos el cambio en el historial
  return *this;//Devolvemos el contador con el nuevo valor
}

Contador Contador::operator++(int)
{
  Contador aux = *this;//Copiamos los valores actuales del puntero a uno auxiliar
  ++this->valor_;//Incrementamos el valor del contador actual
  controlValor();//Comprobamos que no se hayan excedido los limites del intervalo y guardamos el cambio en el historial del contador actual
  return aux;//Devolvemos una copia contador con los antiguos valores sin incrementar y sin esta modificación en su historial
}

Contador Contador::operator--()
{
  --this->valor_;//Decrementamos el valor
  controlValor();//Comprobamos que no se hayan excedido los limites del intervalo y guardamos el cambio en el historial
  return *this;//Devolvemos el contador con el nuevo valor
}

Contador Contador::operator--(int)
{
  Contador aux = *this;//Copiamos los valores actuales del puntero a uno auxiliar
  --this->valor_;//Decrementamos el valor del contador actual
  controlValor();//Comprobamos que no se hayan excedido los limites del intervalo y guardamos el cambio en el historial del contador actual
  return aux;//Devolvemos una copia contador con los antiguos valores sin decrementar y sin esta modificación en su historial
}

Contador Contador::operator+(const int &n)
{
  this->valor_ += n; //Le sumamos al valor actual el de n que ha sido pasado como parametro
  controlValor();//Comprobamos que no se hayan excedido los limites del intervalo y guardamos el cambio en el historial
  return *this;//Devolvemos el contador con el nuevo valor
}

Contador operator+(const int &n, const Contador &contador)
{
  Contador aux;//Creamos un contador auxiliar 
  aux.valor_ = n + contador.valor_;//Guardamos el nuevo valor en el contador auxiliar
  aux.max_ = contador.max_;//Guardamos el nuevo valor en el contador auxiliar
  aux.min_ = contador.min_;//Guardamos el nuevo valor en el contador auxiliar
  aux.controlValor();//Comprobamos que no se hayan excedido los limites del intervalo y guardamos el cambio en el historial
  return aux;//Devolvemos el contador auxiliar con el nuevo valor y los cambios en su historial
}

Contador Contador::operator-(const int &n)
{
  this->valor_ -= n; //Le restamos al valor actual el de n que ha sido pasado como parametro
  controlValor();//Comprobamos que no se hayan excedido los limites del intervalo y guardamos el cambio en el historial
  return *this;//Devolvemos el contador con el nuevo valor
}

Contador operator-(const int &n, const Contador &contador)
{
  Contador aux;//Creamos un contador auxiliar 
  aux.valor_ = n - contador.valor_;//Guardamos el nuevo valor en el contador auxiliar
  aux.max_ = contador.max_;//Guardamos el nuevo valor en el contador auxiliar
  aux.min_ = contador.min_;//Guardamos el nuevo valor en el contador auxiliar
  aux.controlValor();//Comprobamos que no se hayan excedido los limites del intervalo y guardamos el cambio en el historial
  return aux;//Devolvemos el contador auxiliar con el nuevo valor y los cambios en su historial
}

bool Contador::undo(int const &n)
{
  if (n >= (int) history_.size() || n<1)//Comprobamos que haya elementos suficientes en el historial para volver hacia atrás y que n sea mayor que 1.
  {
    return false;//Como una de las dos condiciones no se cumple devolvemos false
  }
  for (int i = 0; i < n; i++)//Vamos eliminando del historial hasta llegar a la posición que queríamos
  {
    history_.pop_back();//Borramos
  } 
  *this = history_.back();//Actualizamos el valor del puntero al actual con los cambios deshechos
  return true;//Como se ha podido realizar correctamente devolvemos true  
}