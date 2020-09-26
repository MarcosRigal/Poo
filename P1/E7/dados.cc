/**
 * @file dados.cc
 * @author Marcos Rivera Gavilán (i92rigam@uco.es)
 * @brief Cuerpo de los metodos de la clase Dados
 * @version 1.0
 * @date 2020-09-26
 */

#include <ctime>
#include <cstdlib>
#include "dados.h"

Dados::Dados()
{
  srand(time(NULL)); //Generamos la semilla
  d1_=1; //Asignamos el valor por defecto al Dado 1
  d2_=1; //Asignamos el valor por defecto al Dado 2
  lanz1_=0;  //Ponemos a 0 el número de lanzamientos del Dado 1
  lanz2_=0; //Ponemos a 0 el número de lanzamientos del Dado 2
  sum1_=0; //Ponemos a 0 el sumatorio de los valores del Dado 1
  sum2_=0; //Ponemos a 0 el sumatorio de los valores del Dado 2
  for (int i = 0; i < 5; i++)
  {
    v1[i]=0;//Ponemos a 0 todos los valores del vector que almacena los ultimos 5 resultados del Dado 1
    v2[i]=0;//Ponemos a 0 todos los valores del vector que almacena los ultimos 5 resultados del Dado 2
  }
  
}

void Dados::lanzamiento()
{
  d1_=(rand()%6)+1; //Se asigna un valor aleatorio al Dado 1
  d2_=(rand()%6)+1; //Se asigna un valor aleatorio al Dado 2
  lanz1_++; //Se añade 1 al número de lanzamientos del Dado 1
  lanz2_++; //Se añade 1 al número de lanzamientos del Dado 2
  sum1_ += d1_; //Se añade el valor del Dado 1 al sumatorio de sus valores
  ordena1(); //Se actualiza el vector de los ultimos 5 valores del Dado 1 con el último valor
  sum2_ += d2_; //Se añade el valor del Dado 2 al sumatorio de sus valores
  ordena2(); //Se actualiza el vector de los ultimos 5 valores del Dado 2 con el último valor
}

int Dados::getDado1()
{
  return d1_; //Se devuelve el valor del Dado 1
}

int Dados::getDado2()
{
  return d2_; //Se devuelve el valor del Dado 2
}

bool Dados::setDado1(int v)
{
  if (v > 0 && v < 7) //Comprobamos que el valor que se desea asignar sea menor que 7 y mayor que 0
  {
    d1_ = v; //Se asigna el valor pasado como parámetro al Dado 1
    lanz1_++; //Se añade 1 al número de lanzamientos del Dado 1
    sum1_ += d1_; //Se añade el valor del Dado 1 al sumatorio de sus valores
    ordena1(); //Se actualiza el vector de los ultimos 5 valores del Dado 1 con el último valor
    return true; //Como la operación se ha completado con exito devolvemos true
  }
  return false; //El valor pasado como parametro no es valido por lo tanto abortamos la operación y devolvemos false ya que no se ha podido completar
}

bool Dados::setDado2(int v)
{
  if (v > 0 && v < 7) //Comprobamos que el valor que se desea asignar sea menor que 7 y mayor que 0
  {
    d2_ = v; //Se asigna el valor pasado como parámetro al Dado 2
    lanz2_++; //Se añade 1 al número de lanzamientos del Dado 2
    sum2_ += d2_; //Se añade el valor del Dado 2 al sumatorio de sus valores
    ordena2(); //Se actualiza el vector de los ultimos 5 valores del Dado 2 con el último valor
    return true; //Como la operación se ha completado con exito devolvemos true
  }
  return false; //El valor pasado como parametro no es valido por lo tanto abortamos la operación y devolvemos false ya que no se ha podido completar
}

int Dados::getSuma()
{
  return (d1_+d2_); //Devuelve la suma de los valores del Dado 1 y del Dado 2
}

int Dados::getDiferencia()
{
  return (abs(d1_-d2_)); //Devuelve la diferencia de los valores del Dado 1 y del Dado 2
}

int Dados::getLanzamientos1()
{
  return lanz1_; //Devuelve el numero de lanzamientos del Dado 1
}

int Dados::getLanzamientos2()
{
  return lanz2_; //Devuelve el numero de lanzamientos del Dado 2
}

float Dados::getMedia1()
{
  float media = 0; //Inicializamos la variable media a 0
  if (lanz1_ == 0) //Comprobamos que el numero de lanzamientos sea mayor que 0
  {
    return media; //Como no se han producido lanzamientos la media es 0
  }
  media = sum1_/lanz1_; //Como se han producido lanzamientos calculamos la media dividiendo el sumatorio de los valores del Dado 1 entre el numero de veces que este ha sido lanzado
  return media; //Devolvemos el valor de la media
}

float Dados::getMedia2()
{
  float media = 0; //Inicializamos la variable media a 0
  if (lanz2_ == 0) //Comprobamos que el numero de lanzamientos sea mayor que 0
  {
    return media; //Como no se han producido lanzamientos la media es 0
  }
  media = sum2_/lanz2_; //Como se han producido lanzamientos calculamos la media dividiendo el sumatorio de los valores del Dado 2 entre el numero de veces que este ha sido lanzado
  return media; //Devolvemos el valor de la media
}

void Dados::ordena1()
{ //Movemos los datos de izquierda a derecha borrando el último y almacenando el nuevo valor del dado
  v1[4]=v1[3];
  v1[3]=v1[2];
  v1[2]=v1[1];
  v1[1]=v1[0];
  v1[0]=d1_;
}

void Dados::ordena2()
{ //Movemos los datos de izquierda a derecha borrando el último y almacenando el nuevo valor del dado
  v2[4]=v2[3];
  v2[3]=v2[2];
  v2[2]=v2[1];
  v2[1]=v2[0];
  v2[0]=d2_;
}

void Dados::getUltimos1(int ultimos[])
{ //Copiamos los valores al vector pasado como parametro
  ultimos[4]=v1[4];
  ultimos[3]=v1[3];
  ultimos[2]=v1[2];
  ultimos[1]=v1[1];
  ultimos[0]=v1[0];
}

void Dados::getUltimos2(int ultimos[])
{ //Copiamos los valores al vector pasado como parametro
  ultimos[4]=v2[4];
  ultimos[3]=v2[3];
  ultimos[2]=v2[2];
  ultimos[1]=v2[1];
  ultimos[0]=v2[0];
}
