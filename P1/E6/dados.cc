//Cuerpo de los metodos de la clase Dados

#include <ctime>
#include <cstdlib>
#include "dados.h"

Dados::Dados()
{
  srand(time(NULL));
  d1_=1;
  d2_=1;
  lanz1_=0;
  lanz2_=0;
  sum1_=0;
  sum2_=0;
}

void Dados::lanzamiento()
{
  d1_=(rand()%6)+1;
  d2_=(rand()%6)+1;
  lanz1_++;
  lanz2_++;
  sum1_ += d1_;
  sum2_ += d2_;
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
    lanz1_++;
    sum1_ += d1_;
    return true;
  }
  return false;
}

bool Dados::setDado2(int v)
{
  if (v > 0 && v < 7)
  {
    d2_ = v;
    lanz2_++;
    sum2_ += d2_;
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

int Dados::getLanzamientos1()
{
  return lanz1_;
}

int Dados::getLanzamientos2()
{
  return lanz2_;
}

float Dados::getMedia1()
{
  if (lanz1_ == 0)
  {
    return 0;
  }
  return (sum1_/lanz1_);
}

float Dados::getMedia2()
{
  if (lanz2_ == 0)
  {
    return 0;
  }
  return (sum2_/lanz2_);
}