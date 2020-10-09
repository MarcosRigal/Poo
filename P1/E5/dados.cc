//Cuerpo de los metodos de la clase Dados

#include <ctime>
#include <cstdlib>
#include "dados.h"

Dados::Dados()
{
  srand(time(NULL));
  d1_=1;
  d2_=1;
}

void Dados::lanzamiento()
{
  d1_=(rand()%6)+1;
  d2_=(rand()%6)+1;
}

int Dados::getDado1()
{
  return d1_;
}

int Dados::getDado2()
{
  return d2_;
}

bool Dados::setDado1(int v)
{
  if (v > 0 && v < 7)
  {
    d1_ = v;
    return true;
  }
  return false;
}

bool Dados::setDado2(int v)
{
  if (v > 0 && v < 7)
  {
    d2_ = v;
    return true;
  }
  return false;
}

int Dados::getSuma()
{
  return (d1_+d2_);
}

int Dados::getDiferencia()
{
  return (abs(d1_-d2_));
}