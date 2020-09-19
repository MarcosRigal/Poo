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
  v0_1_=0;
  v1_1_=0;
  v2_1_=0;
  v3_1_=0;
  v4_1_=0;
  v0_2_=0;
  v1_2_=0;
  v2_2_=0;
  v3_2_=0;
  v4_2_=0;
}

void Dados::lanzamiento()
{
  d1_=(rand()%6)+1;
  d2_=(rand()%6)+1;
  lanz1_++;
  lanz2_++;
  sum1_ += d1_;
  ordena1();
  sum2_ += d2_;
  ordena2();
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
    ordena1();
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
    ordena2();
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
  float media = 0;
  if (lanz1_ == 0)
  {
    return media;
  }
  media = sum1_/lanz1_;
  return media;
}

float Dados::getMedia2()
{
  float media = 0;
  if (lanz2_ == 0)
  {
    return media;
  }
  media = sum2_/lanz2_;
  return media;
}

void Dados::ordena1()
{
  v4_1_=v3_1_;
  v3_1_=v2_1_;
  v2_1_=v1_1_;
  v1_1_=v0_1_;
  v0_1_=d1_;
}

void Dados::ordena2()
{
  v4_2_=v3_2_;
  v3_2_=v2_2_;
  v2_2_=v1_2_;
  v1_2_=v0_2_;
  v0_2_=d2_;
}

void Dados::getUltimos1(int ultimos[])
{
  ultimos[4]=v4_1_;
  ultimos[3]=v3_1_;
  ultimos[2]=v2_1_;
  ultimos[1]=v1_1_;
  ultimos[0]=v0_1_;
}

void Dados::getUltimos2(int ultimos[])
{
  ultimos[4]=v4_2_;
  ultimos[3]=v3_2_;
  ultimos[2]=v2_2_;
  ultimos[1]=v1_2_;
  ultimos[0]=v0_2_;
}