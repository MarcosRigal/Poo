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
  v1.resize(5,0); //Ponemos a 0 todos los valores del vector que almacena los ultimos 5 resultados del Dado 1
  v2.resize(5,0); //Ponemos a 0 todos los valores del vector que almacena los ultimos 5 resultados del Dado 2  
}

void Dados::lanzamiento()
{ 
  setDado1(((rand()%6)+1)); //Se asigna un valor aleatorio del 1 al 6 al Dado 1
  setDado2(((rand()%6)+1)); //Se asigna un valor aleatorio del 1 al 6 al Dado 2
}

bool Dados::setDado1(int const &v)
{
  if (v > 0 && v < 7) //Comprobamos que el valor que se desea asignar sea menor que 7 y mayor que 0
  {
    d1_ = v; //Se asigna el valor pasado como parámetro al Dado 1
    lanz1_++; //Se añade 1 al número de lanzamientos del Dado 1
    sum1_ += getDado1(); //Se añade el valor del Dado 1 al sumatorio de sus valores
    ordena1(); //Se actualiza el vector de los ultimos 5 valores del Dado 1 con el último valor
    return true; //Como la operación se ha completado con exito devolvemos true
  }
  return false; //El valor pasado como parametro no es valido por lo tanto abortamos la operación y devolvemos false ya que no se ha podido completar
}

bool Dados::setDado2(int const &v)
{
  if (v > 0 && v < 7) //Comprobamos que el valor que se desea asignar sea menor que 7 y mayor que 0
  {
    d2_ = v; //Se asigna el valor pasado como parámetro al Dado 2
    lanz2_++; //Se añade 1 al número de lanzamientos del Dado 2
    sum2_ += getDado2(); //Se añade el valor del Dado 2 al sumatorio de sus valores
    ordena2(); //Se actualiza el vector de los ultimos 5 valores del Dado 2 con el último valor
    return true; //Como la operación se ha completado con exito devolvemos true
  }
  return false; //El valor pasado como parametro no es valido por lo tanto abortamos la operación y devolvemos false ya que no se ha podido completar
}

int Dados::getDiferencia() const
{
  return (abs(d1_-d2_)); //Devuelve la diferencia de los valores del Dado 1 y del Dado 2
}

float Dados::getMedia1() const
{
  float media = 0; //Inicializamos la variable media a 0
  if (lanz1_ == 0) //Comprobamos que el numero de lanzamientos sea mayor que 0
  {
    return media; //Como no se han producido lanzamientos la media es 0
  }
  media = (float)sum1_/(float)lanz1_; //Como se han producido lanzamientos calculamos la media dividiendo el sumatorio de los valores del Dado 1 entre el numero de veces que este ha sido lanzado
  return media; //Devolvemos el valor de la media
}

float Dados::getMedia2() const
{
  float media = 0; //Inicializamos la variable media a 0
  if (lanz2_ == 0) //Comprobamos que el numero de lanzamientos sea mayor que 0
  {
    return media; //Como no se han producido lanzamientos la media es 0
  }
  media = (float)sum2_/(float)lanz2_; //Como se han producido lanzamientos calculamos la media dividiendo el sumatorio de los valores del Dado 2 entre el numero de veces que este ha sido lanzado
  return media; //Devolvemos el valor de la media
}

void Dados::ordena1()
{ //Movemos los datos de izquierda a derecha borrando el último y almacenando el nuevo valor del dado
  v1.emplace(v1.begin(), getDado1());
  v1.pop_back();
}

void Dados::ordena2()
{ //Movemos los datos de izquierda a derecha borrando el último y almacenando el nuevo valor del dado
  v2.emplace(v2.begin(), getDado2());
  v2.pop_back();
}

void Dados::getUltimos1(int ultimos[]) const
{ //Copiamos los valores al vector pasado como parametro
  for (int i = 0; i < 5; i++)
  {
    ultimos[i]=v1[i];
  } 
}

void Dados::getUltimos2(int ultimos[]) const
{ //Copiamos los valores al vector pasado como parametro
  for (int i = 0; i < 5; i++)
  {
    ultimos[i]=v2[i];
  }
}

std::ostream &operator<<(std::ostream &stream, const Dados &d)
{
   stream << "(";
   stream << d.d1_;
   stream << ", ";
   stream << d.d2_;
   stream << ")";
   return stream;
}
std::istream &operator>>(std::istream &stream, Dados &d)
{
   int daux;
   
   std::cout << "Introduce un valor para el dado 1: ";
   std::cin >> daux;

   while (!d.setDado1(daux))
   {
      std::cout << "Error introduzca un valor entre 1 y 6: ";
      std::cin >> daux; 
   }

   std::cout << "Introduce un valor para el dado 2: ";
   std::cin >> daux;

   while (!d.setDado2(daux))
   {
      std::cout << "Error introduzca un valor entre 1 y 6: ";
      std::cin >> daux; 
   }

   return stream;
}
